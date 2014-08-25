#ifndef PAINTERUTILS_H
#define PAINTERUTILS_H
#include <QPainter>

/** @brief This class is used to facilitate the paints of different graphs
  *
  * This class defines some usefull procedures for some basic standard drawings,
  * all the functios in this class are static meanings that can be called without the need
  * to make an instance of the class itself
  *
  */


class painterUtils
{
public:
    ///The constructor
    painterUtils();
    /**
     * @brief This procedure draws a uniform spaced line graph
     * @param qp : the painter you want to use for the drawing
     * @param startPos : the start position of the rectangle (left top corner)
     * @param width : the width of the rectangle
     * @param height : the height of the rectangle
     * @param data : the data to be displayed, this is a vector of floats rapresentings the y
     *               coordinates of our points ( which are uniformely distribuited on the x)
     * @param lineColor : the color we want to use for the line
     * @param bodyColor : the color we want to use for the body delimited by the graph (below)
     *
     * Example of possible graph :
     * @image html performanceSingleGraph.png "Regular Graph"
    */
    static void drawRectangleGraph(QPainter &qp ,int const &startPos,
                                   int const &width,int const &height,
                                   std::vector<float>  &data,
                                   QColor &lineColor , QColor &bodyColor);
    /**
     * @brief This procedure draws a single bar graph
     * @param qp : the painter you want to use for the drawing
     * @param startPos : the start position of the rectangle (left top corner)
     * @param width : the width of the rectangle
     * @param height : the height of the rectangle
     * @param value : the value in percentage of the width for the lenght of the bar
     * @param drawText : Whether or not to draw the text percentage
     * @param color1 : The starting color of the bar (color gets interpolated with color2)
     * @param color2 : The ending color of the bar (color gets interpolated with color1)
     *
     * Example of possible graph :
     * @image html performanceSingleBar.png "Bar Graph"
    */
    static void drawRectangleBar(QPainter &qp ,int const &startPos,
                          int const &width,int const &height ,const float value
                          , bool drawText,QColor &color1 , QColor &color2);


};

#endif // PAINTERUTILS_H
