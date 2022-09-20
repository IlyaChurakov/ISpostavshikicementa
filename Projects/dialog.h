#ifndef DIALOG_H
#define DIALOG_H

#include "project.h"

#include <QDialog>

namespace Ui {
class Dialog;
}

/// Класс для работы с дилоговым окном при добавлении/редактировании проекта
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /// Конструктор по умолчанию
    explicit Dialog(QWidget *parent = nullptr);
    /// Конструктор с данными проекте
    Dialog(const Project &project, QWidget *parent = nullptr);
    /// Деструктор класса
    ~Dialog();

signals:
    /// Сигнал отправки проекте
    void sendProject(Project);

private slots:
    /// Слот нажатия кнопки OK
    void pushButtonOk_clicked();

private:
    /// Метод получения заполненных данных о проекте
    Project *getProject();
    /// Метод записывания данных о проекте в интерфес
    void setProject(const Project &project);

    /// Указатель на интерфейс диалогового окна
    Ui::Dialog *ui;
};

#endif // DIALOG_H
