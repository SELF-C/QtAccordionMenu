#include "qaccordion.h"


QAccordion::QAccordion(const QString& title, QWidget* parent) : QGroupBox(title, parent)
{
	auto* layout = new QVBoxLayout();
	layout->setContentsMargins(0, 7, 0, 0);
	layout->setSpacing(0);
	QGroupBox::setLayout(layout);

	m_widget = new QFrame(parent);
	m_widget->setFrameShape(QFrame::Panel);
	m_widget->setFrameShadow(QFrame::Plain);
	m_widget->setLineWidth(0);
	layout->addWidget(m_widget);
	m_collapsed = false;
	
	m_arrowColor = m_widget->palette().windowText().color();

	auto widgetColor = m_widget->palette().background().color();
	m_titleColor = QColor(widgetColor.red() - 20, widgetColor.green() - 20, widgetColor.blue() - 20, widgetColor.alpha());

}

QAccordion::~QAccordion()
{
	delete m_widget;
}


void QAccordion::setLayout(QLayout* layout)
{
	m_widget->setLayout(layout);
}

QRect QAccordion::expandCollapseRect()
{
	return QRect(0, 0, this->width(), 20);
}

void QAccordion::mouseReleaseEvent(QMouseEvent* event)
{
	if (this->expandCollapseRect().contains(event->pos()))
	{
		toggleCollapsed();
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void QAccordion::toggleCollapsed()
{
	setCollapsed(!m_collapsed);
}

void QAccordion::setCollapsed(bool state)
{
	m_collapsed = state;
	if (state)
	{
		this->setMinimumHeight(20);
		this->setMaximumHeight(20);
		m_widget->setVisible(false);
	}
	else
	{
		this->setMinimumHeight(0);
		this->setMaximumHeight(16777215);	// By default, this property contains a value of 16777215.
		m_widget->setVisible(true);
	}
}

void QAccordion::drawArrow(QPainter* painter, int x, int y)
{
	QVector<QPoint> points(3);
	if (!m_collapsed)
	{
		points[0] = QPoint(x + 10, y + 6);
		points[1] = QPoint(x + 20, y + 6);
		points[2] = QPoint(x + 15, y + 11);
	}
	else
	{
		points[0] = QPoint(x + 10, y + 4);
		points[1] = QPoint(x + 15, y + 9);
		points[2] = QPoint(x + 10, y + 14);
	}

	auto currentBrush = painter->brush();
	auto currentPen = painter->pen();

	painter->setBrush(QBrush(m_arrowColor, Qt::SolidPattern));
	painter->setPen(QPen(Qt::NoPen));
	painter->drawPolygon(QPolygon(points));
	
	painter->setBrush(currentBrush);
	painter->setPen(currentPen);

}

void QAccordion::paintEvent(QPaintEvent* event)
{
	auto* painter = new QPainter();
	painter->begin(this);

	auto font = painter->font();
	font.setBold(true);
	painter->setFont(font);

	auto x = this->rect().x();
	auto y = this->rect().y();
	auto w = this->rect().width();
	int offset = 25;
	
	painter->setRenderHint(painter->Antialiasing);
	painter->fillRect(this->expandCollapseRect(), m_titleColor);
	painter->drawText(
		x + offset, y + 3, w, 16,
		Qt::AlignLeft | Qt::AlignTop,
		this->title()
	);
	
	drawArrow(painter, x, y);

	painter->setRenderHint(QPainter::Antialiasing, false);
	painter->end();
}
