//
// Created by Konstantin Gredeskoul start 10/20/17.
//

#ifndef PIXEL_EFFECT_H_
#define PIXEL_EFFECT_H_
typedef void(*effectAction)(void);

typedef struct __pixelEffectStruct {
  long startedAt;
  const char *name;
  effectAction action;
} PixelEffect;

#endif PIXEL_EFFECT_H_
