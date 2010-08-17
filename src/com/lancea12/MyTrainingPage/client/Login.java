package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.GWT;
import com.google.gwt.user.client.ui.TextArea;

public class Login {

	/**
	 * Create a remote service proxy to talk to the server-side Login service.
	 */	
	private final LoginService loginService = GWT
			.create(LoginService.class);

	public String loginCheck () {
		
		final TextArea loggedIn = new TextArea();
		
		if (loginService.isLoggedIn()){
			loggedIn.setText("logged  in");
		} else {
			loggedIn.setText("Please log in");
		}
				
		return loggedIn.getText();
	}
	
}
