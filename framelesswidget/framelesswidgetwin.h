#ifndef FRAMELESSWIDGETWIN_H
#define FRAMELESSWIDGETWIN_H

#include "framelesswidget.h"

#ifdef Q_OS_WIN
class FramelessWidgetWin : public FramelessWidget
{
    Q_OBJECT
public:
    FramelessWidgetWin(bool p_frameless, QWidget *p_parent = nullptr);

protected:
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
    bool nativeEvent(const QByteArray &p_eventType, void *p_message, qintptr *p_result);
#else
    bool nativeEvent(const QByteArray &p_eventType, void *p_message, long *p_result);
#endif

    void moveEvent(QMoveEvent *p_event) Q_DECL_OVERRIDE;

    void setWindowFlagsOnUpdate() Q_DECL_OVERRIDE;

private:
    // To fix some unkonwn bugs of the interface.
    void forceRedraw();

    void updateMargins();

    int m_resizeAreaWidth = 6;

    QTimer *m_redrawTimer = nullptr;

    QSize m_sizeBeforeMove;

    QMargins m_maximizedMargins;

    int m_titleBarHeight = 0;
};
#else
class FramelessWidgetWinDummy
{
public:
    FramelessWidgetWinDummy() = default;
};
#endif


#endif // FRAMELESSWIDGETWIN_H
