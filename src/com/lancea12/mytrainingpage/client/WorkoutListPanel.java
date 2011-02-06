package com.lancea12.mytrainingpage.client;

import com.google.gwt.user.client.ui.HasVerticalAlignment;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.VerticalPanel;

public class WorkoutListPanel extends VerticalPanel {

	public WorkoutListPanel() {
		super();
		
		setStyleName("workoutList");
		setVerticalAlignment(HasVerticalAlignment.ALIGN_TOP);
		setSpacing(0);
		
		for (int i=0; i<3; i++) {
			Label label = new Label("workout " + i);
			
			label.setStyleName("workoutListItem");
			add(label);
			//setCellHeight(label, "300px");
		}
		
		
	}

	
}
