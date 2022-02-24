#ifndef TMNAVPANEL_H
#define TMNAVPANEL_H

#include <QPushButton>
#include <QButtonGroup>
#include <QWidget>

class QPushButton;


class TMNavPanel : public QWidget
{
    Q_OBJECT
public:
    explicit TMNavPanel(QWidget *parent = nullptr);

    ~TMNavPanel();

    enum class NavOrientation{
        HORIZONTAL,
        VERTIAL
    };


    void setOrientation(NavOrientation ori);

    ///
    /// \brief addNavItem
    /// \param widget
    /// 该函数执行后，widget的内存交由TMNavPanel管理
    int addNavItem(QAbstractButton *widget);

    int addNavItem(const QString& title);

    void setNavItemFixedHeight(int height);

    void setCheckNavItemByID(int id);
signals:
    void navItemChanged(uint32_t id);

private:
    class NavItem : public QPushButton {
    public:
        explicit NavItem(const QString &text, QWidget *parent = nullptr);
        //TODO: 如何定制UI
    };

private:
    NavOrientation mOrientation;

    QButtonGroup mBtnGroup;

    int mNavItemId;

    int mNavItemFixedHeight;
};

#endif // TMNAVPANEL_H
