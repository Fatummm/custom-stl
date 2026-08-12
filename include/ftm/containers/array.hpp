#pragma once
#include <cstddef>
#include <iterator>

namespace ftm {

template <std::size_t N>
concept NotZero = N != 0; 

template <typename T, std::size_t Size>
requires NotZero<Size>
class array {
public:
  class iterator;
  class const_iterator;
  using value_type             = T;
  using size_type              = std::size_t;
  using difference_type        = std::ptrdiff_t;
  using reference              = value_type&;
  using const_reference        = const value_type&;
  using pointer                = value_type*;
  using const_pointer          = const value_type*;
  using reverse_iterator       = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  // element access
  reference at(std::size_t);
  const_reference at(std::size_t) const;
  
  reference operator[](std::size_t) noexcept;
  const_reference operator[](std::size_t) const noexcept;
  
  reference front();
  const_reference front() const;
  
  reference back();
  const_reference back() const;
  
  pointer data() noexcept;
  const_pointer data() const noexcept;

  // capacity
  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;

  // iterators
  constexpr iterator begin() noexcept;
  constexpr const_iterator begin() const noexcept;
  constexpr const_iterator cbegin() const noexcept;
  constexpr reverse_iterator rbegin() noexcept;
  constexpr const_reverse_iterator rbegin() const noexcept;
  constexpr const_reverse_iterator crbegin() const noexcept;

  constexpr iterator end() noexcept;
  constexpr const_iterator end() const noexcept;
  constexpr const_iterator cend() const noexcept;
  constexpr reverse_iterator rend() noexcept;
  constexpr const_reverse_iterator rend() const noexcept;
  constexpr const_reverse_iterator crend() const noexcept;

  // iterator class
  class iterator {
  public:
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = T&;
    using pointer           = T*;
    using iterator_category = std::random_access_iterator_tag;

    constexpr iterator();
    constexpr explicit iterator(pointer);

    constexpr reference operator*() const;
    constexpr pointer operator->() const;
    constexpr reference operator[](difference_type) const;

    constexpr iterator& operator++();
    constexpr iterator operator++(int);

    constexpr iterator& operator--();
    constexpr iterator operator--(int);

    constexpr iterator& operator+=(difference_type);
    constexpr iterator& operator-=(difference_type);

    constexpr iterator operator+(difference_type) const;
    constexpr iterator operator-(difference_type) const;

    constexpr difference_type operator-(const iterator&) const;

    constexpr bool operator==(const iterator&) const;
    constexpr bool operator!=(const iterator&) const;
    constexpr bool operator<(const iterator&) const;
    constexpr bool operator>(const iterator&) const;
    constexpr bool operator<=(const iterator&) const;
    constexpr bool operator>=(const iterator&) const;
  private:
    pointer ptr_;
  };
  
  // const_iterator class
  class const_iterator {
  public:
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = const T&;
    using pointer           = const T*;
    using iterator_category = std::random_access_iterator_tag;

    constexpr const_iterator();
    constexpr explicit const_iterator(const_pointer);
    constexpr const_iterator(const iterator&);

    constexpr const_reference operator*() const;
    constexpr const_pointer operator->() const;
    constexpr const_reference operator[](difference_type) const;

    constexpr const_iterator& operator++();
    constexpr const_iterator operator++(int);

    constexpr const_iterator& operator--();
    constexpr const_iterator operator--(int);

    constexpr const_iterator& operator+=(difference_type);
    constexpr const_iterator& operator-=(difference_type);

    constexpr const_iterator operator+(difference_type) const;
    constexpr const_iterator operator-(difference_type) const ;

    constexpr difference_type operator-(const const_iterator&) const;

    constexpr bool operator==(const const_iterator&) const;
    constexpr bool operator!=(const const_iterator&) const;
    constexpr bool operator<(const const_iterator&) const;
    constexpr bool operator>(const const_iterator&) const;
    constexpr bool operator<=(const const_iterator&) const;
    constexpr bool operator>=(const const_iterator&) const;
  private:
    const_pointer ptr_;
  };
  
  T arr_[Size];
};

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::iterator it
);

template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::const_iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::const_iterator it
);

} /* ftm */

#include <ftm/containers/impl/array.ipp>
#include <ftm/containers/impl/array_iterator.ipp>
#include <ftm/containers/impl/array_const_iterator.ipp>
