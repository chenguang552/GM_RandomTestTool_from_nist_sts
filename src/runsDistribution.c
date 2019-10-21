#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/externs.h"
#include "../include/cephes.h"

int RunsDistribution(int n)
{
    int ret = 0;
    int i = 0, j = 0, k = 0;
    unsigned char runFlag = 0x00;
    double p_value = 0.0, sum_bi = 0.0, sum_gi = 0.0, V = 0.0;
    double *bi = NULL, *gi = NULL, *e = NULL;
    double bit = 0.0, git = 0.0, et = 0.0;

    bi = (double *)calloc(sizeof(double), n);
    if (NULL == bi) {
        goto end;
    }
    gi = (double *)calloc(sizeof(double), n);
    if (NULL == gi) {
        goto end;
    }
    e = (double *)calloc(sizeof(double), n);
    if (NULL == e) {
        goto end;
    }

    for (i = 1; i <= n; ++i) {
        e[i - 1] = (double)(n - i + 3) / pow(2, i + 2);
        if (e[i - 1] >= 5) {
            k = i;
        }
    }

    runFlag = epsilon[0];
    j = 1;
    for (i = 1; i < n; ++i) {
        if (epsilon[i] != runFlag) {
            if (runFlag == 0x00) {
                gi[j - 1] += 1;
            } else if (runFlag == 0x01) {
                bi[j - 1] += 1;
            }
            runFlag = epsilon[i];
            j = 1;
        } else {
            ++j;
        }
    }

    for (i = 0; i < k; ++i) {
        bit = bi[i];
        et = e[i];
        sum_bi += pow(bit - et, 2) / et;
    }
    for (i = 0; i < k; ++i) {
        git = gi[i];
        et = e[i];
        sum_gi += pow(git - et, 2) / et;
    }
    V = sum_bi + sum_gi;

    p_value = cephes_igamc(k - 1, V / 2);
    if (p_value < ALPHA) {
        goto end;
    }

    ret = 1;

    end:


    fprintf(stats[TEST_RUNSDISTRIBUTION], "\t\t\t      RUNSDISTRIBUTION TEST\n");
	fprintf(stats[TEST_RUNSDISTRIBUTION], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_RUNSDISTRIBUTION], "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(stats[TEST_RUNSDISTRIBUTION], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_RUNSDISTRIBUTION], "\t\t(b) n value = %d\n", n);
	fprintf(stats[TEST_RUNSDISTRIBUTION], "\t\t---------------------------------------------\n");

	fprintf(stats[TEST_RUNSDISTRIBUTION], "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value); fflush(stats[TEST_RUNSDISTRIBUTION]);
	fprintf(results[TEST_RUNSDISTRIBUTION], "%f\n", p_value); fflush(results[TEST_RUNSDISTRIBUTION]);

    

    if (NULL != bi) {
        free(bi);
    }
    if (NULL != gi) {
        free(gi);
    }
    if (NULL != e) {
        free(e);
    }
    return ret;
}

