//
// Created by student on 11/28/20.
//
#include "Small.h"
#include "Medium.h"
#include "Large.h"
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
    Small small{};

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
        small.randomize();
        DoNotOptimize(multimap.count(small));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_Multimap_Find(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    Small small{};

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
        small.randomize();
        auto res=multimap.find(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_Multimap_EqualRange(State& state)
{
    std::multimap<Small,Small> multimap{};
    auto N=state.range(0);
    Small small{};
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
    Small small{};

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
    Small small{};

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
        small.randomize();
        auto res=multimap.upper_bound(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_Multimap_UpperBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


//


static void Medium_Multimap_Empty(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_Multimap_Size(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_Multimap_MaxSize(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.max_size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_Multimap_Count(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    auto N=state.range(0);
    Medium mediumOne{};
    Medium mediumTwo{};
    Medium medium{};
    for(auto i=0u;i<N;i++)
    {
        mediumOne.randomize();
        mediumTwo.randomize();
        multimap.insert({mediumOne,mediumTwo});
    }
    for(auto _ :state)
    {
        medium.randomize();
        DoNotOptimize(multimap.count(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<15u)->Complexity();

static void Medium_Multimap_Find(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    auto N=state.range(0);

    Medium medium{};
    for(auto i=0u;i<N;i++)
    {
        Medium MediumOne{};
        Medium MediumTwo{};
        MediumOne.randomize();
        MediumTwo.randomize();
        DoNotOptimize(multimap.insert({MediumOne,MediumTwo}));
    }
    for(auto _ :state)
    {
        medium.randomize();
        auto res=multimap.find(medium);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Medium_Multimap_EqualRange(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    auto N=state.range(0);

    Medium medium{};
    for(auto i=0u;i<N;i++)
    {
        Medium MediumOne{};
        Medium MediumTwo{};
        MediumOne.randomize();
        MediumTwo.randomize();
        DoNotOptimize(multimap.insert({MediumOne,MediumTwo}));
    }
    for(auto _ :state)
    {
        medium.randomize();
        DoNotOptimize(multimap.equal_range(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Medium_Multimap_LowerBound(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    auto N=state.range(0);

    Medium medium{};
    for(auto i=0u;i<N;i++)
    {
        Medium MediumOne{};
        Medium MediumTwo{};
        MediumOne.randomize();
        MediumTwo.randomize();
        multimap.insert({MediumOne,MediumTwo});
    }
    for(auto _ :state)
    {
        medium.randomize();
        DoNotOptimize(multimap.lower_bound(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_LowerBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_Multimap_UpperBound(State& state)
{
    std::multimap<Medium,Medium> multimap{};
    auto N=state.range(0);

    Medium medium{};
    for(auto i=0u;i<N;i++)
    {
        Medium MediumOne{};
        Medium MediumTwo{};
        MediumOne.randomize();
        MediumTwo.randomize();
        multimap.insert({MediumOne,MediumTwo});
    }
    for(auto _ :state)
    {
        medium.randomize();
        DoNotOptimize(multimap.upper_bound(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_Multimap_UpperBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

/// LARGE



static void Large_Multimap_Empty(State& state)
{
    std::multimap<Large,Large> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_Multimap_Size(State& state)
{
    std::multimap<Large,Large> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_Multimap_MaxSize(State& state)
{
    std::multimap<Large,Large> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.max_size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_Multimap_Count(State& state)
{
    std::multimap<Large,Large> multimap{};
    auto N=state.range(0);

    Large large{};
    for(auto i=0u;i<N;i++)
    {
        Large LargeOne{};
        Large LargeTwo{};
        LargeOne.randomize();
        LargeTwo.randomize();
        multimap.insert({LargeOne,LargeTwo});
    }
    for(auto _ :state)
    {
        large.randomize();
        DoNotOptimize(multimap.count(large));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_Multimap_Find(State& state)
{
    std::multimap<Large,Large> multimap{};
    auto N=state.range(0);

    Large large{};
    for(auto i=0u;i<N;i++)
    {
        Large LargeOne{};
        Large LargeTwo{};
        LargeOne.randomize();
        LargeTwo.randomize();
        multimap.insert({LargeOne,LargeTwo});
    }
    for(auto _ :state)
    {
        large.randomize();
        DoNotOptimize(multimap.find(large));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_Multimap_EqualRange(State& state)
{
    std::multimap<Large,Large> multimap{};
    auto N=state.range(0);

    Large large{};
    for(auto i=0u;i<N;i++)
    {
        Large LargeOne{};
        Large LargeTwo{};
        LargeOne.randomize();
        LargeTwo.randomize();
        multimap.insert({LargeOne,LargeTwo});
    }
    for(auto _ :state)
    {
        large.randomize();
        DoNotOptimize(multimap.equal_range(large));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_Multimap_LowerBound(State& state)
{
    std::multimap<Large,Large> multimap{};
    auto N=state.range(0);

    Large large{};
    for(auto i=0u;i<N;i++)
    {
        Large LargeOne{};
        Large LargeTwo{};
        LargeOne.randomize();
        LargeTwo.randomize();
        multimap.insert({LargeOne,LargeTwo});
    }
    for(auto _ :state)
    {
        large.randomize();
        DoNotOptimize(multimap.lower_bound(large));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_LowerBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_Multimap_UpperBound(State& state)
{
    std::multimap<Large,Large> multimap{};
    auto N=state.range(0);
    Large large{};
    for(auto i=0u;i<N;i++)
    {
        Large LargeOne{};
        Large LargeTwo{};
        LargeOne.randomize();
        LargeTwo.randomize();
        multimap.insert({LargeOne,LargeTwo});
    }
    for(auto _ :state)
    {
        large.randomize();
        DoNotOptimize(multimap.upper_bound(large));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_Multimap_UpperBound)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


