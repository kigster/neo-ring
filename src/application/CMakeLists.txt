cmake_minimum_required(VERSION 3.2.2)

include_directories(${PROJECT_SOURCE_DIR}/src/libraries)

set(SOURCES
        EffectsController.cpp
        BrightnessController.cpp
        )

set(HEADERS
        EffectsController.h
        BrightnessController.h
        PixelEffect.h
        ValueWithinRange.h
        )

set(ARDUINO_COMPILE_FLAGS "${ARDUINO_COMPILE_FLAGS} -DNEOPIXEL_EFFECTS_ENABLED")

generate_arduino_library(application
        SRCS ${SOURCES}
        HDRS ${HEADERS}
        LIBS Adafruit_NeoPixel
        BOARD $ENV{BOARD_NAME}
        )
