#include <cstddef>

namespace ftm {

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator::const_iterator()
  : ptr_(nullptr) 
{

}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator::const_iterator(const_pointer p)
  : ptr_(p) 
{

}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator::const_iterator(const iterator& it)
  : ptr_(it.operator->())
{
  
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_reference 
  array<T, Size>::const_iterator::operator*() const
{
  return *ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_pointer 
  array<T, Size>::const_iterator::operator->() const
{
  return ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_reference
  array<T, Size>::const_iterator::operator[]
(
  difference_type n
) const
{
  return ptr_[n];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator& array<T, Size>::const_iterator::operator++()
{
  ++ptr_;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::const_iterator::operator++(int)
{
  const_iterator tmp(ptr_);
  ++ptr_;
  return tmp;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator& array<T, Size>::const_iterator::operator--()
{
  --ptr_;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::const_iterator::operator--(int)
{
  const_iterator tmp(ptr_);
  --ptr_;
  return tmp;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator& array<T, Size>::const_iterator::operator+=(
  difference_type n
)
{
  ptr_ += n;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator& array<T, Size>::const_iterator::operator-=(
  difference_type n
)
{
  ptr_ -= n;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::const_iterator::operator+(
  difference_type n
) const
{
  return const_iterator(ptr_ + n);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::const_iterator it
)
{
  return it.operator+(n);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator array<T, Size>::const_iterator::operator-(
  difference_type n
) const
{
  return const_iterator(ptr_ - n);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator::difference_type 
  array<T, Size>::const_iterator::operator-
(
  const const_iterator& other
) const
{
  return static_cast<difference_type>(ptr_ - other.ptr_);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::const_iterator::operator==(const const_iterator& other) const
{
  return ptr_ == other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::const_iterator::operator!=(const const_iterator& other) const
{
  return ptr_ != other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::const_iterator::operator<(const const_iterator& other) const
{
  return ptr_ < other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::const_iterator::operator>(const const_iterator& other) const
{
  return ptr_ > other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::const_iterator::operator<=(const const_iterator& other) const
{
  return ptr_ <= other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::const_iterator::operator>=(const const_iterator& other) const
{
  return ptr_ >= other.ptr_;
}

} /* ftm */