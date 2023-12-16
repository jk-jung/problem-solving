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
    cin >> n;
    vector<pair<string, int>> v(n), r;
    for (auto &t: v){
        cin >> t.F;
        if(t.F != "removeMin")cin >> t.S;
        else t.S = 0;
    }

    priority_queue<int, vi, greater<>> q;

    for (const auto& t: v) {
        if (t.F == "insert"){
            q.push(t.S);
        }
        else if(t.F == "getMin"){
            while(!q.empty() && q.top() < t.S){
                r.pb({"removeMin", 0});
                q.pop();
            }
            if(q.empty() || q.top() > t.S){
                r.pb({"insert", t.S});
                q.push(t.S);
            }
        }else {
            if(q.empty())r.pb({"insert", 0});
            else q.pop();
        }
        r.pb(t);
    }
    cout << r.size() << endl;
    for(auto t: r){
        cout << t.F;
        if(t.F != "removeMin")cout << " " << t.S;
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
