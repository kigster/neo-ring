
#include "NeoTransitions.h"

#define BRIGHTNESS 50

static const uint8_t
          brightnessMin = 0,
          brightnessMax = 255,
          brightnessChangeEveryMS = 6,
          defaultBrightnessIncrement = 1;

static uint8_t
          brightnessIncrement = defaultBrightnessIncrement,
          brightness = brightnessMin + (brightnessMax - brightnessMin) / 2;

static uint32_t brightnessChangedAt = 0;

static const int refreshDelay = 10; // ms
static const int effectChangeRate = 30000; // ms

uint32_t lastRefreshAt = 0,
lastEffectChangeAt = 0;

void changeBrightness(NeoPixelManager &manager, uint32_t now) {
  if (now - brightnessChangeEveryMS - random(0, 6) > brightnessChangedAt) {
    brightnessChangedAt = now;
    brightness += brightnessIncrement;
    if (brightness >= brightnessMax) {
      brightnessIncrement = -defaultBrightnessIncrement;
      brightness = brightnessMax;
    } else if (brightness <= brightnessMin) {
      brightnessIncrement = defaultBrightnessIncrement;
      brightness = brightnessMin;
    }
    manager.strip()->setBrightness(brightness);
  }
}

void changeEffect(NeoPixelManager &manager, uint32_t now) {
  if (lastEffectChangeAt == 0) {
    lastEffectChangeAt = now;
  }

  int rateDelta = random(effectChangeRate/2, effectChangeRate);

  if (now - lastEffectChangeAt > rateDelta) {
    lastEffectChangeAt = now;
    manager.nextEffect();
    Serial.print(F("changing effect -> current effect index = "));
    Serial.println(manager.effects()->currentEffectIndex());
  }
}

void refreshEffect(NeoPixelManager &manager, uint32_t now) {
  if (now - lastRefreshAt > refreshDelay) {
    manager.refreshEffect();
    lastRefreshAt = now;
  }
}
