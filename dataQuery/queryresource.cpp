#include "queryresource.h"
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sstream>
CpuQuery::CpuQuery():m_percent(0.0),m_cacheSize(30),
    m_cacheStartIndex(0)
{
    //Initializing number of cores
     m_numberOfCores = sysconf(_SC_NPROCESSORS_ONLN);

     //Initializing cache vectors
     m_lastTotalUser = std::vector<int>(m_numberOfCores +1,0);
     m_lastTotalUserLow = std::vector<int>(m_numberOfCores +1,0);
     m_lastTotalSys = std::vector<int>(m_numberOfCores +1,0);
     m_lastTotalIdle = std::vector<int>(m_numberOfCores +1,0);

     m_percentages = std::vector<std::vector<float> >
             (m_numberOfCores +1, std::vector<float>(m_cacheSize,0));

     //Init data
     getCPUs();

}



void CpuQuery::getCPUs()
{
        //Initialize if stram
        std::ifstream filess("/proc/stat");
        std::string line;
        i=0;
        while (std::getline(filess, line))
        {

                //loop the cores
                if (i <= (m_numberOfCores))
                {

                //storing the cache index
                int currCacheIndex = m_cacheStartIndex-1;
                if (currCacheIndex < 0)
                {
                    currCacheIndex = m_cacheSize -1;
                }
//                std::cout<<currCacheIndex<<std::endl;

                    std::stringstream ss;
                    //get the cpu name
                    ss <<line;
                    //Get different data usage
                    ss >>m_tempStr;
                    ss>>m_totalUser;
                    ss>>m_totalUserLow;
                    ss>>m_totalSys;
                    ss>>m_totalIdle;


                    //Compute the percentage
                    if (m_totalUser < m_lastTotalUser[i] ||
                        m_totalUserLow < m_lastTotalUserLow[i] ||
                        m_totalSys < m_lastTotalSys[i] ||
                        m_totalIdle < m_lastTotalIdle[i])
                    {
                        //Overflow detection. Just skip this value.
                        m_percent = -1.0;
                        m_percentages[i][currCacheIndex]=m_percent;
                    }
                    else
                    {
                        m_total = (m_totalUser -m_lastTotalUser[i]) +
                                (m_totalUserLow - m_lastTotalUserLow[i]) +
                            (m_totalSys - m_lastTotalSys[i]);
                        m_percent = m_total;
                        m_total += (m_totalIdle - m_lastTotalIdle[i]);

                        //Check if we got a valid result
                        if (m_total > 0 )
                        {
                            m_percent /= m_total;
                        m_percent *= 100;
                        }
                        else
                        {
                            m_percent =0;
                        }
                        //store the data in correct cache index
                        m_percentages[i][currCacheIndex]=m_percent;
                    }

                    //store the data in the cache for next iteration
                    m_lastTotalUser[i] = m_totalUser;
                    m_lastTotalUserLow[i] = m_totalUserLow;
                    m_lastTotalSys[i] = m_totalSys;
                    m_lastTotalIdle[i] = m_totalIdle;




                }
                else
                {break;}
                i++;
        }

        //loop the cache index
        m_cacheStartIndex++;
        if ( m_cacheStartIndex > (m_cacheSize -1))
        {
            m_cacheStartIndex = 0;
        }


  }

void CpuQuery::getInstantCPU(const int &coreIDx ,
                             std::vector<std::vector<float> > &cache)
{
    //resize incoming cache
    cache.resize(1);
    cache[0].resize(1);
    //store the data in the cache if ithe core idx is a valid index
    if (coreIDx <= m_numberOfCores +1)
        cache[0][0] = m_percentages[coreIDx][m_cacheStartIndex];

    else
        cache[0][0] = -1;
}

void CpuQuery::getAllInstantCPUs(std::vector<std::vector<float> > &cache)
{
    //resize incoming cache
    cache.resize(1);
    cache[0].resize(m_numberOfCores +1);

    //store correct data
    for (int i = 0; i <m_numberOfCores +1;i++)
    {
        cache[0][i] = m_percentages[i][m_cacheStartIndex];

    }


}

