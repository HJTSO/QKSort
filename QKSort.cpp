#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define MAXNUM 200

typedef struct
{
	char name[MAX];
	int ms, en, cp, ave, schnum;
}student;

typedef struct
{
	int key;
	student stu;
}rectype;
rectype R[MAXNUM];

int PARTITION( rectype R[], int l, int h ) //返回划分后被定位的基准记录的位置 
{
	int i, j;
	rectype temp;
	
	i = l; 
	j = h; 
	temp = R[i]; //初始化， temp为基准 
	
	do
	{
		while((R[j].key >= temp.key ) && (i < j))
			j--; //从右向左扫描，查找第1个关键字小于temp.key的记录 
		if(i < j) 	R[i++] = R[j];  //交换R[i]和R[j]
		while((R[i].key <= temp.key ) && (i < j))
			i++; //从左向右扫描，查找第1个关键字大于temp.key的记录 
		if(i < j) 	R[j--] = R[i];  //交换R[i]和R[j]  
	}while( i != j );
	
	R[i] = temp;  //基准temp已被最后定位 
	
	return i;
} //PARTITION

void QUICKSORT( rectype R[], int s1, int t1 )  //对R[s1]到R[t1]快排 
{
	int i;
	if( s1 < t1 )  // 只有一个记录或无记录时无须排序 
	{
		i = PARTITION( R, s1, t1 );  //对R[s1]到R[t1]做划分 
		QUICKSORT( R, s1, i - 1 );   //递归处理左区间 
		QUICKSORT( R, i + 1, t1 );   //递归处理右区间
	}
} //QUICKSORT

int START()
{
	int i, n;
	
	printf("请输入学生人数：");
	scanf("%d", &n );
	printf("\n");
	printf("请分别输入%d个人的号码、姓名，数学、英语、计算机科目的成绩:\n", n );
	for( i = 0; i < n; i++ )
	{
		scanf("%d%s%d%d%d", &R[i].stu.schnum, R[i].stu.name, &R[i].stu.ms, &R[i].stu.en, &R[i].stu.cp );
		R[i].stu.ave = ( R[i].stu.ms + R[i].stu.en + R[i].stu.cp ) / 3;
		R[i].key = R[i].stu.ave;
	}
	
	return i;
} //START

void OUTPUT( int n )
{
	int i;
	
	printf("\n排列后的结果是：\n\n");
	printf("     号码     姓名    高等数学   计算机    英语    平均分 \n");
	for( i = 0; i < n; i++ )
		printf( "%9d%9s%9d%9d%9d%9d\n", R[i].stu.schnum, R[i].stu.name, R[i].stu.ms, R[i].stu.en, R[i].stu.cp, R[i].stu.ave );	
	
} //OUTPUT

int main()
{
	int i, n;
	
	n = START();
	QUICKSORT( R, 0, n - 1 );
	OUTPUT( n );
	printf("\n");
	return 0;
}  //main 
