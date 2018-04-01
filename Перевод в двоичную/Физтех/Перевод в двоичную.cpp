#include <iostream>
using namespace std;
void main()
{
	unsigned int a, i;
	cout << "Input a= ";
	cin >> a;
	for(i = 0; a != 0; i++)
	{
		cout << a % 2;
		a = a / 2;
	}
	cout << endl << i << endl;
	system("pause");
}