#include <AFMotor.h>
#include <Servo.h>           
Servo name_servo; 
Servo servo2;
int fsrPin = A0;     
int fsrReading;
int servo_position = 0 ;
int state = 1;
const int redPin1 = 3;
const int greenPin2 = 4;
int greenbuttonPin = 0;
int redbuttonPin = 0;


void setup(){
Serial.begin(9600); 
name_servo.attach (10); 
servo2.attach (9);
greenbuttonPin = digitalRead(greenPin2);
redbuttonPin = digitalRead(redPin1);
  pinMode(redPin1, INPUT);
  pinMode(greenPin2, INPUT);
}

void loop(){ 
fsrReading = analogRead(fsrPin);  
if (fsrReading > 1){ 
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
  
  if(state == 1){
    if (fsrReading > 1){
      state = 2;
      Serial.println(state);
    } 
  }

  if (state == 2) {
    if(fsrReading < 1  ){
      state = 1;
      Serial.println(state);
    }
    else{
     if (greenbuttonPin == HIGH) {
      state = 4;  
      Serial.println(state);
     }
     else{
      if (redbuttonPin == HIGH){
        state = 3;
        Serial.println(state);
      }
     }
    }
  }
    if (state == 4){
    if (greenbuttonPin == HIGH){
      servo2.attach (9);
      servo2.write (0);
      name_servo.attach(10);
      name_servo.write (180);
      Serial.println(state);
  
  }
  else {
    (state = 2);
  }
  }  
  else if (state == 3){
    if (redbuttonPin == HIGH){
      servo2.attach (9);
      servo2.write (180);
      name_servo.attach (10);
      name_servo.write (0);
      Serial.println(state);
  }
  
  else { 
     (state = 2);
  }
  } 
  //if (state == 4){
    //if (greenbuttonPin == HIGH){
      //servo2.attach (9);
      //servo2.write (180);
      //name_servo.attach(10);
      //name_servo.write (0);
      //Serial.println(state);
  //}
  //}
  //else {
    //(state = 2);
  //}
   
  
  
  if (fsrReading < 10) {
    Serial.println(" - No pressure");
  } else if (fsrReading < 100) {
    Serial.println(" - Light touch");
  } else if (fsrReading < 300) {
    Serial.println(" - Light squeeze");
  } else if (fsrReading < 600) {
    Serial.println(" - Medium squeeze");
  } else {
    Serial.println(" - Big squeeze");
  }  
 greenbuttonPin = digitalRead(greenPin2);
 redbuttonPin = digitalRead(redPin1);
 if (greenbuttonPin == HIGH) {
    Serial.println("greenon");
  }else {
    Serial.println("1off");
  }
  if (redbuttonPin == HIGH) {
    Serial.println ("redon");
  } else {
    Serial.println("2off");
  }
  name_servo.detach();
  servo2.detach();
// if (fsrReading > 50) {
  //name_servo.attach (10);
  //name_servo.write (0);
  //servo2.attach (9);
  //servo2.write (180);
  //}
  //else {
  //name_servo.detach();
  //servo2.detach();
}
}
      
