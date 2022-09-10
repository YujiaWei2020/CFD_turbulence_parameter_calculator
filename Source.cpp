//turbulence parameters calculation//
/*
1. Adding more turbulence model
2. Upload to git
3. Upgrate to HTML, web associate calculator
*/

#include <iostream>
#include <fstream>
using namespace std;


class turbulence
{
public:
	double L, V, rey,I,k,l,w,sigma,Vt;
	void calculator()
	{
		cout << "Enter characteristic length: ";
		cin >> L;
		cout << "Enter inflow velocity: ";
		cin >> V;
		//reynolds number
		rey = density * L * V / dyvis;
		//I:turbulence intensity
		I = 0.16 * pow(rey, -0.125);
		//k:turbulent kinetic energy
		k = 1.5 * (pow(V * I, 2));
		//sigma:height of the first adjacent layer
		sigma = L / (pow(rey, 0.5));
		//l:turbulence length scale
		l = 0.4 * sigma;
		//w:turbulence specific dissipation rate
		w = pow(k, 0.5) / (pow(Cu, 0.25) * l);
		//Vt: turbulent kinetic eddy viscosity
		Vt = pow(1.5, 0.5) * V * I * l;

	}
	void title()
	{
		cout << " k-omega SST turbulence model parameter calculation v1.0 " << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	void write();
	void coutt() 
	{
		cout << "reynolds number: Reynolds " << rey << endl;
		cout << "I " << I << endl;
		cout << "turbulent kinetic energy: k " << k << endl;
		cout << "turbulence specific dissipation rates: w " << w << endl;;
		cout << "turbulent kinetic eddy viscosity: nut " << Vt << endl;
	}

private:

	double density = 998;
	double dyvis = 0.001;
	double Cu = 0.09;  //model coefficient
};

void turbulence::write()
{
	ofstream myfile("turbulence.txt");
	if (myfile.is_open())
	{
		myfile << "reynolds number: Reynolds " << rey << endl;
		myfile << "I " << I << endl;
		myfile << "turbulent kinetic energy: k " << k << endl;
		myfile << "turbulence specific dissipation rates: w " << w << endl;;
		myfile << "turbulent kinetic eddy viscosity: nut " << Vt << endl;


		myfile.close();
	}
	else cout << "Unable to open file";
}
int main()
{
	turbulence tur1;
	tur1.title();
	tur1.calculator();
	tur1.write();
	tur1.coutt();

	return 0;
}