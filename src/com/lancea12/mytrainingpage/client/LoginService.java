package com.lancea12.mytrainingpage.client;

import com.google.gwt.user.client.rpc.RemoteService;
import com.google.gwt.user.client.rpc.RemoteServiceRelativePath;
import com.lancea12.mytrainingpage.shared.LoginInfo;

/**
 * The client side stub for the RPC service.
 */
@RemoteServiceRelativePath("login")
public interface LoginService extends RemoteService {
  Boolean isLoggedIn();
  LoginInfo login(String requestUri);
  LoginInfo logout(String requestUri);
}
