#include <iostream>
#include <string>
#include <thread>
#include <chrono>

//класс двигателя
class Motor {
public:
    void moveForward(int duration) {
        std::cout << "Move forward " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void moveBackward(int duration) {
        std::cout << "Move backward " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void turnRight(int duration) {
        std::cout << "Turn to right " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }

    void turnLeft(int duration) {
        std::cout << "Turn to left " << duration << " seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(duration));
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

        if (message == "move_forward") {
            motor1.moveForward(2);
        } else if (message == "move_backward") {
            motor1.moveBackward(1);
        } else if (message == "turn_right") {
            motor1.turnRight(3);
        } else if (message == "turn_left") {
            motor1.turnLeft(4);
        } else if (message == "stop") {
            motor1.stop();
        } else {
            std::cout << "Ошибка" << std::endl;
        }
    }
};

int main() {
    ServerCommunicator server;

    // Пример получения сообщений с сервера
    server.receiveMessage("move_forward");
    server.receiveMessage("turn_left");
    server.receiveMessage("stop");

    return 0;
}