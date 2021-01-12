#include <bits/stdc++.h>
using namespace std;

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
    puts("3. ����һ��ѧ����Ϣ�����뵽����ָ����λ��");  
    puts("4. ɾ��ָ��λ�õ�ѧ����¼");  
    puts("5. ͳ�Ʊ���ѧ������"); 
	puts("6. ͳ�Ʊ���ѧ����ֱ�Ӳ�����������۰����������������������"); 
	puts("7. ���ÿ���������ѧ�Ž�������"); 
    puts("8. �������������۰���ң�Ҫ��ʹ�õݹ��㷨ʵ�֣��ɹ����ش�ѧ����ѧ�źͳɼ�");  
    puts("9. ����ѧ�Ž����۰���ң�Ҫ��ʹ�÷ǵݹ��㷨ʵ�֣��ɹ����ش�ѧ���������ͳɼ�");  
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

//ͳ�Ʊ���ѧ����ֱ�Ӳ�����������۰����������������������
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
	puts("����������ɹ�"); 
}

//���ÿ���������ѧ�Ž�������
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
	puts("��ѧ������ɹ�"); 
}

//�������������۰���ң�Ҫ��ʹ�õݹ��㷨ʵ�֣��ɹ����ش�ѧ����ѧ�źͳɼ�
void Binary_Search_name(SqList &L,char* find_name,int l,int r){
	if(l<=r){
		int mid=(l+r)>>1;
		if(strcmp(find_name,L.elem[mid].name)<0) return Binary_Search_name(L,find_name,l,mid-1);
		else if(strcmp(find_name,L.elem[mid].name)>0) return Binary_Search_name(L,find_name,mid+1,r);
		else{
			printf("ѧ��:%s\t\t�ɼ�:%d\n",L.elem[mid].no,L.elem[mid].price);
			return;
		} 
	}
	printf("���Ҳ�����ͬѧ\n");
} 

//����ѧ�Ž����۰���ң�Ҫ��ʹ�÷ǵݹ��㷨ʵ�֣��ɹ����ش�ѧ���������ͳɼ�
void Binary_Search_no(SqList &L){
	char find_no[8];
	printf("�����ͬѧ��ѧ��:");
	scanf("%s",find_no);
	int l=0,r=L.length-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(strcmp(find_no,L.elem[mid].no)<0) r=mid-1;
		else if(strcmp(find_no,L.elem[mid].no)>0) l=mid+1;
		else{
			printf("����:%s\t\t�ɼ�:%d\n",L.elem[mid].name,L.elem[mid].price);
			return;
		} 
	}
	printf("���Ҳ�����ͬѧ\n");
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
    	else if(op==5) printf("ѧ������:%d\n",ListLength(L));
    	else if(op==6) InsertSort(L);
    	else if(op==7) QuickSort(L);
    	else if(op==8) {
    		char find_name[20];
			printf("�����ͬѧ������:");
			scanf("%s",find_name);
			Binary_Search_name(L,find_name,0,L.length-1);
		}
    	else if(op==9) Binary_Search_no(L);
    	else puts("��������ȷ����"); 
	}
	return 0; 
} 
