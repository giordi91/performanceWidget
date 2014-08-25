#include "performancepainter.h"
#include <iostream>

PerformancePainter::PerformancePainter(QPaintDevice * widget) :
    m_width(100),
    m_height(100), m_gridHeightStep(15), m_gridWidthStep(30),
    m_drawGrid(true),
    m_gridColor(QColor(180,180,180,180)),
    m_backgroundColor(QColor(40,40,40,255)),
    m_color1(QColor(0,230,0,255)),
    m_color2(QColor(0,230,0,255)),
    m_widget(widget)

{


}


void PerformancePainter::drawBackground(QPainter &qp)
{
    //  //Declare a painter and a pen used for drawing
    //  QPainter qp(this);
      qp.setPen(QColor(255,255,255,255));
      qp.setBrush(m_backgroundColor);

      //Draw the background
      qp.drawRoundedRect(0,0,m_width-1,m_height-1,
                           3,3
                           ,Qt::AbsoluteSize);


}


void PerformancePainter::drawGrid(QPainter &qp)
{
    //Draw grid
    if (m_drawGrid == false)
        return;
    //Set pen color
    qp.setPen(m_gridColor);

    //Compute height and width steps
    int stepm_height = m_height/m_gridHeightStep;
    int stepm_width = m_width / m_gridWidthStep;

    //Draw horizontal lines
    for (int i = 0; i < stepm_width +1; i++)
    {
      qp.drawLine(m_gridWidthStep*i+2,1
                  ,m_gridWidthStep*i+2, m_height-1);
    }

    //Draw vertical lines
    for (int i = 0; i < stepm_height +1; i++)
    {
      qp.drawLine(4,m_gridHeightStep*i+2,m_width-4,
                  m_gridHeightStep*i+2);
    }

}


void PerformancePainter::setGridColor(QColor color)
{

    m_gridColor = color;

}

void PerformancePainter::setColor1(QColor color)
{

    m_color1 = color;

}


void PerformancePainter::setColor2(QColor color)
{

    m_color2 = color;

}

void PerformancePainter::setBackgroundColor(QColor color)
{
    m_backgroundColor = color;

}
void PerformancePainter::setGeometry(const int width, const int height)
{
    m_width = width;
    m_height = height;

}




void PerformancePainter::setData(std::vector<std::vector<float> > cache)
{
    m_cache = cache;
}


void PerformancePainter::setDrawGrid(const bool value)
{
    m_drawGrid = value;

}
