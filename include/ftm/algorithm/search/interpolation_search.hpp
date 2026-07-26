#pragma once

#include <iterator>

namespace ftm {

/**
 * @brief  Algorithm that implements interpolation search in the array.
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @param  comp function to compare two elements of type T.
 *         Is `std::less<T>()` by default.
 * @retval Iterator to the found element in `[first, last)`, 
 *         and `last` if the element was not found.
 * @note   Type `T` must support arithmetic operations such as 
 *         subtraction and division.
 * @note   The sequence `[first, last)` is considered to be sorted
 *         with respect to `comp`.
 * @note   Time Complexity: `O(log(log n))` for the average case,
 *         and `O(n)` for the worst case.
 * @note   This search is best suited for sequences where values
 *         are uniformly distributed.
 */
template <typename RandomIt, typename T, typename Comparator = std::less<T>>
requires std::random_access_iterator<RandomIt>
RandomIt interpolation_search(
  RandomIt first
  , RandomIt last
  , const T& value
  , Comparator comp = Comparator{}
);

} /* ftm */

#include <ftm/algorithm/search/impl/interpolation_search.ipp>
