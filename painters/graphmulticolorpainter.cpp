#include "graphmulticolorpainter.h"
#include "painterutils.h"
#include <stdio.h>
#include <iostream>


GraphMultiColorPainter::GraphMultiColorPainter(QPaintDevice * widget):
PerformancePainter(widget)

{
    // Initializing colors
    m_color1 =(QColor(0,255,0,255));
    m_color2 = (QColor(0,180,0,0));

    //init colors
    m_colors.clear();
    m_colors.push_back(QColor(  255, 255, 0));
    m_colors.push_back(QColor( 255, 127, 0));
    m_colors.push_back(QColor( 255, 0, 0));
    m_colors.push_back(QColor( 127, 255, 0));

    m_colors.push_back(QColor(  0, 255, 0));
    m_colors.push_back(QColor( 0, 255, 127));
    m_colors.push_back(QColor( 0, 255, 255));
    m_colors.push_back(QColor(  0, 127, 255));

    m_colors.push_back(QColor( 0, 0, 255));
    m_colors.push_back(QColor( 127, 0, 255));
    m_colors.push_back(QColor( 255, 0, 255));
    m_colors.push_back(QColor( 255, 0, 127));
}





void GraphMultiColorPainter::checkColors( )
{
    //Lets check if we have enough color for all the data
    int currSize = m_colors.size();
    int  numberOfColors = m_cache.size();

    //if the color we need are less then the current available colors lets get out
    if (numberOfColors <= currSize)
        return;

    //if not lets create random colors
    for(int i = 0; i < (numberOfColors - currSize) ; i++)
    {


        QColor temp(int(rand() * float(COLOR_RANGE) / RAND_MAX),
                    int(rand() * float(COLOR_RANGE) / RAND_MAX),
                    int(rand() * float(COLOR_RANGE) / RAND_MAX),
                    255);

        m_colors.push_back(temp);

    }

}


void GraphMultiColorPainter::paint()
{

    //checkColors
    checkColors();


    QColor m_back = QColor(0,180,0,0);

    //Create a new painter
    QPainter qpN(m_widget);
    //Draw gird and BG
    drawBackground(qpN);
    drawGrid(qpN);
    //Compute size of the data and step size
    int size = m_cache.size();
    qpN.setBrush(m_back);
    qpN.drawRoundedRect(0 ,0,m_width -2 ,m_height-1,
                     3,3,Qt::AbsoluteSize);

    bool legendOnOff = (MIN_LEGEND_WIDTH * size) <= m_width;


    for(int i = 0 ; i < (size);i++)
    {
       //lets use our utils to draw the graph
       m_back = m_colors[size-i-1];
       m_back.setAlpha(80);
       painterUtils:: drawRectangleGraph(qpN,0,
                                         m_width,m_height,m_cache[size-i-1],
                                         m_colors[size-i-1],m_back);

       //paint legend
       if (legendOnOff )
       {
                QString text = QString("#") + QString::number(size-i-1);
                qpN.drawText(MIN_LEGEND_WIDTH *(size-i-1) +5,15,text);



       }
    }


}


