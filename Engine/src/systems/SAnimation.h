/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Animation System
Description: System that updates animations on objects each frame.
*********************************************************************/
#ifndef SANIMATION_H
#define SANIMATION_H

#include <map>
#include <vector>

#include <system/ISystem.h>



#include <system/System.h>

#include <resources/Mesh.h>
#include <resources/MD5Animation.h>

#include "../components/CAnimation.h"
#include "../components/CGraphics.h"


class SAnimation: public System, public ISystem {
public:
	SAnimation();
	~SAnimation();

	void initialize();
	
	void update(float);

	void Update();
	bool Initialise();
	void FixedUpdate(float dt);
	void Terminate() { this->terminate(); };

private:
        void updateAnimation(CAnimation*, CGraphics*, float);
        void updateMesh(Model*, const MD5Animation::FrameSkeleton&);


		void rebuildCache();
		static std::map<CAnimation*, CGraphics*> CGraphicsCAnimationCache;
};
#endif
