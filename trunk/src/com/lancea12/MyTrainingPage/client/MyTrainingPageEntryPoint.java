package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.TextArea;


public class MyTrainingPageEntryPoint implements EntryPoint {



	
	@Override
	public void onModuleLoad() {
		TextArea text = new TextArea();
		Login login = new Login();
		text.setText(login.loginCheck());


		//VerticalPanel vpanel = new VerticalPanel();
		//vpanel.add(text);
		RootPanel.get().add(text);
		
	}
	

}
