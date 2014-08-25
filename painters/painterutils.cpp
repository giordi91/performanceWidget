#include "painterutils.h"

painterUtils::painterUtils()
{
}


void painterUtils::drawRectangleGraph(QPainter &qp ,int const &startPos,
                                      int const &width,int const &height,
                                      std::vector<float>  &data,
                                      QColor &lineColor , QColor &bodyColor)


{
    //Get the size of the data
    int cacheSize = data.size();
    //Calculating the step size between each sample of the data (uniform distribution)
    float step = float(width-3)/(cacheSize-1);

    //Setup the colors
    qp.setPen(lineColor);
    qp.setBrush(bodyColor);

    //Create a polygon shape
    QPolygonF poly;
    int x,y;
    //Fill in the points to the polygon
    //Remeber that the height is relative to top left corner so needs to be reversed
    for( int i =0; i<cacheSize;i++)
    {
        if (i==0)
        {
            //The first one is the base , same value of the x but with minimum height value
            poly.append(QPoint( startPos+(i*step+2),height-1));
        }

        //Init to min height value
        y = (height-1);
        //convert data in range 0-1 and use it to multiply the height  ( with a small offset)
        y -= (data[i]/100*(height-5));
        //Init value to start position
        x = startPos;
        //Add the correct positon based on the number of steps taken ( plus  a small offset)
        x +=(i*step+2);
        //Append the point
        poly.append(QPoint(x,y));
        if(i== cacheSize -1)
        {
         //append last point
         poly.append(QPoint(x,height-1));
        }
    }
    //Draw the polygon
    qp.drawPolygon(poly);


}

void painterUtils::drawRectangleBar(QPainter &qp ,int const &startPos,int const &width,
                                    int const &height
                                 ,const float value, bool drawText ,
                                    QColor &color1 , QColor &color2)

{
    //Calculate how many pixel our rectangle will cover in width, we base the computation on the current input value
    // which should be a percentage
    int pixToCover = width * value/100.0f ;
    //Lets check the result iis not too small
    if ( value < 1.0 || pixToCover < 0 )
    {
      pixToCover =4;
    }
    //or too big
    if (pixToCover >= width)
    {
      pixToCover = width - 4;
    }
    //Lets build the backaground rectangle
    QRect myQRect = QRect(QPoint(startPos,3) , QSize(pixToCover-1,height-6));
    //Lets build the gradient
    QLinearGradient gradient(myQRect.topLeft(), myQRect.topRight()); // diagonal gradient from top-left to bottom-right
    //Lets set the color for the start positon
    gradient.setColorAt(0, color1);
    float r =(255*value/100.0f);
    if (r<0)
        r=0;
    if (r>255)
        r=255;
    r /= 255;
    //Lets interpolate the second color based on the percentage value
    gradient.setColorAt(1, QColor(color1.red()* (1-r) + color2.red()*r,
                                  color1.green()* (1-r) + color2.green()*r,
                                  color1.blue()* (1-r) + color2.blue()*r,
                                  255));
    //Lets draw the gradient
    qp.fillRect(myQRect, gradient);
    //Lets draw the text in the center of the triangle if needed
    if (drawText == true)
        qp.drawText(startPos + (width/2),height/2,QString::number(int(value)) + " %");

}

