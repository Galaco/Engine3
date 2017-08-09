#ifndef ORPHANEDFILEHANDLEEXCEPTION_H
#define ORPHANEDFILEHANDLEEXCEPTION_H

#include <exception>
#include <filesystem\FileSystemException.h>

class OrphanedFileHandleException : FileSystemException {
public:
	OrphanedFileHandleException(char const* const message) throw() : FileSystemException(message) {
		this->message = message;
	};
};
#endif