#include "vpnform.h"
#include "tabcompleter.h"
#include "src/group.h"
#include "src/widget/groupwidget.h"
#include "src/widget/tool/chattextedit.h"
#include "src/widget/croppinglabel.h"
#include "src/widget/maskablepixmapwidget.h"
#include "src/core/core.h"
#include "src/misc/style.h"
#include <QPushButton>
#include <QMimeData>
#include <QDragEnterEvent>
#include "src/historykeeper.h"
#include "src/misc/flowlayout.h"
#include <QDebug>
#include <QTimer>

/*
    Copyright (C) 2014 by Project Tox <https://tox.im>

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

VPNForm::VPNForm(VPN::Ptr vpn): _vpn(vpn)
{
    nameLabel->setText(vpn->getName());
    avatar->setPixmap(Style::scaleSvgImage(":/img/vpn_button.png", avatar->width(), avatar->height()), Qt::transparent);
#if 0
    for (const VPN::VPNMember &member : vpn->getMembers())
    {
        QLabel *l = new QLabel(member.ip);
        l->setTextFormat(Qt::PlainText);
        namesListLayout->addWidget(l);
    }

    headTextLayout->addWidget(nusersLabel);
    headTextLayout->addLayout(namesListLayout);
    headTextLayout->addStretch();

    nameLabel->setMinimumHeight(12);
    nusersLabel->setMinimumHeight(12);
    setAcceptDrops(true);
#endif
}

void VPNForm::keyPressEvent(QKeyEvent *ev)
{

}

void VPNForm::keyReleaseEvent(QKeyEvent *ev)
{

}

void VPNForm::dropEvent(QDropEvent *ev)
{
    if (ev->mimeData()->hasFormat("friend"))
    {
        int friendId = ev->mimeData()->data("friend").toInt();
        _vpn->requestMembership(friendId);
    }
}

void VPNForm::dragEnterEvent(QDragEnterEvent *ev)
{
    if (ev->mimeData()->hasFormat("friend"))
        ev->acceptProposedAction();
}
