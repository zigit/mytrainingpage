package com.lancea12.mytrainingpage.client;

import com.google.gwt.event.logical.shared.HasResizeHandlers;
import com.google.gwt.event.logical.shared.ResizeEvent;
import com.google.gwt.event.logical.shared.ResizeHandler;
import com.google.gwt.event.shared.HandlerRegistration;
import com.google.gwt.user.client.ui.HTML;
import com.google.gwt.user.client.ui.TabPanel;

public class DataTabPanel extends TabPanel implements HasResizeHandlers{

	public DataTabPanel() {
		super();
		
		setStyleName("dataTabPanel");
		
		addResizeHandler(new ResizeHandler() {
			
			@Override
			public void onResize(ResizeEvent event) {
				System.out.println("data tabs " + event.getWidth() + " " + event.getHeight());
				DataTabPanel.this.setSize(event.getWidth() + "px", event.getHeight() + "px");
			}
		});
		
		add(new WorkoutSummary(), "summary");
		add(new HTML("Graph"), "graph");
		add(new HTML("Map"), "map");
		add(new HTML("Upload"), "upload");
	}

	@Override
	public HandlerRegistration addResizeHandler(ResizeHandler handler) {
		return addHandler(handler, ResizeEvent.getType());
	}


	
	
}
