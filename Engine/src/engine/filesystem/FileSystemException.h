#ifndef FILESYSTEM_FILESYSTEMEXCEPTION_H
#define FILESYSTEM_FILESYSTEMEXCEPTION_H

#include <exception>

class FileSystemException: public std::exception {
public:
	FileSystemException(char const* const message) throw() : std::exception(message) {
		this->message = message;
	};

	virtual char const* what() const throw() {
		return message;
	};

protected:
	const char* message;
};
#endif