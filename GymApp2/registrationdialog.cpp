#include "registrationdialog.h"
#include "ui_registrationdialog.h"
#include <QMessageBox>

RegistrationDialog::RegistrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog)
{
    ui->setupUi(this);
    setWindowTitle("Регистрация");
}

RegistrationDialog::~RegistrationDialog()
{
    delete ui;
}

void RegistrationDialog::on_buttonBox_accepted()
{
    QString name = ui->nameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();
    
    // Validate input
    if (name.isEmpty() || email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля обязательны для заполнения");
        return;
    }
    
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают");
        return;
    }
    
    // Create user with default ID, the DataManager will assign a proper ID when adding the user
    m_user = User(0, name, email, password, UserType::Client);
    
    // In a real application, you would hash the password before storing it
    // For this implementation, we'll just store it as-is (not recommended for production)
    
    // Accept the dialog to return QDialog::Accepted
    accept();
}

void RegistrationDialog::on_buttonBox_rejected()
{
    // Close the dialog with QDialog::Rejected result
    reject();
}

User RegistrationDialog::getUser() const
{
    return m_user;
}