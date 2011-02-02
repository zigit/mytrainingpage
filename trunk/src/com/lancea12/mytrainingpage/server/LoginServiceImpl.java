package com.lancea12.mytrainingpage.server;


import com.lancea12.mytrainingpage.client.LoginService;
import com.lancea12.mytrainingpage.shared.LoginInfo;
import com.google.appengine.api.users.User;
import com.google.appengine.api.users.UserService;
import com.google.appengine.api.users.UserServiceFactory;
import com.google.gwt.user.server.rpc.RemoteServiceServlet;

/**
 * The server side implementation of the RPC service.
 */
@SuppressWarnings("serial")
public class LoginServiceImpl extends RemoteServiceServlet implements
LoginService {

	private UserService userService;

	public LoginServiceImpl() {
		super();
		userService = UserServiceFactory.getUserService();
	}

	public LoginServiceImpl(Object delegate) {
		super(delegate);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Boolean isLoggedIn() {
		return false;
	}

	@Override
	public LoginInfo login(String requestUri) {
		
	    User user = userService.getCurrentUser();
	    LoginInfo loginInfo = new LoginInfo();

	    if (user != null) {
	      loginInfo.setLoggedIn(true);
	      loginInfo.setEmailAddress(user.getEmail());
	      loginInfo.setNickname(user.getNickname());
	      loginInfo.setLogoutUrl(userService.createLogoutURL(requestUri));
	    } else {
	      loginInfo.setLoggedIn(false);
	      loginInfo.setLoginUrl(userService.createLoginURL(requestUri));
	    }
	    return loginInfo;
	}
	
	
	public LoginInfo logout(String requestUri) {
		
		
		return null;
	}
	
	

}
