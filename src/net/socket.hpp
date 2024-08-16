#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <string>

class Socket {
public:
    Socket();
    ~Socket();
    void openSocket(int port);
    void sendMessage(const std::string &message, const std::string &ip, int port);
    std::string receiveMessage();

private:
    int sockfd;
    // Remove Unix-specific fields and use Windows-specific fields if needed
};

#endif // SOCKET_HPP
