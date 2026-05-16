const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  analogWriteResolution(ledPin, 8);  // 0~255
}

void loop() {
  static float angle = 0;

  int brightness = 127.5 + 127.5 * sin(angle);
  analogWrite(ledPin, brightness);

  angle += 0.05;
  if (angle > TWO_PI) angle -= TWO_PI;

  delay(20);
}