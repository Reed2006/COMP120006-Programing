#include <stdio.h>  
#define N 100  

int main() 
{  
    char ch;  
    int a[N], count = 0, flag = 1; // flag ���ڱ���Ƿ��ҵ��������  
    int j, k, m, pos; // j, k, m, pos ���ں�����ѭ��  

    printf("Enter an integer n: ");  
    
    // ��λ��ȡ����  
    while ((ch = getchar()) != '\n') 
	{  
            a[count] = ch - '0';  
            count++;  
    }  
 

    // ������һ�����������  (�Ӻ���ǰ�ң��ҵ����շ塱�� 
    for (j = count - 1; j > 0; j--)
	 {  
        if (a[j] > a[j - 1]) 
		{  
            // �����ܹ��� a[j - 1] ����������  
            pos = count - 1; // �ҵ��Ӻ���ǰ��һ������ a[j - 1] ��Ԫ��  
            while (a[pos] <= a[j - 1] && pos > 0)  
                pos--;   

            // ����  
            int temp = a[pos];  
            a[pos] = a[j - 1];  
            a[j - 1] = temp;  

            // ��ת j ֮��Ĳ���  
            for (m = 0; m < (count - j) / 2; m++) {  
                int temp_2 = a[j + m];  
                a[j + m] = a[count - 1 - m];  
                a[count - 1 - m] = temp_2;  
            }  

            flag = 0; // �ҵ���һ���������  
            break;  
        }  
    }  

    // ���� flag ������  
    if (flag) 
        printf("No larger smallest integers!\n");  
    else {  
        printf("The larger smallest integer: ");  
        for (k = 0; k < count; k++)  
            printf("%d", a[k]);  // ��˳�����     
        printf("\n");  
    }  

    return 0;  
}
