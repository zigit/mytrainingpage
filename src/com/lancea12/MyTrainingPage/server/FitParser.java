package com.lancea12.MyTrainingPage.server;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;

import com.garmin.fit.Decode;
import com.garmin.fit.FileEncoder;
import com.garmin.fit.Fit;
import com.garmin.fit.MesgBroadcaster;
import com.garmin.fit.MesgDefinitionListener;
import com.garmin.fit.MesgListener;
import com.garmin.fit.MesgWithEventListener;
import com.garmin.fit.RecordMesgListener;
import com.garmin.fit.csv.CSVReader;
import com.garmin.fit.csv.LapCSVWriter;
import com.garmin.fit.csv.MesgCSVWriter;
import com.garmin.fit.csv.RecordCSVWriter;
import com.garmin.fit.csv.SessionCSVWriter;
import com.garmin.fit.test.Tests;

public class FitParser {

	
	   public static void main(String args[]) {
		      String in = "/home/lancea12/workspace/mytrainingpage/resources/data/2010-07-24-06-52-38.fit";
		      String out = "/home/lancea12/workspace/mytrainingpage/resources/output/new";




		      try {
		    	  if (!Decode.checkIntegrity((InputStream) new FileInputStream(in)))
		    		  throw new RuntimeException("FIT file integrity failure.");
		      } catch (java.io.IOException e) {
		    	  throw new RuntimeException(e);
		      }


		      Tests tests = new Tests();
		      System.out.println("Running FIT verification tests...");
		      if (tests.run(in))
		    	  System.out.println("Passed FIT verification.");
		      else
		    	  System.out.println("Failed FIT verification.");


		      try {
		    	  Decode decode = new Decode();
		    	  MesgBroadcaster broadcaster = new MesgBroadcaster(decode);
		    	  MesgToTrainingDataAdapter mesgToData = new MesgToTrainingDataAdapter();
		    	  //RecordCSVWriter recordWriter = new RecordCSVWriter(out + "_records.csv"); 

		    	  decode.addListener((MesgDefinitionListener) mesgToData);
		    	  decode.addListener((MesgListener) mesgToData);
		    	  //broadcaster.addListener((RecordMesgListener)recordWriter);
		    	  //broadcaster.addListener((MesgWithEventListener)recordWriter);

		    	  broadcaster.run((InputStream) new FileInputStream(in));


		    	  //recordWriter.close();
		      } catch (java.io.IOException e) {
		    	  throw new RuntimeException(e);
		      }


		   }
	
	
}
