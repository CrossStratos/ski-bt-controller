cmake_minimum_required(VERSION 3.18)

# initialize pico-sdk from submodule
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)

project(ski-bt-controller)

set(CMAKE_CXX_STANDARD 20)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(ski-bt
    src/main.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(ski-bt 
    pico_stdlib
    pico_btstack_ble
    pico_btstack_cyw43
    pico_cyw43_arch_none
    hardware_adc
    )
target_include_directories(ski-bt PRIVATE
    ${CMAKE_CURRENT_LIST_DIR} # For btstack config
    ${CMAKE_SOURCE_DIR}
    )

pico_enable_stdio_usb(ski-bt 1)
pico_enable_stdio_uart(ski-bt 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(ski-bt)