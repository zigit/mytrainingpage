package com.lancea12.MyTrainingPage.shared;

import javax.jdo.annotations.PersistenceCapable;
import javax.jdo.annotations.Persistent;

import com.google.gwt.i18n.client.LocalizableResource.Key;

@PersistenceCapable
public class User {

	@Persistent
	private String firstName;
	
	@Persistent
	private String lastName;
	

	public String getFirstName() {
		return firstName;
	}


	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}


	public String getLastName() {
		return lastName;
	}


	public void setLastName(String lastName) {
		this.lastName = lastName;
	}


	public String getUserName() {
		return userName;
	}


	public void setUserName(String userName) {
		this.userName = userName;
	}


	private String userName;
	
}
