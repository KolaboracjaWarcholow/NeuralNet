#include "stdafx.h"
#include "Class_Connection.h"

Connection::Connection()
	{
		m_Weight = 0;
	}
Connection::Connection(double newWeight)
{
	m_Weight = newWeight;
}
void Connection::ChangeWeight(double newWeight)
{
	m_Weight = newWeight;
}
double Connection::GetWeight()
{
	return m_Weight;
}