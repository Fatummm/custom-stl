#pragma once

#include <iterator>

namespace ftm {

/**
 * @brief  Algorithm that implements simple binary search in the array.
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @param  comp function to compare two elements of type T.
 *         Is `std::less<T>()` by default.
 * @retval Iterator to the found element in `[first, last)`,
 *         and `last` if the element was not found.
 * @note   The sequence `[first, last)` is considered to be sorted
 *         with respect to `comp`.
 * @note   Does not guarantee returning the first
 *         matching element if duplicates exist.
 * @note   Time Complexity: `O(log n)`.
 */
template <typename RandomIt, typename T, typename Comparator = std::less<T>>
  requires std::random_access_iterator<RandomIt>
RandomIt binary_search(RandomIt first,
                       RandomIt last,
                       const T& value,
                       Comparator comp = Comparator{});

/**
 * @brief  Algorithm that finds the first element
 *         that is not less than the value (with respect to comp).
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @param  comp function to compare two elements of type T.
 *         Is `std::less<T>()` by default.
 * @retval Iterator to the first element in [first, last) that
 *         is not less than value, or last if all elements are less than value.
 * @note   The sequence `[first, last)` is considered to be sorted
 *         with respect to `comp`.
 * @note   Time Complexity: `O(log n)`.
 */
template <typename RandomIt, typename T, typename Comparator = std::less<T>>
  requires std::random_access_iterator<RandomIt>
RandomIt lower_bound(RandomIt first,
                     RandomIt last,
                     const T& value,
                     Comparator comp = Comparator{});

/**
 * @brief  Algorithm that finds the first element
 *         that is greater than the value (with respect to comp).
 * @param  first iterator to the first element of sequence.
 * @param  last iterator to element behind the last to examine.
 * @param  value target element to find.
 * @param  comp function to compare two elements of type T.
 *         Is `std::less<T>()` by default.
 * @retval Iterator to the first element in [first, last) that
 *         is greater than value, or last
 *         if all elements are less than or equal to value.
 * @note   The sequence `[first, last)` is considered to be sorted
 *         with respect to `comp`.
 * @note   Time Complexity: `O(log n)`.
 */
template <typename RandomIt, typename T, typename Comparator = std::less<T>>
  requires std::random_access_iterator<RandomIt>
RandomIt upper_bound(RandomIt first,
                     RandomIt last,
                     const T& value,
                     Comparator comp = Comparator{});

}  // namespace ftm

#include <ftm/algorithm/search/impl/binary_search.ipp>
