#ifndef TMTITLEBAR_H
#define TMTITLEBAR_H

#include <QWidget>

namespace Ui {
class TMTitleBar;
}

class TMTitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TMTitleBar(QWidget *parent = nullptr);
    ~TMTitleBar();

private:
    Ui::TMTitleBar *ui;
};

#endif // TMTITLEBAR_H
