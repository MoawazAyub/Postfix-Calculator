# include <iostream>
# include  <string>
# include "Vector.h"
# include "Operator.h"

using namespace std;


template <class T>
class Stack
{
	vector<T> st;

public:

	friend ostream & operator<<(ostream &  out,  Stack & s)
	{
		s.print();
	return out;
	}
	void push( const T & obj)
	{
		st.push_back(obj);
	
	}

	void pop()
	{
		st.pop_back();
	
	}

	const T & top()
	{
		return st[st.getsize() - 1];
	
	}

	int size()
	{
		return st.getsize();
	
	}

	bool empty()
	{
		return (st.getsize() == 0);
	
	}

	void print()
	{
		st.print();
	
	}

	vector<T> gets()
	{
		return s;
	
	}

};