#pragma once

class RingBuffer {
public:
    RingBuffer(int capacity=1);

    int* array;
    int* hArray;
    void add(int value);
    int remove();
private:
    int indexOfLastInsertedItem;
    int capacity;
    int currentSize;
    int findPosToInsert(int opt);
    void getOlder();
    // TODO: ...
};