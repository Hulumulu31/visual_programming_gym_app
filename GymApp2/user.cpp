#include "user.h"
#include <QString>

User::User() : m_id(0), m_type(UserType::Client) {}

User::User(int id, const QString& name, const QString& email, UserType type, const QString& password)
    : m_id(id), m_name(name), m_email(email), m_password(password), m_type(type) {}

User::User(int id, const QString& name, const QString& email, const QString& password, UserType type)
    : m_id(id), m_name(name), m_email(email), m_password(password), m_type(type) {}

int User::getId() const {
    return m_id;
}

QString User::getName() const {
    return m_name;
}

QString User::getEmail() const {
    return m_email;
}

QString User::getPassword() const {
    return m_password;
}

UserType User::getUserType() const {
    return m_type;
}

void User::setId(int id) {
    m_id = id;
}

void User::setName(const QString& name) {
    m_name = name;
}

void User::setEmail(const QString& email) {
    m_email = email;
}

void User::setPassword(const QString& password) {
    m_password = password;
}

void User::setUserType(UserType type) {
    m_type = type;
}