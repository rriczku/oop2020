#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

static void SmallLessThan(State& state)
{
    Small a{};
    Small b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        auto res=(a<b);
        DoNotOptimize(res);
    }
}
BENCHMARK(SmallLessThan);

static void SmallEqual(State& state)
{
    Small a{};
    Small b{};
    a.randomize();
    b.randomize();

    for(auto _ : state){
        auto res=(a==b);
        DoNotOptimize(res);
    }
}
BENCHMARK(SmallEqual);
static void SmallHash(State& state)
{
    Small a{};
    std::hash<Small> hash{};
    a.randomize();

    for(auto _ : state){
        DoNotOptimize(hash(a));
    }
}
BENCHMARK(SmallHash);

//multimap
// unorderedmultimap



