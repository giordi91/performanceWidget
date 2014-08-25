#include "ramdataquery.h"

RamDataQuery::RamDataQuery()
{
    m_cache.resize(1);

}


void RamDataQuery::getData()
{
    //Update the data in the cache , this function also returns
    //the instant memory usage but we discard it since we actually
    // need the cache
    m_mem.getMemoryUsage();
    //Get the ordered data
    m_mem.getOrderedMemoryUsageCache(m_cache[0]);

}
