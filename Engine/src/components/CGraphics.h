/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Component Graphics
Description: Stores renderable data for use with the render system
*********************************************************************/
#ifndef CGRAPHICS_H
#define CGRAPHICS_H

#define RENDER_MODE_2D 0
#define RENDER_MODE_3D 1


#include <entity/IComponent.h>
#include <resources/Model.h>
#include <resources/PointLight.h>
#include <resources/Text.h>
#include <resources/Texture.h>


#include <resources/Material.h>
#include "CCollision.h"

class CGraphics: public IComponent {
public:
	CGraphics();
	~CGraphics();

	void setPointLight(PointLight* light);
	PointLight* getPointLight();
	void addModel(const char*, bool buildCollisions = false, float cubeSize = 1.f, bool dynamic = false);
	void setModel(Model*);
	Model* getModel();

	void addMaterial(const char*);

	void addText(const char* string, double size);
	void setText(Text*);
	Text* getText();

	Material* getOverrideMaterial(unsigned int);

	unsigned int& getRenderMode();
	void setRenderMode(unsigned int);
private:
	Model* m_pModel;
	PointLight* m_pPointlight;
	Text* m_pText;

	std::vector<Material> m_materialList;

	unsigned int m_renderMode;
};
#endif