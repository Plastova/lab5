#include <iostream>
#include <cmath>
#include <fstream> 
using namespace std;

const double eps = 0.001, a=1;
int n=600;
double A, h;

double func(double x) { 
	return sin(x)/((1+x)*sqrt(x));
	}

double calc_A () {
	return -10*log(eps/10);
	}

double pryamoug_center(double a, double b, int n) {
	h = (A - a) / n;
	double res = 0;
	for(int i = 0; i < n-1; i++) {
	res += func(a + h * (i + 0.5));
	}
	res *= h;
	return res;
	}

double trapetsiy (double a, double b, int n) {
	h = (A - a) / n;
	double res = 0;
	for(int i = 0; i < n - 1; i++) {
		res += 0.5*(func(a + h*i) + func(a + h*(i+1)));
	}
	res *= h;
	return res;
	}
	
double simps (double a, double b, int n) {
	h = (A - a) / n;
	double res = 0;
	for(int i = 0; i < n/2; i++) {
		res += (func(a + h*2*i) + 4*func(a + h*(2*i+1)) + func(a + h*(2*i+2)));
	}
	res *= h/3;
	return res;
	}

double runge (double i1, double i2) {
	return fabs((i1-i2)/i1);
	}

int main () {
	double res, res2;
	A = calc_A();
	ofstream fout1, fout2,fout3;
	fout1.open("ans1.dat");
	fout2.open("ans2.dat");
	fout3.open("ans3.dat");
	
	res=pryamoug_center (a,A,n);
	res2=pryamoug_center (a,A,2*n);
	cout<<"1) Po formule pryamougolnikov s tsentralnoy tochkoy:\n\t\tI = "<<res+eps<<endl;
	fout1<<res<<" ";
	res=runge (res, res2);
	cout<<"Pogreshnost po pravilu Runge: "<<res<<endl;
	fout1<<res;
	fout1.close();
	res = trapetsiy(a,A,n);
	res2 = trapetsiy(a,A,2*n);
	cout<<"\n2) Po formule trapetsiy:\n\t\tI = "<<res+eps<<endl;
	fout2<<res<<" ";
	res=runge (res, res2);
	cout<<"Pogreshnost po pravilu Runge: "<<res<<endl;
	fout2<<res;
	fout2.close();
	
	res = simps(a,A,n);
	res2 = simps(a,A,2*n);
	cout<<"\n3) Po formule Simpsona:\n\t\tI = "<<res+eps<<endl;
	fout3<<res<<" ";
	res=runge (res, res2);
	cout<<"Pogreshnost po pravilu Runge: "<<res<<endl;
	fout3<<res;
	fout3.close();
	cout<<endl;
	
	return 0;	
	}
