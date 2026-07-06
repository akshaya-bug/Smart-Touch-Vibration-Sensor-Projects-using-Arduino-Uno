#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define VIBRATION_PIN 2
#define TOUCH_PIN 3
#define BUZZER_PIN 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int knockCount = 0;
bool alarmActive = false;

unsigned long firstKnockTime = 0;

void updateDisplay() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Knock Detector");

  display.setCursor(0, 20);
  display.print("Knocks: ");
  display.println(knockCount);

  display.setCursor(0, 40);

  if (alarmActive)
    display.println("ALARM ACTIVE!");
  else
    display.println("Monitoring...");

  display.display();
}

void showResetCountdown() {

  for (int i = 3; i > 0; i--) {

    display.clearDisplay();

    display.setCursor(10, 20);
    display.setTextSize(2);
    display.print("Reset ");
    display.println(i);

    display.display();

    delay(1000);
  }
}

void setup() {

  pinMode(VIBRATION_PIN, INPUT);
  pinMode(TOUCH_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  updateDisplay();
}

void loop() {

  if (!alarmActive) {

    if (digitalRead(VIBRATION_PIN) == HIGH) {

      if (knockCount == 0) {
        firstKnockTime = millis();
      }

      knockCount++;

      updateDisplay();

      delay(300);

      // Check for 5 knocks within 10 seconds
      if (knockCount >= 5 &&
          (millis() - firstKnockTime <= 10000)) {

        alarmActive = true;
      }
    }

    // Reset count if 10 seconds elapsed
    if (knockCount > 0 &&
        (millis() - firstKnockTime > 10000)) {

      knockCount = 0;
      updateDisplay();
    }
  }

  else {

    // Continuous alarm
    tone(BUZZER_PIN, 1500);

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 20);
    display.println("ALARM!");
    display.display();

    // Touch sensor resets alarm
    if (digitalRead(TOUCH_PIN) == HIGH) {

      noTone(BUZZER_PIN);

      showResetCountdown();

      alarmActive = false;
      knockCount = 0;
      firstKnockTime = 0;

      updateDisplay();

      delay(500);
    }
  }
}