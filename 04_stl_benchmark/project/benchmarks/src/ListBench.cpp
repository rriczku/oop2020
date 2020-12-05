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
        DoNotOptimize(list);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Insert(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> list(size);
    Small s{};
    auto it=list.begin();
    for(auto _ :state)
    {
        state.PauseTiming();
        s.randomize();
        state.ResumeTiming();
        DoNotOptimize(list.insert(it++,s));
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Insert)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Construct(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        std::list<Small> s(size);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Construct)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Erase(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> l(size);
    Small s{};
    for(auto _ :state)
    {
      state.PauseTiming();
      s.randomize();
      auto it=l.begin();
      l.insert(it,s);
      state.ResumeTiming();
      DoNotOptimize(l.erase(it));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Erase)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Push_Back(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> l(size);
    Small s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_back(s);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Push_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_List_Pop_Back(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> l(size);
    Small s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_back(s);
        l.pop_back();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Pop_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Push_Front(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> l(size);
    Small s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_front(s);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Push_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Pop_Front(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> l(size);
    Small s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_front(s);
        l.pop_front();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Pop_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Resize(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        int r=rand()%size;
        std::list<Small> l(size);
        state.ResumeTiming();

        l.resize(r);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Resize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Swap(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> s1(size);
    std::list<Small> s2(size);
    for(auto i=0;i<size;i++)
    {
        Small s{};
        s.randomize();
        s1.push_back(s);
    }
    for(auto i=0;i<size;i++)
    {
        Small s{};
        s.randomize();
        s2.push_back(s);
    }
    for(auto _ :state)
    {
        s1.swap(s2);
        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Swap)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Merge(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> s1(size);
    std::list<Small> s2(size);
    Small s{};
    for(auto _ :state)
    {
        state.PauseTiming();
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s1.push_back(s);
        }
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        state.ResumeTiming();
        s1.merge(s2);
        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Merge)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_List_Splice(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Small> s1{};

    Small s{};
    for(auto _ :state)
    {
        s1.clear();
        std::list<Small> s2{};
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        auto it=s1.begin();

        s1.splice(it,s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Splice)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();



static void Small_List_Remove(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Small> l{};
        for(auto i=0;i<size;i++)
        {
            Small s{};
            s.randomize();
            l.push_back(s);
        }
        Small sm{};
        sm.randomize();
        state.ResumeTiming();
        l.remove(sm);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Remove)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Small_List_Remove_If(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    struct isLess{
        bool operator()(const Small& s){return s.data[0]<100;}
    };
    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Small> l{};
        for(auto i=0;i<size;i++)
        {
            Small s{};
            s.randomize();
            l.push_back(s);
        }
        Small sm{};
        sm.randomize();
        state.ResumeTiming();
        l.remove_if(isLess());
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Remove_If)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Reverse(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::list<Small> l{};
    for(auto i=0;i<size;i++)
    {
        Small s{};
        s.randomize();
        l.push_back(s);
    }
    for(auto _ :state)
    {
        l.reverse();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Reverse)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Unique(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Small> l{};
        for(auto i=0;i<size;i++)
        {
            Small s{};
            s.randomize();
            l.push_back(s);
        }
        state.ResumeTiming();

        l.unique();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Unique)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Small_List_Sort(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Small> l{};
        for(auto i=0;i<size;i++)
        {
            Small s{};
            s.randomize();
            l.push_back(s);
        }
        state.ResumeTiming();

        l.sort();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Small_List_Sort)->RangeMultiplier(2)->Range(1u <<5u,1u<<15u)->Complexity();
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


static void Medium_List_Clear(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Medium> list(size);
        state.ResumeTiming();

        list.clear();
        DoNotOptimize(list);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Insert(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> list(size);
    Medium s{};
    for(auto _ :state)
    {
        auto iter=list.begin();
        s.randomize();
        DoNotOptimize(list.insert(iter++,s));
        ClobberMemory();
        state.PauseTiming();
        list.remove(s);
        state.ResumeTiming();
        DoNotOptimize(list);

    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Insert)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Construct(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        std::list<Medium> s(size);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Construct)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Erase(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> l(size);
    Medium s{};
    for(auto _ :state)
    {
        state.PauseTiming();
        s.randomize();
        auto it=l.begin();
        l.insert(it,s);
        state.ResumeTiming();
        DoNotOptimize(l.erase(it));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Erase)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Push_Back(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> l(size);
    Medium s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_back(s);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Push_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();


static void Medium_List_Pop_Back(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> l(size);
    Medium s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_back(s);
        l.pop_back();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Pop_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Push_Front(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> l(size);
    Medium s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_front(s);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Push_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Pop_Front(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> l(size);
    Medium s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_front(s);
        l.pop_front();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Pop_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Resize(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        int r=rand()%size;
        std::list<Medium> l(size);
        state.ResumeTiming();

        l.resize(r);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Resize)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Swap(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> s1(size);
    std::list<Medium> s2(size);
    for(auto i=0;i<size;i++)
    {
        Medium s{};
        s.randomize();
        s1.push_back(s);
    }
    for(auto i=0;i<size;i++)
    {
        Medium s{};
        s.randomize();
        s2.push_back(s);
    }
    for(auto _ :state)
    {
        s1.swap(s2);
        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Swap)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Merge(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> s1(size);
    std::list<Medium> s2(size);
    Medium s{};
    for(auto _ :state)
    {
        state.PauseTiming();
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s1.push_back(s);
        }
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        state.ResumeTiming();
        s1.merge(s2);
        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Merge)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_SpliceHelp(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> s1{};

    Medium s{};
    for(auto _ :state)
    {
        s1.clear();
        std::list<Medium> s2{};
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        auto it=s1.begin();
        DoNotOptimize(s1);
        DoNotOptimize(it);

        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_SpliceHelp)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();

static void Medium_List_Splice(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Medium> s1{};

    Medium s{};
    for(auto _ :state)
    {

        s1.clear();
        std::list<Medium> s2{};
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        auto it=s1.begin();

        s1.splice(it,s2);
        DoNotOptimize(s2);
        DoNotOptimize(it);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Splice)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();

static void Medium_List_Help(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Medium sm{};
    for(auto _ :state)
    {
        std::list<Medium> l{};
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            l.push_back(s);
        }
        sm.randomize();
        DoNotOptimize(l); DoNotOptimize(sm);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Help)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Remove(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Medium sm{};
    for(auto _ :state)
    {

        std::list<Medium> l{};
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            l.push_back(s);
        }

        sm.randomize();
        l.remove(sm);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Remove)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();


static void Medium_List_Remove_If(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Medium sm{};
    struct isLess{
        bool operator()(const Medium& s){return s.data[0]<100;}
    };
    for(auto _ :state)
    {
        std::list<Medium> l{};
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            l.push_back(s);
        }
        sm.randomize();
        l.remove_if(isLess());
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Remove_If)->RangeMultiplier(2)->Range(1u <<5u,1u<<8u)->Complexity();

static void Medium_List_Reverse(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::list<Medium> l{};
    for(auto i=0;i<size;i++)
    {
        Medium s{};
        s.randomize();
        l.push_back(s);
    }
    for(auto _ :state)
    {
        l.reverse();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Reverse)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Unique(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        std::list<Medium> l{};
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            l.push_back(s);
        }

        l.unique();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Unique)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

static void Medium_List_Sort(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        std::list<Medium> l{};
        for(auto i=0;i<size;i++)
        {
            Medium s{};
            s.randomize();
            l.push_back(s);
        }

        l.sort();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Medium_List_Sort)->RangeMultiplier(2)->Range(1u <<5u,1u<<10u)->Complexity();

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
BENCHMARK(Large_List_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


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
BENCHMARK(Large_List_Empty)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

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
BENCHMARK(Large_List_Size)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

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
BENCHMARK(Large_List_MaxSize)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


static void Large_List_Clear(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Large> list(size);
        state.ResumeTiming();

        list.clear();
        DoNotOptimize(list);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Clear)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Insert(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> list(size);
    Large s{};
    for(auto _ :state)
    {
        auto iter=list.begin();
        s.randomize();
        DoNotOptimize(list.insert(iter++,s));
        ClobberMemory();
        state.PauseTiming();
        list.remove(s);
        state.ResumeTiming();
        DoNotOptimize(list);

    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Insert)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Construct(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        std::list<Large> s(size);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Construct)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Erase(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> l(size);
    Large s{};
    for(auto _ :state)
    {
        s.randomize();
        auto it=l.begin();
        l.insert(it,s);

        DoNotOptimize(l.erase(it));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Erase)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Push_Back(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> l(size);
    Large s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_back(s);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Push_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


static void Large_List_Pop_Back(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> l(size);
    Large s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_back(s);
        l.pop_back();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Pop_Back)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Push_Front(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> l(size);
    Large s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_front(s);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Push_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Pop_Front(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> l(size);
    Large s{};
    for(auto _ :state)
    {
        s.randomize();
        l.push_front(s);
        l.pop_front();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Pop_Front)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Resize(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        int r=rand()%size;
        std::list<Large> l(size);
        state.ResumeTiming();

        l.resize(r);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Resize)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Swap(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> s1(size);
    std::list<Large> s2(size);
    for(auto i=0;i<size;i++)
    {
        Large s{};
        s.randomize();
        s1.push_back(s);
    }
    for(auto i=0;i<size;i++)
    {
        Large s{};
        s.randomize();
        s2.push_back(s);
    }
    for(auto _ :state)
    {
        s1.swap(s2);
        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Swap)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_MergeHelp(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> s1(size);
    std::list<Large> s2(size);
    Large s{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s1.push_back(s);
        }
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }

        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_MergeHelp)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Merge(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> s1(size);
    std::list<Large> s2(size);
    Large s{};
    for(auto _ :state)
    {
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s1.push_back(s);
        }
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }

        s1.merge(s2);
        DoNotOptimize(s1);
        DoNotOptimize(s2);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Merge)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_SpliceHelp(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> s1{};
    Large s{};
    for(auto _ :state)
    {
        s1.clear();
        std::list<Large> s2{};
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        auto it=s1.begin();
        DoNotOptimize(s1);
        DoNotOptimize(it);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_SpliceHelp)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Splice(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    std::list<Large> s1{};

    Large s{};
    for(auto _ :state)
    {
        s1.clear();
        std::list<Large> s2{};
        for(auto i=0;i<size;i++)
        {
            s.randomize();
            s2.push_back(s);
        }
        auto it=s1.begin();
        s1.splice(it,s2);
        DoNotOptimize(s1);
        DoNotOptimize(it);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Splice)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();



static void Large_List_Remove(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Large sm{};
    for(auto _ :state)
    {
        std::list<Large> l{};
        for(auto i=0;i<size;i++)
        {
            Large s{};
            s.randomize();
            l.push_back(s);
        }
        sm.randomize();
        l.remove(sm);
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Remove)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();


static void Large_List_Remove_If(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;
    Large sm{};
    struct isLess{
        bool operator()(const Large& s){return s.data[0]<100;}
    };
    for(auto _ :state)
    {
        std::list<Large> l{};
        for(auto i=0;i<size;i++)
        {
            Large s{};
            s.randomize();
            l.push_back(s);
        }
        sm.randomize();
        l.remove_if(isLess());
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Remove_If)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Reverse(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    std::list<Large> l{};
    for(auto i=0;i<size;i++)
    {
        Large s{};
        s.randomize();
        l.push_back(s);
    }
    for(auto _ :state)
    {
        l.reverse();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Reverse)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Unique(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        state.PauseTiming();
        std::list<Large> l{};
        for(auto i=0;i<size;i++)
        {
            Large s{};
            s.randomize();
            l.push_back(s);
        }
        state.ResumeTiming();

        l.unique();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Unique)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();

static void Large_List_Sort(State& state)
{
    auto N=state.range(0);
    auto size=(std::size_t)N;

    for(auto _ :state)
    {
        std::list<Large> l{};
        for(auto i=0;i<size;i++)
        {
            Large s{};
            s.randomize();
            l.push_back(s);
        }

        l.sort();
        DoNotOptimize(l);
        ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Large_List_Sort)->RangeMultiplier(2)->Range(1u <<5u,1u<<7u)->Complexity();
