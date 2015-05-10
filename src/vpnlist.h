#ifndef VPNLIST_H
#define VPNLIST_H

#include <QList>
#include <QString>

class VPNEntry
{
public:
    struct VPNMember {
    public:
        QString ip;
        uint32_t friendId;
        bool online;
    };

    VPNEntry(uint32_t toxvpnId);
    const QList<VPNMember> &getMembers() const { return _members; }
    QString getName() const { return _name; }
    QString getIP() const { return _ip; }
private:
    VPNEntry();

    QString _name;
    QString _ip;

    uint32_t _toxvpnId;
    QList<VPNMember> _members;
};

class VPNList: public QList<VPNEntry>
{
public:
    VPNList();
    ~VPNList();
    void update();
};

#endif // VPNLIST_H
