#pragma once

#include "SessionMgr.h"

class RegisterAction {
public:
	RegisterAction(string className, PTRCreateObject ptrCreateFn) {
		SessionMgr::getInstance().registClass(className, ptrCreateFn);
	}
};