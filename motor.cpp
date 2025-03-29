#include <iostream>
#include "motor_control.h"
#include "command_receiver.h"

int main() {
    ConcreteMotorControl motor;
    ServerCommunicator server(motor);

    server.receiveMessage("move_forward");
    server.receiveMessage("turn_right");
    server.receiveMessage("stop");

    return 0;
}