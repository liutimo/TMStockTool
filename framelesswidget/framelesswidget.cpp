#include "framelesswidget.h"

#include <QEvent>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>
#include <QLayout>
#include "ui/tmtitlebar.h"

#define TITLE_BAR_FIEXED_HEIGHT 28

FramelessWidget::FramelessWidget(bool p_frameless, QWidget *p_parent/*, bool showTitleBar*/)
    : QWidget(p_parent),
      m_frameless(p_frameless),
      m_defaultFlags(windowFlags())
{
    if (m_frameless) {
        setWindowFlags(m_defaultFlags | Qt::FramelessWindowHint);
    }

//    if (showTitleBar) {
//        initTitleBar();
//    }
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

void FramelessWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if (m_titleBar != nullptr) {
//        mCloseBtn->move(width() - 28, 0);
        if (layout()) {
            layout()->setContentsMargins(0, TITLE_BAR_FIEXED_HEIGHT, 0, 0);
        }
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

//void FramelessWidget::initTitleBar()
//{
//    mIcon = new QLabel(this);
//    mIcon->move(4, 0);
//    mIcon->setFixedSize(28, 28);
//    mIcon->setStyleSheet("background-image: url(:/imgs/imgs/stock_28.png); \
//                         border:none;");


//    mTitle = new QLabel(tr("About"), this);
//    mTitle->setFixedSize(100, 28);
//    mTitle->move(4 + 28 + 2, 0);


//    mCloseBtn = new QPushButton(this);
//    mCloseBtn->setFixedSize(28, 28);
//    mCloseBtn->move(width() - 28, 0);

//    m_titleBar = mCloseBtn;
//}
