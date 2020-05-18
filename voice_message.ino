#include <sim900.h>
#include <SoftwareSerial.h> 
#include <Wire.h> 

int Incomingch;
String data,Fdata;


SoftwareSerial gprs(9,10);

void setup(){
  Serial.begin(9600); 
  sim900_init(&gprs, 9600); 
  pinMode(8, OUTPUT); 
  Serial.println("Arduino - Automatic Voice Machine");
}


void check_Incoming()
{
    if(gprs.available())
    {
   Incomingch = gprs.read(); 
  
  if (Incomingch == 10 || Incomingch ==13) 
  {Serial.println(data);  Fdata =data; data = ""; 
  }
  else
  {
  String newchar = String (char(Incomingch));
  data = data +newchar;
  }
  }
}

void loop(){
  
   check_Incoming();
  
  if(Serial.available()){
    gprs.write(Serial.read()); 
  } 

  if (Fdata == "RING") 
  {
  delay(5000); 
  gprs.write ("ATA\r\n");
  Serial.println ("Placed Received");
  while(Fdata != "OK") 
  {check_Incoming();
  Serial.println ("Playing Recorded message"); 


  delay(500);
  digitalWrite(8, HIGH); 
  delay(200);                 
  digitalWrite(8, LOW); 
  }
  } 
}
