package com.lancea12.mytrainingpage.client;

import com.google.gwt.user.client.rpc.AsyncCallback;
import com.lancea12.mytrainingpage.shared.LoginInfo;

/**
 * The async counterpart of <code>LoginService</code>.
 */
public interface LoginServiceAsync {
  void isLoggedIn(AsyncCallback<Boolean> callback);
  void login(String requestUri, AsyncCallback<LoginInfo> callback);
  void logout(String requestUri, AsyncCallback<LoginInfo> callback);
}
