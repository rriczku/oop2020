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

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}

TEST(LargeTest, LessOperator)
{
    Large largeOne{};
    Large largeTwo{};
    largeTwo.clear();
    largeOne.clear();
    
    std::fill_n(largeOne.data,15,13.43);
    std::fill_n(largeTwo.data,15,13.43);
    largeOne.data[10]=6.66;
    
    EXPECT_TRUE(largeOne<largeTwo);
}
TEST(LargeTest, LessOperatorV2)
{
    Large LargeOne{};
    Large LargeTwo{};
    LargeTwo.clear();
    LargeOne.clear();

    std::fill_n(LargeOne.data,15,13.43);
    std::fill_n(LargeTwo.data,15,13.43);
    LargeOne.data[10]=16.66;

    
    EXPECT_FALSE(LargeOne<LargeTwo);
}
TEST(LargeTest, Equal)
{
    Large LargeOne{};
    Large LargeTwo{};
    LargeTwo.clear();
    LargeOne.clear();

    std::fill_n(LargeOne.data,15,13.43);
    std::fill_n(LargeTwo.data,15,13.43);
    

    ASSERT_EQ(LargeOne,LargeTwo);

    LargeOne.data[10]=6.66;
    
    EXPECT_FALSE(LargeOne==LargeTwo);
}
TEST(LargeTest, Hash)
{
    Large LargeOne{};
    Large LargeTwo{};

    std::fill_n(LargeOne.data,Large::SIZE,1);
    std::fill_n(LargeTwo.data,Large::SIZE,1);

    std::hash<Large> hash{};
    ASSERT_EQ(hash(LargeOne),hash(LargeTwo));
}


// TODO: Add tests for your operators implementation!