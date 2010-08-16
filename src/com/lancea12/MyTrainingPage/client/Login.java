package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.GWT;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.ToggleButton;

public class Login {

	/**
	 * Create a remote service proxy to talk to the server-side Login service.
	 */	
	private final LoginServiceAsync loginService = GWT
			.create(LoginService.class);

	public String loginCheck () {
		
		final TextArea loggedIn = new TextArea();
		
		loginService.isLoggedIn(new AsyncCallback<Boolean>() {
			
			@Override
			public void onSuccess(Boolean result) {
				if (result){
					loggedIn.setText("logged in");
				} else {
					loggedIn.setText("please log in");
				}
			}
			
			@Override
			public void onFailure(Throwable caught) {
				loggedIn.setText("can't communicate with server");
			}
		});
		
		return loggedIn.getText();
	}
	
}
