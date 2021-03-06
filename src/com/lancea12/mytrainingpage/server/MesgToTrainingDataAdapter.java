////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2008 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 1.0Release
// Tag = $Name: AKW1_000 $
////////////////////////////////////////////////////////////////////////////////


package com.lancea12.mytrainingpage.server;

import com.garmin.fit.*;
import com.lancea12.mytrainingpage.server.trainingData.Activity;
import com.lancea12.mytrainingpage.server.trainingData.Session;

import java.util.Collection;
import java.util.Iterator;

public class MesgToTrainingDataAdapter implements MesgListener, MesgDefinitionListener {

	private boolean inLap = false;
	private Activity trainingActivity;
	private Session curSession;
	
	public MesgToTrainingDataAdapter() {}

	public void close() {}

	public void onMesgDefinition(MesgDefinition mesgDef) {
		Collection<FieldDefinition> fields = mesgDef.getFields();
		Mesg mesg = Factory.createMesg(mesgDef.getNum());

		if (mesg == null){
		} else {
			//System.out.println("defining " + mesg.getName());
		}
	}

	public void onMesg(Mesg mesg) {

		System.out.println(mesg.getName());
		
		if (mesg.getName().equals("file_id")){
			inLap = true;
			trainingActivity = new Activity();
			
		} else if (mesg.getName().equals("record")){
			processRecord (mesg);
		} else if  (mesg.getName().equals("lap")){
			processLap(mesg);
		} else if (mesg.getName().equals("event")){
			processEvent(mesg);
		}
		


	}
	
	
	
	private void processRecord (Mesg mesg) {
		Collection<Field> fields = mesg.getFields();
		Iterator<Field> fieldsIterator;
		fieldsIterator = fields.iterator();

		while (fieldsIterator.hasNext()) {
			Field field = fieldsIterator.next();
			if  (field.getName().equals("timestamp")){
				System.out.println("\t" + field.getName() + " = " + field.getValue());
			}
		}
	}
	
	private void processEvent (Mesg mesg){
		Collection<Field> fields = mesg.getFields();
		Iterator<Field> fieldsIterator;
		fieldsIterator = fields.iterator();

		boolean timerTrigger = false;
		while (fieldsIterator.hasNext()) {
			Field field = fieldsIterator.next();
			System.out.println("\t" + field.getName() + " = " + field.getValue());
			if (field.getName().equals("timer_trigger")){
				timerTrigger = true;
			}
			if (timerTrigger && field.getName().equals("event_type")){
				if ((Integer)field.getValue() == 0){
					curSession = new Session();
					
				}
			}
		}
	}
	
	private void processLap (Mesg mesg){
		Collection<Field> fields = mesg.getFields();
		Iterator<Field> fieldsIterator;
		fieldsIterator = fields.iterator();

		while (fieldsIterator.hasNext()) {
			Field field = fieldsIterator.next();
			System.out.println("\t" + field.getName() + " = " + field.getValue());
		}
	}
	
	
}
