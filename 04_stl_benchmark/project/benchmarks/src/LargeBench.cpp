#include "Large.h"
#include "BenchIncludes.h"
#include <list>

static void LargeLessThan(State& state)
{
    Large a{};
    Large b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        a<b;
    }
}
BENCHMARK(LargeLessThan);

static void LargeEqual(State& state)
{
    Large a{};
    Large b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        a==b;
    }
}
BENCHMARK(LargeEqual);
static void LargeHash(State& state)
{
    Large a{};
    std::hash<Large> hash{};
    a.randomize();

    for(auto _ : state){
        hash(a);
    }
}
BENCHMARK(LargeHash);


static void Large_List_Front(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Large Large{};
        Large.randomize();
        list.push_back(Large);
    }
    for(auto _ :state)
    {
        auto res=list.front();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_List_Back(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Large Large{};
        Large.randomize();
        list.push_back(Large);
    }
    for(auto _ :state)
    {
        auto res=list.back();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Large_List_Empty(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Large Large{};
        Large.randomize();
        list.push_back(Large);
    }
    for(auto _ :state)
    {
        auto res=list.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_List_Size(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Large Large{};
        Large.randomize();
        list.push_back(Large);
    }
    for(auto _ :state)
    {
        auto res=list.size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Large_List_MaxSize(State& state)
{
    std::list<Large> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Large Large{};
        Large.randomize();
        list.push_back(Large);
    }
    for(auto _ :state)
    {
        auto res=list.max_size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();
