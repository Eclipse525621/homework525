const int redPin   = 4;
const int greenPin = 16;
const int bluePin  = 18;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  analogWriteResolution(redPin, 8);
  analogWriteResolution(greenPin, 8);
  analogWriteResolution(bluePin, 8);
}

void loop() {
  static float angle = 0;

  int r = 127.5 + 127.5 * sin(angle);
  int g = 127.5 + 127.5 * sin(angle + TWO_PI / 3);
  int b = 127.5 + 127.5 * sin(angle + TWO_PI * 2 / 3);

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

  angle += 0.02;          // 控制渐变速度
  if (angle > TWO_PI) angle = 0;

  delay(20);
}