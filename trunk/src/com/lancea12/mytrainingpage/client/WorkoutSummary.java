package com.lancea12.mytrainingpage.client;

import com.google.gwt.user.client.ui.CellPanel;
import com.google.gwt.user.client.ui.Label;

public class WorkoutSummary extends CellPanel {
	
	
	public WorkoutSummary () {
		add(new Label("Distance"));
		add(new Label("Time"));
		add(new Label("Average Speed"));

	}


}
