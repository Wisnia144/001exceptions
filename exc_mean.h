#include <iostream>
class bad_hmean
{
private:
	double v1;
	double v2;
public :
	bad_hmean(double a = 0, double b = 0) : v1 (a), v2(b){}
	void mesg();

};

inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "wrong args: a = -b\n";
}

class bad_gmean
{
public : 
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) : v1(a),v2(b) {}
	const char * mesg();
};


inline const char * bad_gmean::mesg()
{
	return "Args gmean > 0\n";	
}

class my_excep
{
int k;
public:
	my_excep(int inp = 0) : k(inp){};
	const char * mesg();
};

inline const char * my_excep::mesg()
{
	return "!!!!!!!!!Args>100 or < 50\n";
}
