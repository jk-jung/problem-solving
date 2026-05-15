#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int used[55555];
set<int> p;
int f(int x){
    int r =0 ;
    for(int i=2;i*i<=x;i++){
        while(x % i == 0){
            x /= i;
            if(p.count(i)) r--;
            else r++;
        }
    }
    if(x != 1) {
        if(p.count(x)) r--;
        else r++;
    }
    return r;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vi a(n), b(m);
    for(int &x: a)cin>>x;
    for(int &x: b)cin>>x, p.insert(x);



    int r = 0;
    for(int x: a)r += f(x);

    int g = 0;
    vector<pi> v;
    for(int i=0;i<n;i++){
        g = gcd(g, a[i]);
        int k = f(g);
        if(k < 0)v.pb(mp(k, i));
    }
    sort(v.begin(), v.end());
    for(auto [k, i]: v){
        for(int j=i;j>=0;j--){
            if(used[j])break;
            used[j] = 1, r -= k;
        }
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    solve();
}
