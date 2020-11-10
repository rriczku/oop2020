#include "TextWrap.h"
#include <gtest/gtest.h>

TEST(TextWrap, Constructor) {

    TextWrap textWrap{};
}

TEST(TextWrap, Constructor_PassNumberOfColumnsThroughTheConstructor)
{
    TextWrap textWrap{2};
}
TEST(TextWrap,Wrap_OneCharacterInOneColumn)
{
    TextWrap textWrap{1};
    EXPECT_EQ("a",textWrap("a"));
}