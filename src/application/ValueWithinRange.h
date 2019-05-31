
#ifndef VALUE_WITHIN_RANGE_H_
#define VALUE_WITHIN_RANGE_H_

typedef struct valueWithinRangeStruct {
  int value;
  int minValue;
  int maxValue;
  int interval;
  int increment;
  long lastUpdatedAt;
  long nextUpdateAt;
} ValueWithinRange;


#endif VALUE_WITHIN_RANGE_H_
