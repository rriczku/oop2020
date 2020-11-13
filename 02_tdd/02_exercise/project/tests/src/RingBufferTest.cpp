#include "RingBuffer.h"
#include <gtest/gtest.h>
#include <cstring>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}
TEST(RingBuffer, Constructor_PassCapacityThroughTheConstructor)
{
    RingBuffer ringBuffer{5};
}
TEST(RingBuffer, AddOneElementToBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=3;
    ringBuffer.add(3);
    EXPECT_TRUE(0 == std::memcmp(tab,ringBuffer.array,sizeof(tab)));
}
TEST(RingBuffer, AddTwoElementToBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=3;
    tab[1]=4;
    ringBuffer.add(3);
    ringBuffer.add(4);
    EXPECT_TRUE(0 == std::memcmp(tab,ringBuffer.array,sizeof(tab)));
}
TEST(RingBuffer, DeleteElementElementFromBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=3;
    tab[1]=4;
    ringBuffer.add(3);
    ringBuffer.add(4);
    EXPECT_EQ(3,ringBuffer.remove());
}
TEST(RingBuffer, AddSixElementsToBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=6;tab[1]=2;tab[2]=3;tab[3]=4;tab[4]=5;
    ringBuffer.add(1);ringBuffer.add(2);ringBuffer.add(3);ringBuffer.add(4);ringBuffer.add(5);ringBuffer.add(6);
    EXPECT_TRUE(0 == std::memcmp(tab,ringBuffer.array,5*sizeof(int)));
}
TEST(RingBuffer, RemoveAndAddElementToBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=0;tab[1]=2;tab[2]=3;tab[3]=4;
    ringBuffer.add(1);
    ringBuffer.add(2);
    ringBuffer.add(3);
    ringBuffer.remove();
    ringBuffer.add(4);
    EXPECT_TRUE(0 == std::memcmp(tab,ringBuffer.array,5*sizeof(int)));
}
