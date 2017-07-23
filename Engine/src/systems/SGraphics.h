/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Graphics System
Description: Responsible for rendering all objects to screen. Uses a
			 Deferred Renderer (this could be swapped out for another 
			 rendering method if desired. 
*********************************************************************/
#ifndef SGRAPHICS_H
#define SGRAPHICS_H

#include <map>
#include <vector>

#include <glad/glad.h>


#ifdef USE_QT
#include <graphics/window/QtWindow.h>
#elif USE_GLFW
#include <graphics/window/GLFWWindow.h>
#else
#error No window library specified
#endif

#include <system/ISystem.h>


#include <filesystem/Config.h>
#include <core/ResourceManager.h>

#include <system/System.h>

#include <graphics/Camera.h>
#include <resources/PointLight.h>
#include <resources/Shader.h>

#include <graphics/Pipeline.h>


#include "../components/CGraphics.h"

#include "renderer/DeferredRenderer.h"
#include "renderer/GeometryPass.h"
#include "renderer/PointLightPass.h"
#include "renderer/DirectionalLightPass.h"
#include "renderer/StencilPass.h"
#include "renderer/TransparencyPass.h"

class SGraphics: public System, public ISystem { 
public:
	SGraphics();
	~SGraphics();

	void initialize();
	void update();

	void Update();
	bool Initialise();
	void FixedUpdate(float dt);
	void Terminate() { this->terminate(); };
	

	Window* getCurrentWindow();


private:
	void drawEntity(CGraphics*);
	void drawText(CGraphics*);
	void drawSkybox();

	void generateShadowBuffer();


	Window* m_pWindow;



	void rebuildCache();

	static ResourceManager m_Resources;
	std::vector<CGraphics*> CGraphicsCache;
	static CShaderProgram	m_shaderProg;
	static CShader m_shader[3];
	static GLuint shadowFBO, pass1Index, pass2Index;
};
#endif
