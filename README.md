# Blink-Two-LEDs-by-blynk-led


A simple Arduino project that blinks two LEDs independently at different rates using non-blocking timing with `millis()`. This is a good starting point for understanding how to handle multiple tasks simultaneously without using `delay()`.

## What it does

LED 1 toggles every 500ms and LED 2 toggles every 800ms. Because they run on different intervals, they go in and out of sync over time, which makes the pattern look more interesting than two LEDs blinking together.

The sketch uses `millis()` instead of `delay()`, which means the microcontroller is never sitting idle. This is the correct approach once you start adding more sensors or logic to your project.

## Hardware required

- Arduino Uno, Nano, Mega, or compatible board
- 2x LEDs (any color)
- 2x 220-ohm resistors
- Breadboard and jumper wires

## Wiring

```
Arduino Pin 8  --[220 ohm]--  LED 1 Anode (+)
                              LED 1 Cathode (-) -- GND

Arduino Pin 9  --[220 ohm]--  LED 2 Anode (+)
                              LED 2 Cathode (-) -- GND
```

The longer leg of the LED is the anode (+) and goes toward the resistor. The shorter leg is the cathode (-) and goes to GND.

```
Arduino                 Breadboard
-------                 ----------
Pin 8  ----[220R]------  LED1 (+)
                              |
                         LED1 (-)
                              |
GND    -------------------  GND rail


Pin 9  ----[220R]------  LED2 (+)
                              |
                         LED2 (-)
                              |
GND    -------------------  GND rail
```

## Software setup

1. Open the Arduino IDE (version 1.8 or later).
2. Go to File > Open and select `src/blink_two_leds.ino`.
3. Select your board under Tools > Board.
4. Select the correct port under Tools > Port.
5. Click Upload.

Open the Serial Monitor at 9600 baud after uploading to see startup messages confirming the pin assignments and intervals.

## Configuration

To change the blink speed, edit these two lines near the top of the sketch:

```cpp
const unsigned long LED1_INTERVAL = 500;  // milliseconds
const unsigned long LED2_INTERVAL = 800;  // milliseconds
```

To use different pins, change these:

```cpp
const int LED1_PIN = 8;
const int LED2_PIN = 9;
```

## How millis() timing works

The standard approach using `delay()` looks like this:

```cpp
digitalWrite(LED_PIN, HIGH);
delay(500);
digitalWrite(LED_PIN, LOW);
delay(500);
```

The problem is that `delay()` blocks the entire program. Nothing else can run during that wait. If you add a second LED with a different interval, you cannot do both at the same time with `delay()`.

The `millis()` approach works differently. Instead of waiting, the program checks how much time has passed since the last toggle:

```cpp
unsigned long now = millis();

if (now - lastToggle >= interval) {
  lastToggle = now;
  state = !state;
  digitalWrite(LED_PIN, state);
}
```

This runs in microseconds and immediately moves on to the next task. Two or more LEDs can each have their own interval and timing variable, and they run completely independently.

## Board compatibility

This sketch works without modification on the following boards:

- Arduino Uno
- Arduino Nano
- Arduino Mega
- ESP8266 (NodeMCU, Wemos D1 Mini) - use GPIO numbers, check pin availability
- ESP32 - works the same way

For ESP8266 and ESP32, avoid pins that are used at boot or tied to special functions. Pins 8 and 9 are safe on Uno and Nano. On ESP32, GPIO 2 and GPIO 4 are reliable general-purpose choices.

## File structure

```
blink_two_leds/
├── README.md
├── src/
│   └── blink_two_leds.ino
└── docs/
    └── wiring_notes.md
```

## License

MIT License. Free to use, modify, and distribute.
