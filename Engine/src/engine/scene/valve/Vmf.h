#ifndef SCENE_VTF_H
#define SCENE_VTF_H

#include <scene\Scene.h>

#include <resources\valve\Brush.h>
#include <resources\valve\Mdl.h>
#include <resources\valve\Vmt.h>
#include <resources\valve\Vtf.h>

class VmfScene : public Scene
{
	VmfScene();
	VmfScene(std::vector<Brush*>);

private:
	std::vector<Brush*> m_pBrushList;
	std::vector<Entity*> m_pEntities;

};

#endif