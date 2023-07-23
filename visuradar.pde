import processing.serial.*;

Serial myPort;
int distance = 0;
int angle = 0;

void setup() {
  size(800, 800);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(0);
  drawRadarBackground();
  drawObstacle();
}

void drawRadarBackground() {
  stroke(255);
  noFill();
  for (int r = 50; r <= 300; r += 50) {
    arc(width/2, height, r*2, r*2, PI, TWO_PI);
  }
}

void drawObstacle() {
  float r = distance;
  float theta = radians(angle);
  float x = width/2 + r * cos(theta);
  float y = height - r * sin(theta);
  fill(255, 0, 0);
  noStroke();
  ellipse(x, y, 10, 10);
}

void serialEvent(Serial myPort) {
  String data = myPort.readStringUntil('\n');
  if (data != null) {
    data = trim(data);
    String[] parts = split(data, ',');
    if (parts.length == 2) {
      angle = int(parts[0]);
      distance = int(parts[1]);
    }
  }
}
