package com.lancea12.MyTrainingPage.client;

import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.MenuBar;
import com.google.gwt.user.client.ui.MenuItem;
import com.google.gwt.user.client.ui.VerticalPanel;
import com.lancea12.MyTrainingPage.client.command.LogoutCommand;

public class AppPanel extends VerticalPanel {

	public AppPanel(MyTrainingPageEntryPoint entryPoint) {
		MenuBar menuBar = new MenuBar();
		menuBar.addItem(new MenuItem("logout", new LogoutCommand(entryPoint.getLoginService())));
		
		this.addStyleName("appContainer");
		Label testLabel = new Label("app panel");
		
		//this.add(menuBar);
		this.add(testLabel);
	}

	
}
