#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"

#include <QMainWindow>
#include <QTranslator>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QActionGroup;

/// Класс основного окна
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// Конструктор по умолчанию
    MainWindow(QWidget *parent = nullptr);
    /// Деструктор класса
    ~MainWindow();

private slots:
    /// Слот изменения языка
    void switchLanguage(QAction *action);
    /// Слот добавления проекта в базе данных
    void actionAddProject_triggered();
    /// Слот редактирования проекта в базе данных
    void actionEditProject_triggered();
    /// Слот удаления проекта в базе данных
    void actionDeleteProject_triggered();
    /// Слот получения данных проекта из диалогового окна для последующего их добавления в базу данных
    void recieveAddProject(Project object);
    /// Слот получения данных проекта из диалогового окна для последующего их редактирования в базу данных
    void recieveEditProject(Project object);
    /// Слот вызова диалогового окна "О программе"
    void actionAboutProgram_triggered();

private:
    /// Метод создания языкового меню
    void createLanguageMenu();
    /// Метод с применением дополнительных настроек UI
    void createUi();
    /// Метод запоминания размера окна и применяемого языка
    void readSettings();
    /// Метод применения записываемых размера окна и применяемого языка
    void writeSettings();

    /// Указатель на интерфейс главного окна
    Ui::MainWindow *ui;
    /// Средство примения основных методов базы данных
    Database *db;
    /// Модель для сортировки данных модели базы данных
    QSortFilterProxyModel *proxyModel;
    /// Хранит местоположение файлов перевода
    QString qmPath;
    /// Хранит переводчик
    QTranslator appTranslator;
    /// Хранит меню выбора языка
    QActionGroup *languageActionGroup;
    /// Хранит текущий выбранный язык
    QString currentLanguage;

};
#endif // MAINWINDOW_H
