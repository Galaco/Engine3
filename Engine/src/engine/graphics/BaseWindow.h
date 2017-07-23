#ifndef BASEWINDOW_H
#define BASEWINDOW_H

class BaseWindow
{
public:
	virtual bool isValid() = 0;
	virtual void useCursorInput() = 0;

	virtual void swapBuffers() = 0;

private:
};

#endif