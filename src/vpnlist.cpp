#include "vpnlist.h"
#include "nexus.h"
#include "core/core.h"

#include <cassert>
#include <stdint.h>
#include <inttypes.h>
#include <QVector>
#include <QDebug>

VPNList::VPNList()
{
}

VPNList::~VPNList()
{

}

void VPNList::update()
{
    clear();

    Core *core = Nexus::getCore();
    QVector<uint32_t> list = core->getVPNList();
    qDebug() << "building VPNList with " << list.size() << " entries";
    for (const uint32_t toxvpnId: list)
    {
        VPNEntry entry(toxvpnId);
        this->append(entry);
    }
}

VPNEntry::VPNEntry(uint32_t toxvpnId): _toxvpnId(toxvpnId)
{
    Core *core = Nexus::getCore();

    _ip = core->getVPN_IP(toxvpnId);
    _name = core->getVPNName(toxvpnId);

    for (const uint32_t friendId: core->getVPNFriendsList(toxvpnId))
    {
        VPNEntry::VPNMember member;
        member.friendId = friendId;
        member.ip = core->getVPNFriendIP(toxvpnId, friendId);
        member.online = core->isFriendOnline(friendId);
        _members.append(member);
    }
}
