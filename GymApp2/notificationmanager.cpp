#include "notificationmanager.h"
#include <QTimer>
#include <QDate>
#include <QMessageBox>
#include <QApplication>

NotificationManager::NotificationManager(MembershipManager* membershipManager, QObject* parent)
    : QObject(parent), m_membershipManager(membershipManager) {
    
    // Set up a timer to check for expirations periodically (e.g., daily)
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &NotificationManager::checkExpirations);
    m_timer->start(24 * 60 * 1000); // 24 hours in milliseconds
    
    // Also check when the notification manager is created
    QTimer::singleShot(0, this, &NotificationManager::checkExpirations);
}

void NotificationManager::update(const QString& message) {
    // Show notification to the user
    QMessageBox::information(nullptr, "Напоминание", message);
}

void NotificationManager::checkExpirations() {
    // Get all memberships
    QList<Membership> memberships = m_membershipManager->getMemberships();
    
    QDate today = QDate::currentDate();
    QString message = "Напоминание: ";
    bool hasExpiring = false;
    
    // Check for memberships that are expired or will expire soon (e.g., within 3 days)
    for (const auto& membership : memberships) {
        QDate endDate = membership.getEndDate();
        int daysUntilExpiry = today.daysTo(endDate);
        
        if (daysUntilExpiry <= 0) {
            // Already expired
            message += QString("Абонемент ID %1 (пользователь %2) истек! ")
                           .arg(membership.getId())
                           .arg(membership.getUserId());
            hasExpiring = true;
        } else if (daysUntilExpiry <= 3) {
            // Will expire soon
            message += QString("Абонемент ID %1 (пользователь %2) истекает через %3 дней! ")
                           .arg(membership.getId())
                           .arg(membership.getUserId())
                           .arg(daysUntilExpiry);
            hasExpiring = true;
        }
    }
    
    if (hasExpiring) {
        QMessageBox::information(nullptr, "Напоминание об окончании абонементов", message);
    }
}