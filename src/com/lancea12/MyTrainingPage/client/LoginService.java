package com.lancea12.MyTrainingPage.client;

import com.google.gwt.user.client.rpc.RemoteService;
import com.google.gwt.user.client.rpc.RemoteServiceRelativePath;
import com.lancea12.MyTrainingPage.shared.User;

/**
 * The client side stub for the RPC service.
 */
@RemoteServiceRelativePath("login")
public interface LoginService extends RemoteService {
  Boolean isLoggedIn();
  Boolean login(String userName, String password);
  Boolean register(User user);
}
