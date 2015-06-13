#include "vpnwidget.h"
#include "src/nexus.h"
#include "src/core/core.h"
#include "src/vpnlist.h"

#include <QContextMenuEvent>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QInputDialog>
#include <QMessageBox>
#include <src/widget/maskablepixmapwidget.h>
#include "src/misc/style.h"

VPNWidget::VPNWidget(std::shared_ptr<VPN> vpnInfo): _vpn(vpnInfo)
{
    _vpnForm.reset(new VPNForm(_vpn));
    setName(_vpn->getName());
    setStatusMsg(_vpn->getIP());

    statusPic.setPixmap(QPixmap(":img/status/dot_online.svg"));
    statusPic.setMargin(3);

    statusMessageLabel->setText(_vpn->getIP());

    avatar->setPixmap(Style::scaleSvgImage(":img/vpn.svg", avatar->width(), avatar->height()), Qt::transparent);

    setAcceptDrops(true);
}

VPNWidget::~VPNWidget()
{

}

void VPNWidget::dragEnterEvent(QDragEnterEvent *ev)
{
    if (ev->mimeData()->hasFormat("friend"))
        ev->acceptProposedAction();
}

void VPNWidget::dropEvent(QDropEvent *ev)
{
    if (ev->mimeData()->hasFormat("friend"))
    {
        int friendId = ev->mimeData()->data("friend").toInt();
        _vpn->requestMembership(friendId);

        QMessageBox::information(this, tr("VPN"), tr("Friend has been added to \"%1\"").arg(_vpn->getIP()));
    }
}

void VPNWidget::keyPressEvent(QKeyEvent *ev)
{

    if (_vpnForm)
        _vpnForm->keyPressEvent(ev);

}

void VPNWidget::keyReleaseEvent(QKeyEvent *ev)
{
    if (_vpnForm)
        _vpnForm->keyReleaseEvent(ev);
}



