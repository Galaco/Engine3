#ifndef WINDOW_H
#define WINDOW_H

#include <graphics/BaseWindow.h>
#include <QtWidgets/QMainWindow>
#include <QtGui/QOpenGLFunctions>

class QOpenGLContext;

class Window : public BaseWindow, public QMainWindow, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	explicit Window(QWindow *parent = 0);
	~Window();
	
	virtual void render(QPainter *painter);
	virtual void render();

	virtual void initialize();

	void* getContext();

	void swapBuffers() override;
	bool isValid() override;

	void useCursorInput() override;

public slots:
	void renderLater();
	void renderNow();

protected:
	bool event(QEvent *event) override;


private:
	bool m_animating;

	QOpenGLContext *m_context;
	QOpenGLPaintDevice *m_device;
};

#endif