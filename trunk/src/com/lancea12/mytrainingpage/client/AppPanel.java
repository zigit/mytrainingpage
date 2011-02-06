package com.lancea12.mytrainingpage.client;


import com.google.gwt.event.logical.shared.HasResizeHandlers;
import com.google.gwt.event.logical.shared.ResizeEvent;
import com.google.gwt.event.logical.shared.ResizeHandler;
import com.google.gwt.event.shared.HandlerRegistration;
import com.google.gwt.user.client.ui.MenuBar;
import com.google.gwt.user.client.ui.MenuItem;
import com.google.gwt.user.client.ui.VerticalPanel;
import com.lancea12.mytrainingpage.client.command.LogoutCommand;

public class AppPanel extends VerticalPanel implements HasResizeHandlers{

	private DataTabPanel dataTabPanel;
	
	public AppPanel(MyTrainingPageEntryPoint entryPoint) {
		MenuBar menuBar = new MenuBar();
		menuBar.addItem(new MenuItem("logout", new LogoutCommand(entryPoint.getLoginService())));
		dataTabPanel = new DataTabPanel();

		
		this.setStyleName("appContainer");

		// add elements
		this.add(menuBar);
		this.add(new WorkoutListPanel());
		
		this.addResizeHandler(new ResizeHandler() {
			
			@Override
			public void onResize(ResizeEvent event) {
				System.out.println("app panel " + event.getWidth() + " " + event.getHeight());
				ResizeEvent.fire(dataTabPanel, event.getWidth() - 300, event.getHeight() - 10);
			}
		});
		
		this.add (dataTabPanel);		
		

	}
	


	@Override
	public HandlerRegistration addResizeHandler(ResizeHandler handler) {
		return addHandler(handler, ResizeEvent.getType());
	}

	
}
