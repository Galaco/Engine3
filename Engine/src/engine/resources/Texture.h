/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Texture
Description: Loads and stores a texture from a file. 
Todo: Material data implementation
*********************************************************************/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <glad/glad.h>
#include <SFML/Graphics.hpp>
#include <GLFW/glfw3.h>

#include <resources/IResource.h>

class Texture : public IResource
{
public:
	Texture();
	Texture(const char*, char);
	~Texture();

	GLuint&		load(const char*, char);
	void		unload();
	GLuint&		getTexId();

	bool		hasDiffuse();

private:
	GLuint			diffuse;
	bool			has_diffuse;
};
#endif