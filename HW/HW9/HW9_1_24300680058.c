#include <stdio.h>
#include <string.h>
#define N 1000

int main()
{
    char a[N];
    int i, k, pos, word_len = 0, max_len = 0, j, m, sum = 0, final_pos = 0, max_pos, count = 0, find_pos = 1;
    printf("Enter some text:\n");
    gets(a);
    printf("word list:\n");

    for (i = 0; a[i]; i++)
    {
        if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z'))
        {
            word_len++;
        }//增加单词长度 
        else if (a[i] == 32)//ascii32是空格 
        {
            if (word_len > 0)//前面是单词 
            {
                if (word_len > max_len)
                {
                    max_len = word_len;//更新最长长度 
                }
                word_len = 0;//清空单词长度 
            }
        }
        else//非字母、空格  
        {
            if (word_len > 0)
            {
                if (word_len > max_len)
                {
                    max_len = word_len;
                }
                word_len = 0;
            }
        }
    }

    if (word_len > 0)
    {
        if (word_len > max_len)
        {
            max_len = word_len;
        }
    }//最后检测 

printf("%d\n", max_len);

    for (i = 0; a[i]; i++)
    {
        if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z'))
        {
            final_pos = i;
            word_len++;
        }
        else if (a[i] == 32)
        {
            if (word_len > 0)
            {
                for (j = final_pos - word_len + 1; j <= final_pos; j++)
                {
                    printf("%c", a[j]);
                }
                for (m = word_len; m < max_len + 1; m++)
                {
                    printf(" ");
                }
                count = (count + 1) % 5;
                if (!count)
                {
                    printf("\n");
                }
                if ((word_len == max_len) && find_pos)
                {
                    max_len = word_len;
                    max_pos = final_pos;
                    find_pos = 0;
                }
                sum++;
                word_len = 0;
                final_pos = 0;
            }
        }
        else
        {
            if (word_len > 0)
            {
                for (j = final_pos - word_len + 1; j <= final_pos; j++)
                {
                    printf("%c", a[j]);//输出单词 
                }
                for (m = word_len; m < max_len + 1; m++)
                {
                    printf(" ");
                }
                count = (count + 1) % 5;
                if (!count)
                {
                    printf("\n");
                }
                if (word_len > max_len)
                {
                    max_len = word_len;
                    max_pos = final_pos;
                }
                sum++;
                word_len = 0;
                final_pos = 0;
            }
        }
    }

    if (word_len > 0)//最后\0前的检测 
    {
        for (k = final_pos - word_len + 1; k <= final_pos; k++)
        {
            printf("%c", a[k]);
        }
        printf("\n");
        if (find_pos)
        {
            max_len = word_len;
            max_pos = final_pos;
        }
        sum++;
    }

    printf("\nTotal number of words:%d\n", sum);
    printf("longest word:");
    for (j = max_pos - max_len; j <= max_pos; j++)
    {
        printf("%c", a[j]);
    }
    return 0;
}
