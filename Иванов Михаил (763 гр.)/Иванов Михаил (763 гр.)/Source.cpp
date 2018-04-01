#include "Mass.h"

int main()
{
	double t = 6.8;
	unsigned int k;
	cin >> k;
	double *x = new double[k];
	for (int i = 0; i < k; i++)
	{
		cin >> x[i];
	}
	Mass temp(x, k);
	//temp = temp*.1;
	//cout << temp;
	temp.mid();
	cout << temp;
	system("pause");
	return 0;
}