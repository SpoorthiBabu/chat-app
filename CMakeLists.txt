# cmake_minimum_required(VERSION 3.10)

# project(ArpChat_CPP)

# set(CMAKE_CXX_STANDARD 17)

# include_directories(include)

# add_executable(ArpChat_CPP 
#     src/main.cpp 
#     src/net/arp.cpp 
#     src/net/socket.cpp 
#     src/ui/ui.cpp 
#     src/util/error.cpp 
#     src/util/ringbuffer.cpp
# )

cmake_minimum_required(VERSION 3.10)
project(ArpChat_CPP)

set(CMAKE_CXX_STANDARD 17)

# Specify the directory where the header files are located
include_directories(include)
include_directories(src)



# Add executable
add_executable(ArpChat_CPP src/main.cpp src/net/socket.cpp src/ui/ui.cpp src/util/error.cpp src/util/ringbuffer.cpp)

# Link with Ws2_32 library for Windows
if(MSVC)
    target_link_libraries(ArpChat_CPP Ws2_32)
endif()

