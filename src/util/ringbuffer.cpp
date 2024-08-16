#include "ringbuffer.hpp"

RingBuffer::RingBuffer(size_t size) : size(size), buffer(size), head(0), tail(0) {}

bool RingBuffer::push(uint8_t data) {
    if ((head + 1) % size == tail) {
        return false; // Buffer is full
    }
    buffer[head] = data;
    head = (head + 1) % size;
    return true;
}

bool RingBuffer::pop(uint8_t& data) {
    if (head == tail) {
        return false; // Buffer is empty
    }
    data = buffer[tail];
    tail = (tail + 1) % size;
    return true;
}
