#ifndef COMMAND_RECEIVER_H
#define COMMAND_RECEIVER_H

#include <string>
#include "motor_control.h"

class CommandReceiver {
public:
    virtual ~CommandReceiver() = default;
    virtual void receiveMessage(const std::string& message) = 0;
};

class ServerCommunicator : public CommandReceiver {
public:
    explicit ServerCommunicator(MotorControl& motorControl) 
        : motorControl_(motorControl) {}

    void receiveMessage(const std::string& message) override {
        std::cout << "Received message: " << message << std::endl;

        if (message == "move_forward") {
            motorControl_.moveForward(1);
        } else if (message == "move_backward") {
            motorControl_.moveBackward(2);
        } else if (message == "turn_right") {
            motorControl_.turnRight(3);
        } else if (message == "turn_left") {
            motorControl_.turnLeft(4);
        } else if (message == "stop") {
            motorControl_.stop();
        } else {
            std::cout << "Unknown command" << std::endl;
        }
    }

private:
    MotorControl& motorControl_;
};

#endif