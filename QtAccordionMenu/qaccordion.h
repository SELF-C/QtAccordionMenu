#pragma once
#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>

class QAccordion : public QGroupBox
{
public:
    explicit QAccordion(const QString& title = "", QWidget* parent = nullptr);
    ~QAccordion();

    void setLayout(QLayout* layout);
    
    void setArrowColor(QColor color) { m_arrowColor = color; }
    void setTitleColor(QColor color) { m_titleColor = color; }
    void setCollapsed(bool state = true);
protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;


private:
    QColor m_arrowColor;
    QColor m_titleColor;
    QFrame* m_widget;
    bool m_collapsed;

    QRect expandCollapseRect();
    void toggleCollapsed();
    void drawArrow(QPainter* painter, int x, int y);
};

