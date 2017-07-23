/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Entity
Description: THE game object. Any object in the world will either be,
			 or inherit from this class. Contains a component list 
			 used to control the object.
*********************************************************************/
#ifndef ENTITY_H
#define ENTITY_H

#include <entity/IEntity.h>

#include <core/EventManager.h>


class Entity : public IEntity {
public:
	Entity();
    Entity(const char*);
	~Entity();

protected:
	static EventManager m_EventManager;
};
#endif
