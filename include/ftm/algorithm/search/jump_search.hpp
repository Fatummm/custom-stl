#pragma once

#include <iterator>

namespace ftm {

/**
 * @brief  Algorithm that implements jump search in the array.
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @param  jump_size length of jump.
 *         Set to 0 if you want it to be calculated by algorithm.
 *         Is 0 by default.
 * @param  comp function to compare two elements of type T.
 *         Is `std::less<T>()` by default.
 * @retval Iterator to the found element in `[first, last)`,
 *         and `last` if the element was not found.
 * @note   The sequence `[first, last)` is considered to be sorted
 *         with respect to `comp`.
 * @note   Time Complexity: `O(n/m + m)`, where m is jump size.
 *         If `jump_size` is 0 (default), optimal complexity is `O(sqrt(n))`
 */
template <typename RandomIt, typename T, typename Comparator = std::less<T>>
  requires std::random_access_iterator<RandomIt>
RandomIt jump_search(RandomIt first,
                     RandomIt last,
                     const T& value,
                     Comparator comp = Comparator{},
                     size_t jump_size = 0);

}  // namespace ftm

#include <ftm/algorithm/search/impl/jump_search.ipp>
