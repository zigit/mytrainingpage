package com.lancea12.MyTrainingPage.client;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.TextArea;

public class Mytrainingpage implements EntryPoint{

	@Override
	public void onModuleLoad() {
		displayLogin();
		
	}
	
	
	private  void displayLogin(){
		TextArea text = new TextArea();
		text.setText("Please Login - this is a stub");
		RootPanel.get().add(text);
	}

}
