#ifndef PERFORMANCEPAINTER_H
#define PERFORMANCEPAINTER_H

#include <QPainter>
/**
 * @brief This is an abstract painter
 *
 * This class define an abstract painter that can be subclassed to generate different type of paintings
 * for the performance widget
 *
 * In order to provide a little bit of flexibility this class implements a couple of generic attriutes and relative
 * setter functions , this attributes can be used or not from the subclasses to try to give a bit of customizzation
 * Those attributes are :
 * \li m_color1
 * \li m_color2

 */
class PerformancePainter
{

public:
    /**
     * @brief This is the constructor, for the painter in order to works needs to be initialized with a QPaintDevice
     * object or any of its child
     * @param widget : The widget we want to draw on
     */
    PerformancePainter( QPaintDevice * widget);
    ///The virtual destructor
    virtual ~PerformancePainter(){}
    ///The virtual paint method that needs to be reimplemented in the subclasses
    virtual void paint(){}
    /**
     * @brief This functon is used to set the width and height of the widget to be used internally.
     * @param width : The current width of the widget
     * @param height : The current height of the widget
     */
    void setGeometry(const int width, const int height);
    /**
     * @brief This function is used to set the data that needs to be displayed in by the painter
     * @param cache : The array of values to draw
     */
    void setData(std::vector<std::vector<float> > cache);
    /**
     * @brief Set whether or not to drawa the grid
     * @param value : The bool value to set the gird on off
     */
    void setDrawGrid(const bool value);
    /** This method lets the user set the background color
      * @param color : The QColor for the background
    */
    void setBackgroundColor(QColor color);
    /**
     * @brief Set whether or not to drawa the background color
     * @param qp
     */
    void drawBackground(QPainter &qp);

    void drawGrid(QPainter &qp );
    /** This method lets the user set the grid color
      * @param color : The QColor for the grid
    */
    void setGridColor(QColor color);

    /**
     * @brief This procedure lets you set the color1 you can use in the widget
     * @param color : The color value
     */
    void setColor1(QColor color);
    /**
     * @brief This procedure lets you set the color2 you can use in the widget
     * @param color : The color value
     */
    void setColor2(QColor color);
protected :

protected :
    /// The width of the widget
    int m_width;
    /// The height of the widget
    int m_height;
    /// The vertical resolution of the grid
    int m_gridHeightStep;
    /// The horizontal resolution of the grid
    int m_gridWidthStep;
    /// The drawGrid attriute
    int m_drawGrid;
    /// The color value for the grid
    QColor m_gridColor;
    /// The color value for the background
    QColor m_backgroundColor;
    /// The generic color value 1
    QColor m_color1;
    /// The generic color value 2
    QColor m_color2;
    /// The associated widget to paint on
    QPaintDevice * m_widget;
    /// The internal data to be painted
    std::vector<std::vector<float> >  m_cache;

};

#endif // PERFORMANCEPAINTER_H
