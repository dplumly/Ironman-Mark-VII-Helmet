#include <Servo.h>

Servo servo1;
Servo servo2;

const int BUTTON_PIN = 3;
const int EYES_PIN = 9;

bool faceplateOpen = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int lastButtonState = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(EYES_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  servo1.attach(5);
  servo2.attach(6);

  // Initialize servos to closed position
  servo1.write(170);
  servo2.write(0);

  servo1.detach();
  servo2.detach();

  Serial.println("Setup complete");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // Check for button state change with debounce
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Check if enough time has passed to consider the button stable
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW) {
      if (faceplateOpen) {
        closeFacePlate();
        lightsOn();
        faceplateOpen = false;
      } else {
        openFacePlate();
        lightsOff();
        faceplateOpen = true;
      }
      delay(300);
    }
  }
  lastButtonState = reading;
}

void openFacePlate() {
  Serial.println("Opening faceplate");
  servo1.attach(5);
  servo2.attach(6);

  for (int pos = 170; pos >= 10; pos -= 5) {
    servo1.write(pos);
  }

  for (int pos2 = 10; pos2 <= 170; pos2 += 5) {
    servo2.write(pos2);
  }
  delay(350);

  servo1.detach();
  servo2.detach();
}

void closeFacePlate() {
  Serial.println("Closing faceplate");
  servo1.attach(5);
  servo2.attach(6);

  for (int pos = 0; pos <= 170; pos += 5) {
    servo1.write(pos);
  }

  for (int pos2 = 170; pos2 >= 0; pos2 -= 5) {
    servo2.write(pos2);
  }
  delay(350);

  servo1.detach();
  servo2.detach();
}

void lightsOn() {
  Serial.println("Turning lights on");
  digitalWrite(EYES_PIN, HIGH);
}

void lightsOff() {
  Serial.println("Turning lights off");
  digitalWrite(EYES_PIN, LOW);
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
