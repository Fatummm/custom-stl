#pragma once

#include <iterator>

namespace ftm {

template <typename RandomIt, typename T, typename Comparator = std::less<T>>
requires std::random_access_iterator<RandomIt>
RandomIt interpolation_search(
  RandomIt first
  , RandomIt last
  , const T& value
  , Comparator comp = Comparator{}
)
{
  size_t dist = static_cast<size_t>(std::distance(first, last));
  
  if (dist == 0) return last;

  size_t l = 0;
  size_t r = dist - 1;
  size_t m;

  RandomIt mid_it;
  while (r >= l) {
    if (!comp(first[l], first[r]) && !comp(first[r], first[l])) {
      if (!comp(first[l], value) && !comp(value, first[l])) {
        return std::next(first, l);
      }
      break;
    }
    double coef = (value - first[l]) / static_cast<double>(*(first + r) - *(first + l));
    if (coef < 0 || coef > 1) break;

    m = static_cast<size_t>(l + (r - l) * coef);
    mid_it = std::next(first, m);
    if (comp(*mid_it, value)) {
      l = m + 1;
    } else if (comp(value, *mid_it)) {
      r = (m == 0) ? 0 : m - 1;
    } else {
      return mid_it;
    }
  }
  return last;
}
} /* ftm */