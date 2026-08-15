#include <ftm/algorithm.hpp>
#include <vector>
#include <functional>
#include <catch2/catch_test_macros.hpp>

template <typename Search>
void testCommonScenarios(Search search) {
  SECTION("1. Sorted array")
  {
    std::vector<int> data = {-1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    auto it_begin  = search(data.begin(), data.end(), -1);
    auto it_middle = search(data.begin(), data.end(), 13);
    auto it_end    = search(data.begin(), data.end(), 89);

    REQUIRE(it_begin == data.begin());
    CHECK(*it_begin == -1);

    REQUIRE(it_middle != data.end());
    CHECK(*it_middle == 13);

    REQUIRE(it_end != data.end());
    CHECK(*it_end == 89);
  }

  SECTION("2. Try to find element that does not exist")
  {
    std::vector<int> data = {-1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    auto it_lower  = search(data.begin(), data.end(), -20);
    auto it_inside = search(data.begin(), data.end(), 7);
    auto it_upper  = search(data.begin(), data.end(), 100);
    
    CHECK(it_lower  == data.end());
    CHECK(it_inside == data.end());
    CHECK(it_upper  == data.end());
  }

  SECTION("3. Empty array")
  {
    std::vector<int> data;
    auto it = search(data.begin(), data.end(), 0);
    
    CHECK(it == data.end());
  }

  SECTION("4. Single element")
  {
    std::vector<int> data = {1337};
    auto it_found     = search(data.begin(), data.end(), 1337);
    auto it_not_found = search(data.begin(), data.end(), 1338);
    
    CHECK(it_found != data.end());
    CHECK(it_not_found == data.end());
  }

  SECTION("5. Duplicates")
  {
    std::vector<int> data1 = {2, 2, 2, 2, 2, 2, 2};
    std::vector<int> data2 = {66, 67, 68, 69, 69, 70, 71};
    auto it1 = search(data1.begin(), data1.end(), 2);
    auto it2 = search(data2.begin(), data2.end(), 69);
    
    REQUIRE(it1 != data1.end());
    CHECK(*it1 == 2);
    
    REQUIRE(it2 != data2.end());
    CHECK(*it2 == 69);
  }
}

template <typename Search>
void testCustomComparators(Search search) {
  SECTION("1. std::greater instead of std::less")
  {
    std::vector<int> data = {89, 55, 34, 21, 13, 8, 5, 3, 2, 1, -1};
    auto it_begin  = search(data.begin(), data.end(), 89, std::greater<int>());
    auto it_middle = search(data.begin(), data.end(), 13, std::greater<int>());
    auto it_end    = search(data.begin(), data.end(), -1, std::greater<int>());
    
    REQUIRE(it_begin == data.begin());
    CHECK(*it_begin == 89);
    
    REQUIRE(it_middle != data.end());
    CHECK(*it_middle == 13);
    
    REQUIRE(it_end != data.end());
    CHECK(*it_end == -1);
  }

  SECTION("2. Sorted by remainders of division by 2 (even first, then odd)")
  {
    // all even numbers are considered to be equal to one another
    // the same thing with odd numbers ( 4 == -2, 7 == 31, 6 < 1)
    std::vector<int> data1 = {-2, 4, 6, 4, 2, 7, -1, 3, 9, 1};
    std::vector<int> data2 = {1, 3, 5, 7, 9, 11};
    auto comp = [](int x, int y) {
      return x % 2 < y % 2;
    };
    auto it1 = search(data1.begin(), data1.end(), 4, comp);
    auto it2 = search(data2.begin(), data2.end(), 4, comp);
    
    REQUIRE(it1 != data1.end());
    CHECK(*it1 % 2 == 0);
    
    CHECK(it2 == data2.end());
  }

  SECTION("3. Sorted by the tens digit")
  {
    // Thus, 15 == 19, 73 == 71 and 123 < 34
    std::vector<int> data = {19, 227, 31, 542, 353, 969, 76, 283};
    auto comp = [](int x, int y) {
      return (x / 10 % 10) < (y / 10 % 10);
    };
    auto it_found     = search(data.begin(), data.end(), 340, comp);
    auto it_not_found = search(data.begin(), data.end(), 190, comp);
    
    REQUIRE(it_found != data.end());
    CHECK(*it_found == 542);
    
    CHECK(it_not_found == data.end());
  }
}

TEST_CASE("Linear search", "[search][linear]")
{
  SECTION("Basic scenarios")
  {
    testCommonScenarios([](auto first, auto last, const auto& value) {
        return ftm::linear_search(first, last, value);
    });
  }

  SECTION("Simple unsorted array")
  {
    std::vector<int> data = {3, 2, -1, 5, 27, 3, 333, 101};
    auto it_begin  = ftm::linear_search(data.begin(), data.end(), 3);
    auto it_middle = ftm::linear_search(data.begin(), data.end(), 27);
    auto it_end    = ftm::linear_search(data.begin(), data.end(), 101);
    
    REQUIRE(it_begin == data.begin());
    CHECK(*it_begin == 3);
    
    REQUIRE(it_middle != data.end());
    CHECK(*it_middle == 27);
    
    REQUIRE(it_end != data.end());
    CHECK(*it_end == 101);
  }
}

TEST_CASE("Jump search", "[search][jump]")
{
  SECTION("Basic scenarios")
  {
    testCommonScenarios([](auto first, auto last, const auto& value) {
        return ftm::jump_search(first, last, value);
    });
  }

  SECTION("Custom comparators")
  {
    testCustomComparators([](auto first, auto last, const auto& value, auto comp) {
      return ftm::jump_search(first, last, value, comp);
    });
  }

  SECTION("Custom jump size")
  {
    std::vector<int> data = {-10, 0, 11, 22, 33, 45, 56, 66, 83, 88};
    auto it1   = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 1);
    auto it5   = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 5);
    auto it10  = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 10);
    auto it100 = ftm::jump_search(data.begin(), data.end(), 11, std::less<int>(), 100);
    
    CHECK(it1 == it5);
    CHECK(it5 == it10);
    CHECK(it10 == it100);
    REQUIRE(it100 != data.end());
    CHECK(*it100 == 11);
  }
}

