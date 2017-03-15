#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
class Point
{
	double x, y;
public:
	Point()
	{
		x = 0; y = 0;
	}
	void set()
	{
		cout << "x=";
		cin >> x;
		cout << "y=";
		cin >> y;
	}
	double line()
	{
		return sqrt(x*x + y*y);
	}
	void show()
	{
		cout << "x=" << x << " " << "y=" << y << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	unsigned n;
	double r;
	cout << "n=";
	cin >> n;
	Point *a = new Point[n];
	for (unsigned i = 0; i < n; ++i)
	{
		a[i].set();
	}
	for (unsigned i = 0; i < n; ++i)
	{
		a[i].show();
	}
	for (unsigned i = 0; i < n; ++i)
	{
		r=a[i].line();
		cout << "distance=" << r <<" ";
	}
	delete a;
	_getch();
	return 0;
}
