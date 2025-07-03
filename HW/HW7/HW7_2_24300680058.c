#include <stdio.h>  
#define N 100  

int main() 
{  
    char ch;  
    int a[N], count = 0, flag = 1; // flag 用于标记是否找到更大的数  
    int j, k, m, pos; // j, k, m, pos 用于后续的循环  

    printf("Enter an integer n: ");  
    
    // 逐位读取数字  
    while ((ch = getchar()) != '\n') 
	{  
            a[count] = ch - '0';  
            count++;  
    }  
 

    // 查找下一个更大的排列  (从后往前找，找到“驼峰”） 
    for (j = count - 1; j > 0; j--)
	 {  
        if (a[j] > a[j - 1]) 
		{  
            // 查找能够与 a[j - 1] 交换的数字  
            pos = count - 1; // 找到从后往前第一个大于 a[j - 1] 的元素  
            while (a[pos] <= a[j - 1] && pos > 0)  
                pos--;   

            // 交换  
            int temp = a[pos];  
            a[pos] = a[j - 1];  
            a[j - 1] = temp;  

            // 反转 j 之后的部分  
            for (m = 0; m < (count - j) / 2; m++) {  
                int temp_2 = a[j + m];  
                a[j + m] = a[count - 1 - m];  
                a[count - 1 - m] = temp_2;  
            }  

            flag = 0; // 找到下一个更大的数  
            break;  
        }  
    }  

    // 根据 flag 输出结果  
    if (flag) 
        printf("No larger smallest integers!\n");  
    else {  
        printf("The larger smallest integer: ");  
        for (k = 0; k < count; k++)  
            printf("%d", a[k]);  // 按顺序输出     
        printf("\n");  
    }  

    return 0;  
}
