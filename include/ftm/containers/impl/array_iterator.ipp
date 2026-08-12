#include <cstddef>
namespace ftm {

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator::iterator()
  : ptr_(nullptr) 
{

}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator::iterator(iterator::pointer p)
  : ptr_(p) 
{

}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator::reference array<T, Size>::iterator::operator*() const
{
  return *ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator::pointer array<T, Size>::iterator::operator->() const
{
  return ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator::reference array<T, Size>::iterator::operator[](
  difference_type n
) const
{
  return ptr_[n];
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator& array<T, Size>::iterator::operator++()
{
  ++ptr_;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator array<T, Size>::iterator::operator++(int)
{
  iterator tmp(ptr_);
  ++ptr_;
  return tmp;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator& array<T, Size>::iterator::operator--()
{
  --ptr_;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator array<T, Size>::iterator::operator--(int)
{
  iterator tmp(ptr_);
  --ptr_;
  return tmp;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator& array<T, Size>::iterator::operator+=(
  iterator::difference_type n
)
{
  ptr_ += n;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator& array<T, Size>::iterator::operator-=(
  iterator::difference_type n
)
{
  ptr_ -= n;
  return *this;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator array<T, Size>::iterator::operator+(
  iterator::difference_type n
) const
{
  return iterator(ptr_ + n);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::iterator it
)
{
  return it.operator+(n);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator array<T, Size>::iterator::operator-(
  iterator::difference_type n
) const
{
  return iterator(ptr_ - n);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator::difference_type array<T, Size>::iterator::operator-(
  const iterator& other
) const
{
  return static_cast<difference_type>(ptr_ - other.ptr_);
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::iterator::operator==(const iterator& other) const
{
  return ptr_ == other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::iterator::operator!=(const iterator& other) const
{
  return ptr_ != other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::iterator::operator<(const iterator& other) const
{
  return ptr_ < other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::iterator::operator>(const iterator& other) const
{
  return ptr_ > other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::iterator::operator<=(const iterator& other) const
{
  return ptr_ <= other.ptr_;
}

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr bool array<T, Size>::iterator::operator>=(const iterator& other) const
{
  return ptr_ >= other.ptr_;
}

} /* ftm */