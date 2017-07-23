/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Identifier
Description: Generates unique entity Ids where an id has not been 
			 identified
*********************************************************************/
#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <map>
#include <string>

#include <core/Logger.h>

class Identifier
{
public:
	Identifier();
	~Identifier();
        
        const char* gen();
		const char* gen(const char*);
        
		const char* get();

private:
    static int m_nextId;
    static std::map<const char*, int> m_manualList;
    
	const char* m_id;
};
#endif
