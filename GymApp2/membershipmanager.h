#ifndef MEMBERSHIPMANAGER_H
#define MEMBERSHIPMANAGER_H

#include <QObject>
#include <QList>
#include <QDate>
#include "membership.h"
#include "observer.h"

class MembershipManager : public QObject, public Subject {
    Q_OBJECT

public:
    explicit MembershipManager(QObject* parent = nullptr);

    // Add a new membership
    void addMembership(const Membership& membership);
    
    // Get all memberships
    QList<Membership> getMemberships() const;
    
    // Get memberships for a specific user
    QList<Membership> getMembershipsForUser(int userId) const;
    
    // Update a membership
    void updateMembership(const Membership& membership);
    
    // Remove a membership
    void removeMembership(int id);
    
    // Check for expired memberships and notify observers
    void checkForExpirations();

    // Subject interface implementation
    void attach(QObject* observer) override;
    void detach(QObject* observer) override;
    void notify() override;

private:
    QList<Membership> m_memberships;
    QList<QObject*> m_observers;
};

#endif // MEMBERSHIPMANAGER_H