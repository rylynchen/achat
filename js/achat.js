/**
 * @file achat.js
 *
 * Node JS Callbacks and general Javascript code for the Node JS Chat module.
 */

(function ($) {

  Drupal.behaviors.achat = {
    attach: function (context, settings) {

      $('.achat_form', context).once('achat_form', function () {

        delete Drupal.ajax['edit-send'].options.beforeSerialize;

        $('input[name="checkall"]', this).click(Drupal.behaviors.achat.checkAll);

        $('.achat_form .user-list ul .form-checkbox').click(Drupal.behaviors.achat.checkboxChanged);


      });

      $('.achat_upload_form', context).once('achat_upload_form', function () {
        delete Drupal.ajax['edit-upload'].options.beforeSerialize;
      });

    },

    checkAll: function(e) {
      $('.user-list input[type="checkbox"]').attr('checked', e.target.checked);
    },

    checkboxChanged: function(e) {
      var allchecked = true;
      $('.user-list ul .form-checkbox').each(function(){
        allchecked = this.checked;
        if (this.checked == false) {
          return false;
        }
      });
      $('.achat_form input[name="checkall"]').attr('checked', allchecked);
    },

    addUser: function(message) {
      var uid = message.data.user.uid;
      var name = message.data.user.name;
      var picture = message.data.user.picture != '0' ? message.data.user.picture : Drupal.settings.achat.globalSettings.defaultAvatar;

      var ajax_settings = {
        url: Drupal.settings.achat.currentForm.add_user_ajax_path,
        submit: {form_build_id: Drupal.settings.achat.currentForm.form_build_id, uid: uid},
        selector: '.achat_form'
      };

      var ajax = new Drupal.ajax(false, false, ajax_settings);
      ajax.eventResponse(ajax, {});

      var checkbox = '<input type="checkbox" class="form-checkbox" value="1" name="users[' + uid + ']" id="edit-users-' + uid + '" ' + (document.getElementById('edit-checkall').checked ? 'checked="checked"' : '') + ' />';

      var form_item = '<div class="form-item form-type-checkbox form-item-users-' + uid + '">' + checkbox + '</div>';

      var markup = '<li class="achat-user-box-' + uid + '" class="achat-user-box first">' + picture + '<span class="username">' + name + '</span>' + form_item + '</li>';

      var newElement = $(markup);

      $(newElement).click(Drupal.behaviors.achat.checkboxChanged);
      
      $('#achat_' + message.channel + ' .user-list ul').append(newElement);
    },

    isAccepter: function(msg) {
      var accept = false;
      if (Drupal.settings.achat.currentUser.uid == msg.uid) {
        accept = true;
      } else {
        for(var i in msg.to) {
          if (Drupal.settings.achat.currentUser.uid == msg.to[i]) {
            accept = true;
            break;
          }
        }
      }
      return accept;
    }
  };

  Drupal.ajax.prototype.commands.achatCleanTextarea = function(ajax, response, status)
  {
    var selector = response.data.selector;
    $(selector).val('').focus();
  };

  Drupal.ajax.prototype.commands.reloadBehaviors = function(ajax, response, status)
  {
    Drupal.attachBehaviors();
  };


  Drupal.achat = Drupal.achat || {'initialised' : false};
  var chatIdsMapping = {};

  Drupal.achat.initialiseChat = function() {
    for (var chat in Drupal.settings.achat.chats) {
      // For Chats transmitting messages through sockets, make sure the user is
      // added to the chat channel.
      if (!Drupal.settings.achat.chats[chat].settings.messageTransmission) {
        Drupal.achat.addClientToChatChannel(Drupal.settings.achat.chats[chat].channel);
      }

      // Chat form events handling.
      var chatID = '#achat_' + Drupal.settings.achat.chats[chat].channel;
      chatIdsMapping[chatID] = Drupal.settings.achat.chats[chat].channel;

      $(chatID + ' .form-type-textarea textarea').keyup(function(e) {
        if (e.keyCode == 13 && !e.shiftKey && !e.ctrlKey) {
          var ajax = Drupal.ajax['edit-send'];
          ajax.eventResponse(ajax.element, ajax.event);
        }
        else {
          return true;
        }
      });

    }
  }

  Drupal.Nodejs.connectionSetupHandlers.achat = {
    connect: function() {
      Drupal.achat.initialiseChat();
      Drupal.achat.initialised = true;
    }
  }

  Drupal.Nodejs.callbacks.nodejsChatUserOnlineHandler = {
    callback: function (message) {
      if ($('#achat_' + message.channel + ' .achat-user-box-' + message.data.user.uid).length == 0) {
        Drupal.behaviors.achat.addUser(message);
      }
    }
  }

  Drupal.Nodejs.callbacks.nodejsChatMessageHandler = {
    callback: function(message) {
      var msg = message.data;
      if (Drupal.behaviors.achat.isAccepter(msg)) {
        var chatID = '#achat_' + message.channel;

        // Get current date, to display the time at which the message was sent.
        var currentTime = new Date();
        var messageTime = '<span class="message-time">' + currentTime.getHours() + ':' + currentTime.getMinutes() + '</span>';
        var messageAuthor = '<span class="message-author">' + msg.name + ':</span>';

        var messageText = '<span class="message-text">' + msg.msg + '</span>';

        // Assemble the markup for the message.
        var messageMarkUp = '<div class="achat-message"><div class="message-content"> ' + messageAuthor + messageText + '</div>'
          + messageTime + '</div>';

        // Finally, add it to the chat log.
        $(chatID + ' .chat-log').append(messageMarkUp);

        // Scroll to the last comment. TODO: This has to be improved, to avoid
        // auto-scrolling when a user is reading the comments log. Checking if the
        // chat-log div is focused might be enough.
        $(chatID + ' .chat-log')[0].scrollTop = $(chatID + ' .chat-log')[0].scrollHeight;

        Drupal.attachBehaviors($('.chat-log'));
      }
    }
  }

  Drupal.Nodejs.contentChannelNotificationCallbacks.achat = {
    callback: function (message) {
      if (message.contentChannelNotification && message.data.type == 'disconnect') {
        var uid = message.data.uid;
        var chatID = '#achat_' + message.channel;
        $(chatID + ' .achat-user-box-' + uid).remove();
      }
    }
  }

  Drupal.achat.addClientToChatChannel = function(channelId) {
    var msg = {
      type: 'achat',
      action: 'chat_init',
      channel: channelId,
      callback: 'nodejsChatUserOnlineHandler',
      data: {
        user: Drupal.settings.achat.currentUser
      }
    };
    Drupal.Nodejs.socket.emit('message', msg);
  }

})(jQuery)