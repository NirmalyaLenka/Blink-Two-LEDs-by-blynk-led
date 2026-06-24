# Wiring Notes

This document covers a few things worth knowing before you connect anything.

## Resistor value

A 220-ohm resistor works fine with a standard 5V Arduino and most common LEDs. If you only have 330-ohm or 470-ohm resistors, those work too. The LED will be slightly dimmer but it will not burn out. Do not skip the resistor. Connecting an LED directly between a pin and GND with no resistor will damage the LED and may damage the pin over time.

## LED polarity

LEDs only work in one direction. If yours does not light up, flip it. The longer leg is positive and goes toward the resistor side. The shorter leg is negative and goes to GND. On a breadboard, the flat edge on the base of the LED also indicates the negative leg.

## Pin 8 and Pin 9 on Uno and Nano

These are standard digital I/O pins with no special function at startup. They are safe to use for LEDs on any sketch. Avoid pins 0 and 1 because those are used by the serial port when uploading or printing to Serial Monitor.

## Testing one LED at a time

If something does not work, test each LED separately first. Set one interval very slow, like 2000ms, so you can clearly see if it is toggling. Then add the second one once the first is confirmed working.

## Power considerations

Each LED draws roughly 10 to 20mA at 5V with a 220-ohm resistor. Two LEDs together draw about 30 to 40mA total. The Arduino Uno can supply up to 200mA from its 5V pin, so two LEDs is well within range. This only matters if you plan to add many more LEDs later, in which case you would need external power.
