package com.lancea12.MyTrainingPage.client;

import com.google.gwt.user.client.rpc.AsyncCallback;
import com.lancea12.MyTrainingPage.shared.LoginInfo;

/**
 * The async counterpart of <code>GreetingService</code>.
 */
public interface LoginServiceAsync {
  void isLoggedIn(AsyncCallback<Boolean> callback);
  void login(String requestUri, AsyncCallback<LoginInfo> callback);
  void logout(String requestUri, AsyncCallback<LoginInfo> callback);
}
