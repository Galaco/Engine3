#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <filesystem\FileHandle.h>


class FileManager {
public:
	static FileManager* get() {
		if (m_pSingleton == nullptr) m_pSingleton = new FileManager();
		return m_pSingleton;
	}

	FileHandle& requestHandle(const char* filename);
	void closeHandle(FileHandle& handle);

private:
	FileManager() {};
	static FileManager* m_pSingleton;
	static std::vector<FileHandle> m_pHandles;
};
#endif