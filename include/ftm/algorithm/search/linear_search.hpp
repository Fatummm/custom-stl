#pragma once

#include <iterator>

namespace ftm {

template <typename InputIt, typename T>
requires std::input_iterator<InputIt>
InputIt linear_search(
  InputIt first
  , InputIt last
  , const T& value
) 
{
  for (; first != last; ++first) {
    if (*first == value) {
      return first;
    }
  }
  return last;
}

} /* ftm */