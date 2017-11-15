#include<iostream>
using namespace std;

template<typename T, typename COMP>
T MinMax(T a, T b,T c, COMP comp)
{	
	T res = a;
	if (!comp(res,b))
	{
		res = b;
	}
	if (!comp(res, c))
	{
		res = c;
	}	
	return res;
}

template<typename T>
class WhatDoYouWhant
{
private:
	bool m_minMax;//0 for min - 1 for max
public:
	WhatDoYouWhant(bool minMax):m_minMax(minMax){}
	bool operator() (T a, T b)
	{
		return m_minMax ? a > b : a < b;
	}
};

void main()
{
	cout << MinMax(1, 2, 3, WhatDoYouWhant<int>(false)) << endl;
	cout << MinMax(1, 2, 3, WhatDoYouWhant<int>(true)) << endl;
	cout<< MinMax(1.1, 2.2, 3.3, WhatDoYouWhant<double>(false)) << endl;
	cout << MinMax(1.1, 2.2, 3.3, WhatDoYouWhant<double>(true)) << endl;

}