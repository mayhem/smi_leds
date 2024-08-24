cmake_minimum_required(VERSION 3.7...3.29)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(rpi_smi_leds VERSION 2024.8.25.3
                     DESCRIPTION "Drive 8 or 16 LED strips on an RPI using SMI memory interface"
                     LANGUAGES C)

execute_process(COMMAND python3 ./detect_rpi.py
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}   
                RESULT_VARIABLE return_code
                OUTPUT_VARIABLE RPI_OPTS)
if (return_code EQUAL "0")
    message(STATUS "deteced RPI options: ${RPI_OPTS}")
else()
    message(FATAL_ERROR "Could not detect Raspberry Pi version.")
endif()

# usage: -DENABLE_16_CHANNELS:BOOL=ON
option(ENABLE_16_CHANNELS "Enable 16 LED channels. Default: 8 channels" OFF)
if (ENABLE_16_CHANNELS)
    set(LED_NCHANS "-DLED_NCHANS=16")
else()
    set(LED_NCHANS "-DLED_NCHANS=8")
endif()

include_directories( include )
add_library(smi_leds STATIC smi_leds/rpi_dma_utils.c
                            smi_leds/rpi_dma_utils.h
                            smi_leds/rpi_pixleds.c
                            smi_leds/rpi_pixleds_lib.c
                            smi_leds/rpi_smi_defs.h
                            include/smi_leds.h)
set_target_properties(smi_leds PROPERTIES PUBLIC_HEADER "include/smi_leds.h")
separate_arguments(RPI_OPTS UNIX_COMMAND "${RPI_OPTS}")
target_compile_options(smi_leds PRIVATE ${LED_NCHANS} ${RPI_OPTS} -fPIC)

set( BINARY smi_test )
add_executable( ${BINARY}
                examples/example.c ) 

target_link_libraries( ${BINARY}
                       PUBLIC
                       m
                       PRIVATE
                       smi_leds )

install(TARGETS smi_leds 
        LIBRARY DESTINATION /usr/local/lib/smi_leds
        PUBLIC_HEADER DESTINATION /usr/local/include
)
