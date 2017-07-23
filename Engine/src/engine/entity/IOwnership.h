#ifndef IOWNERSHIP_H
#define IOWNERSHIP_H


template <typename Owner>
class IOwnership
{
public:
	virtual void setOwner(Owner* owner) { m_owner = owner; };

	virtual Owner* getOwner() { return m_owner; };
	
	virtual bool hasOwner() { return (m_owner != nullptr); };

	virtual void removeOwner() { m_owner = nullptr; };


protected:
	Owner* m_owner;
};
#endif