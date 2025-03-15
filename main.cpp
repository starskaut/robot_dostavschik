#include <iostream>
#include <string>
#include <thread>
#include <chrono>

//класс двигателя
class Motor {
public:
    void moveForward(int sec) {
        std::cout << "Move forward " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void moveBackward(int sec) {
        std::cout << "Move backward " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void turnRight(int sec) {
        std::cout << "Turn to left " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void turnLeft(int sec) {
        std::cout << "Turn to right " << sec << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    void stop() {
        std::cout << "Stop motor" << std::endl;
    }
};

//класс приема сообщений с сервера
class ServerCommunicator {
public:
    void receiveMessage(const std::string& message) {
        std::cout << "Received message: " << message << std::endl;

        Motor motor1;

        if (message == "move forward") {
            motor1.moveForward(2);
        } else if (message == "move backward") {
            motor1.moveBackward(1);
        } else if (message == "turn left") {
            motor1.turnRight(3);
        } else if (message == "turn right") {
            motor1.turnLeft(4);
        } else if (message == "stop") {
            motor1.stop();
        } else {
            std::cout << "error" << std::endl;
        }
    }
};

int main() {
    ServerCommunicator server;
    
    server.receiveMessage("move forward");
    server.receiveMessage("turn left");
    server.receiveMessage("stop");

    return 0;
}
