const int ledPin1 = 2;   // 板载 LED
const int ledPin2 = 4;   // 外接 LED

unsigned long previousMillis = 0;
const long interval = 500;   // 500 ms 切换一次
bool ledState = true;        // true: GPIO2 亮；false: GPIO4 亮

void setup() {
  Serial.begin(115200);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // 初始状态
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState = !ledState;   // 翻转状态

    if (ledState) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      Serial.println("GPIO2 ON, GPIO4 OFF");
    } else {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      Serial.println("GPIO2 OFF, GPIO4 ON");
    }
  }
}