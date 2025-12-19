#include "user.h"
#include <QString>

User::User() : m_id(0), m_type(UserType::Client) {}

User::User(int id, const QString& name, const QString& email, const QString& password, UserType type)
    : m_id(id), m_name(name), m_email(email), m_password(hashPassword(password)), m_type(type) {}

User::User(int id, const QString& name, const QString& email, const QString& hashedPassword, UserType type, bool isAlreadyHashed)
    : m_id(id), m_name(name), m_email(email), m_type(type) {
    if (isAlreadyHashed) {
        m_password = hashedPassword; // Устанавливаем уже хешированный пароль
    } else {
        m_password = hashPassword(hashedPassword); // Хешируем пароль
    }
}

User User::createWithPlainPassword(int id, const QString& name, const QString& email, const QString& password, UserType type) {
    return User(id, name, email, password, type); // Вызывает конструктор, который хеширует пароль
}

User User::createWithHashedPassword(int id, const QString& name, const QString& email, const QString& hashedPassword, UserType type) {
    return User(id, name, email, hashedPassword, type, true); // Вызывает конструктор с уже захешированным паролем
}

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
    m_password = hashPassword(password);
}

void User::setUserType(UserType type) {
    m_type = type;
}

// Реализация метода хеширования пароля
QString User::hashPassword(const QString& password) {
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}