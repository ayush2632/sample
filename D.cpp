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
const int sz = 1000000;

int m,r, n;
/* m = #blocks and r = block size */
int A[sz];
int pos_z[sz];
int ans[sz][2];

int main(){
    READ("in.txt");
    int test; si1(test);
    int tc = 1;
    while(test--){
        int entry = 0;
        cout<<"Case #"<<tc++<<endl;
        si2(r,m);
        n = r*m;
        int zeros = 0;
        FOR(i,1,n+1){
            si1(A[i]);
            if(A[i] == 0) pos_z[zeros++] = i;
        }

        int tar = n;
        while(A[tar] == 0) tar-=r;
        FORr(z,zeros-1,0){
            int x = pos_z[z];
            if(x%r == 0) continue;
            int i = x;
            if(i<tar){
                int j = i+1;
                while(i<tar){
                    if(A[j]==0) j++;
                    else{
                        ans[entry][0] = i; ans[entry++][1] = j;
                        i = j; j++;
                    }
                }
            }
            else{
                int j = i-1;
                while(i>tar){
                    if(A[j] == 0) j--;
                    else{
                        ans[entry][0] = j; ans[entry++][1] = i;
                        i = j; j--;
                    }
                }

            }
            A[tar] = 0; A[x] = 1;
            int newT = tar - r;
            while(newT > 0 && A[newT] == 0){
                newT-=r;
            }
            tar = newT;
        }
        printf("%d\n",entry);
        FOR(i,0,entry){
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
    return 0;
}
/*
7
2 2
0 1 2 0
4 2
0 1 2 3 0 4 5 6
3 2
1 0 0 2 3 4
5 6
0 1 2 3 4 5 6 7 0 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 0 23 24 0 25 0
11 12
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 0 20 21 0 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 0 0 45 46 47 48 49 50 51 52 53 54 55 56 57 58 0 59 60 61 62 63 64 65 66 67 68 0 69 70 71 0 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 0 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 0 116 117 0 118 119 120 121
2 4
1 2 3 0 0 0 4 0
4 5
1 2 3 4 0 5 6 7 8 0 9 10 11 0 0 12 13 0 14 15


*/
