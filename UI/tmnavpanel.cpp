#include "tmnavpanel.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QtGlobal>


#define NAVITEM_FIXED_HEIGHT 48

TMNavPanel::TMNavPanel(QWidget *parent) : QWidget(parent), mNavItemId(0), mNavItemFixedHeight(NAVITEM_FIXED_HEIGHT)
{
    connect(&mBtnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this,  [this](int id){
        qDebug() << mBtnGroup.checkedId() << ":" << id;
        emit navItemChanged(id);
    });
}

TMNavPanel::~TMNavPanel()
{
    for (auto* btn : mBtnGroup.buttons()) {
        mBtnGroup.removeButton(btn);
        delete btn;
    }
}

void TMNavPanel::setOrientation(NavOrientation ori)
{
    auto layout = this->layout();
    if (layout != nullptr) {
        delete layout;
    }

    QBoxLayout *boxLayout = nullptr;
    if (ori == NavOrientation::HORIZONTAL) {
        boxLayout = new QHBoxLayout();
    } else {
        boxLayout = new QVBoxLayout();
    }

    boxLayout->setSpacing(0);

    for (auto* btn : mBtnGroup.buttons()) {
        boxLayout->addWidget(btn);
    }


    boxLayout->addStretch();
    setLayout(boxLayout);
    //relayout
    adjustSize();
}

int TMNavPanel::addNavItem(QAbstractButton *widget)
{
    widget->setFixedHeight(mNavItemFixedHeight);
    mBtnGroup.addButton(widget);
    return mBtnGroup.id(widget);
}

int TMNavPanel::addNavItem(const QString &title)
{
    auto* navItem = new NavItem(title);
    return addNavItem(navItem);
}

void TMNavPanel::setNavItemFixedHeight(int h)
{
    mNavItemFixedHeight = h;
}

void TMNavPanel::setCheckNavItemByID(int id)
{
    auto *button = mBtnGroup.button(id);
    if (button != nullptr) {
        button->setChecked(true);
    }
}



//
TMNavPanel::NavItem::NavItem(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setCheckable(true);
    setFocusPolicy(Qt::NoFocus);
}
