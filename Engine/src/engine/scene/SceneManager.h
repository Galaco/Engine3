/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: State Machine (Scene Manager)
Description: Responsible for handling what state is the current state.
			 A state is responsible for its own priority and requesting
			 priority. The manager determines what should be active.
			 Only 1 state can be active at once. Non-active states are
			 on-hold.
*********************************************************************/
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <map>

#include <scene/Scene.h>
#include <System.h>

class SceneManager {
public:
	SceneManager();
	~SceneManager();
        
	static void initialize();
	static void terminate();
	static void update(float dt);

	static void addState(Scene*, std::string);

	static void setActiveState(Scene*);
	static Scene* getActiveState();


	static Scene* getState(std::string);


	static void requestPriority(std::string);	//scene name that wants priority
        

private:
	static std::map<std::string, Scene*> m_stateList;
	static Scene* m_pActiveState;
};
#endif