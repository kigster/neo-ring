#ifndef NEO_HELPERS_H
#define NEO_HELPERS_H

extern Adafruit_NeoPixel strip;

void colorWipe(uint32_t c, uint8_t wait);
void pulseWhite(uint8_t wait);
void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops);
void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength );
void fullWhite();
void rainbowCycle(uint8_t wait);
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);
uint8_t red(uint32_t c);
uint8_t green(uint32_t c);
uint8_t blue(uint32_t c);

#endif
