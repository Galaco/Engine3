#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

#include <exception>
#include <filesystem\FileSystemException.h>

class FileNotFoundException: FileSystemException {
public:
	FileNotFoundException(char const* const message) throw() : FileSystemException(message){
		this->message = message;
	};
};
#endif