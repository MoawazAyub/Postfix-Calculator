# include <iostream>
# include  <string>
# include "Stack.h"

using namespace std;



template <class T>
class Calculator
{

	Stack<T> s;

public:

	void push(const T & obj)
	{
		s.push(obj);
	
	}

	void pop()
	{
		s.pop();
	
	}

	void print()
	{
		s.print();
	
	}

	const T & top()
	{
		return s.top();
	
	}

	int size()
	{
		return s.size();
	
	}

	string input(string st)
	{
		Operator a, b,c;
		b.setdiscription("(");
		string temp;
		int count = 0;
		for (int j = 0 ; j < st.size() ; j++)
		{
			if(st[j] >= 48 && st[j] <= 57)
			{
			temp = temp + st[j];
			count++;
			}

			else if(st[j] == ' ')
			{
			if (count != 0)
			{
				count = 0;
				temp = temp + " ";
			
			}
			}

			else if (st[j] == '(')
			{
				a.setdiscription("(");
				s.push(a);

			
			}

			else if (st[j] == ')')
			{
				Operator a1;
				a1 = s.top();
				while((s.empty()) == false && a1 != b)
				{
					 c = s.top();
					  temp = temp + " ";
					 temp = temp + c.getdiscription();
					 s.pop();
					 
				
				}
				s.pop();
			
			
			}

			else if(st[j] == '+' || st[j] == '-' || st[j] == '*' || st[j] == '/' )
			{
				if (st[j] == '+' && st[j + 1] == '+')
				{
					a.setdiscription("++");
					j++;
					s.push(a);
				
				}

				else if (st[j] == '-' && st[j + 1] == '-')
				{
					a.setdiscription("--");
					j++;
					s.push(a);
				
				}

				else 
				{
					Operator d,e,f;
					a.setdiscription(st[j]);
					s.push(a);
					d = s.top();
					e = s.top();
					s.pop();
					if(!(s.empty()))
					{
						f = s.top();

					}
					while (!(s.empty()) && d.getpresedence() <= f.getpresedence() && f != b)
					{
						
						temp = temp + f.getdiscription();
						temp = temp + " ";
						s.pop();
						if(!(s.empty()))
					    {
						f = s.top();
						}
					}
					s.push(d);

					
				}
					
				
				
			
			
			}//------------
			

		
		}
	if ( !(s.empty()) )
					{
						Operator g = s.top();
						while (!(s.empty()))
						{
							g = s.top();
							temp = temp + " ";
							if (g.getdiscription() != "(")
							{
						temp = temp + g.getdiscription();
							}
						s.pop();
						
						}
					
					
					}

//	cout << temp;
	string temp2;
	int count2 = 0;
	for(int z = 0 ; z < temp.size();z++ )
	{
		if(temp[z] == ' ' || temp[z] == '(')
		{
			count2++;
		}
		else
		{
			count2 = 0;
		
		}
		if(temp[z] !='(' && count2 < 2)
		{
		temp2 = temp2 + temp[z];
		}
	
	}
	return temp2;
	}

	int evaluate(string & st)
	{
		int x=0,y=0;
		Stack<string> a1;
		string temp,temp2,temp3;
		int i = 0;
		int count = 0;

		for(int j = 0 ; j < st.size() ; j++)
		{
			if(st[j] >= 48 && st[j] <= 57)
			{
				temp = temp + st[j];
			count++;
			}

			else if(st[j] == ' ')
			{
			if (count != 0)
			{
				count = 0;
				a1.push(temp);
				temp = "";
			
			}
			}

			else if(st[j] == '+' || st[j] == '-' || st[j] == '*' || st[j] == '/' )
			{
				if (st[j] == '+' && st[j + 1] == '+')
				{
					temp2 = a1.top();
					x = stoi(temp2);
					x = x + 1;
					a1.pop();
					a1.push(to_string(x));
					j++;
				
					
				
				}

				else if (st[j] == '-' && st[j + 1] == '-')
				{
					temp2 = a1.top();
					x = stoi(temp2);
					x = x - 1;
					a1.pop();
					a1.push(to_string(x));
					j++;
				
				
				}

				else if(st[j] == '+')
				{
					int z = 0;
					temp2 = a1.top();
					y = stoi(temp2);
					a1.pop();
					temp2 = a1.top();
					x = stoi(temp2);
					a1.pop();
					z = x + y;
					
					a1.push(to_string(z));
				
				}

				else if(st[j] == '-')
				{
					int z = 0;
					temp2 = a1.top();
					y = stoi(temp2);
					a1.pop();
					temp2 = a1.top();
					x = stoi(temp2);
					a1.pop();
					z = x - y;
					
					a1.push(to_string(z));
				
				}

				else if(st[j] == '*')
				{
					int z = 0;
					temp2 = a1.top();
					y = stoi(temp2);
					a1.pop();
					temp2 = a1.top();
					x = stoi(temp2);
					a1.pop();
					z = x * y;
					
					a1.push(to_string(z));
				
				}

				else if(st[j] == '/')
				{
					int z = 0;
					temp2 = a1.top();
					y = stoi(temp2);
					a1.pop();
					temp2 = a1.top();
					x = stoi(temp2);
					a1.pop();
					z = x / y;
					
					a1.push(to_string(z));
				
				}
					
				
				
			
			
			}//------------
		}
		int v = stoi(a1.top());
		return v;
	}
	
	};



void main()
{
	
	
	Calculator<Operator> c;
	string s;
	string t;
	while(s != "quit")
	{
		cout << "enter command Remember to add spaces between digits (result is in integer)" <<endl;
		getline(cin, s);
		if (s == "quit")
		{
			break;
		
		}
		t = c.input(s);
		cout <<t;
		cout << endl;
		cout << "answer = ";
		cout << c.evaluate(t);
		cout << endl;
	
	}

		
	//Calculator<Operator> c;
	//string s = "2 + 3";
	//string t;
	//t = c.input(s);
	////t = "18 2 * 6 /";
	//cout<<c.input(s);
	//
	//cout << endl;
	//cout<<c.evaluate(t);
	//cout <<endl;
	///*Operator o,t;
	//o.setdiscription("/");
	/*c.push(o);
	
	o.setdiscription("+");
	c.push(o);
	
	o.setdiscription("*");
	c.push(o);
	c.pop();
	o.setdiscription("-");
	c.push(o);
	c.print();
	
	t = c.top();

	int d = t.getpresedence() ;
	cout << d;
	*/
}