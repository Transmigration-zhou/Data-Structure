#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    puts("3. 根据姓名进行查找，返回此学生的学号和成绩");  
    puts("4. 根据指定的位置可返回相应的学生信息（学号，姓名，成绩）");   
    puts("5. 给定一个学生信息，插入到表中指定的位置");  
    puts("6. 删除指定位置的学生记录");  
    puts("7. 统计表中学生个数");  
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

//根据姓名进行查找，返回此学生的学号和成绩
void search(SqList &L){
	char find_name[20];
	printf("输入该同学的姓名:");
	scanf("%s",find_name);
	for(int i=0;i<L.length;i++){
		if(!strcmp(find_name,L.elem[i].name)){
			printf("学号:%s\t\t成绩:%d\n",L.elem[i].no,L.elem[i].price);
			return;
		}
	}
	printf("查找不到此同学\n");
}

//根据指定的位置可返回相应的学生信息（学号，姓名，成绩）
void print(SqList &L){
	int id;
	printf("输入要查找的位置:");
	scanf("%d",&id);
	if(id>=L.length){
		printf("此位置不存在\n");
		return;
	}
	printf("学号:%s\t\t姓名:%s\t\t成绩:%d\n",L.elem[id].no,L.elem[id].name,L.elem[id].price);
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

int main(){
	start();
    SqList L;
    InitList(L);
	int op;
    while(scanf("%d",&op),op){
    	if(op==1) input(L);
    	else if(op==2) output(L);
    	else if(op==3) search(L);
    	else if(op==4) print(L);
    	else if(op==5) ListInsert(L);
    	else if(op==6) ListDelete(L);
    	else if(op==7) printf("学生个数:%d\n",ListLength(L));
    	else puts("请输入正确的数"); 
	}
	return 0; 
}

