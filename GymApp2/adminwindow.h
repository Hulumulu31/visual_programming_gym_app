#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "membership.h"
#include "visit.h"
#include "trainerservice.h"
#include "reportmanager.h"
#include "searchfiltermanager.h"
#include "datamanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void onAddMembershipClicked();
    void onEditMembershipClicked();
    void onDeleteMembershipClicked();
    void onDeleteTrainerServiceClicked();
    void onAttendanceReportClicked();
    void onRevenueReportClicked();
    void onSearchClicked();
    void onSearchFieldChanged(int);

private:
    Ui::AdminWindow *ui;
    
    // Data managers
    ReportManager m_reportManager;
    SearchFilterManager m_searchFilterManager;
    DataManager m_dataManager;
    
    // Initialize UI
    void setupUI();
    void populateMembershipsTable();
    void populateTrainerServicesTable();
    void populateVisitsTable();
    void populateSearchResultsTable(const QList<Membership>& memberships, const QList<TrainerService>& services = QList<TrainerService>());
    void populateSearchResultsTableForTrainerServices(const QList<TrainerService>& results);
    
    // Helper method to get selected membership ID
    int getSelectedMembershipId() const;
    
    // Helper method to get selected trainer service ID
    int getSelectedTrainerServiceId() const;
};

#endif // ADMINWINDOW_H