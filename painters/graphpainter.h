#ifndef GRAPHPAINTER_H
#define GRAPHPAINTER_H
#include "performancepainter.h"

/**
 * @brief This class is draws regular one line graphs
 *
 * This class is a subclass of the abstract class PerformancePainter.
 * It implements a draw of regular one line graphs of which we have an example here
 *
 * \li \c Single Graph:
 * if the matrix/2D array contains just one row it s going to draw something like this
 * @image html performanceSingleGraph.png "Single Graph view"
 *
 * \li \c Multiple Graph:
 * if the data is a 2D array (vector of vectors), is going to draw one graph for each row in the
 * matrix/array and will look something like this.
 *@image html performanceMultiGraph.png "Multi Graph view"
 */
class GraphPainter : public PerformancePainter
{
public:
    /**
     * @brief The constructor
     * @param widget : This is a paintable widget at wich the painter is associated
     */
    GraphPainter(QPaintDevice * widget);
    /// Destructor
    ~GraphPainter(){}
    ///Reimplemented paint function
    void paint();

};

#endif // GRAPHPAINTER_H
