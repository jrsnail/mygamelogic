﻿//
//  CRemoteMsgManager.h
//  myGame
//
//  Created by jiang on 13-7-23.
//
//
#ifndef __U2Prerequisites__
#define __U2Prerequisites__


#include "cocos2d.h"



#define U2EG_NAMESPACE_NAME         u2
#define U2EG_NAMESPACE_BEGIN        namespace U2EG_NAMESPACE_NAME {
#define U2EG_NAMESPACE_END          };
#define U2EG_NAMESPACE_USING        using namespace U2EG_NAMESPACE_NAME;


namespace U2EG_NAMESPACE_NAME
{
    typedef std::string             String;
    typedef std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >            StringStream;
}

#define BLANK                       ""

#define GET_OBJECT_TYPE(T)          typeid(T).name()

typedef const char*                 ObjectType;
typedef const char*                 ObjectName;



#endif /* defined(__U2Prerequisites__) */
