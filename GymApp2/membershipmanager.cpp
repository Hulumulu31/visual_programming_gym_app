#include "membershipmanager.h"
#include <QDate>
#include <QString>
#include "notificationmanager.h"

MembershipManager::MembershipManager(QObject* parent) : QObject(parent) {}

void MembershipManager::addMembership(const Membership& membership) {
    m_memberships.append(membership);
    // Check if the membership is already expired
    if (membership.getEndDate() < QDate::currentDate()) {
        // Notify observers about the new expired membership
        notify();
    }
}

QList<Membership> MembershipManager::getMemberships() const {
    return m_memberships;
}

QList<Membership> MembershipManager::getMembershipsForUser(int userId) const {
    QList<Membership> result;
    for (const auto& membership : m_memberships) {
        if (membership.getUserId() == userId) {
            result.append(membership);
        }
    }
    return result;
}

void MembershipManager::updateMembership(const Membership& membership) {
    for (int i = 0; i < m_memberships.size(); ++i) {
        if (m_memberships[i].getId() == membership.getId()) {
            m_memberships[i] = membership;
            break;
        }
    }
}

void MembershipManager::removeMembership(int id) {
    for (int i = 0; i < m_memberships.size(); ++i) {
        if (m_memberships[i].getId() == id) {
            m_memberships.removeAt(i);
            break;
        }
    }
}

void MembershipManager::checkForExpirations() {
    bool hasExpirations = false;
    for (const auto& membership : m_memberships) {
        if (membership.getEndDate() < QDate::currentDate() && 
            membership.getStatus() != MembershipStatus::Expired) {
            hasExpirations = true;
            break;
        }
    }
    
    if (hasExpirations) {
        notify();
    }
}

// Subject interface implementation
void MembershipManager::attach(QObject* observer) {
    m_observers.append(observer);
}

void MembershipManager::detach(QObject* observer) {
    m_observers.removeAll(observer);
}

void MembershipManager::notify() {
    QString message = QString("Напоминание: Некоторые абонементы истекли или скоро истекут!");
    for (auto* observer : m_observers) {
        // Try to cast to NotificationManager specifically
        if (auto* notificationManager = qobject_cast<NotificationManager*>(observer)) {
            notificationManager->update(message);
        }
    }
}