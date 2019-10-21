/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                       D E B U G G I N G  A I D E S
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "config.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                              M A C R O S
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define MAX(x,y)             ((x) <  (y)  ? (y)  : (x))
#define MIN(x,y)             ((x) >  (y)  ? (y)  : (x))
#define isNonPositive(x)     ((x) <= 0.e0 ?   1  : 0)
#define isPositive(x)        ((x) >  0.e0 ?   1 : 0)
#define isNegative(x)        ((x) <  0.e0 ?   1 : 0)
#define isGreaterThanOne(x)  ((x) >  1.e0 ?   1 : 0)
#define isZero(x)            ((x) == 0.e0 ?   1 : 0)
#define isOne(x)             ((x) == 1.e0 ?   1 : 0)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                         G L O B A L  C O N S T A N T S
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define ALPHA							0.01	/* SIGNIFICANCE LEVEL */
#define MAXNUMOFTEMPLATES				148		/* APERIODIC TEMPLATES: 148=>temp_length=9 */
#define NUMOFTESTS						19		/* MAX TESTS DEFINED  */
#define NUMOFGENERATORS					10		/* MAX PRNGs */
#define MAXFILESPERMITTEDFORPARTITION	148
#define	TEST_FREQUENCY					1		//	GM 1
#define	TEST_BLOCK_FREQUENCY			2		//	GM 2
#define	TEST_CUSUM						3		//	GM 11
#define	TEST_RUNS						4		//	GM 5
#define	TEST_LONGEST_RUN				5		//	GM 7
#define	TEST_RANK						6		//	GM 10
#define	TEST_FFT						7		//	GM 15
#define	TEST_NONPERIODIC				8		//	GM 
#define	TEST_OVERLAPPING				9		//	GM 
#define	TEST_UNIVERSAL					10		//	GM 14
#define	TEST_APEN						11		//	GM 12
#define	TEST_RND_EXCURSION				12		//	GM 
#define	TEST_RND_EXCURSION_VAR			13		//	GM 
#define	TEST_SERIAL						14		//	GM 4
#define	TEST_LINEARCOMPLEXITY			15		//	GM 13


#define TEST_POKERDETECT				16		//  GM 3
#define TEST_RUNSDISTRIBUTION			17		//  GM 6
#define TEST_BINARYDERIVATE				18		//  GM 8
#define TEST_SELFCORRELATION			19		//  GM 9


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                   G L O B A L   D A T A  S T R U C T U R E S
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef unsigned char	BitSequence;

typedef struct _testParameters {
	int		n;
	int		blockFrequencyBlockLength;
	int		nonOverlappingTemplateBlockLength;
	int		overlappingTemplateBlockLength;
	int		serialBlockLength;
	int		linearComplexitySequenceLength;
	int		approximateEntropyBlockLength;
	int		numOfBitStreams;
	int		pokerDetectMValue;
	int		binaryDerivateKValue;
	int		selfCorrelationDValue;
} TP;
