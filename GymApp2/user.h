#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

enum class UserType {
    Admin,
    Client
};

class User {
public:
    User();
    User(int id, const QString& name, const QString& email, UserType type, const QString& password = "");
    User(int id, const QString& name, const QString& email, const QString& password, UserType type); // Alternative constructor

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

private:
    int m_id;
    QString m_name;
    QString m_email;
    QString m_password;
    UserType m_type;
};

#endif // USER_H