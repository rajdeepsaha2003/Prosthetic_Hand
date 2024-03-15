#include <Servo.h>

// Initializing 5 servo fingers
Servo thumb;
Servo index;
Servo midd;
Servo ring;
Servo pinky;

// Servo pin (Change as per your connection)
#define THUMB_PIN 2 
#define INDEX_PIN 3
#define MIDDLE_PIN 5
#define RING_PIN 6
#define PINKY_PIN 4

void setup() {
  // Attaching each servo to its respective pin
  thumb.attach(THUMB_PIN);
  index.attach(INDEX_PIN);
  midd.attach(MIDDLE_PIN);
  ring.attach(RING_PIN);
  pinky.attach(PINKY_PIN);
  Serial.begin(9600);
}

void loop() {
  // Open all servos
  Serial.print("0\n");
  ring.write(0);
  // delay(250);
  thumb.write(0);
  index.write(0);
  midd.write(0);
  pinky.write(0);
 
  
  delay(1000); // 2-second delay
  
  // Close all servos
  Serial.print("180\n");
  ring.write(180);
  // delay(250);
  thumb.write(180);
  index.write(180);
  midd.write(180);
  pinky.write(180);
  
  delay(1000); // 2-second delay
}
