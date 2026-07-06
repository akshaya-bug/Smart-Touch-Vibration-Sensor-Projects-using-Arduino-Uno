#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define VIBRATION_PIN 2
#define ARM_TOUCH_PIN 3
#define RESET_TOUCH_PIN 4

#define LED_PIN 7
#define BUZZER_PIN 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool armed = false;
bool alarmActive = false;

bool lastArmTouch = LOW;
bool lastResetTouch = LOW;

unsigned long movementCount = 0;
unsigned long intrusionCount = 0;
unsigned long systemStartTime;

String securityLevel = "LOW";

void updateSecurityLevel()
{
  if (intrusionCount < 3)
    securityLevel = "LOW";
  else if (intrusionCount < 6)
    securityLevel = "MEDIUM";
  else
    securityLevel = "HIGH";
}

void updateDisplay()
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("SECURITY STATION");

  display.setCursor(0, 12);
  display.print("Status:");

  if (alarmActive)
    display.println("ALARM");
  else if (armed)
    display.println("ARMED");
  else
    display.println("SAFE");

  display.setCursor(0, 24);
  display.print("Moves:");
  display.println(movementCount);

  display.setCursor(0, 36);
  display.print("Alerts:");
  display.println(intrusionCount);

  display.setCursor(0, 48);
  display.print("Level:");
  display.println(securityLevel);

  display.display();
}

void showAlarmScreen()
{
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("WARNING");

  display.setTextSize(1);
  display.setCursor(0, 30);
  display.println("TAMPER DETECTED!");

  display.setCursor(0, 50);
  display.print("Alert #");
  display.print(intrusionCount);

  display.display();
}

void showResetScreen()
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20, 25);
  display.println("SYSTEM RESET");

  display.display();
  delay(1000);
}

void setup()
{
  pinMode(VIBRATION_PIN, INPUT);
  pinMode(ARM_TOUCH_PIN, INPUT);
  pinMode(RESET_TOUCH_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  systemStartTime = millis();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while (true);
  }

  updateDisplay();
}

void loop()
{
  bool armTouch = digitalRead(ARM_TOUCH_PIN);
  bool resetTouch = digitalRead(RESET_TOUCH_PIN);

  // ARM / DISARM
  if (armTouch == HIGH && lastArmTouch == LOW)
  {
    armed = !armed;

    if (!armed)
    {
      alarmActive = false;
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
    }

    updateDisplay();
    delay(250);
  }

  // VIBRATION DETECTION
  if (digitalRead(VIBRATION_PIN) == HIGH)
  {
    if (armed)
    {
      intrusionCount++;
      alarmActive = true;

      updateSecurityLevel();
    }
    else
    {
      movementCount++;
      updateDisplay();
    }

    delay(250);
  }

  // ALARM MODE
  if (alarmActive)
  {
    showAlarmScreen();

    tone(BUZZER_PIN, 1500);

    digitalWrite(LED_PIN, millis() / 200 % 2);
  }
  else
  {
    noTone(BUZZER_PIN);

    if (armed)
    {
      digitalWrite(LED_PIN, millis() / 800 % 2);
    }
    else
    {
      digitalWrite(LED_PIN, LOW);
    }
  }

  // SECRET RESET BUTTON
  if (resetTouch == HIGH && lastResetTouch == LOW)
  {
    alarmActive = false;

    movementCount = 0;
    intrusionCount = 0;

    updateSecurityLevel();

    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);

    showResetScreen();
    updateDisplay();

    delay(250);
  }

  lastArmTouch = armTouch;
  lastResetTouch = resetTouch;
}