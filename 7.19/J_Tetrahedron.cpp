#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1000000007;

struct point {
	point():x(0),y(0),z(0){}
	point(double ax,double ay,double az) {x=ax;y=ay;z=az;}
	double x,y,z;
}p[8];


double eps=1e-8;
point cross(point p1,point p2){
	point tmp;
	tmp.x=p1.y*p2.z-p1.z*p2.y;
	tmp.y=p1.z*p2.x-p1.x*p2.z;
	tmp.z=p1.x*p2.y-p1.y*p2.x;
	return tmp;
}
double dot(point p1,point p2) {
	return p1.x*p2.x+p1.y*p2.y+p1.z*p2.z;
}

double S[4];
point vec[4][3];
double r=0;
point vert[4];
double a[4][4];

void init() {
	for(int i=0;i<4;i++)
		for(int j=i+1;j<=i+3;j++) 
			vec[i][j-i-1]=point(p[j].x-p[i].x,p[j].y-p[i].y,p[j].z-p[i].z);
	for(int i=0;i<4;i++)
		S[i]=sqrt(dot(cross(vec[i][0],vec[i][1]),cross(vec[i][0],vec[i][1])));
	for(int i=0;i<4;i++){
		vert[i]=cross(vec[i][0],vec[i][1]);
		vert[i].x/=S[i];
		vert[i].y/=S[i];
		vert[i].z/=S[i];
	}
}


double ga[3];
bool Gauss(int equ,int var){
	int i,j,k,col;

	for(k=0,col=0;k<equ && col<var;k++,col++) {
		for(i=k;i<equ;i++)
			if(fabs(a[i][col])>eps) {
				for(j=col;j<var+1;j++)
					swap(a[k][j],a[i][j]);
				break;
			}
		if(fabs(a[k][col])<eps) {
			k--;
			continue;
		}

		for(i=0;i<equ;i++) {
			if(i==k || fabs(a[i][col])<eps) continue;
			double x1=a[i][col],x2=a[k][col];
			for(j=0;j<var+1;j++)
				a[i][j]=a[i][j]*x2-a[k][j]*x1;
		}
	}
	
	for(i=k;i<equ;i++)
		if(fabs(a[i][var])>eps)
			return false;
	
	for(i=0;i<var;i++)
		for(j=0;j<equ;j++)
			if(fabs(a[j][i])>eps)
				ga[i]=a[j][var] / a[j][i];

	return true;
}
	
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	while(cin>>p[0].x>>p[0].y>>p[0].z) {
		for(int i=1;i<=3;i++)
			cin>>p[i].x>>p[i].y>>p[i].z;
		for(int i=4;i<=7;i++)
			p[i]=p[i-4];
		init();
		double totv=dot(cross(vec[0][0],vec[0][1]),vec[0][2]);
		if(fabs(totv)<eps) {printf("O O O O\n");continue;}
		double tots=0;
		for(int i=0;i<4;i++)tots+=S[i];
		r=fabs(totv/tots);
		int zz[4];
		for(zz[0]=-1;zz[0]<=1;zz[0]+=2)
		for(zz[1]=-1;zz[1]<=1;zz[1]+=2)
		for(zz[2]=-1;zz[2]<=1;zz[2]+=2)
		for(zz[3]=-1;zz[3]<=1;zz[3]+=2){
			for(int i=0;i<4;i++) {
				a[i][0]=zz[i]*vert[i].x;
				a[i][1]=zz[i]*vert[i].y;
				a[i][2]=zz[i]*vert[i].z;
				a[i][3]=r+zz[i]*dot(p[i],vert[i]);
			}
			if(Gauss(4,3)){
				printf("%.4lf %.4lf %.4lf %.4lf\n",ga[0],ga[1],ga[2],r);	
			}
		}
	}
	return 0;
}
