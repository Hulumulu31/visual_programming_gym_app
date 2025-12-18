/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *profileTab;
    QFormLayout *formLayout;
    QLabel *_nameLabel;
    QLabel *nameValueLabel;
    QLabel *emailLabel;
    QLabel *emailValueLabel;
    QWidget *myMembershipsTab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *membershipTable;
    QWidget *availableMembershipsTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *availableMembershipsTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buyMembershipButton;
    QWidget *trainerServicesTab;
    QVBoxLayout *verticalLayout_trainerServices;
    QTableWidget *trainerServicesTable;
    QHBoxLayout *horizontalLayout_trainerServices;
    QSpacerItem *horizontalSpacer_trainerServices;
    QPushButton *buyTrainerServiceButton;
    QWidget *visitsTab;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *visitsTable;
    QHBoxLayout *horizontalLayout_visits;
    QSpacerItem *horizontalSpacer_visits;
    QPushButton *markVisitButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName("ClientWindow");
        ClientWindow->resize(800, 600);
        centralWidget = new QWidget(ClientWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        profileTab = new QWidget();
        profileTab->setObjectName("profileTab");
        formLayout = new QFormLayout(profileTab);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(1, 1, 1, 1);
        formLayout->setObjectName("formLayout");
        _nameLabel = new QLabel(profileTab);
        _nameLabel->setObjectName("_nameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, _nameLabel);

        nameValueLabel = new QLabel(profileTab);
        nameValueLabel->setObjectName("nameValueLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameValueLabel);

        emailLabel = new QLabel(profileTab);
        emailLabel->setObjectName("emailLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, emailLabel);

        emailValueLabel = new QLabel(profileTab);
        emailValueLabel->setObjectName("emailValueLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, emailValueLabel);

        tabWidget->addTab(profileTab, QString());
        myMembershipsTab = new QWidget();
        myMembershipsTab->setObjectName("myMembershipsTab");
        verticalLayout_2 = new QVBoxLayout(myMembershipsTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        membershipTable = new QTableWidget(myMembershipsTab);
        if (membershipTable->columnCount() < 5)
            membershipTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        membershipTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        membershipTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        membershipTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        membershipTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        membershipTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        membershipTable->setObjectName("membershipTable");

        verticalLayout_2->addWidget(membershipTable);

        tabWidget->addTab(myMembershipsTab, QString());
        availableMembershipsTab = new QWidget();
        availableMembershipsTab->setObjectName("availableMembershipsTab");
        verticalLayout_3 = new QVBoxLayout(availableMembershipsTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        availableMembershipsTable = new QTableWidget(availableMembershipsTab);
        if (availableMembershipsTable->columnCount() < 4)
            availableMembershipsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        availableMembershipsTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        availableMembershipsTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        availableMembershipsTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        availableMembershipsTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        availableMembershipsTable->setObjectName("availableMembershipsTable");

        verticalLayout_3->addWidget(availableMembershipsTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buyMembershipButton = new QPushButton(availableMembershipsTab);
        buyMembershipButton->setObjectName("buyMembershipButton");

        horizontalLayout->addWidget(buyMembershipButton);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget->addTab(availableMembershipsTab, QString());
        trainerServicesTab = new QWidget();
        trainerServicesTab->setObjectName("trainerServicesTab");
        verticalLayout_trainerServices = new QVBoxLayout(trainerServicesTab);
        verticalLayout_trainerServices->setSpacing(6);
        verticalLayout_trainerServices->setContentsMargins(1, 1, 1, 1);
        verticalLayout_trainerServices->setObjectName("verticalLayout_trainerServices");
        trainerServicesTable = new QTableWidget(trainerServicesTab);
        if (trainerServicesTable->columnCount() < 6)
            trainerServicesTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(5, __qtablewidgetitem14);
        trainerServicesTable->setObjectName("trainerServicesTable");

        verticalLayout_trainerServices->addWidget(trainerServicesTable);

        horizontalLayout_trainerServices = new QHBoxLayout();
        horizontalLayout_trainerServices->setSpacing(6);
        horizontalLayout_trainerServices->setObjectName("horizontalLayout_trainerServices");
        horizontalSpacer_trainerServices = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_trainerServices->addItem(horizontalSpacer_trainerServices);

        buyTrainerServiceButton = new QPushButton(trainerServicesTab);
        buyTrainerServiceButton->setObjectName("buyTrainerServiceButton");

        horizontalLayout_trainerServices->addWidget(buyTrainerServiceButton);


        verticalLayout_trainerServices->addLayout(horizontalLayout_trainerServices);

        tabWidget->addTab(trainerServicesTab, QString());
        visitsTab = new QWidget();
        visitsTab->setObjectName("visitsTab");
        verticalLayout_4 = new QVBoxLayout(visitsTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        visitsTable = new QTableWidget(visitsTab);
        if (visitsTable->columnCount() < 1)
            visitsTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        visitsTable->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        visitsTable->setObjectName("visitsTable");

        verticalLayout_4->addWidget(visitsTable);

        horizontalLayout_visits = new QHBoxLayout();
        horizontalLayout_visits->setSpacing(6);
        horizontalLayout_visits->setObjectName("horizontalLayout_visits");
        horizontalSpacer_visits = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_visits->addItem(horizontalSpacer_visits);

        markVisitButton = new QPushButton(visitsTab);
        markVisitButton->setObjectName("markVisitButton");

        horizontalLayout_visits->addWidget(markVisitButton);


        verticalLayout_4->addLayout(horizontalLayout_visits);

        tabWidget->addTab(visitsTab, QString());

        verticalLayout->addWidget(tabWidget);

        ClientWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        ClientWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(ClientWindow);
        statusBar->setObjectName("statusBar");
        ClientWindow->setStatusBar(statusBar);

        retranslateUi(ClientWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QCoreApplication::translate("ClientWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\201\320\272\320\260\321\217 \320\277\320\260\320\275\320\265\320\273\321\214", nullptr));
        _nameLabel->setText(QCoreApplication::translate("ClientWindow", "\320\230\320\274\321\217:", nullptr));
        emailLabel->setText(QCoreApplication::translate("ClientWindow", "Email:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(profileTab), QCoreApplication::translate("ClientWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = membershipTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ClientWindow", "\320\242\320\270\320\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = membershipTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ClientWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = membershipTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ClientWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = membershipTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ClientWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = membershipTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ClientWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(myMembershipsTab), QCoreApplication::translate("ClientWindow", "\320\234\320\276\320\270 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = availableMembershipsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ClientWindow", "\320\242\320\270\320\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = availableMembershipsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ClientWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = availableMembershipsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ClientWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = availableMembershipsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ClientWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        buyMembershipButton->setText(QCoreApplication::translate("ClientWindow", "\320\232\321\203\320\277\320\270\321\202\321\214 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(availableMembershipsTab), QCoreApplication::translate("ClientWindow", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = trainerServicesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ClientWindow", "\320\222\320\270\320\264 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = trainerServicesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ClientWindow", "\320\241\321\200\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = trainerServicesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ClientWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = trainerServicesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ClientWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = trainerServicesTable->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ClientWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = trainerServicesTable->horizontalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ClientWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        buyTrainerServiceButton->setText(QCoreApplication::translate("ClientWindow", "\320\232\321\203\320\277\320\270\321\202\321\214 \321\203\321\201\320\273\321\203\320\263\321\203", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(trainerServicesTab), QCoreApplication::translate("ClientWindow", "\320\242\321\200\320\265\320\275\320\265\321\200\321\201\320\272\320\270\320\265 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = visitsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ClientWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        markVisitButton->setText(QCoreApplication::translate("ClientWindow", "\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(visitsTab), QCoreApplication::translate("ClientWindow", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
