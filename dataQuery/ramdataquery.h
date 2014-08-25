#ifndef RAMDATAQUERY_H
#define RAMDATAQUERY_H
#include <dataQuery/queryresource.h>
#include <dataQuery/dataquery.h>


/**
  @brief This class is used to query the ram data for the performance widge
 */

class RamDataQuery : public DataQuery
{
public:
    /// The constructor
    RamDataQuery();
    /// The destructor
    ~RamDataQuery(){}
    /// This function gather all the data needed and stores it internally in the
    /// cache attribute
    void getData();




private :
    /// The class used for general memory query
    MemoryQuery m_mem;

};


#endif // RAMDATAQUERY_H
