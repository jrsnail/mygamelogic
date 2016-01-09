﻿//
//  CRemoteMsgManager.cpp
//  myGame
//
//  Created by jiang on 13-7-23.
//
//

#include "GameContexts.h"


//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
ShadeContext::ShadeContext(const String& type, const String& name)
    : Context(type, name)
{
}
//-----------------------------------------------------------------------
ShadeContext::~ShadeContext()
{
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
SceneContext::SceneContext(const String& type, const String& name)
    : Context(type, name)
{
}
//-----------------------------------------------------------------------
SceneContext::~SceneContext()
{
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
TabContext::TabContext(const String& type, const String& name)
    : Context(type, name)
{
}
//-----------------------------------------------------------------------
TabContext::~TabContext()
{
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
DialogContext::DialogContext(const String& type, const String& name)
    : Context(type, name)
{
}
//-----------------------------------------------------------------------
DialogContext::~DialogContext()
{
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
ChildContext::ChildContext(const String& type, const String& name)
    : Context(type, name)
{
}
//-----------------------------------------------------------------------
ChildContext::~ChildContext()
{
}