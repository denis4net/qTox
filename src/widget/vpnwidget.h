#ifndef VPNWIDGET_H
#define VPNWIDGET_H

#include <QLabel>
#include <memory>
#include "genericchatroomwidget.h"
#include "src/vpnlist.h"
#include "src/widget/form/vpnform.h"

class VPNWidget: public GenericChatroomWidget
{
    Q_OBJECT
public:
    VPNWidget(std::shared_ptr<VPN> vpnInfo);
    ~VPNWidget();

private:
    std::shared_ptr<VPNForm> _vpnForm;

protected:
    std::shared_ptr<VPN> _vpn;

    void dragEnterEvent(QDragEnterEvent* ev);
    void dropEvent(QDropEvent* ev);
    void keyPressEvent(QKeyEvent* ev);
    void keyReleaseEvent(QKeyEvent* ev);
};

#endif // VPNWIDGET_H
