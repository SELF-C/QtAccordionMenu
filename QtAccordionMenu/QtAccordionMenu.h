#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAccordionMenu.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QDockWidget>
#include <QScrollArea>

class QtAccordionMenu : public QMainWindow
{
    Q_OBJECT

public:
    QtAccordionMenu(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtAccordionMenuClass ui;


    void vertically();
    void horizontal();
    QWidget* accordionMenu(QString title, QWidget* parent);
    QVBoxLayout* sampleButton(QWidget* parent);
};
