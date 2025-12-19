/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QAction *actionImport;
    QAction *actionExport;
    QAction *actionExit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *membershipsTab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *membershipsTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *addMembershipButton;
    QPushButton *editMembershipButton;
    QPushButton *deleteMembershipButton;
    QWidget *trainerServicesTab;
    QVBoxLayout *verticalLayout_trainerServices;
    QTableWidget *trainerServicesTable;
    QHBoxLayout *horizontalLayout_trainerServices;
    QPushButton *deleteTrainerServiceButton;
    QWidget *visitsTab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *visitsTable;
    QWidget *reportsTab;
    QVBoxLayout *verticalLayout_4;
    QSplitter *reportsSplitter;
    QWidget *attendanceReportWidget;
    QVBoxLayout *attendanceReportLayout;
    QLabel *attendanceReportLabel;
    QDateEdit *attendanceReportDate;
    QTextEdit *attendanceReportText;
    QPushButton *attendanceReportButton;
    QWidget *revenueReportWidget;
    QVBoxLayout *revenueReportLayout;
    QLabel *revenueReportLabel;
    QDateEdit *revenueReportDate;
    QTextEdit *revenueReportText;
    QPushButton *revenueReportButton;
    QWidget *searchTab;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *searchGroupBox;
    QFormLayout *formLayout;
    QLabel *searchLabel;
    QComboBox *searchFieldComboBox;
    QLabel *queryLabel;
    QLineEdit *searchQueryLineEdit;
    QGroupBox *filterGroupBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *filterLabel;
    QComboBox *statusFilterComboBox;
    QComboBox *typeFilterComboBox;
    QPushButton *searchButton;
    QTableWidget *searchResultsTable;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(1000, 700);
        actionImport = new QAction(AdminWindow);
        actionImport->setObjectName("actionImport");
        actionExport = new QAction(AdminWindow);
        actionExport->setObjectName("actionExport");
        actionExit = new QAction(AdminWindow);
        actionExit->setObjectName("actionExit");
        centralWidget = new QWidget(AdminWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        membershipsTab = new QWidget();
        membershipsTab->setObjectName("membershipsTab");
        verticalLayout_2 = new QVBoxLayout(membershipsTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        membershipsTable = new QTableWidget(membershipsTab);
        if (membershipsTable->columnCount() < 8)
            membershipsTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        membershipsTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        membershipsTable->setObjectName("membershipsTable");

        verticalLayout_2->addWidget(membershipsTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        addMembershipButton = new QPushButton(membershipsTab);
        addMembershipButton->setObjectName("addMembershipButton");

        horizontalLayout->addWidget(addMembershipButton);

        editMembershipButton = new QPushButton(membershipsTab);
        editMembershipButton->setObjectName("editMembershipButton");

        horizontalLayout->addWidget(editMembershipButton);

        deleteMembershipButton = new QPushButton(membershipsTab);
        deleteMembershipButton->setObjectName("deleteMembershipButton");

        horizontalLayout->addWidget(deleteMembershipButton);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(membershipsTab, QString());
        trainerServicesTab = new QWidget();
        trainerServicesTab->setObjectName("trainerServicesTab");
        verticalLayout_trainerServices = new QVBoxLayout(trainerServicesTab);
        verticalLayout_trainerServices->setSpacing(6);
        verticalLayout_trainerServices->setContentsMargins(11, 11, 11, 11);
        verticalLayout_trainerServices->setObjectName("verticalLayout_trainerServices");
        trainerServicesTable = new QTableWidget(trainerServicesTab);
        if (trainerServicesTable->columnCount() < 9)
            trainerServicesTable->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        trainerServicesTable->setHorizontalHeaderItem(8, __qtablewidgetitem16);
        trainerServicesTable->setObjectName("trainerServicesTable");

        verticalLayout_trainerServices->addWidget(trainerServicesTable);

        horizontalLayout_trainerServices = new QHBoxLayout();
        horizontalLayout_trainerServices->setSpacing(6);
        horizontalLayout_trainerServices->setObjectName("horizontalLayout_trainerServices");
        deleteTrainerServiceButton = new QPushButton(trainerServicesTab);
        deleteTrainerServiceButton->setObjectName("deleteTrainerServiceButton");

        horizontalLayout_trainerServices->addWidget(deleteTrainerServiceButton);


        verticalLayout_trainerServices->addLayout(horizontalLayout_trainerServices);

        tabWidget->addTab(trainerServicesTab, QString());
        visitsTab = new QWidget();
        visitsTab->setObjectName("visitsTab");
        verticalLayout_3 = new QVBoxLayout(visitsTab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        visitsTable = new QTableWidget(visitsTab);
        if (visitsTable->columnCount() < 4)
            visitsTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        visitsTable->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        visitsTable->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        visitsTable->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        visitsTable->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        visitsTable->setObjectName("visitsTable");

        verticalLayout_3->addWidget(visitsTable);

        tabWidget->addTab(visitsTab, QString());
        reportsTab = new QWidget();
        reportsTab->setObjectName("reportsTab");
        verticalLayout_4 = new QVBoxLayout(reportsTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        reportsSplitter = new QSplitter(reportsTab);
        reportsSplitter->setObjectName("reportsSplitter");
        reportsSplitter->setOrientation(Qt::Horizontal);
        attendanceReportWidget = new QWidget(reportsSplitter);
        attendanceReportWidget->setObjectName("attendanceReportWidget");
        attendanceReportLayout = new QVBoxLayout(attendanceReportWidget);
        attendanceReportLayout->setSpacing(6);
        attendanceReportLayout->setContentsMargins(11, 11, 11, 11);
        attendanceReportLayout->setObjectName("attendanceReportLayout");
        attendanceReportLayout->setContentsMargins(0, 0, 0, 0);
        attendanceReportLabel = new QLabel(attendanceReportWidget);
        attendanceReportLabel->setObjectName("attendanceReportLabel");
        attendanceReportLabel->setAlignment(Qt::AlignCenter);

        attendanceReportLayout->addWidget(attendanceReportLabel);

        attendanceReportDate = new QDateEdit(attendanceReportWidget);
        attendanceReportDate->setObjectName("attendanceReportDate");
        attendanceReportDate->setCalendarPopup(true);
        attendanceReportDate->setDate(QDate(2025, 1, 1));

        attendanceReportLayout->addWidget(attendanceReportDate);

        attendanceReportText = new QTextEdit(attendanceReportWidget);
        attendanceReportText->setObjectName("attendanceReportText");
        attendanceReportText->setReadOnly(true);

        attendanceReportLayout->addWidget(attendanceReportText);

        attendanceReportButton = new QPushButton(attendanceReportWidget);
        attendanceReportButton->setObjectName("attendanceReportButton");

        attendanceReportLayout->addWidget(attendanceReportButton);

        reportsSplitter->addWidget(attendanceReportWidget);
        revenueReportWidget = new QWidget(reportsSplitter);
        revenueReportWidget->setObjectName("revenueReportWidget");
        revenueReportLayout = new QVBoxLayout(revenueReportWidget);
        revenueReportLayout->setSpacing(6);
        revenueReportLayout->setContentsMargins(11, 11, 11, 11);
        revenueReportLayout->setObjectName("revenueReportLayout");
        revenueReportLayout->setContentsMargins(0, 0, 0, 0);
        revenueReportLabel = new QLabel(revenueReportWidget);
        revenueReportLabel->setObjectName("revenueReportLabel");
        revenueReportLabel->setAlignment(Qt::AlignCenter);

        revenueReportLayout->addWidget(revenueReportLabel);

        revenueReportDate = new QDateEdit(revenueReportWidget);
        revenueReportDate->setObjectName("revenueReportDate");
        revenueReportDate->setCalendarPopup(true);
        revenueReportDate->setDate(QDate(2025, 1, 1));

        revenueReportLayout->addWidget(revenueReportDate);

        revenueReportText = new QTextEdit(revenueReportWidget);
        revenueReportText->setObjectName("revenueReportText");
        revenueReportText->setReadOnly(true);

        revenueReportLayout->addWidget(revenueReportText);

        revenueReportButton = new QPushButton(revenueReportWidget);
        revenueReportButton->setObjectName("revenueReportButton");

        revenueReportLayout->addWidget(revenueReportButton);

        reportsSplitter->addWidget(revenueReportWidget);

        verticalLayout_4->addWidget(reportsSplitter);

        tabWidget->addTab(reportsTab, QString());
        searchTab = new QWidget();
        searchTab->setObjectName("searchTab");
        verticalLayout_5 = new QVBoxLayout(searchTab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        searchGroupBox = new QGroupBox(searchTab);
        searchGroupBox->setObjectName("searchGroupBox");
        formLayout = new QFormLayout(searchGroupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName("formLayout");
        searchLabel = new QLabel(searchGroupBox);
        searchLabel->setObjectName("searchLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, searchLabel);

        searchFieldComboBox = new QComboBox(searchGroupBox);
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->addItem(QString());
        searchFieldComboBox->setObjectName("searchFieldComboBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, searchFieldComboBox);

        queryLabel = new QLabel(searchGroupBox);
        queryLabel->setObjectName("queryLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, queryLabel);

        searchQueryLineEdit = new QLineEdit(searchGroupBox);
        searchQueryLineEdit->setObjectName("searchQueryLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, searchQueryLineEdit);


        verticalLayout_5->addWidget(searchGroupBox);

        filterGroupBox = new QGroupBox(searchTab);
        filterGroupBox->setObjectName("filterGroupBox");
        horizontalLayout_4 = new QHBoxLayout(filterGroupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        filterLabel = new QLabel(filterGroupBox);
        filterLabel->setObjectName("filterLabel");

        horizontalLayout_4->addWidget(filterLabel);

        statusFilterComboBox = new QComboBox(filterGroupBox);
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->setObjectName("statusFilterComboBox");

        horizontalLayout_4->addWidget(statusFilterComboBox);

        typeFilterComboBox = new QComboBox(filterGroupBox);
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->addItem(QString());
        typeFilterComboBox->setObjectName("typeFilterComboBox");
        typeFilterComboBox->setVisible(false);

        horizontalLayout_4->addWidget(typeFilterComboBox);


        verticalLayout_5->addWidget(filterGroupBox);

        searchButton = new QPushButton(searchTab);
        searchButton->setObjectName("searchButton");

        verticalLayout_5->addWidget(searchButton);

        searchResultsTable = new QTableWidget(searchTab);
        if (searchResultsTable->columnCount() < 7)
            searchResultsTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(5, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        searchResultsTable->setHorizontalHeaderItem(6, __qtablewidgetitem27);
        searchResultsTable->setObjectName("searchResultsTable");

        verticalLayout_5->addWidget(searchResultsTable);

        tabWidget->addTab(searchTab, QString());

        verticalLayout->addWidget(tabWidget);

        AdminWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdminWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        AdminWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(AdminWindow);
        statusBar->setObjectName("statusBar");
        AdminWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExit);

        retranslateUi(AdminWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        actionImport->setText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
        actionExport->setText(QCoreApplication::translate("AdminWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
        actionExit->setText(QCoreApplication::translate("AdminWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = membershipsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AdminWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = membershipsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AdminWindow", "ID \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = membershipsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\321\217 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = membershipsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AdminWindow", "\320\242\320\270\320\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = membershipsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AdminWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = membershipsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AdminWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = membershipsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = membershipsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        addMembershipButton->setText(QCoreApplication::translate("AdminWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202", nullptr));
        editMembershipButton->setText(QCoreApplication::translate("AdminWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        deleteMembershipButton->setText(QCoreApplication::translate("AdminWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(membershipsTab), QCoreApplication::translate("AdminWindow", "\320\220\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\321\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = trainerServicesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("AdminWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = trainerServicesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("AdminWindow", "ID \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = trainerServicesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\321\217 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = trainerServicesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("AdminWindow", "\320\222\320\270\320\264 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = trainerServicesTable->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\200\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = trainerServicesTable->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("AdminWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = trainerServicesTable->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("AdminWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = trainerServicesTable->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = trainerServicesTable->horizontalHeaderItem(8);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        deleteTrainerServiceButton->setText(QCoreApplication::translate("AdminWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(trainerServicesTab), QCoreApplication::translate("AdminWindow", "\320\242\321\200\320\265\320\275\320\265\321\200\321\201\320\272\320\270\320\265 \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = visitsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("AdminWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = visitsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("AdminWindow", "ID \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = visitsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\321\217 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = visitsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("AdminWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(visitsTab), QCoreApplication::translate("AdminWindow", "\320\237\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        attendanceReportLabel->setText(QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217\320\274", nullptr));
        attendanceReportButton->setText(QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\321\217\320\274", nullptr));
        revenueReportLabel->setText(QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\264\320\276\321\205\320\276\320\264\320\260\320\274", nullptr));
        revenueReportButton->setText(QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\202 \320\277\320\276 \320\264\320\276\321\205\320\276\320\264\320\260\320\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(reportsTab), QCoreApplication::translate("AdminWindow", "\320\236\321\202\321\207\320\265\321\202\321\213", nullptr));
        searchGroupBox->setTitle(QCoreApplication::translate("AdminWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        searchLabel->setText(QCoreApplication::translate("AdminWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276:", nullptr));
        searchFieldComboBox->setItemText(0, QCoreApplication::translate("AdminWindow", "\320\232\320\273\320\270\320\265\320\275\321\202\321\203", nullptr));
        searchFieldComboBox->setItemText(1, QCoreApplication::translate("AdminWindow", "\320\242\320\270\320\277\321\203 \320\260\320\261\320\276\320\275\320\265\320\274\320\265\320\275\321\202\320\260", nullptr));
        searchFieldComboBox->setItemText(2, QCoreApplication::translate("AdminWindow", "\320\224\320\260\321\202\320\265", nullptr));
        searchFieldComboBox->setItemText(3, QCoreApplication::translate("AdminWindow", "\320\242\321\200\320\265\320\275\320\265\321\200\321\201\320\272\320\270\320\274 \321\203\321\201\320\273\321\203\320\263\320\260\320\274", nullptr));

        queryLabel->setText(QCoreApplication::translate("AdminWindow", "\320\227\320\260\320\277\321\200\320\276\321\201:", nullptr));
        filterGroupBox->setTitle(QCoreApplication::translate("AdminWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        filterLabel->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\202\320\260\321\202\321\203\321\201:", nullptr));
        statusFilterComboBox->setItemText(0, QCoreApplication::translate("AdminWindow", "\320\222\321\201\320\265", nullptr));
        statusFilterComboBox->setItemText(1, QCoreApplication::translate("AdminWindow", "\320\220\320\272\321\202\320\270\320\262\320\265\320\275", nullptr));
        statusFilterComboBox->setItemText(2, QCoreApplication::translate("AdminWindow", "\320\230\321\201\321\202\320\265\320\272", nullptr));

        typeFilterComboBox->setItemText(0, QCoreApplication::translate("AdminWindow", "\320\222\321\201\320\265", nullptr));
        typeFilterComboBox->setItemText(1, QCoreApplication::translate("AdminWindow", "\320\242\321\200\320\265\320\275\320\260\320\266\320\265\321\200\320\275\321\213\320\271 \320\267\320\260\320\273", nullptr));
        typeFilterComboBox->setItemText(2, QCoreApplication::translate("AdminWindow", "\320\223\321\200\321\203\320\277\320\277\320\276\320\262\321\213\320\265 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\272\320\270", nullptr));
        typeFilterComboBox->setItemText(3, QCoreApplication::translate("AdminWindow", "\320\237\320\273\320\260\320\262\320\260\320\275\320\270\320\265", nullptr));
        typeFilterComboBox->setItemText(4, QCoreApplication::translate("AdminWindow", "\320\221\320\276\320\272\321\201", nullptr));

        searchButton->setText(QCoreApplication::translate("AdminWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = searchResultsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("AdminWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = searchResultsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("AdminWindow", "ID \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = searchResultsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("AdminWindow", "\320\230\320\274\321\217 \320\272\320\273\320\270\320\265\320\275\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = searchResultsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("AdminWindow", "\320\242\320\270\320\277", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = searchResultsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("AdminWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = searchResultsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("AdminWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = searchResultsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("AdminWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(searchTab), QCoreApplication::translate("AdminWindow", "\320\237\320\276\320\270\321\201\320\272 \320\270 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        menuFile->setTitle(QCoreApplication::translate("AdminWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
