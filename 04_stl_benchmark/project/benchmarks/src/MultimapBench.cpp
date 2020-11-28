//
// Created by student on 11/28/20.
//
#include "Small.h"
#include "BenchIncludes.h"
#include <map>

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


