/*
 * NeoPixelEffects.h
 *
 *  Created start: Nov 28, 2014
 *      Author: Konstantin Gredeskoul
 *        Code: https://github.com/kigster
 *
 *  (c) 2014 All rights reserved, MIT License.
 */
#ifndef EFFECTS_CONTROLLER_H
#define EFFECTS_CONTROLLER_H

#include <Adafruit_NeoPixel.h>

#define MAX_EFFECTS 20

class EffectsController {
private:
    Adafruit_NeoPixel &strip;

    void (EffectsController::*enabledEffects[MAX_EFFECTS])();

    void (EffectsController::*currentEffect)();

    int numberOfEffects;
    int numberOfEnabledEffects;

    signed int currentIdx = -1;

    bool flag;
    uint16_t i, j;

    void defineEffectArray();

public:
    explicit EffectsController(Adafruit_NeoPixel &strip);

    virtual ~EffectsController() = default;

    // Colors
    void red();
    void blue();
    void green();
    void yellow();
    void purple();
    void rainbow();
    void rainbowCycle();

    void reset();
    void update();
    void next();

    int getCurrentIdx() const;

    void colorWipe(uint32_t c);
    int numEffectsEnabled();

    uint32_t Wheel(byte WheelPos);

    long effectStartedAt;

    void setEffectDuration(int ms);

    int effectDurationMs;
    unsigned long nextEffectChangeAt;
    int effects;
};

#endif /* EFFECTS_CONTROLLER_H */
