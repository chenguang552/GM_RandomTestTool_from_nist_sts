
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     S T A T I S T I C A L  T E S T  F U N C T I O N  P R O T O T Y P E S 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// void	Frequency(int n);
// void	BlockFrequency(int M, int n);
// void	CumulativeSums(int n);
// void	Runs(int n);
// void	LongestRunOfOnes(int n);
// void	Rank(int n);
// void	DiscreteFourierTransform(int n);
// void	NonOverlappingTemplateMatchings(int m, int n);
// void	OverlappingTemplateMatchings(int m, int n);
// void	Universal(int n);
// void	ApproximateEntropy(int m, int n);
// void	RandomExcursions(int n);
// void	RandomExcursionsVariant(int n);
// void	LinearComplexity(int M, int n);
// void	Serial(int m, int n);



// #include "defs.h"

// /**
//  *
//  * @param in
//  * @param inl
//  * @param out 外部预先分配缓冲区，缓冲区大小因最少为字节数的8倍
//  * @param outbufsize
//  * @return
//  */
// int BytesToBitSequence(unsigned char *in, int inl);

/**
 * 单比特频数检测
 * @param n
 * @return
 */
int Frequency(int n);

/**
 * 块内频数检测
 * @param M
 * @param n
 * @return
 */
int BlockFrequency(int M, int n);

/**
 * 累加和检测
 * @param n
 * @return
 */
int CumulativeSums(int n);

/**
 * 游程总数检测
 * @param n
 * @return
 */
int Runs(int n);

/**
 * 块内最大“1”游程检测
 * @param n
 * @return
 */
int LongestRunOfOnes(int n);

/**
 * 矩阵秩检测
 * @param n
 * @return
 */
int Rank(int n);

/**
 * 离散傅立叶检测
 * @param n
 * @return
 */
int DiscreteFourierTransform(int n);

/**
 * 非重叠模版匹配测试
 * @param m
 * @param n
 * @return
 */
int NonOverlappingTemplateMatchings(int m, int n);

/**
 * 重叠模版匹配测试
 * @param m
 * @param n
 * @return
 */
int OverlappingTemplateMatchings(int m, int n);

/**
 * 通用统计检测
 * @param n
 * @return
 */
int Universal(int n);

/**
 * 近似熵检测
 * @param m
 * @param n
 * @return
 */
int ApproximateEntropy(int m, int n);

/**
 * 自由游程测试
 * @param n
 * @return
 */
int RandomExcursions(int n);

/**
 * 自由变量测试
 * @param n
 * @return
 */
int RandomExcursionsVariant(int n);

/**
 * 线性复杂度检测
 * @param M
 * @param n
 * @return
 */
int LinearComplexity(int M, int n);

/**
 * 重叠子序列检测
 * @param m
 * @param n
 * @return
 */
int Serial(int m, int n);

/**
 * 二元推导检测
 * @param k
 * @param n
 * @param epsilon
 * @return
 */
int BinaryDerivate(int k, int n);

/**
 * 自相关测试
 * @param d
 * @param n
 * @param epsilon
 * @return
 */
int SelfCorrelation(int d, int n);

/**
 * 扑克检测
 * @param M
 * @param n
 * @param epsilon
 * @return
 */
int PokerDetect(int M, int n);

/**
 * 游程分布检测
 * @param n
 * @param epsilon
 * @return
 */
int RunsDistribution(int n);
