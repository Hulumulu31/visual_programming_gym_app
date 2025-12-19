#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>
#include <QCryptographicHash>

enum class UserType {
    Admin,
    Client
};

class User {
public:
    User();
    User(int id, const QString& name, const QString& email, const QString& password, UserType type); // Constructor with password that will be hashed
    // Конструктор для создания пользователя с уже хешированным паролем
    User(int id, const QString& name, const QString& email, const QString& hashedPassword, UserType type, bool isAlreadyHashed);
    // Статические методы для удобного создания пользователей
    static User createWithPlainPassword(int id, const QString& name, const QString& email, const QString& password, UserType type);
    static User createWithHashedPassword(int id, const QString& name, const QString& email, const QString& hashedPassword, UserType type);

    int getId() const;
    QString getName() const;
    QString getEmail() const;
    QString getPassword() const;
    UserType getUserType() const;

    void setId(int id);
    void setName(const QString& name);
    void setEmail(const QString& email);
    void setPassword(const QString& password);
    void setUserType(UserType type);
    
    // Метод для хеширования пароля
    static QString hashPassword(const QString& password);

private:
    int m_id;
    QString m_name;
    QString m_email;
    QString m_password;
    UserType m_type;
};

#endif // USER_H