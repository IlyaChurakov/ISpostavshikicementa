#include "dialog.h"
#include "ui_dialog.h"
#include "database.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    setFixedSize(this->size());

    setModal(true);

    ui->lineEditPostalCode->setInputMask("000000");

    connect(ui->pushButtonOK, &QPushButton::clicked, this, &Dialog::pushButtonOk_clicked);
}

Dialog::Dialog(const Project &project, QWidget *parent) : Dialog(parent)
{
    setProject(project);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::pushButtonOk_clicked()
{
    auto project = getProject();

    emit sendProject(*project);

    delete project;

    close();
}

Project *Dialog::getProject()
{
    return new Project(ui->lineEditCustomer->text(),
                      ui->lineEditAppointment->text(),
                      ui->lineEditCity->text(),
                      ui->lineEditStreetAddress->text(),
                      ui->lineEditPostalCode->text());
}

void Dialog::setProject(const Project &project)
{
    ui->lineEditCustomer->setText(project.customer());
    ui->lineEditAppointment->setText(project.appointment());
    ui->lineEditCity->setText(project.city());
    ui->lineEditStreetAddress->setText(project.streetAddress());
    ui->lineEditPostalCode->setText(project.postalCode());
}
