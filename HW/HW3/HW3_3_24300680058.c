#include <stdio.h>  
#include <math.h>  

int main() 
{  
    double x1, y1, x2, y2, x3, y3, a, b, c;  

    printf("Enter 3 couples of coordinates:");   
    scanf("(%lf,%lf) (%lf,%lf) (%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3);  
  
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));  // x1, y1 到 x2, y2  
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));  // x2, y2 到 x3, y3  
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));  // x3, y3 到 x1, y1  

    if (a + b > c && a + c > b && b + c > a && (y3 - y1) * (x2 - x1) != (x3 - x1) * (y2 - y1)) // 判断是否可以形成三角形,添加共线性检验  
	{  // 判断三角形类型          
        if ((fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6 )) //判断边相不相等 
        {
        	if (fabs(a - b) < 1e-6 && fabs(a - c) < 1e-6)
        		printf("Equilateral triangle.\n");//判断是否等边 
        	else if (fabs(a * a - (b * b + c * c)) < 1e-6 ||   
                fabs(b * b - (a * a + c * c)) < 1e-6 ||   
                fabs(c * c - (a * a + b * b)) < 1e-6) 
                printf("Isosceles right triangle.\n");//判断是否等腰直角 
            else 
            	printf("Isosceles triangle.\n");//鉴别为普通的等腰三角形
		}//等腰组条件判断结束，进入直角判断 
        else if (fabs(a * a - (b * b + c * c)) < 1e-6 ||   
                fabs(b * b - (a * a + c * c)) < 1e-6 ||   
                fabs(c * c - (a * a + b * b)) < 1e-6) 
                printf("Right triangle.\n");  //判断是否是普通的直角三角形 
		else 
			printf("Triangle.\n");    //判断普通三角形
    } 
	else  
        printf("Can not make a triangle.\n");  //不能组成一个三角形 
 
 	return 0;  
 	
}
