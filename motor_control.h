#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <iostream>
#include <chrono>
#include <thread>

class MotorControl {
public:
    virtual ~MotorControl() = default;
    
    virtual void moveForward(int sec) = 0;
    virtual void moveBackward(int sec) = 0;
    virtual void turnRight(int sec) = 0;
    virtual void turnLeft(int sec) = 0;
    virtual void stop() = 0;
};

class ConcreteMotorControl : public MotorControl {
public:
    void moveForward(int sec) override {
        std::cout << "Moving forward " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void moveBackward(int sec) override {
        std::cout << "Moving backward " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void turnRight(int sec) override {
        std::cout << "Turn to right " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void turnLeft(int sec) override {
        std::cout << "Turn to left " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void stop() override {
        std::cout << "Stop motor" << std::endl;
    }
};

#endif 