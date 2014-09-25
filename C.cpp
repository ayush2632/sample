/** author : ayush sharma **/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstring>

#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define FORr(i,a,b) for(int i=a ; i>=b; i--)
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define si1(n) scanf("%d",&n)
#define si2(n1, n2) scanf("%d%d",&n1,&n2)
#define si3(n1,n2,n3) scanf("%d%d%d",&n1, &n2, &n3)
#define si4(n1,n2,n3,n4) scanf("%d%d%d%d",&n1, &n2, &n3, &n4)
#define ff first
#define ss second
#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define show1(a) cout<<a<<"\n"
#define show2(a, b) cout<<a<<"   "<<b<<"\n"
#define show3(a, b, c) cout<<a<<"   "<<b<<"    "<<c<<"\n"
#define show4(a, b, c,d) cout<<a<<"   "<<b<<"    "<<c<<"   "<<d<<"\n"

using namespace std;
typedef long long LL;
typedef pair <int,int> pii;
typedef pair <pii, int> piii;
typedef pair<string,int> psi;
typedef vector<int> vi;
typedef unsigned long long ull;
const int INFI = 1<<29;

const int sz = 1002;
int n;
struct Rule{
    int a, b, c, d, e, f;
    Rule() {}
    Rule(int a_, int b_, int c_, int d_, int e_, int f_) : a(a_) , b(b_), c(c_), d(d_), e(e_), f(f_) {}
};

Rule rules[sz];
int P[sz][2];

int solve(int i, int choice, int a, int b, int c, int d, int e, int f){
    if(a>b || c>d || e>f) return -100000;
    if(i== n) return 0;
    if(P[i][choice] != -1) return P[i][choice];
    int &res = P[i][choice];
    if(choice == 0){
        res = max(solve(i+1,0,a,b,c,d,e,f) , solve(i+1,1,a,b,c,d,e,f));
        return res;
    }
    int newa = max(a, rules[i].a);
    int newb = min(b, rules[i].b);
    int newc = max(c, rules[i].c);
    int newd = min(d, rules[i].d);
    int newe = max(e, rules[i].e);
    int newf = min(f, rules[i].f);
    res = 1 + max(solve(i+1, 0, newa, newb, newc, newd, newe, newf), solve(i+1, 1, newa, newb, newc, newd, newe, newf));
    return res;
}



int main(){
    READ("in.txt");
    int test; si1(test);
    int tc = 1;
    while(test--){
        cout<<"Case #"<<tc++<<endl;
        si1(n);
        FOR(i,0,n){
            int a, b, c, d, e, f;
            si4(a,b,c,d); si2(e,f);
            Rule r(a,b,c,d,e,f);
            rules[i] = r;
        }
        FOR(i,0,n+1) P[i][0] = -1, P[i][1] = -1;
        int ret = max(solve(0,0,0,256,0,256,0,256), solve(0,1,0,256,0,256,0,256)) ;
        printf("%d\n",ret);
    }
    return 0;
}
