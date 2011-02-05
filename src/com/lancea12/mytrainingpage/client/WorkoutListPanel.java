package com.lancea12.mytrainingpage.client;

import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.VerticalPanel;

public class WorkoutListPanel extends VerticalPanel {

	public WorkoutListPanel() {
		super();
		
		setStyleName("workoutList");
		
		add(new Label("workout 1"));
		add(new Label("workout 2"));
	}

	
}
