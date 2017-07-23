#include "Entity.h"

EventManager Entity::m_EventManager;

Entity::Entity() {
	m_id.gen();
}

Entity::Entity(const char* name) {
	m_id.gen(name);
}

Entity::~Entity(){
}