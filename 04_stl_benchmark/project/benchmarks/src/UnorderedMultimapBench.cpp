//
// Created by student on 11/28/20.
//
#include "Small.h"
#include "Medium.h"
#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_map>

static void Small_UnorderedMultimap_Create(State& state)
{
    std::unordered_multimap<Small,Small> multimap{};

    for(auto _ :state)
    {
        Small s{};
        s.randomize();
        multimap.insert({s,s});
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Create)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


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
    Small smallOne{};
    Small smallTwo{};
    for(auto i=0u;i<N;i++)
    {
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
    Small smallOne{};
    Small smallTwo{};
    for(auto i=0u;i<N;i++)
    {
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


static void Small_UnorderedMultimap_Clear(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::multimap<Small,Small> mp{};
    for(auto _ :state)
    {
        state.PauseTiming();
        for(auto i=0;i<size;i++)
        {
            Small s1{};
            s1.randomize();
            mp.insert({s1,s1});
        }
        state.ResumeTiming();
        mp.clear();

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_UnorderedMultimap_Insert(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Small s{};
    for(auto _ :state)
    {
        std::multimap<Small,Small> mp{};
        s.randomize();
        mp.insert({s,s});

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Insert)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_UnorderedMultimap_Erase(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::multimap<Small,Small> mp{};
    Small s{};
    for(auto i=0;i<size;i++)
    {
        s.randomize();
        mp.insert({s,s});
    }
    for(auto _ :state)
    {
        s.randomize();
        DoNotOptimize(mp.erase(s));

        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Erase)->RangeMultiplier(2)->Range(1u <<5u,1u<<15u)->Complexity();



static void Small_UnorderedMultimap_Swap(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::multimap<Small,Small> mp{};
    std::multimap<Small,Small> mp2{};
    Small s{};
    for(auto i=0;i<size;i++)
    {
        s.randomize();
        mp.insert({s,s});
    }
    for(auto _ :state)
    {
        DoNotOptimize(mp);
        DoNotOptimize(mp2);
        mp.swap(mp2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Swap)->RangeMultiplier(2)->Range(1u <<5u,1u<<15u)->Complexity();


static void Small_UnorderedMultimap_Rehash(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::unordered_multimap<Small,Small> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Small s{};
            s.randomize();
            mp.insert({s,s});
        }
        auto n=rand()%size;
        mp.rehash(n);
        ClobberMemory();
        DoNotOptimize(mp);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Rehash)->RangeMultiplier(2)->Range(1u <<5u,1u<<15u)->Complexity();

static void Small_UnorderedMultimap_Reserve(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::unordered_multimap<Small,Small> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Small s{};
            s.randomize();
            mp.insert({s,s});
        }
        auto n=rand()%size;
        mp.reserve(n);

        ClobberMemory();
        DoNotOptimize(mp);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_UnorderedMultimap_Reserve)->RangeMultiplier(2)->Range(1u <<5u,1u<<15u)->Complexity();


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
BENCHMARK(Medium_UnorderedMultimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

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
BENCHMARK(Medium_UnorderedMultimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();


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
BENCHMARK(Medium_UnorderedMultimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();


static void Medium_UnorderedMultimap_Clear(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::multimap<Medium,Medium> mp{};
    for(auto _ :state)
    {
        state.PauseTiming();
        for(auto i=0;i<size;i++)
        {
            Medium s1{};
            s1.randomize();
            mp.insert({s1,s1});
        }
        state.ResumeTiming();
        mp.clear();

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();

static void Medium_UnorderedMultimap_Insert(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Medium s{};
    for(auto _ :state)
    {
        std::multimap<Medium,Medium> mp{};
        s.randomize();
        mp.insert({s,s});

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Insert)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();

static void Medium_UnorderedMultimap_Erase(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::multimap<Medium,Medium> mp{};
    Medium s{};
    for(auto i=0;i<size;i++)
    {
        s.randomize();
        mp.insert({s,s});
    }
    for(auto _ :state)
    {
        s.randomize();
        DoNotOptimize(mp.erase(s));

        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Erase)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();



static void Medium_UnorderedMultimap_Swap(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::multimap<Medium,Medium> mp{};
    std::multimap<Medium,Medium> mp2{};
    Medium s{};
    for(auto i=0;i<size;i++)
    {
        s.randomize();
        mp.insert({s,s});
    }
    for(auto _ :state)
    {
        DoNotOptimize(mp);
        DoNotOptimize(mp2);
        mp.swap(mp2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Swap)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();


static void Medium_UnorderedMultimap_Rehash(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::unordered_multimap<Medium,Medium> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            mp.insert({s,s});
        }
        auto n=rand()%size;
        mp.rehash(n);
        ClobberMemory();
        DoNotOptimize(mp);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Rehash)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();

static void Medium_UnorderedMultimap_Reserve(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::unordered_multimap<Medium,Medium> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            mp.insert({s,s});
        }
        auto n=rand()%size;
        mp.reserve(n);

        ClobberMemory();
        DoNotOptimize(mp);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_UnorderedMultimap_Reserve)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();


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
BENCHMARK(Large_UnorderedMultimap_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

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
BENCHMARK(Large_UnorderedMultimap_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

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
BENCHMARK(Large_UnorderedMultimap_Count)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

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
BENCHMARK(Large_UnorderedMultimap_Find)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


static void Large_UnorderedMultimap_EqualRange(State& state)
{
    std::unordered_multimap<Large,Large> multimap{};
    auto N=state.range(0);
    Large large{};
    Large LargeOne{};
    for(auto i=0u;i<N;i++)
    {
        LargeOne.randomize();
        multimap.insert({LargeOne,LargeOne});
    }
    for(auto _ :state)
    {
        large.randomize();
        DoNotOptimize(multimap.equal_range(large));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_EqualRange)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


static void Large_UnorderedMultimap_ClearHelp(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::multimap<Large,Large> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Large s1{};
            s1.randomize();
            mp.insert({s1,s1});
        }

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_ClearHelp)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_UnorderedMultimap_Clear(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::multimap<Large,Large> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Large s1{};
            s1.randomize();
            mp.insert({s1,s1});
        }
        mp.clear();

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_UnorderedMultimap_Insert(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Large s{};
    for(auto _ :state)
    {
        std::multimap<Large,Large> mp{};
        s.randomize();
        mp.insert({s,s});

        DoNotOptimize(mp);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Insert)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_UnorderedMultimap_Erase(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::multimap<Large,Large> mp{};
    Large s{};
    for(auto i=0;i<size;i++)
    {
        s.randomize();
        mp.insert({s,s});
    }
    for(auto _ :state)
    {
        s.randomize();
        DoNotOptimize(mp.erase(s));

        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Erase)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();



static void Large_UnorderedMultimap_Swap(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::multimap<Large,Large> mp{};
    std::multimap<Large,Large> mp2{};
    Large s{};
    for(auto i=0;i<size;i++)
    {
        s.randomize();
        mp.insert({s,s});
    }
    for(auto _ :state)
    {
        DoNotOptimize(mp);
        DoNotOptimize(mp2);
        mp.swap(mp2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Swap)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


static void Large_UnorderedMultimap_Rehash(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::unordered_multimap<Large,Large> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Large s{};
            s.randomize();
            mp.insert({s,s});
        }
        auto n=rand()%size;
        mp.rehash(n);
        ClobberMemory();
        DoNotOptimize(mp);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Rehash)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_UnorderedMultimap_Reserve(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::unordered_multimap<Large,Large> mp{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            Large s{};
            s.randomize();
            mp.insert({s,s});
        }
        auto n=rand()%size;
        mp.reserve(n);

        ClobberMemory();
        DoNotOptimize(mp);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_UnorderedMultimap_Reserve)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();
