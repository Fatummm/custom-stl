#include <iterator>

namespace ftm {

template <typename RandomIt, typename T, typename Comparator>
  requires std::random_access_iterator<RandomIt>
RandomIt binary_search(RandomIt first,
                       RandomIt last,
                       const T& value,
                       Comparator comp)
{
  size_t dist = static_cast<size_t>(std::distance(first, last));

  if (dist == 0) return last;

  size_t l = 0;
  size_t r = dist;
  size_t m;
  RandomIt mid_it;
  // [l, r)
  while (r > l) {
    m = (r - l) / 2 + l;
    mid_it = first + m;
    if (comp(*mid_it, value)) {
      l = m + 1;
    } else if (comp(value, *mid_it)) {
      r = m;
    } else {
      return mid_it;
    }
  }
  return last;
}

template <typename RandomIt, typename T, typename Comparator>
  requires std::random_access_iterator<RandomIt>
RandomIt lower_bound(RandomIt first,
                     RandomIt last,
                     const T& value,
                     Comparator comp)
{
  size_t dist = static_cast<size_t>(std::distance(first, last));

  if (dist == 0) return last;

  size_t l = 0;
  size_t r = dist;
  size_t m;

  while (r > l) {
    m = (r - l) / 2 + l;
    if (comp(*std::next(first, m), value)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return std::next(first, l);
}

template <typename RandomIt, typename T, typename Comparator>
  requires std::random_access_iterator<RandomIt>
RandomIt upper_bound(RandomIt first,
                     RandomIt last,
                     const T& value,
                     Comparator comp)
{
  size_t dist = static_cast<size_t>(std::distance(first, last));

  if (dist == 0) return last;

  size_t l = 0;
  size_t r = dist;
  size_t m;

  while (r > l) {
    m = (r - l) / 2 + l;
    if (comp(value, *std::next(first, m))) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return std::next(first, l);
}

}  // namespace ftm