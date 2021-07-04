#pragma once

#include <map>
#include <string>

using namespace std;

typedef void* (*PTRCreateObject)(void);

class SessionMgr{
private:
    map<string, PTRCreateObject> m_classMap;
	SessionMgr(){};
public:
	static SessionMgr& getInstance()
	{
		static SessionMgr instance;
		return instance;
	}
    void* getClassByName(string className);
    void registClass(string name, PTRCreateObject method);
};