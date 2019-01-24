#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::max;
struct one{int a,h,k;}peo[1010];
bool cmp(one x,one y){return x.h<y.h;} 
int n,maxh;
bool f[20005];
int main(){
//	freopen("***.in","r",stdin);
//	freopen("***.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&peo[i].a,&peo[i].h,&peo[i].k),maxh=max(maxh,peo[i].h);
	std::sort(peo+1,peo+1+n,cmp);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=peo[i].k;j++){
			for(int k=maxh;k>=0;k--){
				if(f[k]){
					if(k+peo[i].a>peo[i].h) f[peo[i].h]=1; 
					else f[k+peo[i].a]=1;
				}
			}
		}
	for(int i=maxh;i>=0;i--) if(f[i]){printf("%d\n",i);return 0;}
				
//	fclose(stdin);
//	fclose(stdot);
	return 0;
}
/*
7
8 35 1
5 35 1
5 45 1
8 35 1
10 33 1 
4 35 1
2 31 2
*/
