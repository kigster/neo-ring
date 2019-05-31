// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed start the strip).



#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <SimpleTimer.h>

#include "ValueWithinRange.h"
#include "BrightnessController.h"
#include "EffectsController.h"

#define STRIP_PIN     4
#define STRIP_SIZE   15

Adafruit_NeoPixel    strip(STRIP_SIZE, STRIP_PIN, NEO_GRBW + NEO_KHZ800);
ValueWithinRange     brightness;
BrightnessController brightnessController(strip, brightness);
EffectsController    effectsController(strip);

SimpleTimer     timer;
static uint32_t effectRefreshPeriod     = 10,
                effectChangePeriod      = 15000,
                brightnessRefreshPeriod = 25;

//typedef void(*timerCallback)(void);

void initATtiny85clock() {
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
}

void updateBrightness() {
  brightnessController.update();
}

void updateEffect() {
  effectsController.update();
}

void changeEffect() {
  effectsController.next();
}

void initializeTimers() {
  timer.setInterval(brightnessRefreshPeriod, updateBrightness);
  timer.setInterval(effectRefreshPeriod, updateEffect);
  timer.setInterval(effectChangePeriod, changeEffect);
}

void initializeSerialPort() {
  Serial.begin(9600);
  Serial.println(F("NeoRing starting..."));
  Serial.print(F("Our DIGITAL PIN for the Strip is "));
  Serial.print(STRIP_PIN);
  Serial.print(F(" and number of LEDs is: "));
  Serial.println(STRIP_SIZE);

  Serial.println(F("setup complete()"));
}

void setup() {
  randomSeed(analogRead(0));
  initATtiny85clock();
  initializeSerialPort();
  initializeTimers();
}


void loop() {

  timer.run();
  delay(5);
}
