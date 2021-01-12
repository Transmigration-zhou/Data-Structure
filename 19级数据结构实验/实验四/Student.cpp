#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

//学生信息的定义
typedef struct {
    char no[8];   //8位学号
    char name[20]; //姓名
    int price;     //成绩
}Student;

//顺序表的定义
typedef  struct {
	Student *elem;     //指向数据元素的基地址
	int length;       //线性表的当前长度                                                           
}SqList;

//开始界面 
void start(){
	puts("1. 根据指定学生个数，逐个输入学生信息 ");  
    puts("2. 逐个显示学生表中所有学生的相关信息");  
    puts("3. 给定一个学生信息，插入到表中指定的位置");  
    puts("4. 删除指定位置的学生记录");  
    puts("5. 统计表中学生个数"); 
	puts("6. 统计表中学利用直接插入排序或者折半插入排序按照姓名进行排序"); 
	puts("7. 利用快速排序按照学号进行排序"); 
    puts("8. 根据姓名进行折半查找，要求使用递归算法实现，成功返回此学生的学号和成绩");  
    puts("9. 根据学号进行折半查找，要求使用非递归算法实现，成功返回此学生的姓名和成绩");  
    puts("0. 退出");
}

//初始化
void InitList(SqList &L){
	L.elem=(Student*)malloc(MAXSIZE*sizeof(Student));
    L.length=0;
}

//判断学号是否相同 
bool check_same(SqList &L,char* _no){
	for(int i=0;i<L.length;i++){
		if(!strcmp(L.elem[i].no,_no)) return false;
	}
	return true;
}

//判断成绩是否符合要求
bool check_mark(int price){
	if(price<0) return false;
	if(price>100) return false;
	return true; 
} 

//根据指定学生个数，逐个输入学生信息 
void input(SqList &L){
	int n;
	printf("输入要导入学生的个数:");
	scanf("%d",&n);
	if(n+L.length>MAXSIZE){
		printf("导入学生的个数过多\n");
		return;
	}
	for(int i=0;i<n;i++){
		printf("输入学生的学号:");
		scanf("%s",L.elem[L.length].no);
		printf("输入学生的姓名:");
		scanf("%s",L.elem[L.length].name);
		printf("输入学生的成绩:");
		scanf("%d",&L.elem[L.length].price);
		L.length++;
		
	}
	printf("导入成功\n");
}

