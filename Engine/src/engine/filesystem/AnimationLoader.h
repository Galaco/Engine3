/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Animation Loader
Description: Responsible or loading MD5 Foramt Animations
*********************************************************************/
#ifndef ANIMATIONLOADER_H
#define ANIMATIONLOADER_H

#include <string>
#include <map>
#include <memory>
#include <core/Logger.h>

#include <resources/BaseAnimation.h>

#include <resources/MD5Animation.h>


class AnimationLoader {
public:
	AnimationLoader();
	~AnimationLoader();
        
    BaseAnimation* load(std::string);
private:
};
#endif
