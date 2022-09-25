/*
  180 Daraga Training
  Session No : 6 & 7
  Session : DP Classical Problems
  By : Ahmed Gamal
  On : 24/09/2022
*/


/// Fib >> recursion >> memoize
/*
#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 +1;
int mem[N];

int fib (int n) {
    int &ret = mem[n];
        if (~ret)
            return ret;
    /// base case
        if (n==1 || n==2)
            return ret = 1;
    /// code
            return ret = fib(n-1) + fib(n-2);
}


int main()
{
//    int x = 5;
//    int &y =x;
//    cout<<y<<endl;
//    y=10;
//    cout<<x<<" "<<y<<endl;


    int n;

    memset(mem, -1, sizeof mem);
    cin>>n;
    cout<< fib(n);


    /// iterative
    /*
    mem[1]=mem[2]=1;
    for(int i=3;i<=n;i++){
        mem[i] = mem[i-1]+mem[i-2];
    }
    cout<< mem[n];

    return 0;
}

*/


/// Knapsack

#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = (1<<16), OO = 0x3f3f3f3f;

int n, W[N], C[N], k;
int mem[N][N];										//O(n*k)

int solve(int i = 0, int rem = k){
    int &ret = mem[i][rem];
    if (~ret) return ret;
    /// 111111111111 >> 000000000000
    /// 00000000101 >> 111111

    /// base case
        if (i==n){
            return 0;
        }
    /// op1 (take)
        int op1;
        if (W[i]<=rem) {
            op1 = C[i] + solve(i+1, rem - W[i]);
        } else {
            op1 = -OO;
        }

    /// op2 (leave)
        int op2;
        op2 = solve(i+1, rem);

        return ret = max(op1, op2);

}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &k);
	memset(mem, -1, sizeof mem);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d %d", W+i, C+i);
	printf("%d $\n", solve());
	return 0;
}


/// Knapsack
/*
#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = (1<<16), OO = 0x3f3f3f3f;

int n, W[N], C[N], k;
int mem[N][N];										//O(n*k)

int KS(int i = 0, int rem = k){
    int &ret = mem[i][rem];
    if (~ret) return ret;
    /// base case
    if (i == n) {
       return 0;
    }

    return ret = max(W[i]<= rem? KS(i+1, rem-W[i]) + C[i] : -OO, KS(i+1, rem));

}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &k);
	memset(mem, -1, sizeof mem);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d %d", W+i, C+i);
	printf("%d\n", KS());
	return 0;
}
*/


/// Knapsack
/*
#include <bits/stdc++.h>

using namespace std;
const int N = (1<<10) , M = (1<<16), OO = 0x3f3f3f3f;

int n, W[N], C[N], k;
int mem[N][N];										//O(n*k)

int KS(int i = 0, int rem = k){		//O(n*k)
	if(i == n)	return 0;
	int & ret = mem[i][rem];
	if(~ret)	return ret;
	return ret = max(rem>=W[i]? KS(i+1, rem-W[i])+C[i] : -OO, KS(i+1, rem));
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	scanf("%d %d", &n, &k);
	memset(mem, -1, sizeof mem);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d %d", W+i, C+i);
	printf("%d\n", KS());
	return 0;
}
*/



/// LIS (longest increasing subsequence)
/*
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int N = 1e3 + 2, M = 1e4+5, OO = 0x3f3f3f3f;

int n, A[N];
int mem[N][N];

int solve(int i = 0, int prev = n){     //Memory -> O(n^2), Time -> O(n^2)
  if(i == n)  return 0;
  int& ret = mem[i][prev];
  if(~ret)  return ret;
  return ret = max(solve(i+1, prev),(A[i]>A[prev]? solve(i+1, i)+1 : 0));
}

int main(){
  scanf("%d", &n);
  for(int i = 0 ; i < n ; ++i)  scanf("%d", A+i);
  memset(mem, -1, sizeof mem);
  printf("%d\n", solve());
  return 0;
}
*/



/// LCS (longest common subsequence)
/*
#include <bits/stdc++.h>

using namespace std;
const int N = (1<<11) , M = (1<<14), OO = 0x3f3f3f3f;

int mem[N][N];
int n, m;
string s1, s2;

int LCS(int i = 0, int j = 0){
	if(i==n || j == m)	return 0;
	if(~mem[i][j])	return mem[i][j];
	if(s1[i] == s2[j])
		return mem[i][j] = LCS(i+1, j+1)+1;
	return mem[i][j] = max(LCS(i+1, j), LCS(i, j+1));
}

int main(){
  // freopen("i.in", "rt", stdin);
  // freopen("o.out", "wt", stdout);
	cin >> s1 >> s2;
	memset(mem, -1, sizeof mem);
	n = s1.length();
	m = s2.length();
	printf("%d\n", LCS());
	return 0;
}
*/




