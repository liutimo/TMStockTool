#ifndef FRAMELESSWIDGETLINUX_H
#define FRAMELESSWIDGETLINUX_H

#include "framelesswidget.h"

#include <QRect>
#include <QVector>

#ifndef Q_OS_WIN
class FramelessWidgetLinux : public FramelessWidget
{
    Q_OBJECT
public:
    FramelessWidgetLinux(bool p_frameless, QWidget *p_parent = nullptr);

    void setTitleBar(QWidget *p_titleBar) Q_DECL_OVERRIDE;

protected:
    bool eventFilter(QObject *p_obj, QEvent *p_event) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *p_event) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *p_event) Q_DECL_OVERRIDE;

    void mouseMoveEvent(QMouseEvent *p_event) Q_DECL_OVERRIDE;

    void showEvent(QShowEvent *p_event) Q_DECL_OVERRIDE;

private:
    enum Area
    {
        Left = 0,
        TopLeft,
        Top,
        TopRight,
        Right,
        BottomRight,
        Bottom,
        BottomLeft,
        Caption,
        None
    };

    Area hitArea(const QPoint &p_pos) const;

    void doResize(QEvent *p_event);

    void recordMousePress(const QPoint &p_pos);

    const int m_resizeAreaWidth = 6;

    int m_titleBarHeight = 0;

    Area m_mousePressArea = Area::None;

    QPoint m_mousePressPoint;

    bool m_mousePressed = false;

    QRect m_rectOnMousePress;
};
#else
class FramelessWidgetLinuxDummy
{
public:
    FramelessWidgetLinuxDummy() = default;
};
#endif

#endif // FRAMELESSWIDGETLINUX_H
