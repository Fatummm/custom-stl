#include <ftm/containers/array.hpp>
#include <random>
#include <chrono>
#include <catch2/catch_test_macros.hpp>

std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

using ftm::array;

template <std::size_t Size>
void testCapacity() 
{
  array<int, Size>   arr1 = {};
  array<float, Size> arr2 = {};
  array<char, Size>  arr3 = {};
  
  CHECK(arr1.size() == Size);
  CHECK(arr2.size() == Size);
  CHECK(arr3.size() == Size);

  CHECK(arr1.empty() == false);
  CHECK(arr2.empty() == false);
  CHECK(arr3.empty() == false);

  CHECK(arr1.max_size() == Size);
  CHECK(arr2.max_size() == Size);
  CHECK(arr3.max_size() == Size);
}

template <std::size_t Size>
void testDataAccess() 
{
  SECTION("at(...)")
  {
    array<int, Size> arr = {};

    // check out_of_range case
    try {
      arr.at(Size + 1);
      CHECK(false);
    } catch (std::out_of_range& e) {}

    // assignment
    for (std::size_t i = 0; i < Size; ++i) {
      arr.at(i) = static_cast<int>(i);
      CHECK(arr[i] == static_cast<int>(i));
    }
  }

  SECTION("operator[](...)")
  {
    array<int, Size> arr = {};
    // assignment
    for (std::size_t i = 0; i < Size; ++i) {
      arr[i] = static_cast<int>(i);
      CHECK(arr[i] == static_cast<int>(i));
    }
  }

  SECTION("front(...), back(...)")
  {
    array<int, Size> arr = {1};
    CHECK(arr.front() == 1);
    arr.front() = -5;
    CHECK(arr.front() == -5);
    arr.back() = rnd() % 1'000'000;
    CHECK(arr[Size - 1] == arr.back());
  }

  SECTION("data(...)")
  {
    array<int, Size> arr = {};
    for (std::size_t i = 0; i < Size; ++i) {
      arr[i] = rnd() % 1'000'000;
    }
    auto data = arr.data();
    for (std::size_t i = 0; i < Size; ++i) {
      // test synchronization
      CHECK(data[i] == arr[i]);
      data[i] = -1;
      CHECK(arr[i] == -1);
    }
  }
}

template <std::size_t Size>
void testIterators() 
{
  array<int, Size> arr;
  // fill the array with random numbers
  for (std::size_t i = 0; i < Size; ++i) {
    arr[i] = rnd() % 1'000'000;
  }

  SECTION("begin(...), end(...), cbegin(...), cend(...)")
  {
    typename array<int, Size>::iterator it = arr.begin();
    typename array<int, Size>::const_iterator cit = arr.cbegin();
    std::size_t idx = 0;

    // Assert assignment
    CHECK(it == arr.begin());
    CHECK(cit == arr.cbegin());
    
    for (;idx < Size;) {
      CHECK(*it == arr[idx]);
      CHECK(*cit == arr[idx]);
      ++idx;
      ++it;
      ++cit;
    }
    CHECK(it == arr.end());
    CHECK(cit == arr.cend());
    
    // Try to find element that doesn't exist
    auto it1 = std::find(arr.begin(), arr.end(), -1);
    auto it2 = std::find(arr.cbegin(), arr.cend(), -1);

    CHECK(it1 == arr.end());
    CHECK(it2 == arr.cend());

    // Try to find the first element
    auto it3 = std::find(arr.begin(), arr.end(), arr.front());
    auto it4 = std::find(arr.cbegin(), arr.cend(), arr.front());
    CHECK(it3 == arr.begin());
    CHECK(it4 == arr.cbegin());
  }

  SECTION("rbegin(...), rend(...), crbegin(...), crend(...)")
  {
    typename array<int, Size>::reverse_iterator it = arr.rbegin();
    typename array<int, Size>::const_reverse_iterator cit = arr.crbegin();
    std::size_t idx = 0;

    // Assert assignment
    CHECK(it == arr.rbegin());
    CHECK(cit == arr.crbegin());
    
    for (;idx < Size;) {
      CHECK(*it == arr[idx]);
      CHECK(*cit == arr[idx]);
      ++idx;
      ++it;
      ++cit;
    }
    CHECK(it == arr.rend());
    CHECK(cit == arr.crend());
    
    // Try to find element that doesn't exist
    auto it1 = std::find(arr.rbegin(), arr.rend(), -1);
    auto it2 = std::find(arr.crbegin(), arr.crend(), -1);

    CHECK(it1 == arr.rend());
    CHECK(it2 == arr.crend());

    // Try to find the first element
    auto it3 = std::find(arr.rbegin(), arr.rend(), arr.front());
    auto it4 = std::find(arr.crbegin(), arr.crend(), arr.front());
    CHECK(it3 == arr.rbegin());
    CHECK(it4 == arr.crbegin());
  }
}

TEST_CASE("Array capacity methods", "[array][capacity]")
{
  testCapacity<1>();
  testCapacity<100>();
  testCapacity<100'000>();
}

TEST_CASE("Array data access methods", "[array][data]")
{
  testDataAccess<1>();
  testDataAccess<100>();
  testDataAccess<100'000>();
}

TEST_CASE("Array iterators methods", "[array][iterators]")
{
  testIterators<1>();
  testIterators<100>();
  testIterators<100'000>();
}