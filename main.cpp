#include <iostream>
#include <cstdlib>
#include <csignal>
#include "motor_controller.h"
#include "command_receiver.h"

volatile sig_atomic_t flag = 0;

void signal_handler(int signal) {
    flag = 1;
}

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    ConcreteMotorCoinclude <iostream>
    #include <cstdlib>
    #include <csignal>
    #include "motor_controller.h"
    #include "command_receiver.h"
    
    volatile sig_atomicntroller motor;

    // Инициализация Mosquitto
    mosqpp::lib_init();

    const char* mqtt_host = "localhost"; // или IP вашего брокера
    const int mqtt_port = 1883;

    MQTTReceiver mqtt_receiver("robot_client", mqtt_host, mqtt_port, motor);

    std::cout << "Waiting for MQTT commands... (Ctrl+C to exit)" << std::endl;

    while(!flag) {
        mqtt_receiver.loop();
    }

    mosqpp::lib_cleanup();
    return 0;
}
