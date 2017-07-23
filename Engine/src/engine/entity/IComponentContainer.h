#ifndef ICOMPONENTCONTAINER_H
#define ICOMPONENTCONTAINER_H

#include <vector>
#include <entity/IComponent.h>


class IComponentContainer
{
public:
	virtual void addComponent(IComponent* component)
	{
		m_components.push_back(component);
	}

	template<class T>
	IComponent* getComponent()
	{
		for (std::vector<IComponent*>::iterator it = this->m_components.begin(); it != this->m_components.end(); ++it)
		{
			T* x = dynamic_cast<T*>((*it));
			if (x) {
				return x;
			}
		}
		return nullptr;
	}

protected:
	std::vector<IComponent*> m_components;
};
#endif