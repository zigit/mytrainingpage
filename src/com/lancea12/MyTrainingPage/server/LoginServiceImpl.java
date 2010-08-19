package com.lancea12.MyTrainingPage.server;

import com.lancea12.MyTrainingPage.client.LoginService;
import com.google.gwt.user.server.rpc.RemoteServiceServlet;

/**
 * The server side implementation of the RPC service.
 */
@SuppressWarnings("serial")
public class LoginServiceImpl extends RemoteServiceServlet implements
LoginService {



	@Override
	public Boolean isLoggedIn() {
		return false;
	}

	@Override
	public Boolean login(String userName, String password) {
		// TODO Auto-generated method stub
		return null;
	}

}
