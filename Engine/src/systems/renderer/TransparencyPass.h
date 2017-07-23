/*********************************************************************
Project: Dissertation
Author: Josh Martin
Name: Transparency Pass
Description: An addition to the deferred pass. Used to render 
			translucent objects
*********************************************************************/
#ifndef TRANSPARENCYPASS_H
#define TRANSPARENCYPASS_H

#include <glad/glad.h>

#include <graphics/Pipeline.h>

#include "DeferredPass.h"


class TransparencyPass: public DeferredPass{
public:
	TransparencyPass();
	~TransparencyPass();

	void initialize();
	
	void startPass();
	void endPass();

	void setTransformation(const glm::mat4 mat);
private:
};
#endif
