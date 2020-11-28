#include "Small.h"
#include "BenchIncludes.h"
#include <list>
#include <map>
#include <unordered_map>
// TODO: Add benchmarks for operator<. operator==, and hash

static void LessThan(State& state)
{
    Small a{};
    Small b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        a<b;
    }
}
BENCHMARK(LessThan);

static void Equal(State& state)
{
    Small a{};
    Small b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        a==b;
    }
}
BENCHMARK(Equal);
static void Hash(State& state)
{
    Small a{};
    std::hash<Small> hash{};
    a.randomize();

    for(auto _ : state){
        hash(a);
    }
}
BENCHMARK(Hash);

static void Small_List_Front(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small small{};
        small.randomize();
        list.push_back(small);
    }
    for(auto _ :state)
    {
        auto res=list.front();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();


static void Small_List_Back(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small small{};
        small.randomize();
        list.push_back(small);
    }
    for(auto _ :state)
    {
        auto res=list.back();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();


static void Small_List_Empty(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small small{};
        small.randomize();
        list.push_back(small);
    }
    for(auto _ :state)
    {
        auto res=list.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

static void Small_List_Size(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small small{};
        small.randomize();
        list.push_back(small);
    }
    for(auto _ :state)
    {
        auto res=list.size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

static void Small_List_MaxSize(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small small{};
        small.randomize();
        list.push_back(small);
    }
    for(auto _ :state)
    {
        auto res=list.max_size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

//multimap
static void Small_Multimap_Empty(State& state)
{
    std::multimap<Small,Small> multimap{};
    for(auto _ :state)
    {
        auto res=multimap.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_Multimap_Size(State& state)
{
    std::multimap<Small,Small> multimap{};
    for(auto _ :state)
    {
        auto res=multimap.size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_Multimap_MaxSize(State& state)
{
    std::multimap<Small,Small> multimap{};
    for(auto _ :state)
    {
        auto res=multimap.max_size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_Multimap_Count(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.count(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

static void Small_Multimap_Find(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.find(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();


static void Small_Multimap_EqualRange(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.equal_range(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_Multimap_LowerBound(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.lower_bound(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_LowerBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_Multimap_UpperBound(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.upper_bound(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_UpperBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


// unorderedmultimap

static void Small_UnorderedMultimap_Empty(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
    for(auto _ :state)
    {
        auto res=multimap.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_UnorderedMultimap_Size(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
    for(auto _ :state)
    {
        auto res=multimap.size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_UnorderedMultimap_MaxSize(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
    for(auto _ :state)
    {
        auto res=multimap.max_size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_UnorderedMultimap_Count(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.count(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

static void Small_UnorderedMultimap_Find(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.find(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();


static void Small_UnorderedMultimap_EqualRange(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Small smallOne{};
        Small smallTwo{};
        smallOne.randomize();
        smallTwo.randomize();
        multimap.insert({smallOne,smallTwo});
    }
    for(auto _ :state)
    {
        Small small{};
        small.randomize();
        auto res=multimap.equal_range(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();



