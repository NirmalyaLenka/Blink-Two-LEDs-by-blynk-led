/*
  Blink Two LEDs
  --------------
  Blinks two LEDs alternately using millis() for non-blocking timing.
  LED 1 blinks every 500ms, LED 2 blinks every 800ms independently.

  Hardware:
    - LED 1 connected to pin 8 via 220-ohm resistor to GND
    - LED 2 connected to pin 9 via 220-ohm resistor to GND

  Board: Arduino Uno (also works on Nano, Mega, ESP32, ESP8266)
  Author: NirmalyaLenka
*/

// Pin definitions
const int LED1_PIN = 8;
const int LED2_PIN = 9;

// Blink intervals in milliseconds
const unsigned long LED1_INTERVAL = 500;
const unsigned long LED2_INTERVAL = 800;

// State tracking
bool led1State = LOW;
bool led2State = LOW;

unsigned long led1LastToggle = 0;
unsigned long led2LastToggle = 0;

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Blink Two LEDs started.");
  Serial.print("LED 1 on pin ");
  Serial.print(LED1_PIN);
  Serial.println(" - 500ms interval");
  Serial.print("LED 2 on pin ");
  Serial.print(LED2_PIN);
  Serial.println(" - 800ms interval");
}

void loop() {
  unsigned long now = millis();

  // Handle LED 1
  if (now - led1LastToggle >= LED1_INTERVAL) {
    led1LastToggle = now;
    led1State = !led1State;
    digitalWrite(LED1_PIN, led1State);
  }

  // Handle LED 2
  if (now - led2LastToggle >= LED2_INTERVAL) {
    led2LastToggle = now;
    led2State = !led2State;
    digitalWrite(LED2_PIN, led2State);
  }
}
