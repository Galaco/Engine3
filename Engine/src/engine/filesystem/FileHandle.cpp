#include "FileHandle.h"

#include <filesystem\exception\FileNotFoundException.h>

FileHandle::FileHandle(const char* filepath)
{
	std::ifstream file(filepath, std::ios::binary);

	if (file.is_open() != true) {
		throw FileNotFoundException(filepath);
	}

	this->filepath = filepath;
	this->file = std::make_shared<std::ifstream*>(&file);
}

const char* FileHandle::getOrigin() {
	return this->filepath;
}

std::ifstream* FileHandle::getRawStream()
{
	return *(file.get());
}

char* FileHandle::getRawData() {
	//Parse file once
	if (this->m_pRawStreamData != nullptr) {
		return this->m_pRawStreamData;
	}
	this->m_pRawStreamData = this->readStream();
	return this->m_pRawStreamData;
}

char* FileHandle::readStream() {
	std::ifstream* stream = (*(file.get()));
	if (stream->is_open() == true) {
		char* fileContents;
		size_t size = stream->tellg();
		stream->read(fileContents, size);

		this->m_pRawStreamData = fileContents;
	}
	return this->m_pRawStreamData;
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
