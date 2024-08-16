#include "net/arp.hpp"
#include "ui/ui.hpp"
#include "util/error.hpp"
#include "util/ringbuffer.hpp"
#include "config.hpp"

int main() {
    try {
        // Initialize the application
        Ui ui;
        ui.run();
    } catch (const std::exception& e) {
        Error::log(e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
