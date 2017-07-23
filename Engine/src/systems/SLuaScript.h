/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Lua Script System
Description: Responsible for running lua scripts tht are not ran on 
			 load, or that require running later on (eg entity update 
			 scripts).
*********************************************************************/
#ifndef SLUASYSTEM_H
#define SLUASYSTEM_H

#include <map>
#include <vector>

#include <engine/interfaces/ISystem.h>
#include <Lua.hpp>

#include <core/System.h>
#include <core/resources/LuaScript.h>

#include "lua/LuaObjectBinds.h"
#include "../components/CLuaScript.h"

class SLuaScript: public System, public ISystem {
public:
	SLuaScript();
	~SLuaScript();

	void initialize();
        
	lua_State* getMasterState();

	LuaScript* createScript();

	void deleteScript(LuaScript* scriptptr);

	void update(float);

	void Update();
	bool Initialise();
	void FixedUpdate(float dt);
	void Terminate() { this->terminate(); };

private:
	lua_State* m_masterLuaState;
	LuaObjectBinds m_luaBinds;

	std::vector<LuaScript*> m_globalScripts;


	void rebuildCache();
	static std::vector<CLuaScript*> CLuaScriptCache;
};
#endif
