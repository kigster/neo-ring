//
// Created by Konstantin Gredeskoul on 1/14/18.
//

#include "BrightnessController.h"
#include "Arduino.h"

BrightnessController::BrightnessController(
        Adafruit_NeoPixel &_strip,
        ValueWithinRange &_brightness) :
        strip(_strip),
        brightness(_brightness) {

    brightness.increment = 1;
    brightness.minValue = 0;
    brightness.maxValue = 255;
    brightness.interval = 15;
    brightness.value = (brightness.maxValue - brightness.minValue) / 2;
}

void BrightnessController::update() {
    int current_timestamp = millis();

    if (current_timestamp - brightness.nextUpdateAt > 0) {
        brightness.lastUpdatedAt = current_timestamp;
        brightness.nextUpdateAt = current_timestamp + brightness.interval;

        brightness.value = constrain(
                brightness.value + brightness.interval,
                brightness.minValue, brightness.maxValue);

        if (brightness.value >= brightness.maxValue - 1) {
            brightness.increment = -abs(brightness.increment);
        } else if (brightness.value == brightness.minValue) {
            brightness.increment = abs(brightness.increment);
        }

        apply();
    }
}

void BrightnessController::apply() {
    strip.setBrightness(brightness.value);
    strip.show();
}

BrightnessController::~BrightnessController() = default;
