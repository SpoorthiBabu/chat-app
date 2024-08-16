#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <vector>
#include <cstddef>
#include <cstdint>

class RingBuffer {
public:
    RingBuffer(size_t size);
    bool push(uint8_t data);
    bool pop(uint8_t& data);

private:
    size_t size;
    std::vector<uint8_t> buffer;
    size_t head;
    size_t tail;
};

#endif // RINGBUFFER_HPP
