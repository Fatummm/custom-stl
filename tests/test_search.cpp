#include <ftm/algorithm.hpp>
#include <vector>
#include <cassert>

template <typename Search>
void testCommonScenarios(Search search) {
  // 1. Sorted array
  {
    std::vector<int> data = {-1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    [[maybe_unused]] auto it_begin  = search(data.begin(), data.end(), -1);
    [[maybe_unused]] auto it_middle = search(data.begin(), data.end(), 13);
    [[maybe_unused]] auto it_end    = search(data.begin(), data.end(), 89);
    assert(it_begin == data.begin() && *it_begin == -1);
    assert(it_middle != data.end() && *it_middle == 13);
    assert(it_end != data.end() && *it_end == 89);
  }

  // 2. Try to find element that does not exist
  {
    std::vector<int> data = {-1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    [[maybe_unused]] auto it_lower  = search(data.begin(), data.end(), -20);
    [[maybe_unused]] auto it_inside = search(data.begin(), data.end(), 7);
    [[maybe_unused]] auto it_upper  = search(data.begin(), data.end(), 100);
    assert(it_lower == data.end() && it_inside == data.end() && it_upper == data.end());
  }

  // 3. Empty array
  {
    std::vector<int> data;
    [[maybe_unused]] auto it = search(data.begin(), data.end(), 0);
    assert(it == data.end());
  }

  // 4. Single element
  {
    std::vector<int> data = {1337};
    [[maybe_unused]] auto it_found     = search(data.begin(), data.end(), 1337);
    [[maybe_unused]] auto it_not_found = search(data.begin(), data.end(), 1338);
    assert(it_found != data.end());
    assert(it_not_found == data.end());
  }

  // 5. Duplicates
  {
    std::vector<int> data1 = {2, 2, 2, 2, 2, 2, 2};
    std::vector<int> data2 = {66, 67, 68, 69, 69, 70, 71};
    [[maybe_unused]] auto it1 = search(data1.begin(), data1.end(), 2);
    [[maybe_unused]] auto it2 = search(data2.begin(), data2.end(), 69);
    assert(it1 != data1.end() && *it1 == 2);
    assert(it2 != data2.end() && *it2 == 69);
  }
}

template <typename Search>
void testCustomComparators(Search search) {
  // 1. std::greater instead of std::less
  {
    std::vector<int> data = {89, 55, 34, 21, 13, 8, 5, 3, 2, 1, -1};
    [[maybe_unused]] auto it_begin  = search(data.begin(), data.end(), 89, std::greater<int>());
    [[maybe_unused]] auto it_middle = search(data.begin(), data.end(), 13, std::greater<int>());
    [[maybe_unused]] auto it_end    = search(data.begin(), data.end(), -1, std::greater<int>());
    assert(it_begin == data.begin() && *it_begin == 89);
    assert(it_middle != data.end() && *it_middle == 13);
    assert(it_end != data.end() && *it_end == -1);
  }

  // 2. Sorted by remainders of division by 2 (even first, then odd)
  {
    // all even numbers are considered to be equal to one another
    // the same thing with odd numbers ( 4 == -2, 7 == 31, 6 < 1)
    std::vector<int> data1 = {-2, 4, 6, 4, 2, 7, -1, 3, 9, 1};
    std::vector<int> data2 = {1, 3, 5, 7, 9, 11};
    auto comp = [](int x, int y) {
      return x % 2 < y % 2;
    };
    [[maybe_unused]] auto it1 = search(data1.begin(), data1.end(), 4, comp);
    [[maybe_unused]] auto it2 = search(data2.begin(), data2.end(), 4, comp);
    assert(it1 != data1.end() && *it1 % 2 == 0);
    assert(it2 == data2.end());
  }

  // 3. Sorted by the tens digit
  {
    // Thus, 15 == 19, 73 == 71 and 123 < 34
    std::vector<int> data = {19, 227, 31, 542, 353, 969, 76, 283};
    auto comp = [](int x, int y) {
      return (x / 10 % 10) < (y / 10 % 10);
    };
    [[maybe_unused]] auto it_found     = search(data.begin(), data.end(), 340, comp);
    [[maybe_unused]] auto it_not_found = search(data.begin(), data.end(), 190, comp);
    assert(it_found != data.end() && *it_found == 542);
    assert(it_not_found == data.end());
  }
}

void testLinearSearch() {
  // 0. Basic scenarios
  testCommonScenarios([](auto first, auto last, const auto& value) {
        return ftm::linear_search(first, last, value);
    });
  
  // 1. Simple unsorted array
  {
    std::vector<int> data = {3, 2, -1, 5, 27, 3, 333, 101};
    [[maybe_unused]] auto it_begin  = ftm::linear_search(data.begin(), data.end(), 3);
    [[maybe_unused]] auto it_middle = ftm::linear_search(data.begin(), data.end(), 27);
    [[maybe_unused]] auto it_end    = ftm::linear_search(data.begin(), data.end(), 101);
    assert(it_begin == data.begin() && *it_begin == 3);
    assert(it_middle != data.end() && *it_middle == 27);
    assert(it_end != data.end() && *it_end == 101);
  }
}

void testJumpSearch() {
  // 01. Basic scenarios
  testCommonScenarios([](auto first, auto last, const auto& value) {
    return ftm::jump_search(first, last, value);
  });

  // 02. Custom comparators
  testCustomComparators([](auto first, auto last, const auto& value, auto comp) {
    return ftm::jump_search(first, last, value, comp);
  });

  // 1. Custom jump size
  {
    std::vector<int> data = {-10, 0, 11, 22, 33, 45, 56, 66, 83, 88};
    [[maybe_unused]] auto it1   = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 1);
    [[maybe_unused]] auto it5   = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 5);
    [[maybe_unused]] auto it10  = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 10);
    [[maybe_unused]] auto it100 = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 100);
    assert(it1 == it5 && it5 == it10 && it10 == it100 && *it100 == 11);
  }
}

void testBinarySearch() {
  // 01. Basic scenarios
  testCommonScenarios([](auto first, auto last, auto value) {
    return ftm::binary_search(first, last, value);
  });

  // 02. Custom comparators
  testCustomComparators([](auto first, auto last, const auto& value, auto comp) {
    return ftm::binary_search(first, last, value, comp);
  });

  // 1. Upper/lower bounds
  {
    std::vector<int> data = {1, 1, 1, 2, 3, 4, 5, 5, 6, 6, 6};
    [[maybe_unused]] auto lower_it  = ftm::lower_bound(data.begin(), data.end(), 1);
    [[maybe_unused]] auto upper_it1 = ftm::upper_bound(data.begin(), data.end(), 1);
    [[maybe_unused]] auto upper_it2 = ftm::upper_bound(data.begin(), data.end(), 6);
    assert(lower_it == data.begin() && *lower_it == 1);
    assert(upper_it1 != data.end() && *upper_it1 == 2);
    assert(upper_it2 == data.end());
  }
}

void testExponentialSearch() {
  // 01. Basic scenarios
  testCommonScenarios([](auto first, auto last, auto value) {
    return ftm::exponential_search(first, last, value);
  });

  // 02. Custom comparators
  testCustomComparators([](auto first, auto last, const auto& value, auto comp) {
    return ftm::exponential_search(first, last, value, comp);
  });
}

void testInterpolationSearch() {
  // 0. Basic scenarios
  testCommonScenarios([](auto first, auto last, auto value) {
    return ftm::interpolation_search(first, last, value);
  });
}