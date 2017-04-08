// 002Wa33tki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Co ja to mam
using namespace std;

class demo
{
private:
	std::string word;
public:
	demo(const char * str)
	{
		word = str;
		std::cout << "Obj D" << word << "Created\n";
	}
	~demo()
	{
		cout << "Obj d" << word << "Destroyed\n";
	}

	void show() const
	{
		cout << "Obj d" << word << "Running\n";
	}
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int _tmain(int argc, _TCHAR* argv[])
{
	double x,y,z;
	{
		demo d1("blok main");
		cout << "Ready for 2:";
		while(cin >> x >> y)
		{
			try
			{
				z = means(x,y);
				cout << "Median:" << x << " i " << y 
					<< " wynosi " << z << endl;
				cout  << "Ready for next pair:";
			}
			catch(bad_hmean & bg)
			{
				bg.mesg();
				cout << "Try once more.\n";
				continue;
			}
			catch(bad_gmean & hg)
			{
				cout << hg.mesg();
				cout << "Used values:" << hg.v1 << ", "
					<< hg.v2 << endl;
				cout << "Finished \n";
				break;
			}
		}
		d1.show();
	}
	cout << "Koniec\n";
	cin.get();
	cin.get();


	cout << "---" << endl;
	//getch();
	return 0;
}

double hmean(double a, double b)
{
	if(a == -b)
		throw bad_hmean(a,b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if(a < 0 || b < 0)
		throw bad_gmean(a,b);
	return sqrt(a*b);
}

double means(double a, double b)
{
	double am,hm,gm;
	demo d2("Z funkcji means()");
	am = (a + b) / 2.0;
	try
	{
	 hm = hmean(a,b);
	 gm = gmean(a,b);
	}
	catch(bad_hmean & bg)
	{
		bg.mesg();
		cout << "Catched in means\n";
		throw;
	}
	d2.show();
	return (am + hm + gm)/3.0;
}




