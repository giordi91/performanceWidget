#ifndef GRAPHMULTICOLORPAINTER_H
#define GRAPHMULTICOLORPAINTER_H

#include "performancepainter.h"

/**
 * @brief This class is draws one graph with multiples lines
 *
 * This class is a subclass of the abstract class PerformancePainter.
 * It implements a draw just one graph but with all the data in it rappresented as multiple line,
 *  of which we have an example here :
 *
 * each row in the 2D matrix/array is going to be agraph and each column of that row is going to be a value
 * of the graph
 * @image html performanceMultiColorGraph.png "Mulit Color Graph"
 */
class GraphMultiColorPainter : public PerformancePainter
{
public:
    /**
     * @brief The constructor
     * @param widget : This is a paintable widget at wich the painter is associated
     */
    GraphMultiColorPainter(QPaintDevice * widget);
    /// Destructor
    ~GraphMultiColorPainter(){}
    /// Reimplemented paint function
    void paint();

private:
    ///This procedrue checks that we have enough color to produce the graph
    void checkColors();


private :
    //List of colors used for the graph
    std::vector<QColor> m_colors;
    //Constant for the color range
    static const int COLOR_RANGE = 255;
    //Constant for the minimum legend with, this is whats the minimum space required for each
    // number of the legend
    static const int MIN_LEGEND_WIDTH = 30;


};



#endif // GRAPHMULTICOLORPAINTER_H
