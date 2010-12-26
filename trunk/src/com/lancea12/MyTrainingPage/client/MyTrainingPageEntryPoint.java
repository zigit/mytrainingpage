package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.core.client.GWT;
import com.google.gwt.http.client.Request;
import com.google.gwt.http.client.RequestBuilder;
import com.google.gwt.http.client.RequestCallback;
import com.google.gwt.http.client.RequestException;
import com.google.gwt.http.client.Response;
import com.google.gwt.http.client.RequestBuilder.Method;
import com.google.gwt.user.client.rpc.AsyncCallback;
import com.google.gwt.user.client.ui.Anchor;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.VerticalPanel;
import com.lancea12.MyTrainingPage.shared.LoginInfo;




public class MyTrainingPageEntryPoint implements EntryPoint {


	private LoginInfo loginInfo = null;
	private VerticalPanel loginPanel = new VerticalPanel();
	private Label loginLabel = new Label("Please sign in to your Google Account to access the StockWatcher application.");
	private Anchor signInLink = new Anchor("Sign In");
	private LoginServiceAsync loginService;
	
	public LoginServiceAsync getLoginService() {
		return loginService;
	}


	public void setLoginService(LoginServiceAsync loginService) {
		this.loginService = loginService;
	}


	@Override
	public void onModuleLoad() {
		

		// Check login status using login service.
	    loginService = GWT.create(LoginService.class);
	    loginService.login(GWT.getHostPageBaseURL(), new AsyncCallback<LoginInfo>() {
	    	public void onFailure(Throwable error) {
	    	}

	    	public void onSuccess(LoginInfo result) {
	    		loginInfo = result;
	    		if(loginInfo.isLoggedIn()) {
	    			loadTrainingPage();
	    		} else {
	    			loadLogin();
	    		}
	    	}
	    });
		
	}
	
	
	public void loadTrainingPage(){	
		HorizontalPanel mainPanel = new HorizontalPanel();
		VerticalPanel appPanel = new AppPanel(this);
		VerticalPanel adPanel = new VerticalPanel();
		
		
		Label adLabel = new Label("Ads go here");
//		adPanel.addStyleName("adContainer");
		adPanel.add(adLabel);

		
		mainPanel.add(appPanel);
		mainPanel.add(adPanel);
		
		RootPanel.get("appContainer").add(appPanel);
		RootPanel.get("adContainer").add(adPanel);

	}


	private void loadLogin() {
		// Assemble login panel.
		RequestBuilder reqBuilder = new RequestBuilder(RequestBuilder.GET, loginInfo.getLoginUrl());
		reqBuilder.setCallback(new RequestCallback() {
			
			@Override
			public void onResponseReceived(Request request, Response response) {
				loginPanel.add(new HTML(response.getText()));
			}
			
			@Override
			public void onError(Request request, Throwable exception) {
			}
		});
		try {
			Request req = reqBuilder.send();
		} catch (RequestException e) {
			e.printStackTrace();
		}
//		signInLink.setHref(loginInfo.getLoginUrl());
//		loginPanel.add(loginLabel);
//		loginPanel.add(signInLink);
		RootPanel.get().add(loginPanel);
	}
	
		
}
