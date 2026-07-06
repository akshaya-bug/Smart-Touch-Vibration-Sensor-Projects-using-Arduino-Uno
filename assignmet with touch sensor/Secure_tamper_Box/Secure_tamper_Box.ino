#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TOUCH1 2
#define TOUCH2 3

#define LED1 7
#define LED2 6

#define BUZZER 8

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool led1State = false;
bool led2State = false;

bool lastTouch1 = LOW;
bool lastTouch2 = LOW;

void updateDisplay() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(20, 0);
  display.println("Touch Panel");

  display.setCursor(0, 20);
  display.print("LED1 : ");
  display.println(led1State ? "ON" : "OFF");

  display.setCursor(0, 40);
  display.print("LED2 : ");
  display.println(led2State ? "ON" : "OFF");

  display.display();
}

void beepSensor1() {
  tone(BUZZER, 1000);   // Tone for Sensor 1
  delay(100);
  noTone(BUZZER);
}

void beepSensor2() {
  tone(BUZZER, 2000);   // Tone for Sensor 2
  delay(100);
  noTone(BUZZER);
}

void setup() {
  pinMode(TOUCH1, INPUT);
  pinMode(TOUCH2, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  updateDisplay();
}

void loop() {

  bool touch1 = digitalRead(TOUCH1);
  bool touch2 = digitalRead(TOUCH2);

  // Sensor 1
  if (touch1 == HIGH && lastTouch1 == LOW) {
    led1State = !led1State;
    digitalWrite(LED1, led1State);

    beepSensor1();

    updateDisplay();
    delay(200);
  }

  // Sensor 2
  if (touch2 == HIGH && lastTouch2 == LOW) {
    led2State = !led2State;
    digitalWrite(LED2, led2State);

    beepSensor2();

    updateDisplay();
    delay(200);
  }

  lastTouch1 = touch1;
  lastTouch2 = touch2;
}