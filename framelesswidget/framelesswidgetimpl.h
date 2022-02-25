#ifndef FRAMELESSWIDGETIMPL_H
#define FRAMELESSWIDGETIMPL_H

#include "framelesswidgetwin.h"
#include "framelesswidgetlinux.h"


#ifdef Q_OS_WIN
    typedef FramelessWidgetWin FramelessWidgetImpl;
#else
    typedef FramelessWidgetLinux FramelessWidgetImpl;
#endif


#endif // FRAMELESSWIDGETIMPL_H
