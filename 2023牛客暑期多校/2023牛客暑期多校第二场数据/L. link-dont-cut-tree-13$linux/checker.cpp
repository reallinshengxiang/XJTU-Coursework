#include<algorithm>
#include<cmath>
#include "testlib.h"
using namespace std;
const int MAX=1e9;
using ll=long long;
using ld=long double;
const ld eps=1e-4;
struct V{
    ld x,y;
    V(ld _x,ld _y):x(_x),y(_y){}
    V():x(0),y(0){}
    V operator -(const V &a)const{
        return V(x-a.x,y-a.y);
    };
    V operator +(const V &a)const{
        return V(x+a.x,y+a.y);
    };
    V operator *(const ld s)const{
        return V(x*s,y*s);
    }
};
struct Seg{
    V s,t;
    Seg(V a,V b):s(a),t(b){}
};
ld dis(const V &a){return sqrtl(a.x*a.x+a.y*a.y);}
ld dis(V a,V b){return dis(a-b);}
V unitV(const V &v){
    ld f=dis(v);
    return V(v.x/f,v.y/f);
}
ld dot(const V &a,const V &b){
    return a.x*b.x+a.y*b.y;
}
ld cross(const V &a,const V &b){
    return a.x*b.y-a.y*b.x;
}
V cross(const Seg &A,const Seg &B){
    const auto &[a,b]=A;
    const auto &[c,d]=B;
    V n1(b.y-a.y,a.x-b.x);
    V n2(d.y-c.y,c.x-d.x);
    ld dist_c_n2 = c.x * n2.x + c.y * n2.y;
    ld dist_a_n2 = a.x * n2.x + a.y * n2.y;
    ld denominator = n1.x * n2.y - n1.y * n2.x;
    ld fraction = (dist_a_n2 - dist_c_n2) / denominator;
    return V(a.x + fraction * n1.y,a.y - fraction * n1.x);
}
ld S(V a,V b,V c){
    return abs(cross(b-a,c-a))/2;
}
int sgn(ld x){
    if(abs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
bool point_on_segment(V p,Seg seg){
    if(sgn(cross(seg.s-p,p-seg.t))) return false;
    if(dot(seg.s-p,p-seg.t)+eps<0) return false;
    return true;
};
bool check(const array<V,4> &input,const array<V,4> &res){
    auto &[A,B,C,D]=input;
    auto &[a,b,c,d]=res;
    ld s1=S(A,B,D)+S(B,C,D);
    ld s2=S(a,b,d)+S(b,c,d);
    if(abs(s2-2*s1)>eps) return false;
    if(!point_on_segment(A,{a,b})) return false;
    if(!point_on_segment(B,{b,c})) return false;
    if(!point_on_segment(C,{c,d})) return false;
    if(!point_on_segment(D,{d,a})) return false;
    ld lab=dis(a,b),lbc=dis(b,c),lcd=dis(c,d),lda=dis(d,a);
    if(abs(lab-lbc)>eps) return false;
    if(abs(lab-lcd)>eps) return false;
    if(abs(lab-lda)>eps) return false;
    return true;
};
int main(int argc, char * argv[]){
    setName("checker");
    registerTestlibCmd(argc, argv);
    int t=inf.readInt();
    for(int i=1;i<=t;i++){
        string op=ouf.readLine();
        string std=ans.readLine();
        auto in=inf.readDoubles(8,-1e4,1e4);
        V a(in[0],in[1]),b(in[2],in[3]),c(in[4],in[5]),d(in[6],in[7]);
        if(op!=std) quitf(_wa,"WA");
        if(op=="Link cut tree!") continue;
        auto out=ouf.readDoubles(8,-1e9,1e9);
        V A(out[0],out[1]),B(out[2],out[3]),C(out[4],out[5]),D(out[6],out[7]);
        auto res=ans.readDoubles(8,-1e9,1e9);
        if(!check({a,b,c,d},{A,B,C,D})) quitf(_wa,"Not meeting the conditions."); 
        ans.readLine();
        ouf.readLine();
    }
    quitf(_ok, "OK");
}
