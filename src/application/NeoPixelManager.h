/*
 * NeoPixelManager.h
 *
 *  Created on: Nov 28, 2014
 *      Author: Konstantin Gredeskoul
 *        Code: https://github.com/kigster
 *
 *  (c) 2014 All rights reserved, MIT License.
 */
#include "Configuration.h"

#ifdef NEOPIXEL_EFFECTS_ENABLED

#ifndef NEOPIXELMANAGER_H_
#define NEOPIXELMANAGER_H_

#include "Configuration.h"

#include <Adafruit_NeoPixel.h>
#include "NeoPixelEffects.h"
//typedef void (*effectCallback)(void);

#define MAX_EFFECTS 20

class NeoPixelManager {
public:
    NeoPixelManager(uint8_t pixels, uint8_t pin);
    ~NeoPixelManager();

    void
        begin(),
        shutoff(),
        nextEffect(),
        refreshEffect(),
        setRefreshRate(int value);

    bool playing();

    uint32_t color(uint8_t r, uint8_t g, uint8_t b);
    NeoPixelEffects *effects();
    Adafruit_NeoPixel *strip();

private:
    bool _playing;
    NeoPixelEffects _effects;
    Adafruit_NeoPixel *_strip;
};

inline NeoPixelManager::~NeoPixelManager() {};

#endif /* NEOPIXELMANAGER_H_ */
#endif
