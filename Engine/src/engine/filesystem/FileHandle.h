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
	std::ifstream* getRawStream();

	char* getRawData();
	void closeStream();

private:
	char* readStream();

	std::shared_ptr<std::ifstream*> file;
	const char* filepath;

	char* m_pRawStreamData;
};
#endif