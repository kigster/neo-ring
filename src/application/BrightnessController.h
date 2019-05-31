//
// Created by Konstantin Gredeskoul on 1/14/18.
//

#ifndef BRIGHTNESS_CONTROLLER_H_
#define BRIGHTNESS_CONTROLLER_H_

#include <Adafruit_NeoPixel.h>
#include "ValueWithinRange.h"

class BrightnessController {
public:
    BrightnessController(Adafruit_NeoPixel &strip, ValueWithinRange &brightness);

    virtual ~BrightnessController();

    void update();

    void apply();

private:
    Adafruit_NeoPixel strip;

    ValueWithinRange brightness;
};

#endif //BRIGHTNESS_CONTROLLER_H_
