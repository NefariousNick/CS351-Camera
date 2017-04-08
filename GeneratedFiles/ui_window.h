/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *extrudeButton;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    MyGLWidget *myGLWidget;
    QPushButton *animateButton;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLabel *eyeLabel;
    QLabel *camLabel;
    QLabel *upLabel;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(1028, 733);
        gridLayout = new QGridLayout(Window);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Window);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 2, 1, 1);

        extrudeButton = new QPushButton(Window);
        extrudeButton->setObjectName(QStringLiteral("extrudeButton"));
        extrudeButton->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(extrudeButton, 1, 2, 1, 1);

        horizontalSlider = new QSlider(Window);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        myGLWidget = new MyGLWidget(Window);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setMinimumSize(QSize(480, 480));

        horizontalLayout->addWidget(myGLWidget);


        gridLayout->addLayout(horizontalLayout, 0, 2, 1, 1);

        animateButton = new QPushButton(Window);
        animateButton->setObjectName(QStringLiteral("animateButton"));

        gridLayout->addWidget(animateButton, 2, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(Window);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget, 0, Qt::AlignTop);

        eyeLabel = new QLabel(Window);
        eyeLabel->setObjectName(QStringLiteral("eyeLabel"));

        verticalLayout->addWidget(eyeLabel);

        camLabel = new QLabel(Window);
        camLabel->setObjectName(QStringLiteral("camLabel"));

        verticalLayout->addWidget(camLabel);

        upLabel = new QLabel(Window);
        upLabel->setObjectName(QStringLiteral("upLabel"));

        verticalLayout->addWidget(upLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 2);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", Q_NULLPTR));
        label->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
        extrudeButton->setText(QApplication::translate("Window", "Extrude", Q_NULLPTR));
        animateButton->setText(QApplication::translate("Window", "Animate", Q_NULLPTR));
        eyeLabel->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
        camLabel->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
        upLabel->setText(QApplication::translate("Window", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
