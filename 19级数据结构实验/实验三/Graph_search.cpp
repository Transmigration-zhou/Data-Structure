#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef struct{ 
	char name[100];
	char info[10000];
}VertexType; //顶点结构
typedef struct{ 
	VertexType vexs[10];
	int arcs[100][100];//邻接矩阵
	int vexnum,arcnum;//顶点个数，边的个数 
}MGraph; //图结构

int dis[100],pre[100];
bool vis[100];

void start(){
	puts("******************欢迎来到浙江科技学院!******************");
	printf("\t\t%s\n","1.查询景点信息");
	printf("\t\t%s\n","2.问路查询");
	printf("\t\t%s\n","3.增加一个景点极其相关信息");
	printf("\t\t%s\n","4.修改一个景点的相关信息");
	printf("\t\t%s\n","5.增加一条新的路径");
	printf("\t\t%s\n","6.退出");
}

void loading(){
	puts("*********************浙科校园导游系统********************");
	puts("请选择需要的服务：（1-6）"); 
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
			puts("本校景点有：");
			for(int i=1;i<=G.vexnum;i++){
				cout<<"\t\t"<<i<<"."<<G.vexs[i].name<<"\n";
			}
			puts("请选择您要查询的景点：<1-8>");
			int id;cin>>id;
			cout<<G.vexs[id].name<<" "<<G.vexs[id].info<<"\n";
		}
		else if(op==2){
			puts("本校景点有：");
			for(int i=1;i<=G.vexnum;i++){
				cout<<"\t\t"<<i<<"."<<G.vexs[i].name<<"\n";
			}
			int start,end;
			puts("请输入您的位置：<1-8>");
			while(cin>>start){
				if(start>=1&&start<=8) break;
				puts("请重新输入"); 
			}
			puts("请输入您的目的地：<1-8>");
			while(cin>>end){
				if(end>=1&&end<=8) break;
				puts("请重新输入"); 
			}
			Dijkstra(G,start);
			cout<<"路径是：";
			for(int t=end;t!=start;t=pre[t]) cout<<G.vexs[t].name<<"<-";
			cout<<G.vexs[start].name<<"\n";
			cout<<"最短距离是："<<dis[end]<<"\n"; 
		}
		else if(op==3){
			//增加一个景点极其相关信息
			
		}
		else if(op==4){
			//修改一个景点的相关信息
		}
		else if(op==5){
			//增加一条新的路径
		}
		else if(op==6) exit(0);
		else puts("请输入正确的数字"); 
		puts("");
		loading();
	}
	
	
	return 0;
} 



