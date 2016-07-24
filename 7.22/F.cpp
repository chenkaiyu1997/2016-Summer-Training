#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
const double eps=1e-10;
const double eps2=1e-7;
const double pi=3.1415926535897932384626;
struct point {
	double x,y,z;
	point(): x(0),y(0),z(0) {}
	point(double tx,double ty,double tz) {
		x=tx;
		y=ty;
		z=tz;
	}
	void operator*=(double A) {
		x*=A;
		y*=A;
		z*=A;
	}
	void operator/=(double A) {
		x/=A;
		y/=A;
		z/=A;
	}
	friend point operator +(const point& A,const point& B);
	friend point operator -(const point& A,const point& B);	
}c,p[3];

point cross(const point& A,const point& B) {
	return point(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x);
}


point operator +(const point& A,const point& B){
	point tmp;
	tmp.x=A.x+B.x;
	tmp.y=A.y+B.y;
	tmp.z=A.z+B.z;
	return tmp;
}
point operator -(const point& A,const point& B){
	point tmp;
	tmp.x=A.x-B.x;
	tmp.y=A.y-B.y;
	tmp.z=A.z-B.z;
	return tmp;
}
double dot(const point& A,const point& B){
	return A.x*B.x + A.y*B.y + A.z*B.z;
}

double deps(double x){
	if(x<-eps2)return -1;
	if(x>eps2)return 1;
	return 0;
}

point ana(){
	double d,l;
	cin>>d>>l;
	d=d/180*pi;l=l/180*pi;
	point tmp;
	tmp.x=cos(d)*cos(l);
	tmp.y=cos(d)*sin(l);
	tmp.z=sin(d);
	return tmp;
}
point pos,v;
bool check(double mid){
	point tmp=v;
	tmp*=mid;
	tmp=tmp+pos;
	if(dot(tmp,tmp)>=1)return true;
	return false;
}

bool pan() {
	for(int i=0;i<=2;i++) {
		int j=(i+1)%3,k=(i+2)%3;
		point ver=cross(p[i],p[j]);
		double verd=sqrt(dot(ver,ver));
		ver/=verd;
		if(deps(dot(ver,p[k])) * deps(dot(ver,pos))<0)
			return false;
	}
	return true;
}

int main() {
	freopen("A.in","r",stdin);
	double r;	
	cin>>c.x>>c.y>>c.z;
	cin>>r;
	p[0]=ana();
	p[1]=ana();
	p[2]=ana();
	cin>>pos.x>>pos.y>>pos.z;
	pos=pos-c;
	pos/=r;
	cin>>v.x>>v.y>>v.z;
	double vdot=sqrt(dot(v,v));
	v/=vdot;
	double ll=0,rr=fabs(dot(pos,v))-eps;
	while(rr-ll>eps){
		double mid=(ll+rr)/2;
		if(check(mid))ll=mid;
		else rr=mid;
	}
	v*=ll;
	pos=pos+v;
	if(dot(pos,pos)>1+eps2 || (!pan()))
		printf("NO\n");
	else
		printf("YES\n");

}
