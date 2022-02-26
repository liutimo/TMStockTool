#ifndef FRAMELESSWIDGETIMPL_H
#define FRAMELESSWIDGETIMPL_H

#include "framelesswidgetwin.h"
#include "framelesswidgetlinux.h"

#ifndef USB_FRAMELESS_WIDGET
#define USB_FRAMELESS_WIDGET 1
#endif

#ifdef USB_FRAMELESS_WIDGET

#ifdef Q_OS_WIN
    typedef FramelessWidgetWin FramelessWidgetImpl;
#else
    typedef FramelessWidgetLinux FramelessWidgetImpl;
#endif

#else
    typedef QWidget FramelessWidgetImpl;
#endif

#endif // FRAMELESSWIDGETIMPL_H
