#ifndef RAMWIDGET_H
#define RAMWIDGET_H

/**
 * @brief Widget that show the ram usage
 *
 * This widget inherith from PerformanceWidget class. and specialize it in order to
 * show the ram usage.
 */


#include <widgets/performancewidget.h>
#include <dataQuery/ramdataquery.h>

class RamWidget : public PerformanceWidget
{
public :
    /// Constants defining the draw mode
    enum drawMode
    {
        /// Draw the data as bar/s
        DRAW_BARS = 0,
        /// Draw the data as graph/s
        DRAW_GRAPH = 1
    };


public:
    RamWidget(QWidget *parent) ;
    ~RamWidget();
    /** This method lets the user set the display mode for the widget
    *   @param mode : what mode to draw the widget, available options : \li DRAW_BARS
    *                 \li DRAW_GRAPH
    */
    void setDisplayMode(const drawMode mode);
private:
    RamDataQuery m_dataQuery;
    BarsPainter *m_barsP;
    GraphPainter *m_graphP;
    int m_displayMode;


};

#endif // RAMWIDGET_H
