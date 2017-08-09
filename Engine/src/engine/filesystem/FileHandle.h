#ifndef FILESYSTEM_FILEHANDLE_H
#define FILESYSTEM_FILEHANDLE_H

#include <fstream>
#include <memory>

class FileHandle
{
public:
	FileHandle(const char* filepath);
	~FileHandle();

	const char* getOrigin();
	std::ifstream* getStream();

	void closeStream();

private:
	std::shared_ptr<std::ifstream*> file;
	const char* filepath;
};
#endif