#ifndef CLASS_CONNECTION_H
#define CLASS_CONNECTION_H
class Connection
{
private:
	double m_Weight;
	double m_DeltaWeight;
public:
	void ChangeWeight(double);
	double GetWeight();
	void ChangeDeltaWeight(double);
	double GetDeltaWeight();
	Connection(double);
};
#endif
