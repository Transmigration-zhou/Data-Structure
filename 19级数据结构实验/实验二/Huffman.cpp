#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
string str;
int cnt[30];

struct node {
	char c;
	int cnt;
};
vector<node> g;

typedef struct {
	int weight;
	int parent,lchild,rchild;
} HTNode,*HuffmanTree;

typedef char **HuffmanCode;

void Character_Statistics() {
	for(int i=0; i<str.length(); i++) {
		char c=str[i];
		if(c>='a'&&c<='z') cnt[c-'a']++;
		else if(c>='A'&&c<='Z') cnt[c-'A']++;
	}
	for(int i=0; i<26; i++) {
		if(cnt[i]) g.push_back({(char)(i+'a'),cnt[i]});
	}
}

void Select(HuffmanTree HT,int n,int &s1,int &s2) {
	int min1=INF;
	int min2=INF;
	for(int i=1; i<=n; i++) {
		if(HT[i].parent) continue;
		if(HT[i].weight<min1) {
			min2=min1;
			s2=s1;
			min1=HT[i].weight;
			s1=i;
			continue;
		}
		if(HT[i].weight<min2&&HT[i].weight>=min1) {
			min2=HT[i].weight;
			s2=i;
		}
	}
}

void Build_HuffmanTree(HuffmanTree &HT,int n) {
	if(n<=1) return;
	int m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(int i = 0; i <= m; i++) {
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(int i=1; i<=n; i++) {
		HT[i].weight=g[i-1].cnt;
	}
	for(int i=n+1; i<=m; i++) {
		int s1=0,s2=0;
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
}
void Creat_HuffmanCode(HuffmanTree &HT,HuffmanCode &HC, int n) {
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	char *cd=(char*)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(int i=1; i<=n; ++i) {
		int start=n-1;
		for(int c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent) {
			if(HT[f].lchild==c)
				cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

void Encode(int n,HuffmanCode &HC){
	for (int i=0; i<str.length(); i++) {
		for(int j=1; j<=n; j++) {
			if(str[i]==g[j-1].c||str[i]==g[j-1].c-32){
				cout<<HC[j];
			}
		}
	}
	cout<<'\n'; 
}

void Decode(int n,HuffmanTree &HT,string cipher){
	int p=2*n-1;
	for(int i=0;i<cipher.size();i++){
		if(!HT[p].lchild&&!HT[p].rchild){
			if(p-1<n) cout<<g[p-1].c;
			p=2*n-1;
		}
		if(cipher[i]=='0') p=HT[p].lchild;
		else if(cipher[i]=='1') p=HT[p].rchild;
	}
	if(p-1<n) cout<<g[p-1].c;
}

int main() {
	freopen("SourceFile.txt","r",stdin);
	HuffmanTree HT;
	HuffmanCode HC;
	getline(cin,str);
	Character_Statistics();
	int n=g.size();
	Build_HuffmanTree(HT,n);
	Creat_HuffmanCode(HT,HC,n);
	freopen("Code.txt","w",stdout);
	for(int i=1; i<=n; i++) {
		cout<<g[i-1].c<<':'<<HC[i]<<'\n';
	}
	freopen("ResultFile.txt","w",stdout);
	Encode(n,HC);
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	puts("请输入需要编译的密文：");
	string cipher;
	getline(cin,cipher);
	puts("下面是译码：");
	Decode(n,HT,cipher);
	return 0;
}
