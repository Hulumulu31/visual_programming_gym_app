#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>
#include <QString>
#include "membership.h"

// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(QObject* observer) = 0;
    virtual void detach(QObject* observer) = 0;
    virtual void notify() = 0;
};

// Observer interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const QString& message) = 0;
};

// Concrete Observer - Notification Manager
// This class is defined separately in notificationmanager.h to avoid conflicts
// The Observer interface is sufficient for most use cases

#endif // OBSERVER_H