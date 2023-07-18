//
//  main.cpp
//  credit risk
//
//  Using equity price to estimate default probabilities (hull chapter 24.6)

#include <iostream>
#include <string>
#include <cmath>
#include "mertonmodel.hpp"

using namespace std;

//define the parameters
double equity = 3;     //E0
double debt = 10;      //D
double rf_rate = 0.05; //risk free rate
double sigmaE = 0.8;   //equity volatility
double timeT = 1;	   //time

double value0 = equity * sigmaE + debt;  //Value of company’s assets today V0
double sigmaV = mertonmodel();			 //volatility of total asset sigmaV


int main() {
		
	cout<< "Value of asset is " << value0 <<endl;
	cout << "Asset volatility = " << sigmaV << endl;
	
	//black scholes formula for N(d1), N(d2)
	double numerator = log(value0 / debt) + (rf_rate + (sigmaV * sigmaV) / 2) * timeT;
	double denominator = sigmaV * sqrt(timeT);
	double d1value = numerator / denominator;
	double Nd1 = 0.5 * erfc(-d1value * M_SQRT1_2);
	double d2value = d1value - sigmaV * sqrt(timeT);
	double Nd2 = 0.5 * erfc(-d2value * M_SQRT1_2);
	cout << "N(d1) = " << Nd1 << ", N(d2) = " << Nd2 << endl;
	double Nnd2 = 0.5 * erfc(d2value * M_SQRT1_2);
	cout << "N(-d2) probability of default "<< Nnd2 * 100 <<"% " << endl;
	
	//market value of debt = value0 - equity
	double mktdebtv = value0 - equity;
	//present value of the promised payment on the debt is debt * e^-rt
	double pvdebtpayment = debt * exp(-rf_rate*timeT);
	//expected loss on the debt is (pvdebtpayment - mktdebtv)/pvdebtpayment
	double expectedloss = (pvdebtpayment - mktdebtv) / pvdebtpayment;
	//recovery rate = 1 - expected loss / probability of default
	double recoveryrate = 1 - (expectedloss / Nnd2);
	
	cout << "The expected loss on the debt is " << expectedloss*100<< "% of its no-default value"<<endl;
	cout << "The recovery rate is "<< recoveryrate*100<< "% of the debt's no-default value\n"<<endl;
	
	
	return 0;
}

	
	

