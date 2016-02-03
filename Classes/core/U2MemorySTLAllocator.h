#ifndef __U2MemorySTLAllocator_H__
#define __U2MemorySTLAllocator_H__

#include "U2Prerequisites.h"
#include "U2HeaderPrefix.h"


U2EG_NAMESPACE_BEGIN


/** \addtogroup Core
*  @{
*/
/** \addtogroup Memory
*  @{
*/
/**
Wrapper class for operating as an STL container allocator.
This class acts as the host for a configured allocation policy.

It takes the following template parameters:-
<ul>
<li>T           : the type we will be allocating (see rebind later)</li>
<li>AllocPolicy : a memory allocator policy </li>
</ul>

See StdAllocPolicy for an example of implementing a Policy. The reason for
implementing the allocation in a policy is that it makes implementing
a custom allocator easier -  you just have to provide an alternative
policy with just allocate/deallocate implementations; this class does all the
housekeeping associated with keeping the STL happy.
*/

// Base STL allocator class.
template<typename T>
struct STLAllocatorBase
{   // base class for generic allocators
    typedef T value_type;
};

// Base STL allocator class. (const T version).
template<typename T>
struct STLAllocatorBase<const T>
{   // base class for generic allocators for const T
    typedef T value_type;
};

template<typename T, typename AllocPolicy>
class STLAllocator : public STLAllocatorBase<T>
{
public :
    /// define our types, as per ISO C++
    typedef STLAllocatorBase<T>         Base;
    typedef typename Base::value_type   value_type;
    typedef value_type*                 pointer;
    typedef const value_type*           const_pointer;
    typedef value_type&                 reference;
    typedef const value_type&           const_reference;
    typedef std::size_t                 size_type;
    typedef std::ptrdiff_t              difference_type;


    /// the standard rebind mechanism
    template<typename U>
    struct rebind
    {
        typedef STLAllocator<U, AllocPolicy> other;
    };

    /// ctor
    inline explicit STLAllocator()
    { }

    /// dtor
    virtual ~STLAllocator()
    { }

    /// copy ctor - done component wise
    inline STLAllocator( STLAllocator const& )
    { }

    /// cast
    template <typename U>
    inline STLAllocator( STLAllocator<U, AllocPolicy> const& )
    { }

    /// cast
    template <typename U, typename P>
    inline STLAllocator( STLAllocator<U, P> const& )
    { }

    /// memory allocation (elements, used by STL)
    inline pointer allocate( size_type count,
        typename std::allocator<void>::const_pointer ptr = 0 )
    {
        (void)ptr;
        // convert request to bytes
        register size_type sz = count*sizeof( T );
        pointer p  = static_cast<pointer>(AllocPolicy::allocateBytes(sz));
        return p;
    }

    /// memory deallocation (elements, used by STL)
    inline void deallocate( pointer ptr, size_type )
    {
        // convert request to bytes, but we can't use this?
        // register size_type sz = count*sizeof( T );
        AllocPolicy::deallocateBytes(ptr);
    }

    pointer address(reference x) const
    {
        return &x;
    }

    const_pointer address(const_reference x) const
    {
        return &x;
    }

    size_type max_size() const throw()
    {
        // maximum size this can handle, delegate
        return AllocPolicy::getMaxAllocationSize();
    }

#if __cplusplus < 201103L
    void construct(pointer p)
    {
        // call placement new
        new(static_cast<void*>(p)) T();
    }
#endif

    void construct(pointer p, const T& val)
    {
        // call placement new
        new(static_cast<void*>(p)) T(val);
    }

    void destroy(pointer p)
    {
        // do we have to protect against non-classes here?
        // some articles suggest yes, some no
        p->~T();
    }
};


/// determine equality, can memory from another allocator
/// be released by this allocator, (ISO C++)
template<typename T, typename T2, typename P>
inline bool operator==(STLAllocator<T,P> const&,
    STLAllocator<T2,P> const&)
{
    // same alloc policy (P), memory can be freed
    return true;
}

/// determine equality, can memory from another allocator
/// be released by this allocator, (ISO C++)
template<typename T, typename P, typename OtherAllocator>
inline bool operator==(STLAllocator<T,P> const&,
    OtherAllocator const&)
{
    return false;
}
/// determine equality, can memory from another allocator
/// be released by this allocator, (ISO C++)
template<typename T, typename T2, typename P>
inline bool operator!=(STLAllocator<T,P> const&,
    STLAllocator<T2,P> const&)
{
    // same alloc policy (P), memory can be freed
    return false;
}

/// determine equality, can memory from another allocator
/// be released by this allocator, (ISO C++)
template<typename T, typename P, typename OtherAllocator>
inline bool operator!=(STLAllocator<T,P> const&,
    OtherAllocator const&)
{
    return true;
}


/** @} */
/** @} */

U2EG_NAMESPACE_END


#include "U2HeaderSuffix.h"

#endif // __U2MemorySTLAllocator_H__
