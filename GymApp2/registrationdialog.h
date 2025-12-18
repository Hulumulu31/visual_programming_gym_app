#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include <QDialog>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RegistrationDialog; }
QT_END_NAMESPACE

class RegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationDialog(QWidget *parent = nullptr);
    ~RegistrationDialog();

    User getUser() const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::RegistrationDialog *ui;
    User m_user;
};

#endif // REGISTRATIONDIALOG_H