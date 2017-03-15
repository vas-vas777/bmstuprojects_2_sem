#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<clocale>
using namespace std;

class text
{
	char str[128];
public:
	text()
	{
		for (unsigned int i = 0; i < 128; ++i) str[i] = { 0 };
	}
	void operator +(char*);
	void show();
};
void text::operator +(char *s)
{
	strcat_s(str, s);
}
void text::show()
{
	cout << str << endl << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	char *str1 = new char[27];
	char *str2 = new char[28];
	char *str3 = new char[28];
	char *str4 = new char[27];

	strcpy_s(str1,26, "У лукоморья дуб зелёный;\n");
	strcpy_s(str2,27, "Всё ходит по цепи кругом;\n");
	strcpy_s(str3,27,"И днём и ночью кот учёный\n");
	strcpy_s(str4,26,"Златая цепь на дубе том:\n");

	text t;
	t + str1;
	t + str4;
	t + str3;
	t + str2;
	cout << "Получившийся стих" << endl;
	t.show();
	delete[] str1;
	delete[] str2;
	delete[] str3;
	delete[] str4;
	system("pause");
	return 0;
}
