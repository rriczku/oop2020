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
    TextWrap textWrap{4};
    EXPECT_EQ("abcd",textWrap.wrap("abcd"));
}
TEST(TextWrap,Wrap_FourCharacterInThreeColumn)
{
    TextWrap textWrap{3};
    EXPECT_EQ("abc\nd",textWrap.wrap("abcd"));
}
TEST(TextWrap,Wrap_ThreeWordsInThColumn)
{
    TextWrap textWrap{13};
    EXPECT_EQ("siemankooo\nwitam hej",textWrap.wrap("siemankooo witam hej"));
}
TEST(TextWrap,Wrap_LoremIn50Column)
{
    TextWrap textWrap{50};
    EXPECT_EQ("Lorem ipsum dolor sit amet, consectetur adipiscing\nelit. Duis accumsan dignissim ante vel suscipit.\nAenean suscipit ex porttitor, lobortis eros non,\ncursus nunc. In consectetur, magna nec sodales\negestas, nisi felis tincidunt ipsum, et ornare\nmassa magna sit amet eros. Etiam bibendum eros\nviverra augue ultrices vehicula. Etiam risus\nlectus, rhoncus vitae odio eget, sagittis\nmalesuada nisl. Phasellus accumsan mi lorem, eget\nfinibus purus pulvinar nec. Aliquam consequat\nligula et maximus lobortis. In volutpat libero\nvitae eros gravida aliquet. Interdum et malesuada\nfames ac ante ipsum primis in faucibus. Fusce ac\nfelis sapien. Nulla at lacus non risus imperdiet\nbibendum sit amet molestie purus. Nunc quis rutrum\nest. Sed id nisl non tortor facilisis rhoncus.",textWrap.wrap("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."));
}
TEST(TextWrap, Wrap_LoremIn80Column)
{
    TextWrap textWrap(80);
    EXPECT_EQ("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim\nante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc.\nIn consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare\nmassa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula.\nEtiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus\naccumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et\nmaximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et\nmalesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla\nat lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum\nest. Sed id nisl non tortor facilisis rhoncus.",textWrap.wrap("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."));
}
