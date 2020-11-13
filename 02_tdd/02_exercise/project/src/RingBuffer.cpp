#include <iostream>
#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity) : capacity(capacity){
    array = new int [capacity];
    hArray= new int [capacity];
    currentSize=0;
    indexOfLastInsertedItem=-1;
}
void RingBuffer::add(int value){
   int temp;
    if(currentSize>=capacity)
   {
       temp=findPosToInsert(2);
       array[temp]=value;
       hArray[temp]=0;
       //hArray[temp]++;
       indexOfLastInsertedItem=temp;
   }
    else
   {
       temp = findPosToInsert(1);
       array[temp]=value;
       //hArray[temp]++;
       currentSize++;
       indexOfLastInsertedItem=temp;
   }
   getOlder();
   hArray[temp]++;
}
int RingBuffer::remove(){
    int temp=findPosToInsert(2);
    int temp2=array[temp];
    array[temp] = 0;
    hArray[temp] = 0;
    currentSize--;
    return temp2;
}

int RingBuffer::findPosToInsert(int opt) {
    if(opt==1) {
        if(indexOfLastInsertedItem<4&&hArray[indexOfLastInsertedItem+1]==0)
            return indexOfLastInsertedItem+1;
        int min = 0;
        for (int i = 1; i < capacity; i++) {
            if (hArray[i] < hArray[min])
                min = i;
        }
        return min;
    }
    else if(opt==2) {
        int max = 0;
        for (int i = 1; i < capacity; i++) {
            if (hArray[i] > hArray[max])
                max = i;
        }
        return max;
    }
}
void RingBuffer::getOlder()
{
    for(int i=0;i<capacity;i++)
    {
        if(hArray[i]!=0) hArray[i]++;
    }
}