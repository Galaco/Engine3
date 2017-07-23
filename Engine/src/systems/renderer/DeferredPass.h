/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Deferred Pass
Description: Abstract pass for the deferred renderer. All passes 
			 extend from this class
*********************************************************************/
#ifndef DEFERREDPASS_H
#define DEFERREDPASS_H

#include <glad/glad.h>

#include <core/helpers/Config.h>
#include <core/Logger.h>

#include <resources/Shader.h>


class DeferredPass{
public:
	DeferredPass();
	~DeferredPass();

	virtual void initialize();
	
	virtual void startPass();
	virtual void endPass();

	void setFbo(GLuint&);

protected:
	GLuint      m_fbo;
    Logger*     m_pLogger;
        
    CShaderProgram	m_shaderProg;
	CShader m_shader[2];
        
    GLuint m_MVPLocation;
};
#endif
