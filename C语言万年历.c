#include <stdio.h>

int year,month,day,sum;
int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//���������������ƽ����·ݵ�����

char *weekday[7]={"һ","��","��","��","��","��","��"};

void blank()
{
	printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
}

void title()
{
	printf("          ��     ��     ��        \n"); 
}

int runorping(int year) //�����ƽ���������ͬ��������ò�ͬ�ķ���ֵ 
{
	int a = year%4;
	int b = year%400;
	int c = year%100;
	
	if ((a==0 && c!=0) || b==0) {
		return 1;
	} else {
		return 0;
	}
}

int difference(int year,int month,int day,int run[],int ping[]) //����1900��1��1������һ���������ڵ������� 
{
	int i;
	int sum = 0;
	for (i=1900; i<year; i++) {
		int j = runorping(i);
		if (j==1) {
			sum+=366;
		} else {
			sum+=365;
		}
	}
	
	for (i=0; i<month-1; i++) {
		if (runorping(year)==1) {
			sum+=run[i];
		} else {
			sum+=ping[i];
		}
	}
	
	return sum;
}

void print(int sum,int year,int month)
{
	int tabnumber = sum%7;
	int enter = 7 - tabnumber;
	int i;
	for (i=0; i<tabnumber; i++) {
		printf("\t");
	}
	if (runorping(year)==1) {
		for (i=1; i<=run[month-1]; i++) {
			printf("%d\t",i);
			if (i==enter || (i-enter)%7==0) {
				printf("\n");
			}
		}
		
		printf("\n");
	}
	if (runorping(year)==0) {
		for (i=1; i<=run[month-1]; i++) {
			if (i != day) {
				printf("%d\t",i);
			} else if (i == day) {
				printf("@%d\t",i);
			}
			if (i==enter || (i-enter)%7==0) {
				printf("\n");
			}
		}
		
		printf("\n");
	}
}

int main()
{
	scanf("%d%d%d",&year,&month,&day);
	blank();
	title();
	blank();
	
	int i;
	for (i=0; i<7; i++) {
		printf("%s",weekday[i]);
		printf("\t");
	}
	printf("\n");
	int sum = difference(year,month,day,run,ping);
	print(sum,year,month);
	
	return 0;
}
