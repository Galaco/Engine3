#ifndef IUNIQUEIDENTIFIER_H
#define IUNIQUEIDENTIFIER_H

#include <core/helpers/Identifier.h>


class IUniqueIdentifier
{
public:
	const char* getId() { return m_id.get(); };
	void setId(const char* id) { m_id.gen(id); };


protected:
	Identifier      m_id;
};
#endif