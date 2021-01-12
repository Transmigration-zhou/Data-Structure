#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ѧ����Ϣ�Ķ���
typedef struct {
    char no[8];   //8λѧ��
    char name[20]; //����
    int price;     //�ɼ�
}Student;

//����Ķ��壺
typedef struct LNode{
    Student data;       //������
    struct LNode *next;   //ָ����
}LNode,*LinkList;   

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
void InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

//�ж�ѧ���Ƿ���ͬ 
bool check_same(LinkList &L,char* _no){
	LinkList p = L->next;
	while(p!=NULL){
		if(!strcmp(p->data.no, _no)) return false;
		p = p->next;
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
void input(LinkList &L){
	int n;
	printf("����Ҫ����ѧ���ĸ���:");
	scanf("%d",&n);
	LinkList p = L;
	while(p->next!=NULL){
		p=p->next;
	}
	for(int i=0;i<n;i++){
		LinkList q = (LinkList)malloc(sizeof(LNode));
		printf("����ѧ����ѧ��:");
		scanf("%s",q->data.no);
		printf("����ѧ��������:");
		scanf("%s",q->data.name);
		printf("����ѧ���ĳɼ�:");
		scanf("%d",&q->data.price);
		q->next = p->next;
		p->next = q;
	}
	printf("����ɹ�\n");
}

//�����ʾѧ����������ѧ���������Ϣ 
void output(LinkList &L){
	if(L->next==NULL) {
		printf("ѧ����Ϊ��\n");
		return;
	}
	LinkList p = L->next;
	while(p!=NULL){
		printf("ѧ��:%s\t\t����:%s\t\t�ɼ�:%d\n",p->data.no,p->data.name,p->data.price);
		p = p->next;
	}
}

//�����������в��ң����ش�ѧ����ѧ�źͳɼ�
void search(LinkList &L){
	char find_name[20];
	printf("�����ͬѧ������:");
	scanf("%s",find_name);
	LinkList p = L;
	while(p!=NULL){
		if(!strcmp(find_name,p->data.name)){
			printf("ѧ��:%s\t\t�ɼ�:%d\n",p->data.no,p->data.price);
			return;
		}
		p = p->next;
	}
	printf("���Ҳ�����ͬѧ\n");
}

//����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ���
void print(LinkList &L){
	int id,j=0;
	LinkList p = L->next;
	printf("����Ҫ���ҵ�λ��:");
	scanf("%d",&id);
	while(p!=NULL&&j<id){
		p = p->next;
		j++;
	}
	if(p==NULL||j>id){
		printf("��λ�ò�����\n");
		return;
	}
	printf("ѧ��:%s\t\t����:%s\t\t�ɼ�:%d\n",p->data.no,p->data.name,p->data.price);
}

//����һ��ѧ����Ϣ�����뵽����ָ����λ��
void ListInsert(LinkList &L){
	int i,j=0;
	LinkList p = L;
	printf("����Ҫ�����λ��:");
	scanf("%d",&i);
	while(p!=NULL&&j<i){
		p = p->next;
		j++;
	}
	if(p==NULL||j>i){
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
	LinkList s=(LinkList)malloc(sizeof(LNode));
	strcpy(s->data.no,_no);
	strcpy(s->data.name,_name);
	s->data.price=_price;
	s->next = p->next;
	p->next = s;
	printf("����ɹ�\n");
}

//ɾ��ָ��λ�õ�ѧ����¼
void ListDelete(LinkList &L){
	int i,j=0;
	LinkList p = L;
	printf("����Ҫɾ����λ��:");
	scanf("%d",&i);
	while(p->next!=NULL&&j<i){
		p = p->next;
		j++;
	}
	if(p->next==NULL||j>i){
		printf("��λ�ò�����\n");
		return;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q);
	printf("ɾ���ɹ�\n");
}

//ͳ�Ʊ���ѧ������
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
    	else if(op==7) printf("ѧ������:%d\n",ListLength(L));
    	else puts("��������ȷ����"); 
	}
	return 0; 
}

