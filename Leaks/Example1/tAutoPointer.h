#pragma once
#include <assert.h>

template<typename TYPE> class tAutoPointer
{
protected:
  TYPE* m_pointer;

public:
  explicit tAutoPointer(TYPE* pointer)
  {
    assert(pointer);

    m_pointer = pointer;
  }

  ~tAutoPointer()
  {
    if (m_pointer)
    {
      delete m_pointer;
    }
  }

  inline operator TYPE& ()
  {
    return *m_pointer;
  }

  inline operator TYPE* ()
  {
    return m_pointer;
  }

  inline TYPE* operator ->()
  {
    return m_pointer;
  }
};
