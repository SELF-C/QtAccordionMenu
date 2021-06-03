#include "QtAccordionMenu.h"
#include "qaccordion.h"

QtAccordionMenu::QtAccordionMenu(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    vertically();
    horizontal();
}

void QtAccordionMenu::vertically()
{
    auto* dockWidget = new QDockWidget();
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    auto* widget = new QScrollArea();
    widget->setWidgetResizable(true);

    auto* inner = new QWidget();
    widget->setWidget(inner);
    dockWidget->setWidget(widget);

    auto* layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    inner->setLayout(layout);

    layout->addWidget(accordionMenu(u8"Frame Title1", inner));
    layout->addWidget(accordionMenu(u8"Frame Title2", inner));
    layout->addStretch();
}

void QtAccordionMenu::horizontal()
{
    auto* dockWidget = new QDockWidget();
    this->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

    auto* widget = new QScrollArea();
    widget->setWidgetResizable(true);

    auto* inner = new QWidget();
    widget->setWidget(inner);
    dockWidget->setWidget(widget);

    auto* layout = new QGridLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    inner->setLayout(layout);

    layout->addWidget(accordionMenu(u8"Frame Title1", inner), 0, 0, Qt::AlignTop);
    layout->addWidget(accordionMenu(u8"Frame Title2", inner), 0, 1, Qt::AlignTop);

    layout->setRowStretch(0, 0);
    layout->setRowStretch(0, 1);
}

QWidget* QtAccordionMenu::accordionMenu(QString title, QWidget* parent)
{
    auto* widget = new QAccordion(title, parent);
    auto* layout = sampleButton(widget);
    widget->setLayout(layout);
    widget->setCollapsed(true);
    return widget;
}

QVBoxLayout* QtAccordionMenu::sampleButton(QWidget* parent)
{
    auto* layout = new QVBoxLayout(parent);
    for (size_t i = 0; i < 5; i++)
    {
        auto* button = new QPushButton(QString(u8"Button %1").arg(i), parent);
        layout->addWidget(button);
    }
    layout->addStretch();

    return layout;
}
