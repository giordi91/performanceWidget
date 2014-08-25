#include "cpudataquery.h"

CpuDataQuery::CpuDataQuery() : DataQuery()
{
}


void CpuDataQuery::getData()
{
    m_cpu.getCPUs();

    //if we draw a single graph we only get the cache for the
    //current cpu and store it in m_singleCache
    if (m_multi == 0)
    {
        m_cpu.getOrderedCpuCache(m_index, m_cache);
    }
    //if we draw a cache for all cpus then we grab all the cpu caches
    //and store the result in m_cache
    else
    {
        m_cpu.getOrderedCpusCache(m_cache);

    }

}


int CpuDataQuery::getNumberOfCores()
{
    return m_cpu.getNumberOfCores();

}
