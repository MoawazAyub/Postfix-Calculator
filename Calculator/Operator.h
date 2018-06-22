# include <iostream>
# include  <string>


using namespace std;

class Operator
{
	string s;
	int presedence;
public:
	
	Operator()
	{
		presedence = 0;
	
	}

	bool operator!=(Operator & o)
	{
		if(presedence != o.getpresedence())
		{
			return true;
		
		}
		else 
		{
			return false;
		
		}
	
	}
	void print()
	{
		cout << s << endl;
		cout << presedence << endl;
	
	}

	string getdiscription()
	{
		return s;
	
	}

	int getpresedence()
	{
		return presedence;
	
	}

	friend ostream & operator<<(ostream &  out,  Operator & o)
	{
		o.print();
	return out;
	}

	void setdiscription(char s2)
	{
		if(s2 == '-')
		{
			s = s2;
			presedence = 1;
		}

		else if(s2 == '+')
		{
			s = s2;
			presedence = 2;
		}

		else if(s2 == '*')
		{
			s = s2;
			presedence = 3;
		}

		else if(s2 == '/')
		{
			s = s2;
			presedence = 4;
		}

		
			
	
	
	}

	void setdiscription(string s2)
	{
		if(s2 == "-")
		{
			s = s2;
			presedence = 1;
		}

		else if(s2 == "+")
		{
			s = s2;
			presedence = 2;
		}

		else if(s2 == "*")
		{
			s = s2;
			presedence = 3;
		}

		else if(s2 == "/")
		{
			s = s2;
			presedence = 4;
		}

		else if(s2 == "++" || s2 == "--")
		{
			s = s2;
			presedence = 5;
		}

		else if(s2 == "(")
		{
			s = s2;
			presedence = 10;
		}

		else if(s2 == ")")
		{
			s = s2;
			presedence = 11;
		}
			
	
	
	}

	Operator(char s2)
	{
		if(s2 == '-')
		{
			s = s2;
			presedence = 1;
		}

		else if(s2 == '+')
		{
			s = s2;
			presedence = 2;
		}

		else if(s2 == '*')
		{
			s = s2;
			presedence = 3;
		}

		else if(s2 == '/')
		{
			s = s2;
			presedence = 4;
		}
			
	
	}


};