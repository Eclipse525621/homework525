const int ledPin = 2;  // 板载LED，GPIO2

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // S: 三短
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);          // 短亮
    digitalWrite(ledPin, LOW);
    delay(200);          // 短灭
  }
  delay(500);            // 字母间隔（S 和 O 之间）

  // O: 三长
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(600);          // 长亮
    digitalWrite(ledPin, LOW);
    delay(200);          // 短灭
  }
  delay(500);            // 字母间隔（O 和 S 之间）

  // S: 三短
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  delay(2000);           // 单词间隔，循环重新开始
}