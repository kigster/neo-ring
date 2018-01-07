// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed on the strip).

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "application/Configuration.h"
#include "NeoTransitions.h"

#define PIN      4
#define N_LEDS   12

NeoPixelManager neoPixelManager(N_LEDS, PIN);

void setup() {
  randomSeed(analogRead(0));
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  Serial.begin(9600);
  neoPixelManager.begin();
  neoPixelManager.effects()->setFlashWhenEffectsChange(true);

}

void loop() {
  uint32_t now = millis();
  changeBrightness(neoPixelManager, now);
  changeEffect(neoPixelManager, now);
  refreshEffect(neoPixelManager, now);
  delay(3);
}
