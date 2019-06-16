#include <iostream>
#include <functional>

using namespace std;

template <class T>
struct plus : public binary_function<T, T, T>
{
	T operator()(const T& x, const T& y) const
	{
		return x + y;
	}
};

template <class T>
struct less : public binary_function<T, T, T>
{
	bool operator()(const T& x, const T& y) const 
	{
		return x < y;
	}
};
int main()
{
	::plus<int> plusObjInt;
	//std::  调用标准库   ::调用本级
	cout << plusObjInt(5, 7) << endl;


	::less<int> lessObjInt;
	cout << lessObjInt(19, 2) << endl;
	cout << lessObjInt(19, 20) << endl;

	getchar();
	return 0;
}