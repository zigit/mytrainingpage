package com.lancea12.mytrainingpage.server.trainingData;

public class DataPoint {
	
	private double latitude;
	private double longitude;
	private double altitude;
	public double getAltitude() {
		return altitude;
	}
	public void setAltitude(double altitude) {
		this.altitude = altitude;
	}
	public double getTemp() {
		return temp;
	}
	public void setTemp(double temp) {
		this.temp = temp;
	}
	private double speed;
	private int power;
	private int heartrate;
	private int cadence;
	private double temp;
	
	public int getCadence() {
		return cadence;
	}
	public void setCadence(int cadence) {
		this.cadence = cadence;
	}
	public double getLatitude() {
		return latitude;
	}
	public void setLatitude(double latitude) {
		this.latitude = latitude;
	}
	public double getLongitude() {
		return longitude;
	}
	public void setLongitude(double longitude) {
		this.longitude = longitude;
	}
	public double getSpeed() {
		return speed;
	}
	public void setSpeed(double speed) {
		this.speed = speed;
	}
	public int getPower() {
		return power;
	}
	public void setPower(int power) {
		this.power = power;
	}
	public int getHeartrate() {
		return heartrate;
	}
	public void setHeartrate(int heartrate) {
		this.heartrate = heartrate;
	}
	
	

}
