cmake_minimum_required(VERSION 3.14)
project(RobotControl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск Mosquitto
find_package(PkgConfig REQUIRED)
pkg_check_modules(MOSQUITTO REQUIRED mosquitto mosquittopp)

add_executable(${PROJECT_NAME}
    main.cpp
    command_receiver.cpp
    motor_controller.cpp
)

# Настройка include директорий
target_include_directories(${PROJECT_NAME} PRIVATE
    ${MOSQUITTO_INCLUDE_DIRS}
)

# Линковка библиотек
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${MOSQUITTO_LIBRARIES}
    pthread
)
