/********************************************************************************
** Form generated from reading UI file 'visitdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISITDIALOG_H
#define UI_VISITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VisitDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *userIdLabel;
    QLineEdit *userIdLineEdit;
    QLabel *dateTimeLabel;
    QDateTimeEdit *dateTimeEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VisitDialog)
    {
        if (VisitDialog->objectName().isEmpty())
            VisitDialog->setObjectName("VisitDialog");
        VisitDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(VisitDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        userIdLabel = new QLabel(VisitDialog);
        userIdLabel->setObjectName("userIdLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, userIdLabel);

        userIdLineEdit = new QLineEdit(VisitDialog);
        userIdLineEdit->setObjectName("userIdLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, userIdLineEdit);

        dateTimeLabel = new QLabel(VisitDialog);
        dateTimeLabel->setObjectName("dateTimeLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, dateTimeLabel);

        dateTimeEdit = new QDateTimeEdit(VisitDialog);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, dateTimeEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(VisitDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(VisitDialog);

        QMetaObject::connectSlotsByName(VisitDialog);
    } // setupUi

    void retranslateUi(QDialog *VisitDialog)
    {
        VisitDialog->setWindowTitle(QCoreApplication::translate("VisitDialog", "Dialog", nullptr));
        userIdLabel->setText(QCoreApplication::translate("VisitDialog", "ID \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        dateTimeLabel->setText(QCoreApplication::translate("VisitDialog", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VisitDialog: public Ui_VisitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISITDIALOG_H
