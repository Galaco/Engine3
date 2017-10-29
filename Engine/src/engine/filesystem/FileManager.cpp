#include "FileManager.h"

#include <algorithm>
#include <filesystem/exception/OrphanedFileHandleException.h>

FileHandle& FileManager::requestHandle(const char* filename) {
	FileHandle f(filename);
	m_pHandles.push_back(f);
	return m_pHandles.back();
}


void FileManager::closeHandle(FileHandle& handle) {
	//fix me
	std::vector<FileHandle>::iterator position = std::find(m_pHandles.begin(), m_pHandles.end(), handle);
	if (position != m_pHandles.end()) {
		m_pHandles.erase(position);
	}
	else {
		throw OrphanedFileHandleException(handle.getOrigin());
	}
}