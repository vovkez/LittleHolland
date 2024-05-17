cmake_minimum_required(VERSION 3.15)

project(LittleHollandVST3)

# Add VST3 SDK path
set(VST3_SDK_PATH "path/to/vst3sdk")

# Include directories
include_directories(${VST3_SDK_PATH})
include_directories(include)

# Add source files
add_library(LittleHollandVST3 MODULE
    src/Plugin.cpp
    src/NetworkConnection.cpp
)

# Link necessary libraries
target_link_libraries(LittleHollandVST3
    # Add necessary libraries here
)