//逐个显示学生表中所有学生的相关信息 
void output(SqList &L){
	if(!L.length) {
		printf("学生表为空\n");
		return;
	}
	for(int i=0;i<L.length;i++){
		printf("学号:%s\t\t姓名:%s\t\t成绩:%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
	}
} 

//给定一个学生信息，插入到表中指定的位置
void ListInsert(SqList &L){
	if(L.length==MAXSIZE){
		printf("学生表已满\n");
		return;
	}
	int i;
	printf("输入要插入的位置:");
	scanf("%d",&i);
	if(i>=L.length+1){
		printf("此位置不存在\n");
		return;
	}
	char _no[8];   //8位学号
    char _name[20]; //姓名
    int _price;     //成绩
	printf("输入要插入学生的学号:");
	scanf("%s",_no);
	if(!check_same(L,_no)){
		puts("该学号已被使用");
		return;
	}
	printf("输入要插入学生的姓名:");
	scanf("%s",_name);
	printf("输入要插入学生的成绩:");
	scanf("%d",&_price);
	if(!check_mark(_price)){
		puts("成绩不符合要求");
		return;
	}
	if(i<L.length){ //不在末尾
		for(int k=L.length-1;k>=i;k--){
			L.elem[k+1]=L.elem[k];
		}
	}
	strcpy(L.elem[i].no,_no);
	strcpy(L.elem[i].name,_name);
	L.elem[i].price=_price;
	L.length++;
	printf("插入成功\n");
}

//删除指定位置的学生记录
void ListDelete(SqList &L){
	if(!L.length){
		printf("学生表为空\n");
		return;
	}
	int i;
	printf("输入要删除的位置:");
	scanf("%d",&i);
	if(i>=L.length){
		printf("此位置不存在\n");
		return;
	}
	if(i<L.length){ //不在末尾 
		for(int k=i;k<L.length-1;k++){
			L.elem[k]=L.elem[k+1];
		}
	}
	L.length--;
	printf("删除成功\n");
}

//统计表中学生个数
int ListLength(SqList &L){
	return L.length;
}

//统计表中学利用直接插入排序或者折半插入排序按照姓名进行排序
void InsertSort(SqList &L){
	for(int i=1;i<L.length;i++){
		if(strcmp(L.elem[i].name,L.elem[i-1].name)<0){
			Student t=L.elem[i];
			int j;
			for(j=i-1;strcmp(L.elem[j].name,t.name)>0;j--){
				L.elem[j+1]=L.elem[j];
			}
			L.elem[j+1]=t;
		}
	}
	puts("按姓名排序成功"); 
}

//利用快速排序按照学号进行排序
int Partition(SqList &L,int l,int r){
	char p[8];
	strcpy(p,L.elem[l].no);
	while(l<r){
		while(l<r&&strcmp(L.elem[r].no,p)>=0) r--;
		swap(L.elem[l],L.elem[r]);
		while(l<r&&strcmp(L.elem[l].no,p)<=0) l++;
		swap(L.elem[r],L.elem[l]);
	}
	return l;
}

void QSort(SqList &L,int l,int r){
	if(l<r){
		int mid=Partition(L,l,r);
		QSort(L,l,mid-1);
		QSort(L,mid+1,r);
	} 
}

void QuickSort(SqList &L){
	QSort(L,0,L.length-1);
	puts("按学号排序成功"); 
}

//根据姓名进行折半查找，要求使用递归算法实现，成功返回此学生的学号和成绩
void Binary_Search_name(SqList &L,char* find_name,int l,int r){
	if(l<=r){
		int mid=(l+r)>>1;
		if(strcmp(find_name,L.elem[mid].name)<0) return Binary_Search_name(L,find_name,l,mid-1);
		else if(strcmp(find_name,L.elem[mid].name)>0) return Binary_Search_name(L,find_name,mid+1,r);
		else{
			printf("学号:%s\t\t成绩:%d\n",L.elem[mid].no,L.elem[mid].price);
			return;
		} 
	}
	printf("查找不到此同学\n");
} 

//根据学号进行折半查找，要求使用非递归算法实现，成功返回此学生的姓名和成绩
void Binary_Search_no(SqList &L){
	char find_no[8];
	printf("输入该同学的学号:");
	scanf("%s",find_no);
	int l=0,r=L.length-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(strcmp(find_no,L.elem[mid].no)<0) r=mid-1;
		else if(strcmp(find_no,L.elem[mid].no)>0) l=mid+1;
		else{
			printf("姓名:%s\t\t成绩:%d\n",L.elem[mid].name,L.elem[mid].price);
			return;
		} 
	}
	printf("查找不到此同学\n");
} 


int main(){
	start();
    SqList L;
    InitList(L);
	int op;
    while(scanf("%d",&op),op){
    	if(op==1) input(L);
    	else if(op==2) output(L);
    	else if(op==3) ListInsert(L);
    	else if(op==4) ListDelete(L);
    	else if(op==5) printf("学生个数:%d\n",ListLength(L));
    	else if(op==6) InsertSort(L);
    	else if(op==7) QuickSort(L);
    	else if(op==8) {
    		char find_name[20];
			printf("输入该同学的姓名:");
			scanf("%s",find_name);
			Binary_Search_name(L,find_name,0,L.length-1);
		}
    	else if(op==9) Binary_Search_no(L);
    	else puts("请输入正确的数"); 
	}
	return 0; 
} 
