#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "user.h"
#include "adminwindow.h"
#include "clientwindow.h"
#include "jsonmanager.h"
#include "datamanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    Ui::MainWindow *ui;
    User m_currentUser;
    AdminWindow *m_adminWindow;
    ClientWindow *m_clientWindow;
    JsonManager m_jsonManager;
    DataManager m_dataManager;
    
    bool validateUser(const QString &username, const QString &password);
};
#endif // MAINWINDOW_H