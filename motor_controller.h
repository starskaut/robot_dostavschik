#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <iostream>
#include <chrono>
#include <thread>

class MotorController {
public:
    virtual ~MotorController() = default;

    virtual void moveForward(int duration) = 0;
    virtual void moveBackward(int duration) = 0;
    virtual void turnRight(int duration) = 0;
    virtual void turnLeft(int duration) = 0;
    virtual void stop() = 0;
};

class ConcreteMotorController : public MotorController {
public:
    void moveForward(int duration) override {
        std::cout << "Moving forward for " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void moveBackward(int duration) override {
        std::cout << "Moving backward for " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void turnRight(int duration) override {
        std::cout << "Turning right for " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void turnLeft(int duration) override {
        std::cout << "Turning left for " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void stop() override {
        std::cout << "Stopping motor" << std::endl;
    }
};

#endif // MOTOR_CONTROLLER_H
