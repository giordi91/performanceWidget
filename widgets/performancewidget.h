#ifndef PERFORMANCEWIDGET_H
#define PERFORMANCEWIDGET_H


#include <QWidget>
#include <dataQuery/queryresource.h>
#include <QTimer>
#include <painters/graphpainter.h>
#include <painters/barspainter.h>
#include <painters/graphmulticolorpainter.h>
#include <dataQuery/cpudataquery.h>

/**

 * @brief This class is a widget that lets you draw a changing value in time
 *
 * This class provides a basic widget used to draw a changing value in time,
 * The class in order to work needa two things :
 * \li data fetcher : A class inerithed from DataQuery , able to fetch the needed data
 * \li data painter : A class inerithed from PerformancePainter, able to paint the given data
 *
 * In this way doesn't matter how we fatch the data or how we want to display the data, we just swap
 * one of the needed classes and the widget will display accordingly
 *
*/

class PerformanceWidget : public QWidget
{
    Q_OBJECT
public :
    /// Constants defining the update's speed
    enum speedType
    {
      /// Fast update 250 ms
      FAST_UPDATE = 250,
      /// Medium update 500 ms
      MEDIUM_UPDATE = 500,
      /// Slow update 1000 ms
      SLOW_UPDATE = 1000
    } ;

public:
    /// Constructor
    explicit PerformanceWidget(QWidget *parent = 0);
    /// Destructor
    ~PerformanceWidget();
    /// Paint envent
    void paintEvent(QPaintEvent *e);
    /** This method lets the user set the wanted update speed for the
    * widget
    * @param speed : the wanted speed , 3 constants available \li SLOW_UPDATE
    *                \li MEDIUM_UPDATE \li FAST_UPDATE
    */
    void setSpeed( const speedType speed);
    /**
     * @brief Reimplemented size event, automatically connect the setGeometry() of the painter
     * providing correct data
     * @param e : the event
     */
    void resizeEvent(QResizeEvent *e);

    void setDataQuery(DataQuery *dataQ);
    void setPainter(PerformancePainter *painter);
private slots:
    ///This function is used to fetch the data from the data class
    void updateData();

private :
    ///The internal timer for the repaint
    QTimer * m_timer;
    PerformancePainter * m_painter;
    DataQuery * m_dataQuery;




};




#endif // PERFORMANCEWIDGET_H
