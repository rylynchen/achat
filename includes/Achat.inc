<?php

/**
 * Basic chat class
 */
class Achat {

  public $channel;

  public $type;

  public $settings;

  public $user_ids;

  public $form;

  /**
   * Basic constructor, just with the socket.io channel assigned.
   */
  function __construct($channel, $type = 0, $settings = array()) {
    $unique_id = &drupal_static(__METHOD__);
    if (!isset($unique_id)) {
      $unique_id = 0;
    }
    $unique_id++;
    $unique_channel = __CLASS__ . '__' . $channel . '_' . $unique_id;

    $this->type = $type;

    // Some filtering to avoid unwanted characters on the channel_name.
    $this->channel = preg_replace('/[^(_|a-zA-Z0-9)]/', '_', $unique_channel);

    // Check if chat channel exists
    if (!nodejs_get_check_channel($this->channel)) {
      // It doesn't, so try to add it.
      if (nodejs_get_add_channel($this->channel)) {
        // Create channel successfully
      }
      // In case of error, let the caller know.
      else {
        watchdog('achat', 'The Chat channel couldn\'t be created, channel:' . $channel . ' , user:' . $GLOBALS['user']->uid);
        return FALSE;
      }
    }

    // Store any settings passed on to the constructor.
    $this->settings = $settings;
  }

  /**
   * Wrapper function to call sequential steps to render a functional chat.
   */
  function render() {
    // Create socket.io channel
    $this->createSocketChannel();

    // Set the list of present users.
    $this->setUserList();

    // Generate form
    $this->form = $this->getForm();

    // Add assets to the page
    $this->loadAssets();

    // Render the form.
    return drupal_render($this->form);
  }

  /**
   * Generate render array for the chat form.
   */
  function getForm() {
    // If the render array has already been generated, return it.
    if (isset($this->form)) {
      return $this->form;
    }

    return drupal_get_form('achat_form', $this->channel, $this->user_ids, $this->settings, $this->type);
  }

  function loadAssets() {
    cdialog_include();
    // Javascript Assets.
    drupal_add_js(drupal_get_path('module', 'achat') . '/js/achat.js', array('weight' => 30));

    // This is not the best place to do this, but for now it does the job to
    // allow a dev to choose whether the chat messages will go through drupal,
    // or through the nodejs server extension (directly through sockets).
    $this->settings['postMessagePath'] = url('achat/ajax/message', array('absolute' => TRUE));

    // Add general chat settings.
    $chat_settings = array(
      $this->channel => array(
        'channel' => $this->channel,
        'type' => $this->type,
        'settings' => $this->settings,
      ),
    );
    drupal_add_js(array('achat' => array('chats' => $chat_settings)), 'setting');

    // Add global settings. TODO: This should be overridable.
    $global_settings = array(
      'defaultAvatar' => '/' . variable_get('user_picture_default', ''),
    );
    drupal_add_js(array('achat' => array('globalSettings' => $global_settings)), 'setting');

    // Current user settings.
    global $user;
    $current_user = array(
      'uid' => $user->uid,
      'name' => $user->name,
      'picture' => $user->picture,
    );
    $form_build_id = isset($this->form['#build_id']) ? $this->form['#build_id'] : NULL;
    $current_form = array(
      'form_build_id' => $form_build_id,
      'add_user_ajax_path' => '/achat/ajax/form-add-user',
    );
    drupal_add_js(array('achat' => array('currentUser' => $current_user, 'currentForm' => $current_form)), 'setting');

    // CSS Assets TODO: Make this optional, through a setting option maybe?.
    drupal_add_css(drupal_get_path('module', 'achat') . '/css/achat.css');
  }

  function createSocketChannel() {
    global $user;
    $account = user_load($user->uid);
    $avatar = array(
      'path' => isset($account->picture->uri) ? $account->picture->uri : variable_get('user_picture_default', ''),
      'height' => '35',
      'width' => '35',
      'alt' => $user->name,
    );

    $message = (object) array(
      'broadcast' => FALSE,
      'channel' => $this->channel,
      'callback' => 'nodejsChatUserOnlineHandler',
      'data' => array(
        'chatroom' => $this->channel,
        'name' => $user->name,
        'subject' => 'New user connected',
        'body' => 'User ' . $user->name . ' has entered the chat',
        'user' => array(
          'uid' => $user->uid,
          'name' => $user->name,
          'picture' => theme('image', $avatar),
        ),
      ),
    );
    nodejs_send_content_channel_token($this->channel, TRUE);
    nodejs_send_content_channel_message($message);
  }

  /**
   * Sets the list of users present on the chat, making sure the current user
   * is on the list.
   */
  function setUserList() {
    global $user;
    nodejs_add_user_to_channel($user->uid, $this->channel);
    $this->user_ids = $this->getUids();

    // Make sure the current user is as added as well to the channel uids, as it
    // might not have been added by node js if the server hasn't authenticated
    // him previously.
    if (empty($this->user_ids) || !in_array($user->uid, $this->user_ids)) {
      $this->user_ids[] = $user->uid;
      sort($this->user_ids);
    }
  }

  /**
   * Returns an array with the UIDs of the users present on the channel.
   */
  public function getUids() {
    $uids_on_channel = array();
    // Check socket.io channel and return the uids in the desired format.
    if ($users_on_channel = nodejs_get_content_channel_users($this->channel)) {
      // Check how data is returned, for compatibility with all nodejs verions.
      $uids_on_channel = is_object($users_on_channel) ? $users_on_channel->uids : $users_on_channel['uids'];
    }
    return $uids_on_channel;
  }

}
