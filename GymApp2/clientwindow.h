#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QList>
#include "user.h"
#include "membership.h"
#include "visit.h"
#include "trainerservice.h"
#include "datamanager.h"
#include "trainerservicedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(const User& user, QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_buyMembershipButton_clicked();
    void on_markVisitButton_clicked();
    void on_buyTrainerServiceButton_clicked();

private:
    Ui::ClientWindow *ui;
    User m_user;
    DataManager m_dataManager;
    
    // Initialize UI with user data
    void setupUI();
    void populateProfileTab();
    void populateMembershipTab();
    void populateAvailableMembershipsTab(); // For purchasing
    void populateTrainerServicesTab();
    void populateAvailableTrainerServicesTab(); // For purchasing
    void populateVisitsTab();
    void checkMembershipExpiration();
};

#endif // CLIENTWINDOW_H