#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include "IOwnership.h"

#include <core/ResourceManager.h>

class IEntity;


class IComponent : public IOwnership<IEntity>
{
public:
	void setEnabled(bool state) { m_isEnabled = state; };
	bool getEnabled() { return m_isEnabled; };


protected:
	bool m_isEnabled;



	ResourceManager m_Resources;
};
#endif