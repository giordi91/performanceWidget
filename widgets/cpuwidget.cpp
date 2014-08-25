#include <widgets/cpuwidget.h>

CpuWidget::CpuWidget(QWidget *parent) :
    PerformanceWidget(parent), m_dataQuery(CpuDataQuery()),
  m_displayMode(DRAW_GRAPH),m_multi(true),m_index(0)

{
    //Set what data quary we want
    setDataQuery(&m_dataQuery);
    //set data query default config
    m_dataQuery.setMulti(m_multi);
    m_dataQuery.setIndex(m_index);

    //Let s initialize all the painters
    m_graphP = new GraphPainter(this);
    m_multiP = new GraphMultiColorPainter(this);
    m_barsP =  new BarsPainter(this);
    //Initialize painter
    setDisplayMode(DRAW_GRAPH_MULTI_COLOR);
}


void CpuWidget::setDisplayMode(const drawMode mode)
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
        case 2:
        {
            setPainter(m_multiP);
            break;
        }

        }


}

void CpuWidget::setMulti(bool value)
{
    m_multi = value;
    m_dataQuery.setMulti(m_multi);

}

void CpuWidget::setIndex(int value)
{
    if (value <= m_dataQuery.getNumberOfCores())
    {
        m_index = value;
        m_dataQuery.setIndex(value);
    }
    else
        std::cout<<"ERROR : value exiding number of cores .... skipping"<<std::endl;


}

CpuWidget::~CpuWidget()
{
    delete m_graphP;
    delete m_barsP;
    delete m_multiP;

}
