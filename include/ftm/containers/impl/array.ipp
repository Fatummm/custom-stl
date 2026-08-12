#include <cstddef>
#include <iterator>
#include <exception>

namespace ftm {
 
template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::reference array<T, Size>::at(std::size_t idx) 
{
  if (idx >= Size) {
    throw std::out_of_range("Array index out of range");
  }
  return arr_[idx];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::const_reference array<T, Size>::at(std::size_t idx) const
{
  if (idx >= Size) {
    throw std::out_of_range("Array index out of range");
  }
  return arr_[idx];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::reference array<T, Size>::operator[](std::size_t idx) noexcept
{
  return arr_[idx];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::const_reference 
  array<T, Size>::operator[](std::size_t idx) const noexcept
{
  return arr_[idx];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::reference array<T, Size>::front()
{
  return arr_[0];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::const_reference array<T, Size>::front() const
{
  return arr_[0];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::reference array<T, Size>::back()
{
  return arr_[static_cast<std::size_t>(Size - 1)];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::const_reference array<T, Size>::back() const
{
  return arr_[static_cast<std::size_t>(Size - 1)];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::pointer array<T, Size>::data() noexcept
{
  return arr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
array<T, Size>::const_pointer array<T, Size>::data() const noexcept
{
  return arr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::empty() const noexcept
{
  return Size == static_cast<std::size_t>(0);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::size_type array<T, Size>::size() const noexcept
{
  return Size;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::size_type array<T, Size>::max_size() const noexcept
{
  return Size;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator array<T, Size>::begin() noexcept
{
  return iterator(arr_);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::begin() const noexcept
{
  return cbegin();
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::cbegin() const noexcept
{
  return const_iterator(arr_);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::reverse_iterator array<T, Size>::rbegin() noexcept
{
  return std::make_reverse_iterator(end());
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_reverse_iterator array<T, Size>::rbegin() const noexcept
{
  return crbegin();
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_reverse_iterator array<T, Size>::crbegin() const noexcept
{
  return std::make_reverse_iterator(cend());
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator array<T, Size>::end() noexcept
{
  return iterator(arr_ + Size);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::end() const noexcept
{
  return cend();
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::cend() const noexcept
{
  return const_iterator(arr_ + Size);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::reverse_iterator array<T, Size>::rend() noexcept
{
  return std::make_reverse_iterator(begin());
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_reverse_iterator array<T, Size>::rend() const noexcept
{
  return std::make_reverse_iterator(cbegin());
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_reverse_iterator array<T, Size>::crend() const noexcept
{
  return std::make_reverse_iterator(cbegin());
}

} /* ftm */