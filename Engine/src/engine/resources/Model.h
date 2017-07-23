/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Model
Description: Contains a list of meshes, textures and joints. 
			 An instance represents 1 complete exported model.
*********************************************************************/
#ifndef MODEL_H
#define MODEL_H

#include <string>

#include <core/Logger.h>

#include <resources/IResource.h>
#include "Texture.h"

#include <resources/Mesh.h>

class Model : public IResource
{
public:
	Model();
	~Model();

    void setFormat(std::string f);
    std::string getFormat();

	void addMesh(Mesh&);
	std::vector<Mesh>& getMeshes();

	void addTexture(std::string, Texture*);
	std::map<std::string, Texture>& getTextures();
	Texture* getTexture(std::string);

	std::string& getFileFormatVersion();
	void setFileFormatVersion(std::string);
	int& getMeshCount();
	int& getJointCount();

protected:
	std::vector<Mesh> m_meshList;

	std::map<std::string, Texture> m_textureList;

	std::string m_format;

	std::string m_FileFormatVersion;
	int m_meshCount, m_jointCount;

	glm::mat4x4         m_LocalToWorldMatrix;
};
#endif
