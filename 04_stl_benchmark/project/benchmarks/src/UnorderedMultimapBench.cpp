//
// Created by student on 11/28/20.
//
#include "Small.h"
#include "Medium.h"
#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_map>


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
        auto res=multimap.count(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

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
    Small small{};
    small.randomize();
    for(auto _ :state)
    {
        auto res=multimap.find(small);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_UnorderedMultimap_EqualRange(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};
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
BENCHMARK(Small_UnorderedMultimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

// Medium


static void Medium_UnorderedMultimap_Empty(State& state)
{
    std::unordered_multimap<Medium,Medium> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_UnorderedMultimap_Size(State& state)
{
    std::unordered_multimap<Medium,Medium> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_UnorderedMultimap_MaxSize(State& state)
{
    std::unordered_multimap<Medium,Medium> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.max_size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_UnorderedMultimap_Count(State& state)
{
    std::unordered_multimap<Medium,Medium> multimap{};
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
        DoNotOptimize(multimap.count(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<20u)->Complexity();

static void Medium_UnorderedMultimap_Find(State& state)
{
    std::unordered_multimap<Medium,Medium> multimap{};
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
        DoNotOptimize(multimap.find(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Medium_UnorderedMultimap_EqualRange(State& state)
{
    std::unordered_multimap<Medium,Medium> multimap{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Medium MediumOne{};
        Medium MediumTwo{};
        MediumOne.randomize();
        MediumTwo.randomize();
        multimap.insert({MediumOne,MediumTwo});
    }
    Medium medium{};
    for(auto _ :state)
    {
        medium.randomize();
        DoNotOptimize(multimap.equal_range(medium));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

// Large


static void Large_UnorderedMultimap_Empty(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_UnorderedMultimap_Size(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_UnorderedMultimap_MaxSize(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
    for(auto _ :state)
    {
        DoNotOptimize(multimap.max_size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_UnorderedMultimap_Count(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
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
BENCHMARK(Large_UnorderedMultimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_UnorderedMultimap_Find(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
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
BENCHMARK(Large_UnorderedMultimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_UnorderedMultimap_EqualRange(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
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
BENCHMARK(Large_UnorderedMultimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();