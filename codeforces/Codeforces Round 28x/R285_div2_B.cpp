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

void solve() {
    int n;
    cin>>n;
    map<string, string> r;
    while(n--) {
        string a, b;
        cin>>a>>b;
        if(r.find(a) == r.end()) r[b] = a;
        else {
            r[b] = r[a];
            r.erase(a);
        }
    }
    cout<<r.size()<<endl;
    for(auto &p: r) {
        cout<<p.S<<" "<<p.F<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
