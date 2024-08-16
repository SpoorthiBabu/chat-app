#include "socket.hpp"
#include <iostream>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib") // Link with ws2_32.lib

Socket::Socket() : sockfd(INVALID_SOCKET) {}

Socket::~Socket() {
    if (sockfd != INVALID_SOCKET) {
        closesocket(sockfd);
        WSACleanup();
    }
}

void Socket::openSocket(int port) {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed!" << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in server_addr = {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Socket binding failed!" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return;
    }
}

void Socket::sendMessage(const std::string &message, const std::string &ip, int port) {
    sockaddr_in client_addr = {};
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &client_addr.sin_addr);

    sendto(sockfd, message.c_str(), message.size(), 0, (sockaddr*)&client_addr, sizeof(client_addr));
}

std::string Socket::receiveMessage() {
    char buffer[1024] = {0};
    sockaddr_in server_addr = {};
    int len = sizeof(server_addr);
    // int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr*)&server_addr, &len);
    int bufferSize = static_cast<int>(sizeof(buffer));
    int n = recvfrom(sockfd, buffer, bufferSize, 0, (struct sockaddr *)&server_addr, &len);

    return std::string(buffer, n);
}
