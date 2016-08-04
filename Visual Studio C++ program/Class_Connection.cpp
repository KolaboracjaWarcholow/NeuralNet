#include "stdafx.h"
#include "Class_Connection.h"

//Connection::Connection()
//	{
//		m_Weight = 0;
//	}
Connection::Connection(double newWeight)
{
	m_Weight = newWeight;
	m_DeltaWeight = 0;
}
void Connection::ChangeWeight(double newWeight)
{
	m_Weight = newWeight;
}
double Connection::GetWeight()
{
	return m_Weight;
}
void Connection::ChangeDeltaWeight(double newDeltaWeight)
{
	m_DeltaWeight = newDeltaWeight;
}
double Connection::GetDeltaWeight()
{
	return m_DeltaWeight;
}