#include "RingBuffer.h"
#include <gtest/gtest.h>
#include <cstring>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}
TEST(TextWrap, Constructor_PassCapacityThroughTheConstructor)
{
    RingBuffer ringBuffer{5};
}
TEST(TextWrap, AddOneElementToBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=3;
    ringBuffer.add(3);
    EXPECT_TRUE(0 == std::memcmp(tab,ringBuffer.array,sizeof(tab)));
}
TEST(TextWrap, AddTwoElementToBuffer)
{
    RingBuffer ringBuffer{5};
    int* tab = new int[5];
    tab[0]=3;
    tab[1]=4;
    ringBuffer.add(3);
    ringBuffer.add(4);
    EXPECT_TRUE(0 == std::memcmp(tab,ringBuffer.array,sizeof(tab)));
}

// TODO: ...