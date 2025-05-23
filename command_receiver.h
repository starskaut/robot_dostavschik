#ifndef COMMAND_RECEIVER_H
#define COMMAND_RECEIVER_H

#include <string>
#include <mosquittopp.h>
#include "motor_controller.h"

class CommandReceiver {
public:
    virtual ~CommandReceiver() = default;
    virtual void receiveMessage(const std::string& message) = 0;
};

class MQTTReceiver : public CommandReceiver, public mosqpp::mosquittopp {
public:
    MQTTReceiver(const char* id, const char* host, int port, MotorController& motor)
        : mosquittopp(id), motorController_(motor) {
        connect(host, port, 60);
        subscribe(nullptr, "robot/commands");
    }

    void on_message(const struct mosquitto_message* message) override {
        std::string cmd(static_cast<char*>(message->payload), message->payloadlen);
        receiveMessage(cmd);
    }

    void receiveMessage(const std::string& message) override {
        std::cout << "Received command: " << message << std::endl;

        if (message == "move_forward") {
            motorController_.moveForward(1);
        } else if (message == "move_backward") {
            motorController_.moveBackward(1);
        } else if (message == "turn_right") {
            motorController_.turnRight(1);
        } else if (message == "turn_left") {
            motorController_.turnLeft(1);
        } else if (message == "stop") {
            motorController_.stop();
        } else {
            std::cout << "Unknown command: " << message << std::endl;
        }
    }

private:
    MotorController& motorController_;
};

#endif // COMMAND_RECEIVER_H
