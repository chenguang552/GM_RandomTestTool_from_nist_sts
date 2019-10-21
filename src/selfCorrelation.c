#include <math.h>
#include <stdio.h>
#include "../include/stat_fncs.h"
// #include "../include/erf.h"
#include "../include/externs.h"


double nist_erf(double x) {
	// constants
	double t, y;
	double a1 =  0.254829592;
	double a2 = -0.284496736;     
	double a3 =  1.421413741;     
	double a4 = -1.453152027;     
	double a5 =  1.061405429;    
	double p  =  0.3275911;      
	// Save the sign of x     
	int sign = 1;     
	if (x < 0)         
		sign = -1;     
	x = fabs(x);      
	// A&S formula 7.1.26     

	t = 1.0/(1.0 + p*x);     
	y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);      
	return sign*y; 
}

double nist_erfc(double x)
{
	double t, z, ans, result;
	z = fabs(x);
	t = 1.0 / (1.0 + 0.5 * z);

	ans=t*exp(-z*z-1.26551223+t*(1.00002368+t*(0.37409196+t*(0.09678418+
		t*(-0.18628806+t*(0.27886807+t*(-1.13520398+t*(1.48851587+
		t*(-0.82215223+t*0.17087277)))))))));

	if (x >= 0.0) {
		result = ans;
	} else {
		result = 2.0 - ans;
	}
	return result;
}


int SelfCorrelation(int d, int n)
{
    int i = 0;
    int n_d = n - d;
    int Ad = 0;
    double V = 0.0, p_value = 0.0, sqrt2 = 1.41421356237309504880;

    for (i = 0; i < n_d - 1; ++i) {
        Ad += (epsilon[i] ^ epsilon[i + d]);
    }

    V = 2 * ((double)Ad - ((double)n_d / 2)) / sqrt(n_d);

    p_value = nist_erfc(fabs(V) / sqrt2);


	fprintf(stats[TEST_SELFCORRELATION], "\t\t\t      SELFCORRELATION TEST\n");
	fprintf(stats[TEST_SELFCORRELATION], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_SELFCORRELATION], "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(stats[TEST_SELFCORRELATION], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_SELFCORRELATION], "\t\t(a) d value = %d\n", d);
	fprintf(stats[TEST_SELFCORRELATION], "\t\t(b) n value = %d\n", n);
	fprintf(stats[TEST_SELFCORRELATION], "\t\t---------------------------------------------\n");

	fprintf(stats[TEST_SELFCORRELATION], "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value); fflush(stats[TEST_SELFCORRELATION]);
	fprintf(results[TEST_SELFCORRELATION], "%f\n", p_value); fflush(results[TEST_SELFCORRELATION]);

    if (p_value < ALPHA) {
        return 0;
    } else {
        return 1;
    }
}

