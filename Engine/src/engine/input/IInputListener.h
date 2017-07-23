#ifndef IINPUTLISTENER_H
#define IINPUTLISTENER_H

#include <functional>
#include <graphics/BaseWindow.h>

class IInputListener {
public:
	void setWindowToListen(BaseWindow* window) { m_window = window; };

	virtual void pollEvents() = 0;

protected:
	virtual void resetPoll() = 0;

	static BaseWindow* m_window;
};
#endif
