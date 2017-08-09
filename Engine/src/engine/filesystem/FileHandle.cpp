#include "FileHandle.h"

#include <filesystem\exception\FileNotFoundException.h>

FileHandle::FileHandle(const char* filepath)
{
	std::ifstream* file;

	file->open(filepath);
	if (file->is_open() != true) {
		throw FileNotFoundException(filepath);
	}

	this->filepath = filepath;
	this->file = std::make_shared<std::ifstream*>(file);
}

const char* FileHandle::getOrigin() {
	return this->filepath;
}

std::ifstream* FileHandle::getStream()
{
	return *(file.get());
}

void FileHandle::closeStream()
{
	std::ifstream** f = file.get();
	if ((*f)->is_open()) {
		(*f)->close();
	}
}

FileHandle::~FileHandle()
{
	this->closeStream();
}
