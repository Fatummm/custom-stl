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

  /**
   * @brief  Returns a reference to the element at the specified index with bounds checking.
   * @param  pos position of the element to return.
   * @retval Reference to the requested element.
   * @note   Throws std::out_of_range if pos is out of bounds.
   */
  reference at(std::size_t pos);

  /**
   * @brief  Returns a constant reference to the element at the specified index with bounds checking.
   * @param  pos position of the element to return.
   * @retval Constant reference to the requested element.
   * @note   Throws std::out_of_range if pos is out of bounds.
   */
  const_reference at(std::size_t pos) const;
  
  /**
   * @brief  Accesses the element at the specified index without bounds checking.
   * @param  pos position of the element to return.
   * @retval Reference to the requested element.
   */
  reference operator[](std::size_t pos) noexcept;

  /**
   * @brief  Accesses the element at the specified index without bounds checking.
   * @param  pos position of the element to return.
   * @retval Constant reference to the requested element.
   */
  const_reference operator[](std::size_t pos) const noexcept;
  
  /**
   * @brief  Returns a reference to the first element in the array.
   * @param  None
   * @retval Reference to the first element.
   */
  reference front();

  /**
   * @brief  Returns a constant reference to the first element in the array.
   * @param  None
   * @retval Constant reference to the first element.
   */
  const_reference front() const;
  
  /**
   * @brief  Returns a reference to the last element in the array.
   * @param  None
   * @retval Reference to the last element.
   */
  reference back();

  /**
   * @brief  Returns a constant reference to the last element in the array.
   * @param  None
   * @retval Constant reference to the last element.
   */
  const_reference back() const;
  
  /**
   * @brief  Returns a direct pointer to the underlying memory array.
   * @param  None
   * @retval Pointer to the underlying element storage.
   */
  pointer data() noexcept;

  /**
   * @brief  Returns a constant direct pointer to the underlying memory array.
   * @param  None
   * @retval Constant pointer to the underlying element storage.
   */
  const_pointer data() const noexcept;

  /**
   * @brief  Checks whether the array container is empty.
   * @param  None
   * @retval Returns true if the array is empty, false otherwise.
   * @note   Fixed-size array with Size > 0 is never empty, always returns false.
   */
  constexpr bool empty() const noexcept;

  /**
   * @brief  Returns the number of elements in the array.
   * @param  None
   * @retval The number of elements in the array container.
   */
  constexpr size_type size() const noexcept;

  /**
   * @brief  Returns the maximum possible number of elements the array can hold.
   * @param  None
   * @retval Maximum number of elements.
   * @note   Always equals size().
   */
  constexpr size_type max_size() const noexcept;

  /**
   * @brief  Returns an iterator to the first element of the array.
   * @param  None
   * @retval Iterator to the initial element.
   */
  constexpr iterator begin() noexcept;

  /**
   * @brief  Returns a constant iterator to the first element of the array.
   * @param  None
   * @retval Constant iterator to the initial element.
   */
  constexpr const_iterator begin() const noexcept;

  /**
   * @brief  Returns a constant iterator to the first element of the array.
   * @param  None
   * @retval Constant iterator to the initial element.
   */
  constexpr const_iterator cbegin() const noexcept;

  /**
   * @brief  Returns a reverse iterator to the first element of the reversed array.
   * @param  None
   * @retval Reverse iterator to the last element of the array.
   */
  constexpr reverse_iterator rbegin() noexcept;

  /**
   * @brief  Returns a constant reverse iterator to the first element of the reversed array.
   * @param  None
   * @retval Constant reverse iterator to the last element of the array.
   */
  constexpr const_reverse_iterator rbegin() const noexcept;

  /**
   * @brief  Returns a constant reverse iterator to the first element of the reversed array.
   * @param  None
   * @retval Constant reverse iterator to the last element of the array.
   */
  constexpr const_reverse_iterator crbegin() const noexcept;

  /**
   * @brief  Returns an iterator to the element following the last element of the array.
   * @param  None
   * @retval Iterator to the element past the end.
   * @note   Dereferencing this iterator causes undefined behavior.
   */
  constexpr iterator end() noexcept;

  /**
   * @brief  Returns a constant iterator to the element following the last element of the array.
   * @param  None
   * @retval Constant iterator to the element past the end.
   * @note   Dereferencing this iterator causes undefined behavior.
   */
  constexpr const_iterator end() const noexcept;

  /**
   * @brief  Returns a constant iterator to the element following the last element of the array.
   * @param  None
   * @retval Constant iterator to the element past the end.
   * @note   Dereferencing this iterator causes undefined behavior.
   */
  constexpr const_iterator cend() const noexcept;

  /**
   * @brief  Returns a reverse iterator to the element following the last element of the reversed array.
   * @param  None
   * @retval Reverse iterator pointing before the first element.
   * @note   Dereferencing this iterator causes undefined behavior.
   */
  constexpr reverse_iterator rend() noexcept;

  /**
   * @brief  Returns a constant reverse iterator to the element following the last element of the reversed array.
   * @param  None
   * @retval Constant reverse iterator pointing before the first element.
   * @note   Dereferencing this iterator causes undefined behavior.
   */
  constexpr const_reverse_iterator rend() const noexcept;

  /**
   * @brief  Returns a constant reverse iterator to the element following the last element of the reversed array.
   * @param  None
   * @retval Constant reverse iterator pointing before the first element.
   * @note   Dereferencing this iterator causes undefined behavior.
   */
  constexpr const_reverse_iterator crend() const noexcept;

  class iterator {
  public:
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = T&;
    using pointer           = T*;
    using iterator_category = std::random_access_iterator_tag;

    /**
     * @brief  Constructs a default uninitialized or null iterator.
     * @param  None
     * @retval None
     */
    constexpr iterator();

    /**
     * @brief  Constructs an iterator pointing to the given element.
     * @param  ptr pointer to an element.
     * @retval None
     */
    constexpr explicit iterator(pointer ptr);

    /**
     * @brief  Dereferences the iterator to access the underlying element.
     * @param  None
     * @retval Reference to the pointed-to element.
     */
    constexpr reference operator*() const;

    /**
     * @brief  Provides member access to the underlying element through pointer semantics.
     * @param  None
     * @retval Pointer to the element.
     */
    constexpr pointer operator->() const;

    /**
     * @brief  Accesses an element at a given offset relative to the iterator.
     * @param  n offset from the current iterator.
     * @retval Reference to the element at the offset.
     */
    constexpr reference operator[](difference_type n) const;

    /**
     * @brief  Advances the iterator to the next element (prefix increment).
     * @param  None
     * @retval Reference to the updated iterator.
     */
    constexpr iterator& operator++();

    /**
     * @brief  Advances the iterator to the next element (postfix increment).
     * @param  None
     * @retval Copy of the iterator prior to incrementing.
     */
    constexpr iterator operator++(int);

    /**
     * @brief  Decrements the iterator to the previous element (prefix decrement).
     * @param  None
     * @retval Reference to the updated iterator.
     */
    constexpr iterator& operator--();

    /**
     * @brief  Decrements the iterator to the previous element (postfix decrement).
     * @param  None
     * @retval Copy of the iterator prior to decrementing.
     */
    constexpr iterator operator--(int);

    /**
     * @brief  Advances the iterator by the specified distance in-place.
     * @param  n number of positions to advance.
     * @retval Reference to the current iterator.
     */
    constexpr iterator& operator+=(difference_type n);

    /**
     * @brief  Moves the iterator backward by the specified distance in-place.
     * @param  n number of positions to move back.
     * @retval Reference to the current iterator.
     */
    constexpr iterator& operator-=(difference_type n);

    /**
     * @brief  Calculates a new iterator advanced by the given distance.
     * @param  n number of positions to advance.
     * @retval New iterator advanced by n elements.
     */
    constexpr iterator operator+(difference_type n) const;

    /**
     * @brief  Calculates a new iterator moved back by the given distance.
     * @param  n number of positions to move back.
     * @retval New iterator moved back by n elements.
     */
    constexpr iterator operator-(difference_type n) const;

    /**
     * @brief  Calculates the distance between two iterators.
     * @param  other the iterator to subtract.
     * @retval The difference between iterator positions.
     */
    constexpr difference_type operator-(const iterator& other) const;

    /**
     * @brief  Compares two iterators for equality.
     * @param  other the iterator to compare against.
     * @retval Returns true if both iterators point to the same element, false otherwise.
     */
    constexpr bool operator==(const iterator& other) const;

    /**
     * @brief  Compares two iterators for inequality.
     * @param  other the iterator to compare against.
     * @retval Returns true if iterators point to different elements, false otherwise.
     */
    constexpr bool operator!=(const iterator& other) const;

    /**
     * @brief  Checks if the current iterator precedes another iterator.
     * @param  other the iterator to compare against.
     * @retval Returns true if the current iterator points to an earlier position, false otherwise.
     */
    constexpr bool operator<(const iterator& other) const;

    /**
     * @brief  Checks if the current iterator succeeds another iterator.
     * @param  other the iterator to compare against.
     * @retval Returns true if the current iterator points to a later position, false otherwise.
     */
    constexpr bool operator>(const iterator& other) const;

    /**
     * @brief  Checks if the current iterator precedes or equals another iterator.
     * @param  other the iterator to compare against.
     * @retval Returns true if the position is earlier than or equal to other, false otherwise.
     */
    constexpr bool operator<=(const iterator& other) const;

    /**
     * @brief  Checks if the current iterator succeeds or equals another iterator.
     * @param  other the iterator to compare against.
     * @retval Returns true if the position is later than or equal to other, false otherwise.
     */
    constexpr bool operator>=(const iterator& other) const;
  private:
    pointer ptr_;
  };
  
  class const_iterator {
  public:
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using reference         = const T&;
    using pointer           = const T*;
    using iterator_category = std::random_access_iterator_tag;

    /**
     * @brief  Constructs a default uninitialized or null constant iterator.
     * @param  None
     * @retval None
     */
    constexpr const_iterator();

    /**
     * @brief  Constructs a constant iterator pointing to the given element.
     * @param  ptr constant pointer to an element.
     * @retval None
     */
    constexpr explicit const_iterator(const_pointer ptr);

    /**
     * @brief  Converts a non-constant iterator into a constant iterator.
     * @param  other non-constant iterator to convert.
     * @retval None
     */
    constexpr const_iterator(const iterator& other);

    /**
     * @brief  Dereferences the constant iterator to access the underlying element.
     * @param  None
     * @retval Constant reference to the pointed-to element.
     */
    constexpr const_reference operator*() const;

    /**
     * @brief  Provides member access to the underlying element through constant pointer semantics.
     * @param  None
     * @retval Constant pointer to the element.
     */
    constexpr const_pointer operator->() const;

    /**
     * @brief  Accesses an element at a given offset relative to the constant iterator.
     * @param  n offset from the current iterator.
     * @retval Constant reference to the element at the offset.
     */
    constexpr const_reference operator[](difference_type n) const;

    /**
     * @brief  Advances the constant iterator to the next element (prefix increment).
     * @param  None
     * @retval Reference to the updated iterator.
     */
    constexpr const_iterator& operator++();

    /**
     * @brief  Advances the constant iterator to the next element (postfix increment).
     * @param  None
     * @retval Copy of the iterator prior to incrementing.
     */
    constexpr const_iterator operator++(int);

    /**
     * @brief  Decrements the constant iterator to the previous element (prefix decrement).
     * @param  None
     * @retval Reference to the updated iterator.
     */
    constexpr const_iterator& operator--();

    /**
     * @brief  Decrements the constant iterator to the previous element (postfix decrement).
     * @param  None
     * @retval Copy of the iterator prior to decrementing.
     */
    constexpr const_iterator operator--(int);

    /**
     * @brief  Advances the constant iterator by the specified distance in-place.
     * @param  n number of positions to advance.
     * @retval Reference to the current iterator.
     */
    constexpr const_iterator& operator+=(difference_type n);

    /**
     * @brief  Moves the constant iterator backward by the specified distance in-place.
     * @param  n number of positions to move back.
     * @retval Reference to the current iterator.
     */
    constexpr const_iterator& operator-=(difference_type n);

    /**
     * @brief  Calculates a new constant iterator advanced by the given distance.
     * @param  n number of positions to advance.
     * @retval New constant iterator advanced by n elements.
     */
    constexpr const_iterator operator+(difference_type n) const;

    /**
     * @brief  Calculates a new constant iterator moved back by the given distance.
     * @param  n number of positions to move back.
     * @retval New constant iterator moved back by n elements.
     */
    constexpr const_iterator operator-(difference_type n) const;

    /**
     * @brief  Calculates the distance between two constant iterators.
     * @param  other the constant iterator to subtract.
     * @retval The difference between iterator positions.
     */
    constexpr difference_type operator-(const const_iterator& other) const;

    /**
     * @brief  Compares two constant iterators for equality.
     * @param  other the constant iterator to compare against.
     * @retval Returns true if both iterators point to the same element, false otherwise.
     */
    constexpr bool operator==(const const_iterator& other) const;

    /**
     * @brief  Compares two constant iterators for inequality.
     * @param  other the constant iterator to compare against.
     * @retval Returns true if iterators point to different elements, false otherwise.
     */
    constexpr bool operator!=(const const_iterator& other) const;

    /**
     * @brief  Checks if the current constant iterator precedes another iterator.
     * @param  other the constant iterator to compare against.
     * @retval Returns true if the current iterator points to an earlier position, false otherwise.
     */
    constexpr bool operator<(const const_iterator& other) const;

    /**
     * @brief  Checks if the current constant iterator succeeds another iterator.
     * @param  other the constant iterator to compare against.
     * @retval Returns true if the current iterator points to a later position, false otherwise.
     */
    constexpr bool operator>(const const_iterator& other) const;

    /**
     * @brief  Checks if the current constant iterator precedes or equals another iterator.
     * @param  other the constant iterator to compare against.
     * @retval Returns true if the position is earlier than or equal to other, false otherwise.
     */
    constexpr bool operator<=(const const_iterator& other) const;

    /**
     * @brief  Checks if the current constant iterator succeeds or equals another iterator.
     * @param  other the constant iterator to compare against.
     * @retval Returns true if the position is later than or equal to other, false otherwise.
     */
    constexpr bool operator>=(const const_iterator& other) const;
  private:
    const_pointer ptr_;
  };
  
  T arr_[Size];
};

/**
 * @brief  Adds an integer offset to a non-constant iterator.
 * @param  n offset distance.
 * @param  it iterator to advance.
 * @retval New iterator advanced by n positions.
 */
template <typename T, std::size_t Size>
requires NotZero<Size>
constexpr array<T, Size>::iterator operator+(
  typename array<T, Size>::difference_type n
  , typename array<T, Size>::iterator it
);

/**
 * @brief  Adds an integer offset to a constant iterator.
 * @param  n offset distance.
 * @param  it constant iterator to advance.
 * @retval New constant iterator advanced by n positions.
 */
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