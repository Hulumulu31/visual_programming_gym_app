#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QObject>
#include <QTimer>
#include <QDate>
#include "membershipmanager.h"
#include "observer.h"

class NotificationManager : public QObject, public Observer {
    Q_OBJECT

public:
    explicit NotificationManager(MembershipManager* membershipManager, QObject* parent = nullptr);

    void update(const QString& message) override;

public slots:
    void checkExpirations();

private:
    MembershipManager* m_membershipManager;
    QTimer* m_timer;
};

#endif // NOTIFICATIONMANAGER_H