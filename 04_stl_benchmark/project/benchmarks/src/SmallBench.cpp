#include "Small.h"
#include "BenchIncludes.h"
#include <list>
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

