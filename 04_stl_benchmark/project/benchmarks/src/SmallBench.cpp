#include "Small.h"
#include "BenchIncludes.h"

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