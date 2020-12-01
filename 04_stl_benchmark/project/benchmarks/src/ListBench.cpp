//
// Created by student on 11/28/20.
//
#include "Small.h"
#include "Medium.h"
#include "Large.h"
#include "BenchIncludes.h"
#include <list>

static void Small_List_Front(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        auto res=list.front();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_List_Back(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        auto res=list.back();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_List_Empty(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        auto res=list.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Size(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        auto res=list.size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_MaxSize(State& state)
{
    std::list<Small> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        auto res=list.max_size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Clear(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Small> list(size);
        state.ResumeTiming();

        list.clear();
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();



//---------------------------------MEDIUM-------------------------------------------------

static void Medium_List_Front(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.front());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Medium_List_Back(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.back());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Medium_List_Empty(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Size(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_MaxSize(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.max_size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


//---------------------------------LARGE------------------------------------------------------


static void Large_List_Front(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.front());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_List_Back(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.back());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_List_Empty(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_List_Size(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_List_MaxSize(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);

    for(auto _ :state)
    {
        DoNotOptimize(list.max_size());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();