cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(rpi_smi_leds VERSION 0.1.0
                     DESCRIPTION "Drive 8 or 16 LED strips on an RPI using SMI memory interface"
                     LANGUAGES C)

# usage: -DENABLE_16_CHANNELS:BOOL=ON
option(ENABLE_16_CHANNELS "Enable 16 LED channels. Default: 8 channels" OFF)
if (ENABLE_16_CHANNELS)
    set(LED_NCHANS "-DLED_NCHANS=16")
else()
    set(LED_NCHANS "-DLED_NCHANS=8")
endif()

include_directories( include )
add_library(smi_leds STATIC smi_led/rpi_dma_utils.c
                            smi_led/rpi_dma_utils.h
                            smi_led/rpi_pixleds.c
                            smi_led/rpi_pixleds_lib.c
                            include/rpi_pixleds_lib.h
                            smi_led/rpi_smi_defs.h)
target_compile_options(smi_leds PRIVATE ${LED_NCHANS})

#target_link_libraries(rpi_smi_leds PUBLIC smi-leds)

set( BINARY smi_test )
add_executable( ${BINARY}
                examples/example.c ) 

target_link_libraries( ${BINARY}
                       PRIVATE
                       smi_leds )