TEST_CASE("Binary search", "[search][binary]") 
{
  SECTION("Basic scenarios")
  {
    testCommonScenarios([](auto first, auto last, auto value) {
      return ftm::binary_search(first, last, value);
    });
  }

  SECTION("Custom comparators")
  {
    testCustomComparators([](auto first, auto last, const auto& value, auto comp) {
      return ftm::binary_search(first, last, value, comp);
    });
  }

  SECTION("Upper/lower bounds")
  {
    std::vector<int> data = {1, 1, 1, 2, 3, 4, 5, 5, 6, 6, 6};
    auto lower_it  = ftm::lower_bound(data.begin(), data.end(), 1);
    auto upper_it1 = ftm::upper_bound(data.begin(), data.end(), 1);
    auto upper_it2 = ftm::upper_bound(data.begin(), data.end(), 6);
    
    REQUIRE(lower_it == data.begin());
    CHECK(*lower_it == 1);
    
    REQUIRE(upper_it1 != data.end());
    CHECK(*upper_it1 == 2);
    
    CHECK(upper_it2 == data.end());
  }
}

TEST_CASE("Exponential search", "[search][exponential]") 
{
  SECTION("Basic scenarios")
  {
    testCommonScenarios([](auto first, auto last, auto value) {
      return ftm::exponential_search(first, last, value);
    });
  }

  SECTION("Custom comparators")
  {
    testCustomComparators([](auto first, auto last, const auto& value, auto comp) {
      return ftm::exponential_search(first, last, value, comp);
    });
  }
}

TEST_CASE("Interpolation search", "[search][interpolation]") {
  SECTION("Basic scenarios")
  {
    testCommonScenarios([](auto first, auto last, auto value) {
      return ftm::interpolation_search(first, last, value);
    });
  }
}