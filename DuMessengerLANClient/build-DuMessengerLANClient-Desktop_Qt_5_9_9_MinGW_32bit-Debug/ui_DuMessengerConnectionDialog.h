/********************************************************************************
** Form generated from reading UI file 'DuMessengerConnectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUMESSENGERCONNECTIONDIALOG_H
#define UI_DUMESSENGERCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DuMessengerConnectionDialog
{
public:
    QPushButton *ok;
    QPushButton *cancel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostname;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *port;

    void setupUi(QDialog *DuMessengerConnectionDialog)
    {
        if (DuMessengerConnectionDialog->objectName().isEmpty())
            DuMessengerConnectionDialog->setObjectName(QStringLiteral("DuMessengerConnectionDialog"));
        DuMessengerConnectionDialog->resize(900, 595);
        ok = new QPushButton(DuMessengerConnectionDialog);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(380, 190, 93, 28));
        cancel = new QPushButton(DuMessengerConnectionDialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(490, 190, 93, 28));
        widget = new QWidget(DuMessengerConnectionDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 50, 217, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        hostname = new QLineEdit(widget);
        hostname->setObjectName(QStringLiteral("hostname"));

        horizontalLayout->addWidget(hostname);

        widget1 = new QWidget(DuMessengerConnectionDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(80, 100, 126, 24));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        port = new QSpinBox(widget1);
        port->setObjectName(QStringLiteral("port"));
        port->setMaximum(999999999);

        horizontalLayout_2->addWidget(port);


        retranslateUi(DuMessengerConnectionDialog);

        QMetaObject::connectSlotsByName(DuMessengerConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DuMessengerConnectionDialog)
    {
        DuMessengerConnectionDialog->setWindowTitle(QApplication::translate("DuMessengerConnectionDialog", "Dialog", Q_NULLPTR));
        ok->setText(QApplication::translate("DuMessengerConnectionDialog", "Accepter", Q_NULLPTR));
        cancel->setText(QApplication::translate("DuMessengerConnectionDialog", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("DuMessengerConnectionDialog", "HOSTNAME:", Q_NULLPTR));
        label_2->setText(QApplication::translate("DuMessengerConnectionDialog", "PORT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DuMessengerConnectionDialog: public Ui_DuMessengerConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUMESSENGERCONNECTIONDIALOG_H
