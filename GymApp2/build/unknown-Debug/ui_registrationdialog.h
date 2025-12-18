/********************************************************************************
** Form generated from reading UI file 'registrationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONDIALOG_H
#define UI_REGISTRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistrationDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *confirmPasswordLabel;
    QLineEdit *confirmPasswordLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RegistrationDialog)
    {
        if (RegistrationDialog->objectName().isEmpty())
            RegistrationDialog->setObjectName("RegistrationDialog");
        RegistrationDialog->resize(400, 250);
        verticalLayout = new QVBoxLayout(RegistrationDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(RegistrationDialog);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(RegistrationDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameLineEdit);

        emailLabel = new QLabel(RegistrationDialog);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(RegistrationDialog);
        emailLineEdit->setObjectName("emailLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, emailLineEdit);

        passwordLabel = new QLabel(RegistrationDialog);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, passwordLabel);

        passwordLineEdit = new QLineEdit(RegistrationDialog);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, passwordLineEdit);

        confirmPasswordLabel = new QLabel(RegistrationDialog);
        confirmPasswordLabel->setObjectName("confirmPasswordLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, confirmPasswordLabel);

        confirmPasswordLineEdit = new QLineEdit(RegistrationDialog);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");
        confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, confirmPasswordLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(RegistrationDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RegistrationDialog);

        QMetaObject::connectSlotsByName(RegistrationDialog);
    } // setupUi

    void retranslateUi(QDialog *RegistrationDialog)
    {
        RegistrationDialog->setWindowTitle(QCoreApplication::translate("RegistrationDialog", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("RegistrationDialog", "\320\230\320\274\321\217:", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegistrationDialog", "Email:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegistrationDialog", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        confirmPasswordLabel->setText(QCoreApplication::translate("RegistrationDialog", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationDialog: public Ui_RegistrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONDIALOG_H
