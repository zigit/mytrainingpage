package com.lancea12.mytrainingpage.client;

import com.google.gwt.user.client.ui.MenuBar;
import com.google.gwt.user.client.ui.MenuItem;
import com.google.gwt.user.client.ui.VerticalPanel;
import com.lancea12.mytrainingpage.client.command.LogoutCommand;

public class AppPanel extends VerticalPanel {

	public AppPanel(MyTrainingPageEntryPoint entryPoint) {
		MenuBar menuBar = new MenuBar();
		menuBar.addItem(new MenuItem("logout", new LogoutCommand(entryPoint.getLoginService())));
		
		this.setStyleName("appContainer");
		
		this.add(menuBar);
		this.add(new WorkoutListPanel());
		
		this.add (new DataTabPanel());
		
	}

	
}
