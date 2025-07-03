#include <stdio.h>  
#include <string.h>  

#define N 100  

// Function to find the longest common substring between two strings  
char *commonstr(char *str1, char *str2, char *str3) 
{  
    static char common[N];  
    int maxLength = 0;      // Length of the longest common substring found  
    int len1 = strlen(str1);  
    
	int start, length;	
    // Iterate through all possible substrings in str1  
    for (start = 0; start < len1; start++)
	 {  
        for (length = 1; length <= len1 - start; length++)
		 {  
            char temp[N];  
            strncpy(temp, &str1[start], length);  
            temp[length] = '\0'; 

            if(strstr(str2, temp) && strstr(str3, temp))
            {
            	if(length > maxLength)
            	{
					maxLength = length;
            		strcpy(common, temp);
            	}
			}
		}
	}
	if (maxLength == 0)
        common[0] = '\0';  
  
	return common;
} 
int main() 
{  
    char a[N], b[N], c[N];  

    printf("Enter 3 strings (length < 100):\n");  

    gets(a);  
    gets(b);  
    gets(c);  
 
    char *finalCommon = commonstr(a, b, c);  

    // Êä³ö½á¹û  
    if (strlen(finalCommon) > 0)  
        printf("Longest common substring: %s\n", finalCommon);   
	else  
        printf("No common substring found.\n");   

    return 0;  
}
