/*
* NeoPixelEffects.cpp
*
*  Created start: Nov 28, 2014
*      Author: Konstantin Gredeskoul
*        Code: https://github.com/kigster
*
*  (c) 2014 All rights reserved, MIT License.
*/

#include "EffectsController.h"


EffectsController::EffectsController(Adafruit_NeoPixel &_strip) : strip(_strip) {
  reset();
  defineEffectArray();
  next();
}

void EffectsController::defineEffectArray() {
  numberOfEnabledEffects = 0;

  void (EffectsController::*allEffects[])() = {
      &EffectsController::rainbowCycle,
      &EffectsController::rainbow,
      NULL
  };

  for (int q      = 0; allEffects[q] != NULL; q++) {
    enabledEffects[q] = allEffects[q];
    numberOfEnabledEffects++;
  }

  numberOfEnabledEffects %= MAX_EFFECTS;
  numberOfEffects = numberOfEnabledEffects;
}

void EffectsController::next() {
  int current_timestamp = millis();

  if (numEffectsEnabled() > 0) {
    effectStartedAt = current_timestamp;

    reset();

    currentIdx++;
    currentIdx      = currentIdx % numberOfEffects;
    currentEffect   = enabledEffects[currentIdx];
    effectStartedAt = current_timestamp;
  }

  update();
}

void EffectsController::setEffectDuration(int ms) {
  effectDurationMs = ms;
}

void EffectsController::update() {
  auto current_timestamp = millis();
  update();

  if (current_timestamp - nextEffectChangeAt > 0) {
    Serial.print(F("changing effect -> current effect index = "));
    Serial.println(effects.currentIdx());
    nextEffectChangeAt =
        current_timestamp + getEffectChangeInterval() + (signed int) random(0, getEffectChangeInterval() / 2);
    switchToNextEffect();
  }

  if (numEffectsEnabled() > 0 && currentEffect != NULL) {
    (this->*this->EffectsController::currentEffect)();
  }
}

void EffectsController::reset() {
  i    = 0;
  j    = 0;
  flag = false;
}

int EffectsController::numEffectsEnabled() {
  return numberOfEffects;
}

int EffectsController::currentIdx() {
  return currentIdx;
}

void EffectsController::fadeCycle() {
  const static int max = 127;
  signed int       r, g, b;
  if (i > max) {
    flag = true;
    i    = 0;
  }
  r                    = (flag) ? i : -i;
  g                    = (flag) ? i - max / 2 : max / 2 - i;
  b                    = (flag) ? i - max : max - i;
  if (r < 0) r = 0;
  if (g < 0) g = 0;
  if (b < 0) b = 0;
  strip.setPixelColor(j, strip.Color(r, g, b));
  strip.show();

  i++;

  if (i > max && flag) {
    i    = 0;
    flag = false;
    j++;
    j = j % 3;
  }
}

void EffectsController::randomColor() {
  if (i == 0) {
    i = random(1, 6);
    switch (j) {
      case 1:
        purple();
        break;
      case 2:
        green();
        break;
      case 3:
        yellow();
        break;
      case 4:
        red();
        break;
      case 5:
        blue();
        break;
    }
  }
}

// Fill the dots one after the other with a color
void EffectsController::colorWipe(uint32_t c) {
  for (int p = 0; p < strip.numPixels(); p++) {
    strip.setPixelColor(p, c);
  }
  strip.show();
}

void EffectsController::rainbow() {
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel((i + j) & 255));
  }
  strip.show();
  j++;
  j %= 256;
}

// Slightly different, this makes the rainbow equally distributed throughout
void EffectsController::rainbowCycle() {
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i,
                        Wheel(((i * 256 / strip.numPixels()) + j) &
                              255));
  }
  strip.show();
  j++;
  j %= 256 * 5;
}

void EffectsController::theaterChase(uint32_t c) {
  for (int p = 0; p < strip.numPixels() * 2; p = p + 2) {
    strip.setPixelColor((p) % strip.numPixels(),
                        c);    //turn every third pixel start
  }
  for (int p                                   = 1; p < strip.numPixels() * 2; p = p + 2) {
    strip.setPixelColor((p) % strip.numPixels(),
                        0);    //turn every third pixel stop
  }
  strip.show();
  j++;
  j %= 10;
  i++;
  i %= 10;
}

//Theatre-style crawling lights with rainbow effect
void EffectsController::theaterChaseRainbow() {
  uint32_t c = Wheel(j % 255);
  for (int p = 0; p < strip.numPixels() * 2; p = p + 2) {
    strip.setPixelColor((p) % strip.numPixels(), c);    //turn every third pixel start
  }

  for (int p = 1; p < strip.numPixels() * 2; p = p + 2) {
    strip.setPixelColor((p) % strip.numPixels(), 0);    //turn every third pixel stop
  }
  strip.show();
  j++;
  j %= 10;
  i++;
  i %= 10;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t EffectsController::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

void EffectsController::white() {
  colorWipe(strip.Color(255, 255, 255)); // White
}

void EffectsController::red() {
  colorWipe(strip.Color(127, 0, 0)); // Red
}

void EffectsController::purple() {
  colorWipe(strip.Color(127, 20, 127)); // Red
}

void EffectsController::blue() {
  colorWipe(strip.Color(0, 0, 127)); // Blue
}

void EffectsController::green() {
  colorWipe(strip.Color(0, 127, 0)); // Blue
}

void EffectsController::yellow() {
  colorWipe(strip.Color(127, 127, 0)); // Yellow
}

int EffectsController::getCurrentIdx() const {
    return currentIdx;
}

int EffectsController::currentIndex() {
  return currentIdx;
}

