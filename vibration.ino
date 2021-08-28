#include <Arduino.h>

#define ON 1
#define OFF 0

int vibration_Sensor = 2, buzz = A4, present_condition = 0, previous_condition = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(vibration_Sensor, INPUT);
}

void soundSiren(void);

void loop() {
  previous_condition = present_condition;
  present_condition = digitalRead(vibration_Sensor);
  if (previous_condition != present_condition) {
    soundSiren();
  }
  else {
    digitalWrite(buzz, OFF);
  }
}

void soundSiren() {
  for (int i = 3; i <= 11; i += 2)
    digitalWrite(i, HIGH);

  for (int hz = 440; hz < 1000; hz++) {
    tone(buzz, hz, 50);
    delay(5);
  }

  for (int i = 3; i <= 11; i += 2)
    digitalWrite(i, LOW);

  for (int i = 4; i <= 12; i += 2)
    digitalWrite(i, HIGH);
  for (int hz = 1000; hz > 440; hz--) {
    tone(buzz, hz, 50);
    delay(5);
  }

  for (int i = 0; i <= 2; i++) {
    digitalWrite(buzz, HIGH);
    tone(buzz, 800, 50);
  }

  tone(buzz, 1000, 250);
  delay(500);
  tone(buzz, 1000, 250);
  delay(500);
  tone(buzz, 1000, 250);
  delay(500);
  tone(buzz, 1000, 250);
  delay(500);
  tone(buzz, 1000, 250);
  delay(500);
  tone(buzz, 1000, 250);
}
