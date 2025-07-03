//输入一个正整数(在int值范围内, 用一个int型变量保存), 逆序输出该正整数.
//要求: 循环计算整数的每一位数值并输出.注意 : 原数若以0结尾, 逆序时不输出0, 但原数中间包含的0原样输出.

#include<stdio.h>

int main()
{
    int num, digit;
    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int i = 0, count = 0; num > 0; i++)//引入计数器count 
    {
		int digit = num % 10;
		if (digit == 0 && i == count)//判断是不是最后一位为0，是的话仅仅去掉这一位，且若倒数多为为0，加以判断并去除，如1000留1 
		{
			num /= 10;
			count ++;//每符合新的num最后一位连续为0，需要用count来和i比较是否倒数几位都是零 
			continue;
		}
        printf("%d", digit);
        num /= 10;
    }
    
    return 0;
}

    

