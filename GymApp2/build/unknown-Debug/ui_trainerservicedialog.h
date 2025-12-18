/********************************************************************************
** Form generated from reading UI file 'trainerservicedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINERSERVICEDIALOG_H
#define UI_TRAINERSERVICEDIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TrainerServiceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *serviceTypeLabel;
    QComboBox *serviceTypeComboBox;
    QLabel *durationLabel;
    QComboBox *durationComboBox;
    QLabel *startDateLabel;
    QDateEdit *startDateEdit;
    QLabel *costLabel;
    QLabel *costLabelValue;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TrainerServiceDialog)
    {
        if (TrainerServiceDialog->objectName().isEmpty())
            TrainerServiceDialog->setObjectName("TrainerServiceDialog");
        TrainerServiceDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(TrainerServiceDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        serviceTypeLabel = new QLabel(TrainerServiceDialog);
        serviceTypeLabel->setObjectName("serviceTypeLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, serviceTypeLabel);

        serviceTypeComboBox = new QComboBox(TrainerServiceDialog);
        serviceTypeComboBox->addItem(QString());
        serviceTypeComboBox->addItem(QString());
        serviceTypeComboBox->addItem(QString());
        serviceTypeComboBox->addItem(QString());
        serviceTypeComboBox->setObjectName("serviceTypeComboBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, serviceTypeComboBox);

        durationLabel = new QLabel(TrainerServiceDialog);
        durationLabel->setObjectName("durationLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, durationLabel);

        durationComboBox = new QComboBox(TrainerServiceDialog);
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->addItem(QString());
        durationComboBox->setObjectName("durationComboBox");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, durationComboBox);

        startDateLabel = new QLabel(TrainerServiceDialog);
        startDateLabel->setObjectName("startDateLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, startDateLabel);

        startDateEdit = new QDateEdit(TrainerServiceDialog);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setCalendarPopup(true);
        startDateEdit->setDate(QDate(2025, 1, 1));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, startDateEdit);

        costLabel = new QLabel(TrainerServiceDialog);
        costLabel->setObjectName("costLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, costLabel);

        costLabelValue = new QLabel(TrainerServiceDialog);
        costLabelValue->setObjectName("costLabelValue");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, costLabelValue);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(TrainerServiceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TrainerServiceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TrainerServiceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TrainerServiceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TrainerServiceDialog);
    } // setupUi

    void retranslateUi(QDialog *TrainerServiceDialog)
    {
        TrainerServiceDialog->setWindowTitle(QCoreApplication::translate("TrainerServiceDialog", "\320\237\320\276\320\272\321\203\320\277\320\272\320\260 \321\202\321\200\320\265\320\275\320\265\321\200\321\201\320\272\320\276\320\271 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        serviceTypeLabel->setText(QCoreApplication::translate("TrainerServiceDialog", "\320\222\320\270\320\264 \321\202\321\200\320\265\320\275\320\265\321\200\320\260:", nullptr));
        serviceTypeComboBox->setItemText(0, QCoreApplication::translate("TrainerServiceDialog", "\320\242\321\200\320\265\320\275\320\260\320\266\320\265\321\200\320\275\321\213\320\271 \320\267\320\260\320\273", nullptr));
        serviceTypeComboBox->setItemText(1, QCoreApplication::translate("TrainerServiceDialog", "\320\223\321\200\321\203\320\277\320\277\320\276\320\262\321\213\320\265 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\272\320\270", nullptr));
        serviceTypeComboBox->setItemText(2, QCoreApplication::translate("TrainerServiceDialog", "\320\237\320\273\320\260\320\262\320\260\320\275\320\270\320\265", nullptr));
        serviceTypeComboBox->setItemText(3, QCoreApplication::translate("TrainerServiceDialog", "\320\221\320\276\320\272\321\201", nullptr));

        durationLabel->setText(QCoreApplication::translate("TrainerServiceDialog", "\320\241\321\200\320\276\320\272 \321\203\321\201\320\273\321\203\320\263\320\270:", nullptr));
        durationComboBox->setItemText(0, QCoreApplication::translate("TrainerServiceDialog", "\320\240\320\260\320\267\320\276\320\262\320\260\321\217", nullptr));
        durationComboBox->setItemText(1, QCoreApplication::translate("TrainerServiceDialog", "\320\235\320\265\320\264\320\265\320\273\321\217", nullptr));
        durationComboBox->setItemText(2, QCoreApplication::translate("TrainerServiceDialog", "\320\234\320\265\321\201\321\217\321\206", nullptr));
        durationComboBox->setItemText(3, QCoreApplication::translate("TrainerServiceDialog", "\320\237\320\276\320\273\320\263\320\276\320\264\320\260", nullptr));
        durationComboBox->setItemText(4, QCoreApplication::translate("TrainerServiceDialog", "\320\223\320\276\320\264", nullptr));
        durationComboBox->setItemText(5, QCoreApplication::translate("TrainerServiceDialog", "\320\224\320\262\320\260 \320\263\320\276\320\264\320\260", nullptr));

        startDateLabel->setText(QCoreApplication::translate("TrainerServiceDialog", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
        costLabel->setText(QCoreApplication::translate("TrainerServiceDialog", "\320\246\320\265\320\275\320\260:", nullptr));
        costLabelValue->setText(QCoreApplication::translate("TrainerServiceDialog", "500 \321\200\321\203\320\261.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainerServiceDialog: public Ui_TrainerServiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINERSERVICEDIALOG_H
