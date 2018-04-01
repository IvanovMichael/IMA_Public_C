#pragma once
#include <iostream>

using namespace std;

class Mass
{
public:
	double *x;
	unsigned int n;

	double mid(double(*f)(double))
	{
		double A = 0;
		if (f == 0)
		{
			for (int i = 0; i < n; i++)
			{
				A += x[i];
			}
		}
		else
			for (int i = 0; i < n; i++)
			{
				A += f(x[i]);
			}
		A /= n;

		return A;
	}

	Mass add(double d)
	{
		Mass m;
		m.n = n + 1;
		m.x = new double[n + 1];
		for (int i = 0; i < n; i++)
		{
			m.x[i] = x[i];
		}
		m.x[n] = d;
		return m;
	}
	
	Mass()
	{
		n = 0;
	}

	Mass(Mass& m)
	{
		n = m.n;
		x = new double [n];
		for (int i = 0; i < n; i++)
		{
			x[i] = m.x[i];
		}
	}

	Mass(double *arr, int k)
	{
		n = k;
		x = new double[n];
		for (int i = 0; i < n; i++)
		{
			x[i] = arr[i];
		}
	}

	Mass operator++(int)
	{
		Mass m(*this);
		for (int i = 0; i < n;)
		{
			x[i++]++;
		}
		return m;
	}

	Mass& operator = (Mass& m)
	{
		delete[]x;
		n = m.n;
		x = new double[n];
		for (int i = 0; i < n; i++)
		{
			x[i] = m.x[i];
		}
		return *this;
	}

	Mass operator *(double a)
	{
		Mass Y(*this);
		for (int i = 0; i < n; i++)
		{
			Y.x[i] = Y.x[i] * a;
		}
		return Y;
	}

	friend ostream& operator <<(ostream& out, Mass& m)
	{
		for (int i = 0; i < m.n; i++)
		{
			out << "x" << i + 1 << " = " << m.x[i] << '\n';
		}
		return out;
	}

	friend istream& operator >>(istream& in, Mass& m)
	{
		for (int i = 0; i < m.n; i++)
		{
			in >> m.x[i];
		}
		return in;
	}

	~Mass()
	{
		delete[] x;
	};
};