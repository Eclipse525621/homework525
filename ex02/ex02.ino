const int ledPin = 2;          // ESP32 板载 LED（GPIO2）
unsigned long previousMillis = 0;
const long interval = 500;     // 500 ms 翻转一次（1 Hz）
bool ledState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  unsigned long currentMillis = millis();

  // 判断是否到达翻转时间
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // 翻转 LED 状态
    ledState = !ledState;
    digitalWrite(ledPin, ledState);

    // 串口调试输出
    Serial.print("LED is ");
    Serial.println(ledState ? "ON" : "OFF");
  }

  // 这里可以放其他非阻塞任务
}