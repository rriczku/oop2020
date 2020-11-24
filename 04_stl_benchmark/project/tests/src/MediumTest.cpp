#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Medium.h"

TEST(MediumTest, SizeIsOneKiloByte) {

    EXPECT_EQ(1024u, sizeof(Medium));
}

TEST(MediumTest, CreateObject) {

    Medium medium{};
}

TEST(MediumTest, HasLessThenOperator) {

    Medium a{};
    Medium b{};
    a < b;
}

TEST(MediumTest, HasEqualityOperator) {

    Medium a{};
    Medium b{};
    a == b;
}

TEST(MediumTest, CanBeHashed) {

    Medium medium{};
    std::hash<Medium> hash;
    hash(medium);
}

TEST(MediumTest, Collections) {

    Medium medium{};

    std::vector<Medium> vector{};
    vector.push_back(medium);

    std::array<Medium, 1> array{};
    array[0] = medium;

    std::deque<Medium> deque{};
    deque.push_back(medium);

    std::list<Medium> list{};
    list.push_back(medium);

    std::forward_list<Medium> forward_list{};
    forward_list.push_front(medium);

    std::map<Medium, bool> map{};
    map[medium] = true;

    std::set<Medium> set{};
    set.insert(medium);

    std::unordered_map<Medium, bool> unordered_map{};
    unordered_map[medium] = true;

    std::unordered_set<Medium> unordered_set{};
    unordered_set.insert(medium);
}


TEST(MediumTest, Randomize) {

    Medium medium{};
    medium.randomize();

    auto count = 0u;

    for (int i : medium.data) {
        ASSERT_LE(0, i);
        ASSERT_GE(std::numeric_limits<int>::max(), i);

        if (i != 0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(MediumTest, Clear) {

    Medium medium{};
    medium.randomize();
    medium.clear();

    for (int i : medium.data) {
        ASSERT_EQ(0, i);
    }
}
TEST(MediumTest, LessOperator)
{
    Medium mediumOne{};
    Medium mediumTwo{};
    for(int i=0;i<Medium::SIZE;i++)
    {
        if(i>=100)
        {
            mediumTwo.data[i]=i+1;
            mediumOne.data[i]=i;
        }
        else
        {
            mediumOne.data[i]=i;
            mediumTwo.data[i]=i;
        }
    }
    EXPECT_TRUE(mediumOne<mediumTwo);
}
TEST(MediumTest, LessOperatorV2)
{
    Medium mediumOne{};
    Medium mediumTwo{};
    for(int i=0;i<Medium::SIZE;i++)
    {
        if(i>=100)
        {
            mediumTwo.data[i]=i-1;
            mediumOne.data[i]=i;
        }
        else
        {
            mediumOne.data[i]=i;
            mediumTwo.data[i]=i;
        }
    }
    EXPECT_FALSE(mediumOne<mediumTwo);
}
TEST(MediumTest, Equal)
{
    Medium mediumOne{};
    Medium mediumTwo{};

    std::fill_n(mediumOne.data,Medium::SIZE,1);
    std::fill_n(mediumTwo.data,Medium::SIZE,1);

    ASSERT_EQ(mediumOne,mediumTwo);

    mediumOne.data[5]=5;
    EXPECT_FALSE(mediumOne==mediumTwo);
}
TEST(MediumTest, Hash)
{
    Medium mediumOne{};
    Medium mediumTwo{};

    std::fill_n(mediumOne.data,Medium::SIZE,1);
    std::fill_n(mediumTwo.data,Medium::SIZE,1);

    std::hash<Medium> hash{};
    ASSERT_EQ(hash(mediumOne),hash(mediumTwo));
}
