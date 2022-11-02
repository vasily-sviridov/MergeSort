#include <algorithm>
#include <functional>
#include <iterator>

namespace utils {
template <class Iterator, class Compare = std::less<>>
void MergeSort(Iterator begin, Iterator end, Compare comp = Compare{}) {
  if (!(std::distance(begin, end) > 1)) {
    return;
  }

  Iterator middle = begin + std::distance(begin, end) / 2;
  MergeSort(begin, middle, comp);
  MergeSort(middle, end, comp);
  std::inplace_merge(begin, middle, end, comp);
}
}  // namespace utils