#ifdef USE_QT
#include "QtWindow.h"

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

Window::Window(QWindow *parent)
	: QWindow(parent)
	, m_animating(false)
	, m_context(0)
	, m_device(0)
{
	setSurfaceType(QWindow::OpenGLSurface);
}

Window::~Window()
{
	delete m_device;
}
void Window::render(QPainter *painter)
{
	Q_UNUSED(painter);
}

void Window::initialize()
{
}

void Window::render()
{
	if (!m_device)
		m_device = new QOpenGLPaintDevice;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	m_device->setSize(size());

	QPainter painter(m_device);
	render(&painter);
}

void Window::renderLater()
{
	requestUpdate();
}

bool Window::event(QEvent *event)
{
	switch (event->type()) {
	case QEvent::UpdateRequest:
		renderNow();
		return true;
	default:
		return QWindow::event(event);
	}
}

void Window::exposeEvent(QExposeEvent *event)
{
	Q_UNUSED(event);

	if (isExposed())
		renderNow();
}

void Window::renderNow()
{
	if (!isExposed())
		return;

	bool needsInitialize = false;

	if (!m_context) {
		m_context = new QOpenGLContext(this);
		m_context->setFormat(requestedFormat());
		m_context->create();

		needsInitialize = true;
	}

	m_context->makeCurrent(this);

	if (needsInitialize) {
		initializeOpenGLFunctions();
		initialize();
	}

	render();

	m_context->swapBuffers(this);

	if (m_animating)
		renderLater();
}


QOpenGLContext* Window::getContext()
{
	return this->m_context;
}



bool Window::isValid()
{
	//@TODO
	return false;
}

void Window::useCursorInput()
{
	//@TODO
}

void Window::swapBuffers()
{
	//@TODO
}
#endif