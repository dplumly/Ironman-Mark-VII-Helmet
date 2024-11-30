#include <Servo.h> 

Servo servo1; 
Servo servo2; 

int button = 3; 
int eyes = 9;         

int reading;           
bool faceplateOpen = false; 

void setup() 
{
  Serial.begin(9600);
  servo1.attach(5);
  servo2.attach(6);    
  pinMode(eyes, OUTPUT);
  pinMode(button, INPUT); 

 if (faceplateOpen) {
    closeFacePlate();
  }

  servo1.write(170);
  servo2.write(0);

  Serial.println("Setup complete");  
}

void loop() {
  reading = digitalRead(button);

  static unsigned long lastPress = 0;
  if (reading == HIGH && millis() - lastPress > 50) { 
    lastPress = millis();

    if (faceplateOpen) {
      closeFacePlate();
      lightsOn();
      faceplateOpen = false;
    } else {
      openFacePlate();
      lightsOff();
      faceplateOpen = true;
    }
  }
}

void openFacePlate() {
  Serial.println("Opening faceplate");
  
  for (int pos = 170; pos >= 0; pos -= 5) {
    servo1.write(pos);  
    delay(10);
  }

  for (int pos2 = 0; pos2 <= 170; pos2 += 5) {
    servo2.write(pos2); 
    delay(10);
  }
  delay(350); 
}


// OPening/closing facemask functions
void closeFacePlate() {
  Serial.println("Closing faceplate");

  for (int pos = 0; pos <= 170; pos += 5) {
    servo1.write(pos);
    delay(10);
  }

  for (int pos2 = 170; pos2 >= 0; pos2 -= 5) {
    servo2.write(pos2);
    delay(10);
  }
  delay(350); 
}


// Lighting up eyes functions
void lightsOn() {
  Serial.println("Turning lights on");
  digitalWrite(eyes, HIGH);    
}

void lightsOff() {
  Serial.println("Turning lights off");
  digitalWrite(eyes, LOW);    
}



















//#include <Servo.h>
//
//Servo servo1;
//Servo servo2;
//
//int button = 3;
//int eyes = 9;
//
//
//int state;
//int reading;
//int pos = 0;
//int pos2 = 0;
//
//// long time = 0;
//// long debounce = 50;
//
//void setup()
//{
//  Serial.begin(9600);
//  servo1.attach(5);
//  servo2.attach(6);
//  pinMode(eyes, OUTPUT);
//  pinMode(button, INPUT_PULLUP);
//  Serial.println("setup");
//}
//
//
//void loop ()
//{
//  Serial.println("main loop");
//
//  reading = digitalRead(button);
//  state = digitalRead(eyes);
//
//  if (reading == HIGH && state == LOW) {
//    delay(15);
//    if (reading == HIGH && state == LOW) {
//      closeFacePlate();
//      delay(10);
//      lightsOn();
//    }
//  }
//
//  if (reading == HIGH && state == HIGH) {
//    delay(15);
//    if (reading == HIGH && state == HIGH) {
//      openFacePlate();
//      delay(10);
//      lightsOff();
//    }
//  }
//}
//
//
//
//
//
//
//void openFacePlate()
//{
//  Serial.println("openFacePlate Function");
//
//  for (pos = 170; pos >= 0; pos -= 10) {
//    servo1.write(pos);
//    delay(10);
//  }
//
//  for (pos2 = 0; pos2 <= 170; pos2 += 10) {
//    servo2.write(pos2);
//    delay(10);
//  }
//}
//
//void closeFacePlate()
//{
//  Serial.println("closeFacePlate Function");
//
//  for (pos = 0; pos <= 170; pos += 10) {
//    servo1.write(pos);
//    delay(10);
//  }
//
//  for (pos2 = 170; pos2 >= 0; pos2 -= 10) {
//    servo2.write(pos2);
//    delay(10);
//  }
//}
//
//void lightsOn()
//{
//  digitalWrite(eyes, HIGH);
//}
//
//void lightsOff()
//{
//  digitalWrite(eyes, LOW);
//}
//
//
//
//
