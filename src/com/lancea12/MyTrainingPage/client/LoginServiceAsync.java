package com.lancea12.MyTrainingPage.client;

import com.google.gwt.user.client.rpc.AsyncCallback;
import com.lancea12.MyTrainingPage.shared.User;

/**
 * The async counterpart of <code>GreetingService</code>.
 */
public interface LoginServiceAsync {
  void isLoggedIn(AsyncCallback<Boolean> callback);
  void login(String userName, String password, AsyncCallback<Boolean> callback);
  void register(User user, AsyncCallback<Boolean> callback);
}
