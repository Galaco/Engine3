#ifndef IENTITY_H
#define IENTITY_H

#include <entity/IComponent.h>
#include <entity/IComponentContainer.h>
#include <entity/IOwnership.h>
#include <entity/IUniqueIdentifier.h>

#include <entity/components/CTransform.h>


class IEntity : public IOwnership<IEntity>, public IComponentContainer, public IUniqueIdentifier
{
public:
	virtual void addComponent(IComponent* component)
	{
		component->setOwner(this);
		IComponentContainer::addComponent(component);
	}

	CTransform& GetTransform() { return m_transform; };
	void SetTransform(CTransform& transform) { m_transform = transform; };

protected:
	CTransform m_transform;
};
#endif