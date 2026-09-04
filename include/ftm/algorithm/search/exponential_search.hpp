#pragma once

#include <iterator>

namespace ftm {

/**
 * @brief  Algorithm that implements exponential search in the array.
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @param  comp function to compare two elements of type T.
 *         Is `std::less<T>()` by default.
 * @retval Iterator to the found element in `[first, last)`,
 *         and `last` if the element was not found.
 * @note   The sequence `[first, last)` is considered to be sorted
 *         with respect to `comp`.
 * @note   Particularly efficient when the target element is near the beginning
 *         of the sequence, or for unbounded/infinite ranges.
 * @note   Time Complexity: `O(log i)` for the average case,
 *         and O(log n) if the element was not found.
 */
template <typename RandomIt, typename T, typename Comparator = std::less<T>>
  requires std::random_access_iterator<RandomIt>
RandomIt exponential_search(RandomIt first,
                            RandomIt last,
                            const T& value,
                            Comparator comp = Comparator{});

}  // namespace ftm

#include <ftm/algorithm/search/impl/exponential_search.ipp>
