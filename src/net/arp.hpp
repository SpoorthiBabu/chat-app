#ifndef ARP_HPP
#define ARP_HPP

#include <string>

class Arp {
public:
    void sendGratuitousArp(const std::string& data);
};

#endif // ARP_HPP
