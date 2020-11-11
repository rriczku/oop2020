#include "RingBuffer.h"
#include <gtest/gtest.h>

TEST(RingBuffer, Constructor) {

    RingBuffer ringBuffer{};
}
TEST(TextWrap, Constructor_PassCapacityThroughTheConstructor)
{
    RingBuffer textWrap{5};
}
TEST(TextWrap, AddOneElementToBuffer)
{
    RingBuffer textWrap{5};
    textWrap.add(10);
}


// TODO: ...