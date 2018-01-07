cmake_minimum_required(VERSION 3.2.2)

set(SOURCES
        NeoPixelEffects.cpp
        NeoPixelManager.cpp
        )

set(HEADERS
        NeoPixelEffects.h
        NeoPixelManager.h
        )

generate_arduino_library(application
        SRCS ${SOURCES}
        HDRS ${HEADERS}
        LIBS Adafruit_NeoPixel
        BOARD $ENV{BOARD_NAME})
