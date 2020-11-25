#include "Medium.h"
#include "BenchIncludes.h"


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