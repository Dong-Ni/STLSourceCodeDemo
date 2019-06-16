#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <algorithm>

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
	//std::  ���ñ�׼��   ::���ñ���
	cout << plusObjInt(5, 7) << endl;


	::less<int> lessObjInt;
	cout << lessObjInt(19, 2) << endl;
	cout << lessObjInt(19, 20) << endl;

	//��outtile�󶨵�cout��ÿ�ζ�outtileָ��һ��Ԫ�أ��ͺ��һ�� " "
	cout << "============================" << endl;
	ostream_iterator<int> outite(cout, " ");
	int ia[] = {0,1,2,3,4,5};
	vector<int> id(ia, ia + 6);
	copy(id.begin(), id.end(), outite);
	cout << endl;

	for_each(id.begin(), id.end(), compose1(bind2nd(multiplies<int>(), 3), bind2nd(plus<int>(), 2)));

	getchar();
	return 0;
}