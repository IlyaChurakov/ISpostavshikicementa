/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelCustomer;
    QLineEdit *lineEditCustomer;
    QVBoxLayout *verticalLayout;
    QLabel *labelAppointment;
    QLineEdit *lineEditAppointment;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelCity;
    QLineEdit *lineEditCity;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelStreetAddress;
    QLineEdit *lineEditStreetAddress;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelPostalCode;
    QLineEdit *lineEditPostalCode;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 329);
        verticalLayout_6 = new QVBoxLayout(Dialog);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelCustomer = new QLabel(Dialog);
        labelCustomer->setObjectName(QString::fromUtf8("labelCustomer"));

        verticalLayout_2->addWidget(labelCustomer);

        lineEditCustomer = new QLineEdit(Dialog);
        lineEditCustomer->setObjectName(QString::fromUtf8("lineEditCustomer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditCustomer->sizePolicy().hasHeightForWidth());
        lineEditCustomer->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(lineEditCustomer);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelAppointment = new QLabel(Dialog);
        labelAppointment->setObjectName(QString::fromUtf8("labelAppointment"));

        verticalLayout->addWidget(labelAppointment);


        verticalLayout_6->addLayout(verticalLayout);

        lineEditAppointment = new QLineEdit(Dialog);
        lineEditAppointment->setObjectName(QString::fromUtf8("lineEditAppointment"));

        verticalLayout_6->addWidget(lineEditAppointment);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelCity = new QLabel(Dialog);
        labelCity->setObjectName(QString::fromUtf8("labelCity"));

        verticalLayout_3->addWidget(labelCity);

        lineEditCity = new QLineEdit(Dialog);
        lineEditCity->setObjectName(QString::fromUtf8("lineEditCity"));

        verticalLayout_3->addWidget(lineEditCity);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelStreetAddress = new QLabel(Dialog);
        labelStreetAddress->setObjectName(QString::fromUtf8("labelStreetAddress"));

        verticalLayout_4->addWidget(labelStreetAddress);

        lineEditStreetAddress = new QLineEdit(Dialog);
        lineEditStreetAddress->setObjectName(QString::fromUtf8("lineEditStreetAddress"));
        sizePolicy.setHeightForWidth(lineEditStreetAddress->sizePolicy().hasHeightForWidth());
        lineEditStreetAddress->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(lineEditStreetAddress);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelPostalCode = new QLabel(Dialog);
        labelPostalCode->setObjectName(QString::fromUtf8("labelPostalCode"));

        verticalLayout_5->addWidget(labelPostalCode);

        lineEditPostalCode = new QLineEdit(Dialog);
        lineEditPostalCode->setObjectName(QString::fromUtf8("lineEditPostalCode"));
        lineEditPostalCode->setMaxLength(6);

        verticalLayout_5->addWidget(lineEditPostalCode);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(Dialog);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);


        verticalLayout_6->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        labelCustomer->setText(QCoreApplication::translate("Dialog", "INN", nullptr));
        labelAppointment->setText(QCoreApplication::translate("Dialog", "Suplier", nullptr));
        labelCity->setText(QCoreApplication::translate("Dialog", "City", nullptr));
        labelStreetAddress->setText(QCoreApplication::translate("Dialog", "Street address", nullptr));
        labelPostalCode->setText(QCoreApplication::translate("Dialog", "Postal code", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("Dialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
