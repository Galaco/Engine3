#include "CCollision.h"

CCollision::CCollision(){
	weight = 1.f;
	dynamic = false;
}

CCollision::~CCollision(){
	
}

void CCollision::rebuildCollisionBox(Model* model)
{
	if (!model) {
		buildBoxFromPrimitive("quad");
	}
	else {
		m_collisionBox.buildFromModel(model);
	}

	if (!m_owner) return;
	m_collisionBox.resize(m_owner->GetTransform().getScale(), (m_owner)->GetTransform().getPosition());
}


AABB& CCollision::getCollisionBox(){
	return m_collisionBox;
}

void CCollision::buildBoxFromPrimitive(std::string primitive)
{
	if (primitive == "quad")
		m_collisionBox.build(-0.5, -0.5, 0, 0.5, 0.5, 0);
}