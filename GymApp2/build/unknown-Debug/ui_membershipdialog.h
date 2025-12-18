/********************************************************************************
** Form generated from reading UI file 'membershipdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERSHIPDIALOG_H
#define UI_MEMBERSHIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MembershipDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *durationLabel;
    QComboBox *durationComboBox;
    QLabel *accessLabel;
    QComboBox *accessComboBox;
    QLabel *timeLabel;
    QComboBox *timeComboBox;
    QLabel *startDateLabel;
    QDateEdit *startDateEdit;
    QLabel *costLabel;
    QLineEdit *costLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MembershipDialog)
    {
        if (MembershipDialog->objectName().isEmpty())
            MembershipDialog->setObjectName("MembershipDialog");
        MembershipDialog->resize(400, 350);
        verticalLayout = new QVBoxLayout(MembershipDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        durationLabel = new QLabel(MembershipDialog);
        durationLabel->setObjectName("durationLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, durationLabel);

        durationComboBox = new QComboBox(MembershipDialog);
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->setObjectName("durationComboBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, durationComboBox);

        accessLabel = new QLabel(MembershipDialog);
        accessLabel->setObjectName("accessLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, accessLabel);

        accessComboBox = new QComboBox(MembershipDialog);
        accessComboBox->addItem(QString());
        accessComboBox->addItem(QString());
        accessComboBox->addItem(QString());
        accessComboBox->addItem(QString());
        accessComboBox->addItem(QString());
        accessComboBox->setObjectName("accessComboBox");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, accessComboBox);

        timeLabel = new QLabel(MembershipDialog);
        timeLabel->setObjectName("timeLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, timeLabel);

        timeComboBox = new QComboBox(MembershipDialog);
        timeComboBox->addItem(QString());
        timeComboBox->addItem(QString());
        timeComboBox->addItem(QString());
        timeComboBox->addItem(QString());
        timeComboBox->setObjectName("timeComboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, timeComboBox);

        startDateLabel = new QLabel(MembershipDialog);
        startDateLabel->setObjectName("startDateLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, startDateLabel);

        startDateEdit = new QDateEdit(MembershipDialog);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, startDateEdit);

        costLabel = new QLabel(MembershipDialog);
        costLabel->setObjectName("costLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, costLabel);

        costLineEdit = new QLineEdit(MembershipDialog);
        costLineEdit->setObjectName("costLineEdit");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, costLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(MembershipDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MembershipDialog);

        QMetaObject::connectSlotsByName(MembershipDialog);
    } // setupUi

    void retranslateUi(QDialog *MembershipDialog)
    {
        MembershipDialog->setWindowTitle(QCoreApplication::translate("MembershipDialog", "Dialog", nullptr));
        durationLabel->setText(QCoreApplication::translate("MembershipDialog", "\320\241\321\200\320\276\320\272 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217:", nullptr));
        durationComboBox->setItemText(0, QCoreApplication::translate("MembershipDialog", "\320\240\320\260\320\267\320\276\320\262\321\213\320\271", nullptr));
        durationComboBox->setItemText(1, QCoreApplication::translate("MembershipDialog", "\320\234\320\265\321\201\321\217\321\207\320\275\321\213\320\271", nullptr));
        durationComboBox->setItemText(2, QCoreApplication::translate("MembershipDialog", "\320\237\320\276\320\273\321\203\320\263\320\276\320\264\320\276\320\262\320\276\320\271", nullptr));
        durationComboBox->setItemText(3, QCoreApplication::translate("MembershipDialog", "\320\223\320\276\320\264\320\276\320\262\320\276\320\271", nullptr));
        durationComboBox->setItemText(4, QCoreApplication::translate("MembershipDialog", "\320\224\320\262\321\203\321\205\320\263\320\276\320\264\320\276\320\262\320\276\320\271", nullptr));

        accessLabel->setText(QCoreApplication::translate("MembershipDialog", "\320\224\320\276\321\201\321\202\321\203\320\277 \320\272 \320\267\320\276\320\275\320\260\320\274:", nullptr));
        accessComboBox->setItemText(0, QCoreApplication::translate("MembershipDialog", "\320\242\321\200\320\265\320\275\320\260\320\266\320\265\321\200\320\275\321\213\320\271 \320\267\320\260\320\273", nullptr));
        accessComboBox->setItemText(1, QCoreApplication::translate("MembershipDialog", "\320\227\320\260\320\273 \320\263\321\200\321\203\320\277\320\277\320\276\320\262\321\213\321\205 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\276\320\272", nullptr));
        accessComboBox->setItemText(2, QCoreApplication::translate("MembershipDialog", "\320\221\320\260\321\201\321\201\320\265\320\271\320\275", nullptr));
        accessComboBox->setItemText(3, QCoreApplication::translate("MembershipDialog", "\320\221\320\276\320\272\321\201", nullptr));
        accessComboBox->setItemText(4, QCoreApplication::translate("MembershipDialog", "\320\237\320\276\320\273\320\275\321\213\320\271 \320\264\320\276\321\201\321\202\321\203\320\277", nullptr));

        timeLabel->setText(QCoreApplication::translate("MembershipDialog", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217:", nullptr));
        timeComboBox->setItemText(0, QCoreApplication::translate("MembershipDialog", "\320\243\321\202\321\200\320\265\320\275\320\275\320\270\320\271", nullptr));
        timeComboBox->setItemText(1, QCoreApplication::translate("MembershipDialog", "\320\224\320\275\320\265\320\262\320\275\320\276\320\271", nullptr));
        timeComboBox->setItemText(2, QCoreApplication::translate("MembershipDialog", "\320\222\320\265\321\207\320\265\321\200\320\275\320\270\320\271", nullptr));
        timeComboBox->setItemText(3, QCoreApplication::translate("MembershipDialog", "\320\237\320\276\320\273\320\275\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));

        startDateLabel->setText(QCoreApplication::translate("MembershipDialog", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
        costLabel->setText(QCoreApplication::translate("MembershipDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MembershipDialog: public Ui_MembershipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERSHIPDIALOG_H
