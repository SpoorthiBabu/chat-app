#include "arp.hpp"
#include <iostream>

void Arp::sendGratuitousArp(const std::string& data) {
    // Construct and send a gratuitous ARP packet with the given data
    std::cout << "Sending gratuitous ARP packet with data: " << data << std::endl;
    // Logic to send ARP packet (this is a placeholder)
}
