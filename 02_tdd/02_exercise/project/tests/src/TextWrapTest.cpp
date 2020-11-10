#include "TextWrap.h"
#include <gtest/gtest.h>

TEST(TextWrap, Constructor) {

    TextWrap textWrap{};
}

TEST(TextWrap, Constructor_PassNumberOfColumnsThroughTheConstructor)
{
    TextWrap textWrap{2};
}