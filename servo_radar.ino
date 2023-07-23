#include <Servo.h>
#include "GL042MT.h"

#define RX_PIN 12
#define TX_PIN 11

GL042MT sensor(RX_PIN, TX_PIN);
Servo myservo;

int pos = 0;
int it = 10;

void setup() {
  myservo.attach(9);
  sensor.begin();
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  int i = 0;
  int t = 0;
  int a = 0;

  for (i = 0; i < 180; i++) {
    myservo.write(i);
    delay(20);
    for (t = 0; t < it; t++) {
      int distance = sensor.readDistance();
      if (distance >= 0) {
        a = distance + a;
      }
      delay(30);
    }

    a = a / (it-1);
    t = 0;

    Serial.print(i);
    Serial.print(",");
    Serial.println(a);
    a = 0;
  }
}
