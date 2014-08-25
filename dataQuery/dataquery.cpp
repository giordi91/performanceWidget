#include "dataquery.h"

DataQuery::DataQuery():m_index(0), m_multi(0)
{
}



void DataQuery::setIndex(int index)
{

    m_index = index;

}

void DataQuery::setMulti( bool value)
{
    m_multi = value;
}

