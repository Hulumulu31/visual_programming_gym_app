#include "visit.h"

Visit::Visit() : m_id(0), m_userId(0) {}

Visit::Visit(int id, int userId, const QDateTime& dateTime)
    : m_id(id), m_userId(userId), m_dateTime(dateTime) {}

int Visit::getId() const {
    return m_id;
}

int Visit::getUserId() const {
    return m_userId;
}

QDateTime Visit::getDateTime() const {
    return m_dateTime;
}

void Visit::setId(int id) {
    m_id = id;
}

void Visit::setUserId(int userId) {
    m_userId = userId;
}

void Visit::setDateTime(const QDateTime& dateTime) {
    m_dateTime = dateTime;
}