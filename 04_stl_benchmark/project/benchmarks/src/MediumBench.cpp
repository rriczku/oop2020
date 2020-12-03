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
        auto res = (a<b);
        DoNotOptimize(res);
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
        auto res=(a==b);
        DoNotOptimize(res);
    }
}
BENCHMARK(MediumEqual);
static void MediumHash(State& state)
{
    Medium a{};
    std::hash<Medium> hash{};
    a.randomize();

    for(auto _ : state){
        DoNotOptimize(hash(a));
    }
}
BENCHMARK(MediumHash);

