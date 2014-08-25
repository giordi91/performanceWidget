#include "ramwidget.h"

RamWidget::RamWidget(QWidget *parent) :
    PerformanceWidget(parent), m_dataQuery(RamDataQuery())
//  m_displayMode(DRAW_GRAPH)

{
    //Set what data quary we want
    setDataQuery(&m_dataQuery);
    //set data query default config
//    m_dataQuery.setMulti(m_multi);
//    m_dataQuery.setIndex(m_index);

    //Let s initialize all the painters
    m_graphP = new GraphPainter(this);
    m_barsP =  new BarsPainter(this);
    //Initialize painter
    setDisplayMode(DRAW_BARS);
}


void RamWidget::setDisplayMode(const drawMode mode)
{
        m_displayMode = mode;

        switch (m_displayMode) {
        case 0:
        {
            setPainter(m_barsP);
            break;
        }
        case 1:
        {
            setPainter(m_graphP);
            break;
        }
//        case 2:
//        {
//            setPainter(m_multiP);
//            break;
//        }

        }


}


RamWidget::~RamWidget()
{
    delete m_graphP;
    delete m_barsP;
//    delete m_multiP;

}
