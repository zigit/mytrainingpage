package com.lancea12.mytrainingpage.client.command;

import com.google.gwt.core.client.GWT;
import com.google.gwt.user.client.Command;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.lancea12.mytrainingpage.client.LoginServiceAsync;
import com.lancea12.mytrainingpage.shared.LoginInfo;

public class LogoutCommand implements Command {

	private LoginServiceAsync loginService;
	
	public LogoutCommand(LoginServiceAsync loginService) {
		super();
		this.loginService = loginService;
		// TODO Auto-generated constructor stub
	}

	@Override
	public void execute() {
		loginService.logout(GWT.getHostPageBaseURL(),  new AsyncCallback<LoginInfo>() {

			@Override
			public void onSuccess(LoginInfo result) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void onFailure(Throwable caught) {
				// TODO Auto-generated method stub
				
			}
		    });
	}

}
