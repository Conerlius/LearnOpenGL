//
// Created by Conerlius on 2021/7/4.
//

#include "SessionMgr.h"

void* SessionMgr::getClassByName(string className) {
    map<string, PTRCreateObject>::const_iterator iter;
    iter = m_classMap.find(className) ;
    if ( iter == m_classMap.end() )
        return NULL ;
    else
        return iter->second() ;
}

void SessionMgr::registClass(string name, PTRCreateObject method){
    m_classMap.insert(pair<string, PTRCreateObject>(name, method)) ;
}