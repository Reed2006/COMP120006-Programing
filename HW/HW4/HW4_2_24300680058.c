//����һ��������(��intֵ��Χ��, ��һ��int�ͱ�������), ���������������.
//Ҫ��: ѭ������������ÿһλ��ֵ�����.ע�� : ԭ������0��β, ����ʱ�����0, ��ԭ���м������0ԭ�����.

#include<stdio.h>

int main()
{
    int num, digit;
    printf("Enter an integer: ");
    scanf("%d", &num);

    for (int i = 0, count = 0; num > 0; i++)//���������count 
    {
		int digit = num % 10;
		if (digit == 0 && i == count)//�ж��ǲ������һλΪ0���ǵĻ�����ȥ����һλ������������ΪΪ0�������жϲ�ȥ������1000��1 
		{
			num /= 10;
			count ++;//ÿ�����µ�num���һλ����Ϊ0����Ҫ��count����i�Ƚ��Ƿ�����λ������ 
			continue;
		}
        printf("%d", digit);
        num /= 10;
    }
    
    return 0;
}

    

