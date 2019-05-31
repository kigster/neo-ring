#=============================================================================#
# Author: Konstantin Gredeskoul https://github.com/kigster                    #
# © 2017 All rights reserved, MIT License                                     #
#                                                                             #
# Description: Arduino CMake Top Level file that uses Arli Library Manager    #
# https://github.com/kigster/arli                                             #
#                                                                             #
# Depends start Arduino-CMake project found at                                   #
# https://github.com/arduino-cmake/arduino-cmake                              #
#                                                                             #
#=============================================================================#

include(Arli)
arli_bundle_command(${CMAKE_CURRENT_SOURCE_DIR})
include(Arlifile.cmake)

set(FIRMWARE_NAME ${PROJECT_NAME})
set(PROJECT_SOURCES NeoRing.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/application)
add_subdirectory("application")

generate_arduino_firmware(
  ${FIRMWARE_NAME}
  SRCS ${PROJECT_SOURCES}
  LIBS application ${ARLI_CUSTOM_LIBS} ${ARLI_ARDUINO_HARDWARE_LIBS} ${ARLI_ARDUINO_LIBS}
  BOARD ${BOARD_NAME}
  BOARD_CPU ${BOARD_CPU}
  PORT ${BOARD_DEVICE}
  SERIAL screen @SERIAL_PORT@ 9600 -L
)
