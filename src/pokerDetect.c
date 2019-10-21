#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/externs.h"
#include "../include/cephes.h"

typedef struct _PokerNi {
    unsigned int flag;
    unsigned int count;
} PokerNi;

unsigned char toByte(BitSequence *subEpsilon, int M)
{
    int i = 0;
    unsigned char result = 0;
    for (i = 0; i < M; ++i) {
        result |= (subEpsilon[i] << (M - i - 1));
    }
    return result;
}

int findIndex(PokerNi *tab, int tabSize, unsigned int flag)
{
    int i = 0;
    for (i = 0; i < tabSize; ++i) {
        if (tab[i].flag == flag) {
            return i;
        }
    }
    return -1;
}

int PokerDetect(int M, int n)
{
    int ret = 0;
    int i = 0, j = 0, N = n / M, index = 0, c = 0;
    int maxElements = (int) pow(2, M);
    double p_value = 0.0, sum_ni = 0.0, mp = 0.0, V = 0.0;
    unsigned int flag = 0;
    PokerNi *tab = NULL;

    if (M > 8) {
        return 0;
    }

    tab = (PokerNi *)calloc(sizeof(PokerNi), maxElements);
    if (NULL == tab) {
        return 0;
    }
    for (i = 0; i < maxElements; ++i) {
        tab[i].flag = (unsigned int) i;
        tab[i].count = 0;
    }

    for (i = 0, j = 0; j < N; ++j, i += M) {
        flag = toByte(epsilon + i, M);
        index = findIndex(tab, maxElements, flag);
        if (-1 == index) {
            goto end;
        }
        tab[index].count += 1;
    }

    for (i = 0; i < maxElements; ++i) {
        sum_ni += pow(tab[i].count, 2);
    }
    mp = (double)maxElements / N;
    V = mp * sum_ni - N;

    p_value = cephes_igamc((double)(maxElements - 1) / 2, V / 2);
    if (p_value < ALPHA) {
        goto end;
    }

    ret = 1;

    end:

    fprintf(stats[TEST_POKERDETECT], "\t\t\t      POKERDETECT TEST\n");
	fprintf(stats[TEST_POKERDETECT], "\t\t---------------------------------------------\n");
	fprintf(stats[TEST_POKERDETECT], "\t\tCOMPUTATIONAL INFORMATION:\n");
	fprintf(stats[TEST_POKERDETECT], "\t\t---------------------------------------------\n");
    
	fprintf(stats[TEST_POKERDETECT], "\t\t(a) M value = %d\n", M);
	fprintf(stats[TEST_POKERDETECT], "\t\t(b) n value = %d\n", n);
	fprintf(stats[TEST_POKERDETECT], "\t\t---------------------------------------------\n");

	fprintf(stats[TEST_POKERDETECT], "%s\t\tp_value = %f\n\n", p_value < ALPHA ? "FAILURE" : "SUCCESS", p_value); fflush(stats[TEST_POKERDETECT]);
	fprintf(results[TEST_POKERDETECT], "%f\n", p_value); fflush(results[TEST_POKERDETECT]);

    free(tab);
    return ret;
}