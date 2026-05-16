// Lab02_SOS_millis.ino
const int ledPin = 2;   // ESP32 板载 LED (GPIO2)

// 时间参数（单位：ms）
const int dotTime  = 200;
const int dashTime = 600;
const int gapTime  = 200;
const int letterGap = 500;
const int wordGap   = 2000;

// 状态机变量
unsigned long previousMillis = 0;
int state = 0;          // 当前执行到哪一步
int stepCount = 0;      // 计数：3 次短 / 3 次长

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (state) {

    // ===== S: 三短 =====
    case 0: // 短闪 ON
      if (currentMillis - previousMillis >= gapTime) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, HIGH);
        state = 1;
      }
      break;

    case 1: // 短闪 OFF
      if (currentMillis - previousMillis >= dotTime) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, LOW);
        stepCount++;
        state = (stepCount < 3) ? 0 : 2;
      }
      break;

    case 2: // S → O 间隔
      if (currentMillis - previousMillis >= letterGap) {
        previousMillis = currentMillis;
        stepCount = 0;
        state = 3;
      }
      break;

    // ===== O: 三长 =====
    case 3: // 长闪 ON
      if (currentMillis - previousMillis >= gapTime) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, HIGH);
        state = 4;
      }
      break;

    case 4: // 长闪 OFF
      if (currentMillis - previousMillis >= dashTime) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, LOW);
        stepCount++;
        state = (stepCount < 3) ? 3 : 5;
      }
      break;

    case 5: // O → S 间隔
      if (currentMillis - previousMillis >= letterGap) {
        previousMillis = currentMillis;
        stepCount = 0;
        state = 6;
      }
      break;

    // ===== S: 三短 =====
    case 6: // 短闪 ON
      if (currentMillis - previousMillis >= gapTime) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, HIGH);
        state = 7;
      }
      break;

    case 7: // 短闪 OFF
      if (currentMillis - previousMillis >= dotTime) {
        previousMillis = currentMillis;
        digitalWrite(ledPin, LOW);
        stepCount++;
        state = (stepCount < 3) ? 6 : 8;
      }
      break;

    case 8: // 单词间隔
      if (currentMillis - previousMillis >= wordGap) {
        previousMillis = currentMillis;
        stepCount = 0;
        state = 0;
      }
      break;
  }
}
