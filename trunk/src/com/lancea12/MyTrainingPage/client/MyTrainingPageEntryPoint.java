package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.VerticalPanel;


public class MyTrainingPageEntryPoint implements EntryPoint {



	
	@Override
	public void onModuleLoad() {

		VerticalPanel appPanel = new VerticalPanel();
		Login login = new Login(appPanel);
		appPanel.addStyleName("appContainer");
		login.loginCheck();

		VerticalPanel adPanel = new VerticalPanel();
		Label adLabel = new Label("Ads go here");
		adPanel.addStyleName("adContainer");
		adPanel.add(adLabel);

		RootPanel.get("appContainer").add(appPanel);
		RootPanel.get("adContainer").add(adPanel);


		
	}
	

}
