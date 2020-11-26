#include "Medium.h"
#include "BenchIncludes.h"
#include <list>

static void MediumLessThan(State& state)
{
    Medium a{};
    Medium b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        a<b;
    }
}
BENCHMARK(MediumLessThan);

static void MediumEqual(State& state)
{
    Medium a{};
    Medium b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        a==b;
    }
}
BENCHMARK(MediumEqual);
static void MediumHash(State& state)
{
    Medium a{};
    std::hash<Medium> hash{};
    a.randomize();

    for(auto _ : state){
        hash(a);
    }
}
BENCHMARK(MediumHash);


static void Medium_List_Front(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Medium Medium{};
        Medium.randomize();
        list.push_back(Medium);
    }
    for(auto _ :state)
    {
        auto res=list.front();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();


static void Medium_List_Back(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Medium Medium{};
        Medium.randomize();
        list.push_back(Medium);
    }
    for(auto _ :state)
    {
        auto res=list.back();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();


static void Medium_List_Empty(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Medium Medium{};
        Medium.randomize();
        list.push_back(Medium);
    }
    for(auto _ :state)
    {
        auto res=list.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

static void Medium_List_Size(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Medium Medium{};
        Medium.randomize();
        list.push_back(Medium);
    }
    for(auto _ :state)
    {
        auto res=list.size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();

static void Medium_List_MaxSize(State& state)
{
    std::list<Medium> list{};
    auto N=state.range(0);
    for(auto i=0u;i<N;i++)
    {
        Medium Medium{};
        Medium.randomize();
        list.push_back(Medium);
    }
    for(auto _ :state)
    {
        auto res=list.max_size();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<18u)->Complexity();
