#include<iostream>
#include<cstdlib>
#include<stdio.h>

using namespace std;
class car
{
	unsigned int speed, power;
public:
	car(unsigned int speed, unsigned int power)
	{
		this->speed = speed;
		this->power = power;
	}
	virtual void show()
	{
		cout << "power=" << power << " " << "speed=" << speed << endl;
	}
};
class track : public car
{
	double weigh;
public:
	track(unsigned int speed, unsigned int power, unsigned int weigh) :
		car(speed, power)
	{
		this->weigh = weigh;
	}
	void show()
	{
		car::show();
		cout << "wiegh=" << weigh;
	}

};
int main()
{
	unsigned int speed, power, n, weigh;
	cout << "n=";
	if (scanf_s("%d", &n) != 0)
		cout;
	else exit(1);
	for (unsigned int i = 0; i<n; ++i)
	{

		cout << "speed1=";
		if (scanf_s("%d", &speed) != 0)
			cout << "power1=";
		if (scanf_s("%d", &power) != 0)
			cout;
		else exit(1);
		car a1(speed, power);

		cout << "speed2=";
		if (scanf_s("%d", &speed) != 0)
			cout << "power2=";
		else exit(1);
		if (scanf_s("%d", &power) != 0)
			cout << "weigh=";
		else exit(1);
		if (scanf_s("%d", &weigh) != 0)
			cout;
		else exit(1);
		track t1(speed, power, weigh);
		car *aa;
		aa = &a1;
		aa->show();
		aa = &t1;
		aa->show();
		cout << endl;
	}
	system("pause");
	return 0;
}
