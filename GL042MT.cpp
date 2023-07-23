#include "Arduino.h"
#include "GL042MT.h"
#include "SoftwareSerial.h"

SoftwareSerial mySerial(_rxPin, _txPin);

GL042MT::GL042MT(int rxPin, int txPin) {
  _rxPin = rxPin;
  _txPin = txPin;
}

void GL042MT::begin() {
  mySerial.begin(115200);
}

int GL042MT::readDistance() {
  if (mySerial.available() >= 4) {
    byte frameHeader = mySerial.read();
    byte dataH = mySerial.read();
    byte dataL = mySerial.read();
    byte checksum = mySerial.read();

    if ((frameHeader + dataH + dataL) & 0xFF == checksum) {
      return dataH * 256 + dataL;
    } else {
      return -1;  // return -1 in case of checksum error
    }
  } else {
    return -2;  // return -2 if not enough data is available
  }
}
