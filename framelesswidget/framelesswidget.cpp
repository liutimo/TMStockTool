#include "framelesswidget.h"

#include <QEvent>


FramelessWidget::FramelessWidget(bool p_frameless, QWidget *p_parent)
    : QWidget(p_parent),
      m_frameless(p_frameless),
      m_defaultFlags(windowFlags())
{
    if (m_frameless) {
        setWindowFlags(m_defaultFlags | Qt::FramelessWindowHint);
    }
}


bool FramelessWidget::isFrameless() const
{
    return m_frameless;
}

void FramelessWidget::setTitleBar(QWidget *p_titleBar)
{
    Q_ASSERT(!m_titleBar && m_frameless);

    m_titleBar = p_titleBar;
}

void FramelessWidget::changeEvent(QEvent *p_event)
{
    QWidget::changeEvent(p_event);

    if (p_event->type() == QEvent::WindowStateChange) {
        m_windowStates = windowState();
        m_resizable = m_windowStates == Qt::WindowNoState;
        m_movable = m_windowStates == Qt::WindowNoState;
        emit windowStateChanged(m_windowStates);
    }
}

bool FramelessWidget::isMaximized() const
{
    return (m_windowStates & Qt::WindowMaximized) && !(m_windowStates & Qt::WindowFullScreen);
}

void FramelessWidget::setWindowFlagsOnUpdate()
{
    // Do nothing by default.
}
