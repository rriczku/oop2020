#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity) : capacity(capacity){

    array = new int [capacity];
    currentSize=0;

}
void RingBuffer::add(int value){
    array[currentSize]=value;
}
