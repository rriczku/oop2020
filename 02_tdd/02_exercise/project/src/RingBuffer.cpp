#include <iostream>
#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity) : capacity(capacity){
    array = new int [capacity];
    currentSize=0;
}
void RingBuffer::add(int value){
    array[currentSize]=value;
    currentSize++;
}
int RingBuffer::remove(){
    int temp=array[0];
    array[0] = 0;
    return temp;
}