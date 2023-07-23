#include "GL042MT.h"

GL042MT sensor(10, 11);  // RX, TX

void setup() {
  Serial.begin(115200);
  sensor.begin();
}

void loop() {
  int distance = sensor.readDistance();
  if (distance >= 0) {
    Serial.println("Distance: " + String(distance) + " mm");
  } else if (distance == -1) {
    Serial.println("Checksum error");
  } else if (distance == -2) {
    Serial.println("Not enough data");
  }
  delay(14);
}
