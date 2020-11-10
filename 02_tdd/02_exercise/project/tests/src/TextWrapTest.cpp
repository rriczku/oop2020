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
    EXPECT_EQ("a",textWrap.wrap("a"));
}
TEST(TextWrap,Wrap_OneCharacterInOneColumn_OtherCharacter)
{
    TextWrap textWrap{1};
    EXPECT_EQ("b",textWrap.wrap("b"));
}
TEST(TextWrap,Wrap_TwoCharacterInOneColumn)
{
    TextWrap textWrap{1};
    EXPECT_EQ("a\nb",textWrap.wrap("ab"));
}
TEST(TextWrap,Wrap_FourCharacterInTwoColumn)
{
    TextWrap textWrap{2};
    EXPECT_EQ("ab\ncd",textWrap.wrap("abcd"));
}
TEST(TextWrap,Wrap_FourCharacterInFourColumn)
{
    TextWrap textWrap{1};
    EXPECT_EQ("a\nb\nc\nd",textWrap.wrap("abcd"));
}
