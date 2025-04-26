cmake_minimum_required(VERSION 3.14)
project(RobotControl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    command_receiver.cpp
    motor_controller.cpp
)

include(FetchContent)
set(FETCHCONTENT_QUIET ON)

# Mosquitto configuration
FetchContent_Declare(
    mosquittopp
    GIT_REPOSITORY https://github.com/eclipse/mosquitto.git
    GIT_TAG a196c2b244f248072a6b3ac8fb3f00ce0ff63dea
)

# Mosquitto build options
set(WITH_DOCS OFF CACHE BOOL "[Mosquitto] Disable documentation build" FORCE)
set(DOCUMENTATION OFF CACHE BOOL "[Mosquitto] Docs" FORCE)
set(WITH_APPS OFF CACHE BOOL "[Mosquitto] App build" FORCE)
set(WITH_CJSON OFF CACHE BOOL "[Mosquitto] Disable JSON build" FORCE)

FetchContent_MakeAvailable(mosquittopp)

FetchContent_GetProperties(mosquittopp
    POPULATED mosquittopp_POPULATED
    SOURCE_DIR mosquittopp_SOURCE_DIR
    BINARY_DIR mosquittopp_BINARY_DIR
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${mosquittopp_SOURCE_DIR}/include
        ${mosquittopp_SOURCE_DIR}/lib
        ${mosquittopp_SOURCE_DIR}/lib/cpp
        ${mosquittopp_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
        mosquittopp
        pthread
)
