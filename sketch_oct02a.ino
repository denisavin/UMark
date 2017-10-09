/*  $   $  %   $   $$   $$$   $  $
 *  $   $  $$ $$  $  $  $  $  $ $
 *  $   $  $ $ $  $$$$  $$$   $$
 *   $$$   $   $  $  $  $  $  $  $
 */
#include "Ultrasonic.h"

int ledPin = 5;
int buzzerPin = 3;
int tempo = 150;
int distance = 30; // distance for save eyes
unsigned int dist_cm;

// sensor connected to:
// Trig - 7, Echo - 9
Ultrasonic ultrasonic(7 ,9);

void setup() {
  Serial.begin(9600);         // start the serial port
  pinMode(ledPin, OUTPUT);
  pinMode(12, OUTPUT);
  for(int i = 0; i<2; i++) {     // Loading Ubookmark
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 500, 30);
    delay(30);
    digitalWrite(ledPin, LOW);
    delay(35);
  }
}

void loop() {
  dist_cm = ultrasonic.Ranging(CM);
  if(dist_cm == 206)
    dist_cm = ultrasonic.Ranging(CM);
  
  Serial.println(dist_cm); // get distance
  
  if (dist_cm <= distance){
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 262, tempo);
    delay(100);
    digitalWrite(ledPin, LOW);
    tone(buzzerPin, 262, tempo);
    delay(100);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  
  delay(150);           // arbitary wait time.
}
