package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.GWT;
import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.PasswordTextBox;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.TextBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class Login {

	/**
	 * Create a remote service proxy to talk to the server-side Login service.
	 */	
	private final LoginServiceAsync loginService = (LoginServiceAsync)GWT.create(LoginService.class);

	private VerticalPanel mainPanel;
	
	public Login (VerticalPanel vPanel){
		mainPanel = vPanel;
	}
	
	public void loginCheck () {
		
		final TextArea text = new TextArea();

		
		loginService.isLoggedIn(new AsyncCallback<Boolean>() {
			
			@Override
			public void onSuccess(Boolean loggedIn) {
				if (!loggedIn){
					displayLoginPage ();
				}
			}
			
			@Override
			public void onFailure(Throwable arg0) {
				text.setText("failure");
			}
		});
				


	}
	
	private void displayLoginPage(){
		Label loginLabel = new Label("Please Log In");
		loginLabel.addStyleName("gwt-Label");

		// create a panel for the username
		HorizontalPanel namePanel = new HorizontalPanel();
		Label nameLabel = new Label("Name:");
		TextBox nameBox = new TextBox();
		namePanel.add(nameLabel);
		namePanel.add(nameBox);
		namePanel.setVerticalAlignment(HorizontalPanel.ALIGN_MIDDLE);
		
		// create a panel for the password
		HorizontalPanel passwordPanel = new HorizontalPanel();
		PasswordTextBox passwordBox = new PasswordTextBox();
		Label passwordLabel = new Label("Password:");
		passwordPanel.add(passwordLabel);
		passwordPanel.add(passwordBox);
		passwordPanel.setHorizontalAlignment(HorizontalPanel.ALIGN_RIGHT);
		
		Button loginButton = new Button();
		loginButton.setText("Login");

		Button regButton = new Button();
		regButton.setText("Register");
		
		regButton.addClickHandler(new ClickHandler() {
			
			@Override
			public void onClick(ClickEvent event) {
				mainPanel.clear();
				displayRegPage();
				
			}
		});
		
		
		mainPanel.add(loginLabel);
		mainPanel.add(namePanel);
		mainPanel.add(passwordPanel);
		mainPanel.add(loginButton);
		mainPanel.add(regButton);
		mainPanel.setHorizontalAlignment(VerticalPanel.ALIGN_RIGHT);
	}
	
	private void displayRegPage(){
		Label regLabel = new  Label("Please provide the information below to register");
		
		mainPanel.add(regLabel);
	}

	
}
