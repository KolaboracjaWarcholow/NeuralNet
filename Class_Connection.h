#ifndef CLASS_CONNECTION_H
#define CLASS_CONNECTION_H
class Connection
{
private:
	double m_Weight;
public:
	void ChangeWeight(double newWeight);
	double GetWeight();
	Connection();
	Connection(double);
};
#endif
