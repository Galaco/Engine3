#ifndef WINDOW_H
#define WINDOW_H

#include <core/BaseWindow.h>
#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>

class QOpenGLContext;

class Window : public BaseWindow, public QWindow, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	explicit Window(QWindow *parent = 0);
	~Window();
	
	virtual void render(QPainter *painter);
	virtual void render();

	virtual void initialize();

	QOpenGLContext* getContext();

	void swapBuffers() override;
	bool isValid() override;

	void useCursorInput() override;

public slots:
	void renderLater();
	void renderNow();

protected:
	bool event(QEvent *event) override;

	void exposeEvent(QExposeEvent *event) override;


private:
	bool m_animating;

	QOpenGLContext *m_context;
	QOpenGLPaintDevice *m_device;
};

#endif