const std::vector<float>& CpuQuery::getCpuCache(const int &coreIDx)
{

    return m_percentages[coreIDx];

}

void CpuQuery::getOrderedCpuCache(const int &coreIDx , std::vector<std::vector<float> > &cache )
{
    //resize incoming cache
    cache.resize(1);
    cache[0].resize(m_cacheSize);
    //reorder wanted cache and store it correctly in the target cache
    reorderCache(m_percentages[coreIDx] , cache[0]);



}

void CpuQuery::getOrderedCpusCache(std::vector<std::vector<float> > &cache)
{

    //resize incoming cache
    cache.resize(m_numberOfCores +1);
    for (int j = 0 ;j < m_numberOfCores +1; j++)
    {
        cache[j].resize(m_cacheSize);
        reorderCache(m_percentages[j] , cache[j]);

    }



}

void CpuQuery::reorderCache(std::vector<float> &source, std::vector<float> &target)
{
    //let s make a copy of the internal start index so we can use it to loop it
    int tempIndex = int(m_cacheStartIndex)-1;
    //loop cache size
    for (i =0 ; i < m_cacheSize ;i++)
    {

        target[i]= source[tempIndex];
        tempIndex ++;
        if ( tempIndex > (m_cacheSize-1 ))
        {
            tempIndex = 0;
        }
    }


}

int CpuQuery::getNumberOfCores()
{
    return sysconf(_SC_NPROCESSORS_ONLN);
}


MemoryQuery::MemoryQuery() : m_memoryUnit(GIGA_BYTE) ,
                             m_cacheSize(30),
                             m_cacheStartIndex(0)

{
    m_cache.resize(m_cacheSize);

}

float MemoryQuery::getTotalMem()
{

    long bytes =    sysconf( _SC_PHYS_PAGES) * sysconf( _SC_PAGESIZE );
    return convertMemory(bytes);

}



float MemoryQuery::getUsedMem()
{
    long bytes =  (sysconf( _SC_PHYS_PAGES) * sysconf( _SC_PAGESIZE ))-
            sysconf( _SC_AVPHYS_PAGES) * sysconf( _SC_PAGESIZE );
    return convertMemory(bytes);


}


float MemoryQuery::getFreeMemory()
{
    long bytes =sysconf( _SC_AVPHYS_PAGES) * sysconf( _SC_PAGESIZE );
    return convertMemory(bytes);

}


float MemoryQuery::getMemoryUsage()
{
    float percentage = float(getUsedMem())/getTotalMem()*100.0f;
    int currCacheIndex = m_cacheStartIndex-1;
    if (currCacheIndex < 0)
    {
        currCacheIndex = m_cacheSize -1;
    }
    m_cache[currCacheIndex] =   percentage;


    //loop the cache index
    m_cacheStartIndex++;
    if ( m_cacheStartIndex > (m_cacheSize -1))
    {
        m_cacheStartIndex = 0;
    }


    return percentage;

}

float MemoryQuery::convertMemory( long bytes)
{

    float toReturn = 0 ;
    switch(m_memoryUnit)
    {
    case 0 :

        toReturn= float(bytes)/MEGA_BYTE_MULT;
        break;
    case 1 :
        toReturn= float(bytes)/GIGA_BYTE_MULT;
        break;

    }

    return toReturn;

}


const std::vector<float>&  MemoryQuery::getMemoryUsageCache()
{
        return m_cache;
}

void MemoryQuery::getOrderedMemoryUsageCache(std::vector<float>  &cache)
{

    //resize incoming cache
    cache.resize(m_cacheSize);
//    cache[0].resize(m_cacheSize);
    //reorder wanted cache and store it correctly in the target cache
    reorderCache(m_cache , cache);

}

void MemoryQuery::reorderCache(std::vector<float> &source, std::vector<float> &target)
{
    //let s make a copy of the internal start index so we can use it to loop it
    int tempIndex = int(m_cacheStartIndex)-1;
    //loop cache size
    for (int i =0 ; i < m_cacheSize ;i++)
    {

        target[i]= source[tempIndex];
        tempIndex ++;
        if ( tempIndex > (m_cacheSize-1 ))
        {
            tempIndex = 0;
        }
    }


}
