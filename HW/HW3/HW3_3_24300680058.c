#include <stdio.h>  
#include <math.h>  

int main() 
{  
    double x1, y1, x2, y2, x3, y3, a, b, c;  

    printf("Enter 3 couples of coordinates:");   
    scanf("(%lf,%lf) (%lf,%lf) (%lf,%lf)", &x1, &y1, &x2, &y2, &x3, &y3);  
  
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));  // x1, y1 �� x2, y2  
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));  // x2, y2 �� x3, y3  
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));  // x3, y3 �� x1, y1  

    if (a + b > c && a + c > b && b + c > a && (y3 - y1) * (x2 - x1) != (x3 - x1) * (y2 - y1)) // �ж��Ƿ�����γ�������,��ӹ����Լ���  
	{  // �ж�����������          
        if ((fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6 )) //�жϱ��಻��� 
        {
        	if (fabs(a - b) < 1e-6 && fabs(a - c) < 1e-6)
        		printf("Equilateral triangle.\n");//�ж��Ƿ�ȱ� 
        	else if (fabs(a * a - (b * b + c * c)) < 1e-6 ||   
                fabs(b * b - (a * a + c * c)) < 1e-6 ||   
                fabs(c * c - (a * a + b * b)) < 1e-6) 
                printf("Isosceles right triangle.\n");//�ж��Ƿ����ֱ�� 
            else 
            	printf("Isosceles triangle.\n");//����Ϊ��ͨ�ĵ���������
		}//�����������жϽ���������ֱ���ж� 
        else if (fabs(a * a - (b * b + c * c)) < 1e-6 ||   
                fabs(b * b - (a * a + c * c)) < 1e-6 ||   
                fabs(c * c - (a * a + b * b)) < 1e-6) 
                printf("Right triangle.\n");  //�ж��Ƿ�����ͨ��ֱ�������� 
		else 
			printf("Triangle.\n");    //�ж���ͨ������
    } 
	else  
        printf("Can not make a triangle.\n");  //�������һ�������� 
 
 	return 0;  
 	
}
