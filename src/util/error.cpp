#include "error.hpp"
#include <iostream>

void Error::log(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}
