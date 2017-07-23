/*********************************************************************
Project: Dissertation
Author: Josh Martin

Name: Model Loader
Description: Responsible for determining filetype, and passing the 
			 loading to the correct filetype loader
*********************************************************************/
#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <string>
#include <map>
#include <memory>
#include <core/Logger.h>

#include <filesystem/ObjLoader.h>
#include <filesystem/Md5Loader.h>

#include <resources/Model.h>


class ModelLoader {
public:
	ModelLoader();
	~ModelLoader();
        
    Model* load(std::string);	//Loads a model from a string

        
private:
	static ObjLoader	m_Obj;
	static Md5Loader	m_Md5;
};
#endif
