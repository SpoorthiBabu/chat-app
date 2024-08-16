#include "ui.hpp"
#include "net/socket.hpp"
#include <iostream>
#include <string>
#include <thread>

void Ui::run() {
    std::cout << "Running the UI..." << std::endl;

    Socket socket;
    socket.openSocket(12345);  // Open socket on port 12345

    std::thread receiver([&socket]() {
        while (true) {
            std::string received = socket.receiveMessage();
            if (!received.empty()) {
                std::cout << "\n[Received]: " << received << std::endl;
            }
        }
    });

    std::string input;
    while (true) {
        std::cout << "Enter a message (type 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            std::cout << "Exiting the UI..." << std::endl;
            break;
        }

        socket.sendMessage(input, "127.0.0.1", 12345);  // Send message to localhost on port 12345
    }

    receiver.join();
}
