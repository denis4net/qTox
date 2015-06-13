#ifndef VPNLIST_H
#define VPNLIST_H

#include <QList>
#include <QString>
#include <memory>

class VPN
{
public:
    typedef std::shared_ptr<VPN> Ptr;

    struct VPNMember {
    public:
        QString ip;
        uint32_t friendId;
        bool online;
    };

    VPN(uint32_t toxvpnId);
    const QList<VPNMember> &getMembers() const { return _members; }
    QString getName() const { return _name; }
    QString getIP() const { return _ip; }
    bool requestMembership(uint32_t friendId);
private:
    VPN();

    QString _name;
    QString _ip;

    uint32_t _toxvpnId;
    QList<VPNMember> _members;
};

class VPNList: public QList< std::shared_ptr<VPN> >
{
public:
    VPNList();
    ~VPNList();
    void update();
};

#endif // VPNLIST_H
