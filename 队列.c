#include <stdio.h>
struct queue
{
	int date[100];
	int head;
	int tail;
};

int main()
{
	struct queue q;
	int i=1;
	q.head=1;
	q.tail=1;
	for (i=1; i<=9; i++) {
		scanf("%d",&q.date[q.tail]);
		q.tail++;
	}
	
	while (q.head < q.tail ) {
		//打印队首并将队首出列 
		printf("%d",q.date[q.head]);
		q.head++;
		
		//先将新队首的数添加到队尾 
		q.date[q.tail] = q.date[q.head];
		q.tail++;
		//再将队首出队 
		q.head++;
	}
	
	return 0;
}
