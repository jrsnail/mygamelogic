﻿#ifndef __U2Singleton_H__
#define __U2Singleton_H__

// Added by Steve Streeting for Ogre
#include "U2Prerequisites.h"


#if U2_COMPILER == U2_COMPILER_MSVC
// Turn off warnings generated by this singleton implementation
#   pragma warning (disable : 4311)
#   pragma warning (disable : 4312)
#   pragma warning (disable : 4661)
#endif

#if defined ( U2_GCC_VISIBILITY )
#   pragma GCC visibility push(default)
#endif


U2EG_NAMESPACE_BEGIN


// End SJS additions
/** Template class for creating single-instance global classes.
*/
template <typename T> class Singleton
{
private:
	/** \brief Explicit private copy constructor. This is a forbidden operation.*/
	Singleton(const Singleton<T> &);

	/** \brief Private operator= . This is a forbidden operation. */
	Singleton& operator=(const Singleton<T> &);

protected:
	static T* msSingleton;

public:
	Singleton( void )
	{
		assert( !msSingleton );
		msSingleton = static_cast< T* >( this );
	}

	~Singleton( void )
	{
		assert( msSingleton );
		msSingleton = 0;
	}

	static T& getSingleton( void )
	{
		assert( msSingleton );
		return ( *msSingleton );
	}

	static T* getSingletonPtr( void )
	{
		return msSingleton;
	}
};


U2EG_NAMESPACE_END


#if defined ( U2_GCC_VISIBILITY )
#   pragma GCC visibility pop
#endif


#endif
