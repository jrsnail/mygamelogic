﻿//
//  CRemoteMsgManager.cpp
//  myGame
//
//  Created by jiang on 13-7-23.
//
//

#include "ApplicationCommands.h"

#include "ApplicationPrerequisites.h"
#include "ApplicationMediators.h"



//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
StartupCommand::StartupCommand(const String& type, const String& name)
    : SimpleCommand(type, name)
{
}
//-----------------------------------------------------------------------
StartupCommand::~StartupCommand()
{
}
//-----------------------------------------------------------------------
void StartupCommand::go(const Notification& notification)
{
    Notification ntf(NTF_Application_Trans2Shade);
    getFacade().broadcastNotification(ntf);

    Notification ntfLogo(NTF_Application_Trans2Logo);
    getFacade().broadcastNotification(ntfLogo);
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
Trans2ShadeCommand::Trans2ShadeCommand(const String& type, const String& name)
    : SimpleCommand(type, name)
{
}
//-----------------------------------------------------------------------
Trans2ShadeCommand::~Trans2ShadeCommand()
{
}
//-----------------------------------------------------------------------
void Trans2ShadeCommand::go(const Notification& notification)
{
    // create context tree
    u2::Context* pTo = ContextManager::getSingleton().createObject(
        OT_Context, "ShadeContext"
        , OT_ShadeMediator, "ShadeMediator"
        , OT_ShadeViewComponent, "ShadeViewComponent"
        );
    ContextProxy& contextProxy = (ContextProxy&)PredefinedFacade::getSingleton().retrieveProxy(ON_Proxy_Context);
    contextProxy.pushBack(ON_ContextQueue_Shade, pTo, ContextQueue::eTransType::TT_Overlay);
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
Trans2LogoCommand::Trans2LogoCommand(const String& type, const String& name)
    : TransCommand(type, name)
{
}
//-----------------------------------------------------------------------
Trans2LogoCommand::~Trans2LogoCommand()
{
}
//-----------------------------------------------------------------------
void Trans2LogoCommand::go(const Notification& notification)
{
    // create context tree
    u2::Context* pLogo = ContextManager::getSingleton().createObject(
        OT_Context, "LogoContext"
        , OT_LogoMediator, "LogoMediator"
        , OT_LogoViewComponent, "LogoViewComponent"
        );
    ContextProxy& contextProxy = (ContextProxy&)PredefinedFacade::getSingleton().retrieveProxy(ON_Proxy_Context);
    contextProxy.pushBack(ON_ContextQueue_Scene, pLogo, ContextQueue::eTransType::TT_Overlay);
}