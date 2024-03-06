#include <Servo.h>

// Initializing 5 servo fingers
Servo thumb;
Servo indexFinger;
Servo middleFinger;
Servo ringFinger;
Servo pinkyFinger;

// Servo pin (Change as per your connection)
#define THUMB_PIN 2 
#define INDEX_PIN 3
#define MIDDLE_PIN 5
#define RING_PIN 6
#define PINKY_PIN 9

void setup() {
  // Attaching each servo to its respective pin
  thumb.attach(THUMB_PIN);
  indexFinger.attach(INDEX_PIN);
  middleFinger.attach(MIDDLE_PIN);
  ringFinger.attach(RING_PIN);
  pinkyFinger.attach(PINKY_PIN);
}

void loop() {
  // Open all servos
  thumb.write(0);
  indexFinger.write(0);
  middleFinger.write(0);
  ringFinger.write(0);
  pinkyFinger.write(0);
  
  delay(2000); // 2-second delay
  
  // Close all servos
  thumb.write(180);
  indexFinger.write(180);
  middleFinger.write(180);
  ringFinger.write(180);
  pinkyFinger.write(180);
  
  delay(2000); // 2-second delay
}
