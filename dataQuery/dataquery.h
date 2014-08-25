#ifndef DATAQUERY_H
#define DATAQUERY_H
#include <iostream>
#include <stdio.h>
#include <vector>
/**
  *@brief This class is an abstract class used to generate classes for data fetching
  *
  *This class is is used as a base for implementing different type of
  *classes used to query different type of data.
  *You will need to reimplement the virtual fucntions getData and destructor
  *The data you will fetch will need to be stored in the m_cache member
  * which is a 2D std::vector<float> matrix.
  * You also have a couplw of variables you can use in your computation
  * if needed :
  *  \li m_index
  *  \li m_multi
  */

class DataQuery
{
public:
    /// The constructor
    DataQuery();
    /// The destructor
    virtual ~DataQuery(){}
    /// The virtual fucntion to reimplement used to gather the data
    virtual void getData(){}
    /** Setter function for the index
    * @param index : the value at which you want to set the index
    */
    void setIndex(int index);
    /** Setter funtcion for the multi variable
    * @param value : wheter or not to set the multi attribute to on or off
    */
    void setMulti(bool value);


public :
    int m_index;
    int m_multi;
    /// The cache used to store all the data
    std::vector<std::vector<float> > m_cache;
};

#endif // DATAQUERY_H
