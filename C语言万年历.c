#include <stdio.h>

int year,month,day,sum;
int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//用数组输入闰年和平年各月份的天数

char *weekday[7]={"一","二","三","四","五","六","日"};

void blank()
{
	printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
}

void title()
{
	printf("          万     年     历        \n"); 
}

int runorping(int year) //闰年和平年的天数不同，因此设置不同的返回值 
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

int difference(int year,int month,int day,int run[],int ping[]) //计算1900年1月1日星期一到输入日期的天数和 
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
