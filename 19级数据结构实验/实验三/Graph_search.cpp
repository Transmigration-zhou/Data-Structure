#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef struct{ 
	char name[100];
	char info[10000];
}VertexType; //����ṹ
typedef struct{ 
	VertexType vexs[10];
	int arcs[100][100];//�ڽӾ���
	int vexnum,arcnum;//����������ߵĸ��� 
}MGraph; //ͼ�ṹ

int dis[100],pre[100];
bool vis[100];

void start(){
	puts("******************��ӭ�����㽭�Ƽ�ѧԺ!******************");
	printf("\t\t%s\n","1.��ѯ������Ϣ");
	printf("\t\t%s\n","2.��·��ѯ");
	printf("\t\t%s\n","3.����һ�����㼫�������Ϣ");
	printf("\t\t%s\n","4.�޸�һ������������Ϣ");
	printf("\t\t%s\n","5.����һ���µ�·��");
	printf("\t\t%s\n","6.�˳�");
}

void loading(){
	puts("*********************���У԰����ϵͳ********************");
	puts("��ѡ����Ҫ�ķ��񣺣�1-6��"); 
}

int serach_id(MGraph &G,char* place){
	for(int i=0;i<G.vexnum;i++){
		if(!strcmp(G.vexs[i].name,place)) return i;
	}
	return -1;
}

void CreateMGraph(MGraph &G){
	cin>>G.vexnum>>G.arcnum;
	for(int i=1;i<=G.vexnum;i++){
		cin>>G.vexs[i].name>>G.vexs[i].info;
	}
	for(int i=1;i<=G.vexnum;i++){
		for(int j=1;j<=G.vexnum;j++){
			G.arcs[i][j]=INF;
		}
	}
	for(int i=1;i<=G.arcnum;i++){
		char placeu[100],placev[100];
		int u,v,w;
		scanf("%s%s%d",placeu,placev,&w);
		u=serach_id(G,placeu),v=serach_id(G,placev);
		if(~u&&~v) G.arcs[u][v]=G.arcs[v][u]=w;
	}
}

void Dijkstra(MGraph &G,int start){
	memset(dis,INF,sizeof dis);
    memset(vis,false,sizeof vis);
    memset(pre,-1,sizeof pre);
    dis[start]=0;
    for(int i=1;i<=G.vexnum;i++){
    	int u=-1;
    	for(int j=1;j<=G.vexnum;j++){
    		if(!vis[j]&&(u==-1||dis[u]>dis[j])) u=j;
		}
		vis[u]=true;
		for(int v=1;v<=G.vexnum;v++){
			if(G.arcs[u][v]!=INF&&dis[u]+G.arcs[u][v]<dis[v]){
				dis[v]=dis[u]+G.arcs[u][v];
				pre[v]=u;
			}
		}
	}
}

int main(){
	freopen("graph.txt","r",stdin);
	MGraph G;
	CreateMGraph(G);
	freopen("CON","r",stdin);
	start();
	int op;
	loading();
	while(cin>>op){
		if(op==1){
			puts("��У�����У�");
			for(int i=1;i<=G.vexnum;i++){
				cout<<"\t\t"<<i<<"."<<G.vexs[i].name<<"\n";
			}
			puts("��ѡ����Ҫ��ѯ�ľ��㣺<1-8>");
			int id;cin>>id;
			cout<<G.vexs[id].name<<" "<<G.vexs[id].info<<"\n";
		}
		else if(op==2){
			puts("��У�����У�");
			for(int i=1;i<=G.vexnum;i++){
				cout<<"\t\t"<<i<<"."<<G.vexs[i].name<<"\n";
			}
			int start,end;
			puts("����������λ�ã�<1-8>");
			while(cin>>start){
				if(start>=1&&start<=8) break;
				puts("����������"); 
			}
			puts("����������Ŀ�ĵأ�<1-8>");
			while(cin>>end){
				if(end>=1&&end<=8) break;
				puts("����������"); 
			}
			Dijkstra(G,start);
			cout<<"·���ǣ�";
			for(int t=end;t!=start;t=pre[t]) cout<<G.vexs[t].name<<"<-";
			cout<<G.vexs[start].name<<"\n";
			cout<<"��̾����ǣ�"<<dis[end]<<"\n"; 
		}
		else if(op==3){
			//����һ�����㼫�������Ϣ
			
		}
		else if(op==4){
			//�޸�һ������������Ϣ
		}
		else if(op==5){
			//����һ���µ�·��
		}
		else if(op==6) exit(0);
		else puts("��������ȷ������"); 
		puts("");
		loading();
	}
	
	
	return 0;
} 



