#ifndef NEO_TRANSITIONS_H
#define NEO_TRANSITIONS_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#include "application/Configuration.h"
#include "application/NeoPixelManager.h"

void changeBrightness(NeoPixelManager &neoPixelManager, uint32_t now);
void changeEffect(NeoPixelManager &neoPixelManager, uint32_t now);
void refreshEffect(NeoPixelManager &neoPixelManager, uint32_t now);

#endif
