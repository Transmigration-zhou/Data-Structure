#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//ѧ����Ϣ�Ķ���
typedef struct {
    char no[8];   //8λѧ��
    char name[20]; //����
    int price;     //�ɼ�
}Student;

//˳���Ķ���
typedef  struct {
	Student *elem;     //ָ������Ԫ�صĻ���ַ
	int length;       //���Ա�ĵ�ǰ����                                                           
}SqList;

//��ʼ���� 
void start(){
	puts("1. ����ָ��ѧ���������������ѧ����Ϣ ");  
    puts("2. �����ʾѧ����������ѧ���������Ϣ");  
    puts("3. �����������в��ң����ش�ѧ����ѧ�źͳɼ�");  
    puts("4. ����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ���");   
    puts("5. ����һ��ѧ����Ϣ�����뵽����ָ����λ��");  
    puts("6. ɾ��ָ��λ�õ�ѧ����¼");  
    puts("7. ͳ�Ʊ���ѧ������");  
    puts("0. �˳�");
}

//��ʼ��
void InitList(SqList &L){
	L.elem=(Student*)malloc(MAXSIZE*sizeof(Student));
    L.length=0;
}

//�ж�ѧ���Ƿ���ͬ 
bool check_same(SqList &L,char* _no){
	for(int i=0;i<L.length;i++){
		if(!strcmp(L.elem[i].no,_no)) return false;
	}
	return true;
}

//�жϳɼ��Ƿ����Ҫ��
bool check_mark(int price){
	if(price<0) return false;
	if(price>100) return false;
	return true; 
} 

//����ָ��ѧ���������������ѧ����Ϣ 
void input(SqList &L){
	int n;
	printf("����Ҫ����ѧ���ĸ���:");
	scanf("%d",&n);
	if(n+L.length>MAXSIZE){
		printf("����ѧ���ĸ�������\n");
		return;
	}
	for(int i=0;i<n;i++){
		printf("����ѧ����ѧ��:");
		scanf("%s",L.elem[L.length].no);
		printf("����ѧ��������:");
		scanf("%s",L.elem[L.length].name);
		printf("����ѧ���ĳɼ�:");
		scanf("%d",&L.elem[L.length].price);
		L.length++;
		
	}
	printf("����ɹ�\n");
}

//�����ʾѧ����������ѧ���������Ϣ 
void output(SqList &L){
	if(!L.length) {
		printf("ѧ����Ϊ��\n");
		return;
	}
	for(int i=0;i<L.length;i++){
		printf("ѧ��:%s\t\t����:%s\t\t�ɼ�:%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
	}
} 

//�����������в��ң����ش�ѧ����ѧ�źͳɼ�
void search(SqList &L){
	char find_name[20];
	printf("�����ͬѧ������:");
	scanf("%s",find_name);
	for(int i=0;i<L.length;i++){
		if(!strcmp(find_name,L.elem[i].name)){
			printf("ѧ��:%s\t\t�ɼ�:%d\n",L.elem[i].no,L.elem[i].price);
			return;
		}
	}
	printf("���Ҳ�����ͬѧ\n");
}

//����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ���
void print(SqList &L){
	int id;
	printf("����Ҫ���ҵ�λ��:");
	scanf("%d",&id);
	if(id>=L.length){
		printf("��λ�ò�����\n");
		return;
	}
	printf("ѧ��:%s\t\t����:%s\t\t�ɼ�:%d\n",L.elem[id].no,L.elem[id].name,L.elem[id].price);
}

//����һ��ѧ����Ϣ�����뵽����ָ����λ��
void ListInsert(SqList &L){
	if(L.length==MAXSIZE){
		printf("ѧ��������\n");
		return;
	}
	int i;
	printf("����Ҫ�����λ��:");
	scanf("%d",&i);
	if(i>=L.length+1){
		printf("��λ�ò�����\n");
		return;
	}
	char _no[8];   //8λѧ��
    char _name[20]; //����
    int _price;     //�ɼ�
	printf("����Ҫ����ѧ����ѧ��:");
	scanf("%s",_no);
	if(!check_same(L,_no)){
		puts("��ѧ���ѱ�ʹ��");
		return;
	}
	printf("����Ҫ����ѧ��������:");
	scanf("%s",_name);
	printf("����Ҫ����ѧ���ĳɼ�:");
	scanf("%d",&_price);
	if(!check_mark(_price)){
		puts("�ɼ�������Ҫ��");
		return;
	}
	if(i<L.length){ //����ĩβ
		for(int k=L.length-1;k>=i;k--){
			L.elem[k+1]=L.elem[k];
		}
	}
	strcpy(L.elem[i].no,_no);
	strcpy(L.elem[i].name,_name);
	L.elem[i].price=_price;
	L.length++;
	printf("����ɹ�\n");
}

//ɾ��ָ��λ�õ�ѧ����¼
void ListDelete(SqList &L){
	if(!L.length){
		printf("ѧ����Ϊ��\n");
		return;
	}
	int i;
	printf("����Ҫɾ����λ��:");
	scanf("%d",&i);
	if(i>=L.length){
		printf("��λ�ò�����\n");
		return;
	}
	if(i<L.length){ //����ĩβ 
		for(int k=i;k<L.length-1;k++){
			L.elem[k]=L.elem[k+1];
		}
	}
	L.length--;
	printf("ɾ���ɹ�\n");
}

//ͳ�Ʊ���ѧ������
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
    	else if(op==7) printf("ѧ������:%d\n",ListLength(L));
    	else puts("��������ȷ����"); 
	}
	return 0; 
}

