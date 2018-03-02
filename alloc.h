#include <cstddef>

template<class T>
class BaseStlAllocator
{
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T value_type;
  template<class U>
  struct rebind
  {
    typedef BaseStlAllocator<U> other;
  };
 
  BaseStlAllocator() throw ()  {   } 

  template<class U>
  BaseStlAllocator(const BaseStlAllocator<U>& a) throw () {   } 

  pointer address(reference x) const
  {
    return &x;
  }

  const_pointer address(const_reference x) const
  {
    return &x;
  }

  pointer allocate(size_type cnt, const void*  = 0)
  {
    return static_cast<pointer>(malloc(cnt * sizeof(T)));
  }

  void deallocate(pointer p, size_type)
  {
    if (p != NULL)
      free(p);
  }

  size_type max_size() const throw ()
  {
    return (size_type)-1;
  }

  void construct(pointer p, const T& val)
  { 
    new(p) T(val); 
  }

  void destroy(pointer p)
  {
    p->~T();
  }

  template<class R>
  bool operator==(const BaseStlAllocator<R>& other) const
  {
    return true;
  }

  template<class R>
  bool operator!=(const BaseStlAllocator<R>& other) const
  {
    return !(*this == other);
  }
};  // BaseStlAllocator 


typedef std::basic_string<char16_t, std::char_traits<char16_t>, BaseStlAllocator<char16_t>> my_string;
