﻿//
//  CRemoteMsgManager.h
//  myGame
//
//  Created by jiang on 13-7-23.
//
//
#ifndef __ApplicationMediators__
#define __ApplicationMediators__


#include "U2GameBase.h"


U2EG_NAMESPACE_USING


class ShadeMediator : public CocosMediator
{
public:
    ShadeMediator(const String& type, const String& name);

    virtual ~ShadeMediator(void);

    virtual Mediator::NotificationNames listNotificationInterests(void) const override;

    virtual void handleNotification(const Notification& notification) override;

protected:
};


class LogoMediator : public CocosMediator
{
public:
	LogoMediator(const String& type, const String& name);

	virtual ~LogoMediator(void);

    virtual void onRegister(void) override;

    virtual void onRemove(void) override;

    virtual Mediator::NotificationNames listNotificationInterests(void) const override;

    virtual void handleNotification(const Notification& notification) override;

    virtual void startup(const u2::Context* context) override;

	virtual void end() override;

protected:
    virtual void onCommonStateChanged(ViewComponent* viewComp, const String& objName, const String& msg) override;
};


#endif /* defined(__ApplicationMediators__) */
