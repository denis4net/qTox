#ifndef VPNFORM_H
#define VPNFORM_H

/*
    Copyright (C) 2015 by Project ToxVPN <https://tox.im>

    This file is part of qTox, a Qt-based graphical interface for Tox.

    This program is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    See the COPYING file for more details.
*/

#include <QWidget>
#include <QPoint>
#include <QDateTime>
#include <QMenu>
#include "genericchatform.h"
#include "src/core/corestructs.h"
#include "src/vpnlist.h"
#include "ui_mainwindow.h"

namespace Ui {class MainWindow;}

class VPNForm : public GenericChatForm
{
    Q_OBJECT
public:
    VPNForm(VPN::Ptr vpn);

    void keyPressEvent(QKeyEvent* ev);
    void keyReleaseEvent(QKeyEvent* ev);

protected:
    VPN::Ptr _vpn;

    void dropEvent(QDropEvent *);
    void dragEnterEvent(QDragEnterEvent *);
};

#endif // VPNFORM_H
