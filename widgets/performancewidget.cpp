#include <QPainter>
#include <QLinearGradient>
#include <painters/painterutils.h>
#include "performancewidget.h"


PerformanceWidget::PerformanceWidget(QWidget *parent) :
    QWidget(parent),
    m_timer(NULL),
    m_painter(NULL),
    m_dataQuery(NULL)

{
    //Setup the timer
    m_timer = new QTimer (this);
    connect(m_timer, SIGNAL(timeout()),this,  SLOT(updateData()));
    connect(m_timer, SIGNAL(timeout()),this,  SLOT(repaint()));
    m_timer->start(SLOW_UPDATE);
}


void PerformanceWidget::paintEvent(QPaintEvent *e)
{


  //Just silancing the waring about the event not being used
  (void)e;
    if (m_dataQuery == NULL)
        return;
    m_painter->setData(m_dataQuery->m_cache);
    m_painter->paint();


}


void PerformanceWidget::setSpeed(const speedType speed)
{
    m_timer->stop();
    m_timer->start(speed);
}


PerformanceWidget::~PerformanceWidget()
{
    delete m_timer;

}


void PerformanceWidget::setDataQuery(DataQuery *dataQ)
{
    m_dataQuery = dataQ;

}

void PerformanceWidget::resizeEvent(QResizeEvent *e)
{

    (void)e;
    if (m_painter != NULL)
    {
        m_painter->setGeometry(width(),height());

    }

}


void PerformanceWidget::updateData()
{
    if (m_dataQuery != NULL)
        m_dataQuery->getData();
    else
        std::cout<<"ERROR : NO DATA QUERY DEVICE PROVIDED"<<std::endl;

}


void PerformanceWidget::setPainter(PerformancePainter *painter)
{
    m_painter = painter;
    m_painter->setGeometry(width(),height());
    updateData();
}


