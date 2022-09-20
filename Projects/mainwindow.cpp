#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , db(new Database)
    , proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);

    readSettings();

    db->connect(this);

    createUi();

    connect(ui->actionAdd_project, &QAction::triggered, this, &MainWindow::actionAddProject_triggered);
    connect(ui->actionEdit_project, &QAction::triggered, this, &MainWindow::actionEditProject_triggered);
    connect(ui->actionDelete_project, &QAction::triggered, this, &MainWindow::actionDeleteProject_triggered);
    connect(ui->actionAbout_program, &QAction::triggered, this, &MainWindow::actionAboutProgram_triggered);
}

MainWindow::~MainWindow()
{
    writeSettings();
    delete db;
    delete ui;
}

void MainWindow::actionAboutProgram_triggered()
{
    QString mainText = tr("CHURAKOV Ilya MIHAILOVICH\n"
                        "ICTMS 3-4\n"
                        "Development of IP projects of cement mortar");

    QMessageBox::about(this, tr("About program"), mainText);
}

void MainWindow::switchLanguage(QAction *action)
{
  QString localeFile = action->data().toString();
  appTranslator.load(localeFile, qmPath);
  ui->retranslateUi(this);
}

void MainWindow::actionAddProject_triggered()
{
    auto dialog = new Dialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Project adding"));

    connect(dialog, &Dialog::sendProject, this, &MainWindow::recieveAddProject);

    dialog->show();
}

void MainWindow::actionEditProject_triggered()
{
    QModelIndex index = ui->tableView->currentIndex();

    Project object(index.siblingAtColumn(1).data().toString(),
                    index.siblingAtColumn(2).data().toString(),
                    index.siblingAtColumn(3).data().toString(),
                    index.siblingAtColumn(4).data().toString(),
                    index.siblingAtColumn(5).data().toString());

    auto dialog = new Dialog(object, this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("Project editing"));

    connect(dialog, &Dialog::sendProject, this, &MainWindow::recieveEditProject);

    dialog->show();
}

void MainWindow::actionDeleteProject_triggered()
{
    int id = ui->tableView->currentIndex().siblingAtColumn(0).data().toInt();
    if (!db->deleteProject(id)) {
        QMessageBox::warning(this,
                             tr("ERORR"),
                             tr("Error deleting a project!"));

        return;
    }

    db->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::recieveAddProject(Project object)
{
    if (!db->addProject(object)) {
        QMessageBox::warning(this,
                             tr("ERORR"),
                             tr("Error adding a project!"));

        return;
    }

    db->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::recieveEditProject(Project object)
{
    int id = ui->tableView->currentIndex().siblingAtColumn(0).data().toInt();
    if (!db->editProject(id, object)) {
        QMessageBox::warning(this,
                             tr("ERORR"),
                             tr("Error editing a project!"));

        return;
    }

    db->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::createLanguageMenu()
{
  languageActionGroup = new QActionGroup(this);

  connect(languageActionGroup, &QActionGroup::triggered, this, &MainWindow::switchLanguage);

  QDir dir(qmPath);

  QStringList fileNames = dir.entryList(QStringList("Projects_*.qm"));

  for (int i = 0; i < fileNames.size(); i++) {

      QString locale = fileNames[i];

      QTranslator translator;
      translator.load(fileNames[i], qmPath);

      QString language = translator.translate("MainWindow", "English");
      QAction *action = new QAction(tr("&%1 %2")
                                           .arg(i + 1)
                                           .arg(language),
                                           this);
      action->setCheckable(true);
      action->setData(locale);
      ui->menuLanguage->addAction(action);
      languageActionGroup->addAction(action);

      if (currentLanguage == locale) {
          action->setChecked(true);
          switchLanguage(action);
        }
  }
}

void MainWindow::createUi()
{
    db->select();

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);

    ui->tableView->setSortingEnabled(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    QSqlQueryModel *model = db->getModel();
    proxyModel->setSourceModel(model);

    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Suolier"));
    model->setHeaderData(2, Qt::Horizontal, tr("INN"));
    model->setHeaderData(3, Qt::Horizontal, tr("City"));
    model->setHeaderData(4, Qt::Horizontal, tr("Street address"));
    model->setHeaderData(5, Qt::Horizontal, tr("Postal code"));

    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

    qApp->installTranslator(&appTranslator);
    qmPath = qApp->applicationDirPath() + "/translations";
    createLanguageMenu();
}

void MainWindow::readSettings()
{
  QSettings settings("ProjectsSoft", "Projects");

  currentLanguage = settings.value("checkedLanguage", "Projects_en_US.qm").toString();
  restoreGeometry(settings.value("geometryMainWindow").toByteArray());
}

void MainWindow::writeSettings()
{
  QSettings settings("ProjectsSoft", "Projects");

  QAction *currentLang = languageActionGroup->checkedAction();

  if (currentLang) {
      QString checkedLanguage = currentLang->data().toString();
      settings.setValue("checkedLanguage", checkedLanguage);
    }

  settings.setValue("geometryMainWindow", saveGeometry());
}
