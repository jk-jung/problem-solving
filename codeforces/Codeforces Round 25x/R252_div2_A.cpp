#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, m;
    cin >> n >> m;
    vi r;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        int x= 0,ok = 0;
        while(k--){
            cin>>x;
            if(x  < m)ok = 1;
        }
        if(ok)r.pb(i+1);
    }
    cout<<r.size()<<endl;
    for(int x:r)cout<<x<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
