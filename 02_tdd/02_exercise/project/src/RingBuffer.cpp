#include <iostream>
#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity) : capacity(capacity){
    array = new int [capacity];
    currentSize=0;
}
void RingBuffer::add(int value){
    array[currentSize]=value;

    if(currentSize==4) currentSize=0;
    else currentSize++;
}
int RingBuffer::remove(){
    int temp=array[0];
    array[0] = 0;
    currentSize--;
    return temp;
}