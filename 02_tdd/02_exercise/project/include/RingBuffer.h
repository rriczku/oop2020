#pragma once

class RingBuffer {
public:
    RingBuffer(int capacity=1);

    int* array;
    void add(int value);
private:
    int capacity;
    int currentSize;
    // TODO: ...
};