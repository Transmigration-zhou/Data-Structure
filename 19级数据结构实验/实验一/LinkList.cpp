#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//学生信息的定义
typedef struct {
    char no[8];   //8位学号
    char name[20]; //姓名
    int price;     //成绩
}Student;

//链表的定义：
typedef struct LNode{
    Student data;       //数据域
    struct LNode *next;   //指针域
}LNode,*LinkList;   

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
void InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

//判断学号是否相同 
bool check_same(LinkList &L,char* _no){
	LinkList p = L->next;
	while(p!=NULL){
		if(!strcmp(p->data.no, _no)) return false;
		p = p->next;
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
void input(LinkList &L){
	int n;
	printf("输入要导入学生的个数:");
	scanf("%d",&n);
	LinkList p = L;
	while(p->next!=NULL){
		p=p->next;
	}
	for(int i=0;i<n;i++){
		LinkList q = (LinkList)malloc(sizeof(LNode));
		printf("输入学生的学号:");
		scanf("%s",q->data.no);
		printf("输入学生的姓名:");
		scanf("%s",q->data.name);
		printf("输入学生的成绩:");
		scanf("%d",&q->data.price);
		q->next = p->next;
		p->next = q;
	}
	printf("导入成功\n");
}

//逐个显示学生表中所有学生的相关信息 
void output(LinkList &L){
	if(L->next==NULL) {
		printf("学生表为空\n");
		return;
	}
	LinkList p = L->next;
	while(p!=NULL){
		printf("学号:%s\t\t姓名:%s\t\t成绩:%d\n",p->data.no,p->data.name,p->data.price);
		p = p->next;
	}
}

//根据姓名进行查找，返回此学生的学号和成绩
void search(LinkList &L){
	char find_name[20];
	printf("输入该同学的姓名:");
	scanf("%s",find_name);
	LinkList p = L;
	while(p!=NULL){
		if(!strcmp(find_name,p->data.name)){
			printf("学号:%s\t\t成绩:%d\n",p->data.no,p->data.price);
			return;
		}
		p = p->next;
	}
	printf("查找不到此同学\n");
}

//根据指定的位置可返回相应的学生信息（学号，姓名，成绩）
void print(LinkList &L){
	int id,j=0;
	LinkList p = L->next;
	printf("输入要查找的位置:");
	scanf("%d",&id);
	while(p!=NULL&&j<id){
		p = p->next;
		j++;
	}
	if(p==NULL||j>id){
		printf("此位置不存在\n");
		return;
	}
	printf("学号:%s\t\t姓名:%s\t\t成绩:%d\n",p->data.no,p->data.name,p->data.price);
}

//给定一个学生信息，插入到表中指定的位置
void ListInsert(LinkList &L){
	int i,j=0;
	LinkList p = L;
	printf("输入要插入的位置:");
	scanf("%d",&i);
	while(p!=NULL&&j<i){
		p = p->next;
		j++;
	}
	if(p==NULL||j>i){
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
	LinkList s=(LinkList)malloc(sizeof(LNode));
	strcpy(s->data.no,_no);
	strcpy(s->data.name,_name);
	s->data.price=_price;
	s->next = p->next;
	p->next = s;
	printf("插入成功\n");
}

//删除指定位置的学生记录
void ListDelete(LinkList &L){
	int i,j=0;
	LinkList p = L;
	printf("输入要删除的位置:");
	scanf("%d",&i);
	while(p->next!=NULL&&j<i){
		p = p->next;
		j++;
	}
	if(p->next==NULL||j>i){
		printf("此位置不存在\n");
		return;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	printf("删除成功\n");
}

//统计表中学生个数
int ListLength(LinkList &L){
	int ans=0;
	LinkList p = L->next;
	while(p!=NULL){
		p=p->next;
		ans++;
	}
	return ans;
}

int main(){
#ifdef DEBUG
//    freopen("F:/laji/1.in", "r", stdin);
//	freopen("F:/laji/2.out", "w", stdout);
#endif
	start(); 
	LinkList L;
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

