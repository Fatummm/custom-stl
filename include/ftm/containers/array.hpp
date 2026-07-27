#pragma once
#include <cstddef>
#include <iterator>

namespace ftm {

template <typename T, std::size_t Size>
class array {
public:
  using value_type             = T;
  using size_type              = std::size_t;
  using difference_type        = std::ptrdiff_t;
  using reference              = value_type&;
  using const_reference        = const value_type&;
  using pointer                = value_type*;
  using const_pointer          = const value_type*;
  using reverse_iterator       = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<iterator>;
  
  // element access
  reference at(size_t);
  const_reference at(size_t) const;
  
  reference operator[](size_t);
  const_reference operator[](size_t) const noexcept;
  
  reference front();
  const_reference front() const;
  
  reference back();
  const_reference back() const;
  
  pointer data();
  const_pointer data() const;

  // capacity
  constexpr bool empty() const noexcept;
  constexpr size_type size() const noexcept;
  constexpr size_type max_size() const noexcept;

  // iterators
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  const_iterator cbegin() const noexcept;
  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;
  const_reverse_iterator crbegin() const noexcept;

  iterator end() noexcept;
  const_iterator end() const noexcept;
  const_iterator cend() const noexcept;
  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;
  const_reverse_iterator() crend() const noexcept;

  // iterator class
  class iterator {
  public:
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = T&;
    using pointer           = T*;
    using iterator_category = std::random_access_iterator_tag;

    iterator();
    explicit iterator(pointer p);

    reference operator*() const;
    pointer operator->() const;
    reference operator[](difference_type)

    iterator& operator++();
    iterator operator++(int);

    iterator& operator--();
    iterator operator--(int);

    iterator& operator+=(difference_type);
    iterator& operator-=(difference_type);

    iterator operator+(difference_type) const;
    iterator operator-(difference_type) const;

    difference_type operator-(const iterator&) const;

    bool operator==(const iterator&);
    bool operator!=(const iterator&);
    bool operator<(const iterator&);
    bool operator>(const iterator&);
    bool operator<=(const iterator&);
    bool operator>=(const iterator&);
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

    const_iterator();
    explicit const_iterator(const_pointer);
    const_iterator(const iterator&);

    const_reference operator*() const;
    const_pointer operator->() const;
    const_reference operator[](difference_type) const;

    const_iterator& operator++();
    const_iterator operator++(int);

    const_iterator& operator--();
    const_iterator operator--(int);

    const_iterator& operator+=(difference_type);
    const_iterator& operator-=(difference_type);

    const_iterator operator+(difference_type);
    const_iterator operator-(difference_type);

    difference_type operator-(const iterator&);

    bool operator==(const const_iterator&);
    bool operator!=(const const_iterator&);
    bool operator<(const const_iterator&);
    bool operator>(const const_iterator&);
    bool operator<=(const const_iterator&);
    bool operator>=(const const_iterator&);
  private:
    const_pointer ptr_;
  };
private:
  T arr_[Size];
};

template <typename T, std::size_t Size>
typename array<T, Size>::iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::iterator it
);

template <typename T, std::size_t Size>
typename array<T, Size>::const_iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::const_iterator it
);

} /* ftm */

#include <ftm/containers/impl/array.ipp>
