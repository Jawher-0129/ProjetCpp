/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QPushButton *send;
    QPushButton *bind;
    QLabel *label;
    QLineEdit *message;
    QLabel *label_2;
    QLineEdit *nickname;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 90, 711, 371));
        send = new QPushButton(Widget);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(370, 520, 93, 28));
        bind = new QPushButton(Widget);
        bind->setObjectName(QStringLiteral("bind"));
        bind->setGeometry(QRect(470, 520, 93, 28));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 530, 56, 16));
        message = new QLineEdit(Widget);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(110, 520, 131, 31));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 40, 81, 16));
        nickname = new QLineEdit(Widget);
        nickname->setObjectName(QStringLiteral("nickname"));
        nickname->setGeometry(QRect(130, 30, 171, 31));
        QWidget::setTabOrder(message, send);
        QWidget::setTabOrder(send, textEdit);
        QWidget::setTabOrder(textEdit, bind);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        send->setText(QApplication::translate("Widget", "Envoyer", Q_NULLPTR));
        bind->setText(QApplication::translate("Widget", "Se connecter", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "Message", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Votre Nom:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
