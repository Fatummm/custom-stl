#pragma once

#include <iterator>

namespace ftm {

/**
 * @brief  Algorithm of simple element search in sequence.
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @retval Iterator to the found element in `[first, last)`, 
 *         and `last` if the element was not found
 * @note   Time Complexity: `O(n)`
 */
template <typename InputIt, typename T>
requires std::input_iterator<InputIt>
InputIt linear_search(
  InputIt first
  , InputIt last
  , const T& value
);

} /* ftm */

#include <ftm/algorithm/search/impl/linear_search.ipp>
