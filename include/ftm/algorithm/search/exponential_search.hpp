#pragma once

#include <iterator>
#include <ftm/algorithm/search/binary_search.hpp>

namespace ftm {

template <typename RandomIt, typename T, typename Comparator = std::less<T>>
requires std::random_access_iterator<RandomIt>
RandomIt exponential_search(
  RandomIt first
  , RandomIt last
  , const T& value
  , Comparator comp = Comparator{}
)
{
  size_t dist = static_cast<size_t>(std::distance(first, last));

  if (dist == 0) return last;

  size_t bound = 1;
  size_t mult_coef = 2;

  if (!comp(*first, value) && !comp(value, *first)) return first;

  while (bound < dist && comp(*std::next(first, bound), value)) {
    bound *= mult_coef;
  }

  RandomIt lower = std::next(first, bound / mult_coef);
  RandomIt upper = (bound < dist) ? std::next(first, bound) : last;

  RandomIt it = binary_search(lower, upper, value, comp);
  if (it != last && !comp(*it, value) && !comp(value, *it)) {
    return it;
  }
  return last;
}

} /* ftm */