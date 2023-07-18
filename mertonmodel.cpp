//
//  mertonmodel.cpp
//  credit risk
//
//

#include "mertonmodel.hpp"
#include <cmath>
#include <iostream>
#include <string>
//#include "main.cpp"
using namespace std;

//call these values from main.cpp
extern double equity;
extern double sigmaE;
extern double value0;
extern double debt;
extern double rf_rate;
extern double timeT;

double mertonmodel() {
	double initialGuess = 1;  // Initial guess for sigmaV
	double tolerance = 1e-8;    // Tolerance for convergence
	int masigmaVIterations = 2000;   // Maximum number of iterations

	// Function to calculate the standard normal distribution (N)
	auto standardNormalDistribution = [](double sigmaV) {
		return 0.5 * (1 + erf(sigmaV / sqrt(2)));
	};
	
	
	// Function representing the equation sigmaV = E0*sigE / N([ln(value/debt) + (rf + sigmaV^2/2)] / sigmaV*sqrt(T)
	auto equation = [&](double sigmaV) {
		double numerator = log(value0/debt) + (rf_rate + sigmaV * sigmaV / 2);
		double denominator = sigmaV * sqrt(timeT);
		return sigmaV - (equity*sigmaE/(equity*sigmaE+debt)) / standardNormalDistribution(numerator / denominator);
	};

	// Function to calculate the derivative of the equation
	auto equationDerivative = [&](double sigmaV) {
		double numerator = log(value0/debt) + (rf_rate + sigmaV * sigmaV / 2);
		double denominator = sigmaV * sqrt(timeT);
		double derivative = (equity*sigmaE/(equity*sigmaE+debt)) * exp(-0.5 * numerator * numerator / (denominator * denominator));
		derivative = -numerator / (denominator * denominator * standardNormalDistribution(numerator / denominator));
		return 1 - derivative;
	};

	// Newton-Raphson method to approximate the solution
	double sigmaV = initialGuess;
	int iteration = 0;

	while (iteration < masigmaVIterations) {
		double f = equation(sigmaV);
		double fPrime = equationDerivative(sigmaV);
		double delta = f / fPrime;

		sigmaV -= delta;

		if (abs(delta) < tolerance)
			return sigmaV;

		iteration++;
	}

	return numeric_limits<double>::quiet_NaN();  // Return NaN if no solution is found within maxIterations
}
