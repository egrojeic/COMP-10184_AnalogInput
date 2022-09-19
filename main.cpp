/*
I, Jorge Isaza, student number 000811486, certify that all code submitted is my own work; 
that I have not copied it from any other source. 
I also certify that I have not allowed my work to be copied by others.
*/

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
String GetTempertureDescription(float temp){
  String response = "";

  if(temp <=10){
    response = "Cold";
  }
  else if(temp > 10 && temp <=15){
    response = "Cool";
  }
  else if(temp > 10 && temp <=15){
    response = "Cool";
  }
  else if(temp > 15 && temp <=25){
    response = "Perfect";
  }
  else if(temp > 25 && temp <=30){
    response = "Warm";
  }
  else if(temp > 30 && temp <=35){
    response = "Hot";
  }
  else if(temp > 35){
    response = "Too Hot";
  }


  return response;

}

void loop() { 
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
 
  float converterFactor = 50.0/1024.0;

  // print value to the USB port 

  String temperatureDescription = "";

  float temperature = 0;
  temperature = converterFactor * (float)iVal;



  temperatureDescription = " is equivalent to a temperature input of " + String(temperature) + " which is " + GetTempertureDescription(temperature) + "!";

  Serial.println("Digitized output of " + String(iVal) + temperatureDescription); 
 
  // wait 0.5 seconds (500 ms) 
  delay(500); 
} 


