#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>
#include <QMargins>

class QTimer;
class QPushButton;
class QLabel;

// Base class. Use FramelessWidgetImpl instead.
class FramelessWidget : public QWidget
{
    Q_OBJECT
public:
    FramelessWidget(bool p_frameless, QWidget *p_parent = nullptr/*, bool showTitleBar = false*/);

    bool isFrameless() const;

    virtual void setTitleBar(QWidget *p_titleBar);
signals:
    void windowStateChanged(Qt::WindowStates p_state);

protected:
    void changeEvent(QEvent *p_event) Q_DECL_OVERRIDE;

protected:
    bool isMaximized() const;

    virtual void setWindowFlagsOnUpdate();

    const bool m_frameless = true;

    bool m_movable = true;

    bool m_resizable = false;

    const Qt::WindowFlags m_defaultFlags;

    QWidget *m_titleBar = nullptr;

    Qt::WindowStates m_windowStates = Qt::WindowNoState;


private:
//    void initTitleBar();

//    QLabel *mIcon;
//    QLabel *mTitle;
//    QPushButton *mCloseBtn;

};

#endif // FRAMELESSWIDGET_H
