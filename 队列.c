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
		//��ӡ���ײ������׳��� 
		printf("%d",q.date[q.head]);
		q.head++;
		
		//�Ƚ��¶��׵�����ӵ���β 
		q.date[q.tail] = q.date[q.head];
		q.tail++;
		//�ٽ����׳��� 
		q.head++;
	}
	
	return 0;
}
