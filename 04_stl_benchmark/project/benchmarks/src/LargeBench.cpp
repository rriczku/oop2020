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


