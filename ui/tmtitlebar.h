#ifndef TMTITLEBAR_H
#define TMTITLEBAR_H

#include <QWidget>

namespace Ui {
class TMTitleBar;
}

#include <QPoint>

class TMTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TMTitleBar(QWidget *parent = nullptr);
    ~TMTitleBar();

protected:
    void mousePressEvent(QMouseEvent *p_event) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *p_event) Q_DECL_OVERRIDE;

    void mouseMoveEvent(QMouseEvent *p_event) Q_DECL_OVERRIDE;

    void paintEvent(QPaintEvent *p_event) Q_DECL_OVERRIDE;
private:
    Ui::TMTitleBar *ui;

    bool mPressed = false;
    QPoint mPressPoint;
};

#endif // TMTITLEBAR_H
