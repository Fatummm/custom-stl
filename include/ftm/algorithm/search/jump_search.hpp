#pragma once

#include <cmath>
#include <iterator>

namespace ftm {

template <typename RandomIt, typename T, typename Comparator = std::less<T>>
requires std::random_access_iterator<RandomIt>
RandomIt jump_search(
  RandomIt first
  , RandomIt last
  , const T& value
  , size_t jump_size = 0
  , Comparator comp = Comparator{}
) 
{
  size_t dist = static_cast<size_t>(std::distance(first, last));
  
  if (dist == 0) return last;

  if (jump_size == 0) {
    jump_size = static_cast<size_t>(std::sqrt(dist));
  }

  RandomIt current = first;
  RandomIt prev = current;

  for (; current != last; ) {
    prev = current;
    if (static_cast<size_t>(std::distance(current, last)) <= jump_size) {
      current = last;
      break;
    } else {
      std::advance(current, jump_size);
    }

    if (comp(value, *current)) break;
    else if (!comp(*current, value)) return current;
  }

  for (; prev < current; ++prev) {
    if (!comp(*prev, value) && !comp(value, *prev)) return prev;
  }
  
  return last;
}

}