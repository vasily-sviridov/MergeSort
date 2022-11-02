#include <benchmark/benchmark.h>
#include <MergeSort.hpp>
#include <random>

static void BM_MergeSort(benchmark::State& state) {
  std::vector<int> v(state.range(0));
  std::iota(v.begin(), v.end(), 0);
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(v.begin(), v.end(), g);
  for (auto _ : state) {
    utils::MergeSort(v.begin(), v.end());
  }
}
BENCHMARK(BM_MergeSort)->RangeMultiplier(2)->Range(1 << 10, 1 << 18);

BENCHMARK_MAIN();
