/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Component Animation
Description: Holds animation data for AnimationSystem
*********************************************************************/
#ifndef CANIMATION_H
#define CANIMATION_H

#include <entity/IComponent.h>
#include <resources/BaseAnimation.h>

class CAnimation: public IComponent {
public:
	CAnimation();
	CAnimation(BaseAnimation* animation);
	~CAnimation();

	void setAnimation(BaseAnimation* animation);
	BaseAnimation* getAnimation();
	void addAnimation(const char* path);
private:
	BaseAnimation* m_pAnimation;
};
#endif