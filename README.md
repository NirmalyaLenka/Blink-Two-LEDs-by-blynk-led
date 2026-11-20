# Blink Two LEDs with Independent Timing

A small Arduino/C++ example that toggles two LEDs on independent intervals using `millis()`, without blocking the main loop with `delay()`.

**Important naming note:** despite the repository name, the checked-in sketch does not include Blynk libraries, Wi-Fi setup, a Blynk template, or a cloud/app integration. It is a local GPIO timing example.

## Features

- LED 1 toggles every 500 ms.
- LED 2 toggles every 800 ms.
- Uses separate state and timestamp variables for each LED.
- Prints the configured pins and intervals to Serial Monitor at 9600 baud.

The intervals are the time between state changes, not a complete on/off cycle duration.

## Hardware

- Arduino Uno, classic Nano, or another board with a compatible Arduino core
- Two LEDs
- Two current-limiting resistors (220 Ω is the documented example)
- Breadboard and jumper wires

## Wiring

The sketch's current pin definitions are:

| Signal | Sketch pin | Connection |
|---|---:|---|
| LED 1 | D8 | GPIO → 220 Ω resistor → LED anode; cathode → GND |
| LED 2 | D9 | GPIO → 220 Ω resistor → LED anode; cathode → GND |
| Ground | GND | Common ground for both LEDs |

Use one resistor per LED. Power the board off before changing the circuit, and never connect an LED directly to a GPIO without current limiting.

**Board compatibility:** this wiring and pin map is intended for boards such as the Arduino Uno/Nano/Mega where digital pins 8 and 9 are available. Do not assume the same numeric pins are safe on ESP32 or ESP8266 boards; GPIO numbering and reserved pins differ, and GPIO 8/9 are connected to flash on many ESP32 variants. Change the sketch's pin definitions only after checking the exact board pinout.

## Setup and upload

1. Install the Arduino IDE and the board support package for your board, if it is not already available.
2. Open `blink_two_leds.ino` from the repository root. The README's earlier `src/` path does not exist in the current tree.
3. Select the correct board and serial port.
4. Upload the sketch.
5. Open Serial Monitor at **9600 baud** to view the startup messages.

No third-party Arduino library is included by the sketch.

## Configuration

The current sketch defines the LED pins and toggle intervals near the top:

```cpp
const int LED1_PIN = 8;
const int LED2_PIN = 9;

const unsigned long LED1_INTERVAL = 500;
const unsigned long LED2_INTERVAL = 800;
```

Intervals are measured in milliseconds. The loop compares the elapsed time against each interval using unsigned subtraction, so the timing checks continue without blocking waits.

## Repository contents

| Path | Purpose |
|---|---|
| `blink_two_leds.ino` | Main Arduino sketch |
| `wiring_notes.md` | LED polarity, resistor, and wiring notes |
| `LICENSE (6)` | Checked-in MIT license text; the filename is non-standard |
| `gitignore (8)` | Ignore-pattern text, but the filename is not the conventional `.gitignore` name |
| `README.md` | Project guide |

The files named `LICENSE (6)` and `gitignore (8)` have not been renamed. Git will not treat `gitignore (8)` as the repository's root `.gitignore` file.

## Troubleshooting

- **LED stays off:** check polarity, resistor placement, ground, and the selected board pin.
- **Only one LED blinks:** test each LED and connection separately, then recheck D8 and D9.
- **Wrong timing:** confirm the intervals are in milliseconds and that the intended sketch was uploaded.
- **ESP32/ESP8266 board:** review and adapt the pin mapping for the exact board instead of assuming Uno pin numbering.

## Verification status

The README and wiring notes were compared with the checked-in sketch and root file list. No Arduino compilation, upload, or physical LED test was performed.

## Maintenance & Audit

- **Audit date:** 11 November 2026
- **Documentation status:** README updated to match the root-level sketch, actual timing behavior, and board-specific pin limitations.
- **Verification boundary:** Documentation only; no build or hardware result is claimed.
