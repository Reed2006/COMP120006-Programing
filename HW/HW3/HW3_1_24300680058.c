 //欧洲使用13位的欧洲商品编码(European Article Number, EAN), 每个EAN码的最后一位是校验位.
// 计算校验位的方法为: 首先把第2、4、6、8、10、12位的数字相加; 然后把第1、3、5、7、9、11位的数字相加; 
// 接着把第一次加法的结果乘以3, 再和第二次加法的结果相加; 随后, 再把上述结果减去1; 相减后的结果除以10取余数; 
// 最后用9减去余数得到的就是校验位. 编写程序, 输入一个13位的EAN, 判断校验位是否有效.
//Tip. 13位整数已经超出int / long的范围, 所以不能用一个int / long型变量保存EAN码.本课程未学习long long int类型, 所以也不要使用该类型.
#include <stdio.h>

int main()
{
	int e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13; // 定义13个整型变量保存EAN码的每一位
	printf("Enter a 13-digit EAN: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12, &e13); // 输入EAN码

	int sum1 = e2 + e4 + e6 + e8 + e10 + e12; // 计算第一次加法
	int sum2 = e1 + e3 + e5 + e7 + e9 + e11; // 计算第二次加法
	int sum3 = sum1 * 3 + sum2; // 计算第三次加法
	int check_digit = 9 - (sum3 - 1) % 10;// 计算校验位

	if (check_digit == e13)//判断是否校验位是否与校验码相等 
		printf("VALID");
	else
		printf("INVALID");

	return 0;
	
}

