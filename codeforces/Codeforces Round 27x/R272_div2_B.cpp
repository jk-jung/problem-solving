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
    string a, b;
    cin>>a>>b;
    map<int, int> x, y;
    x[0] = 1;
    for(char c:b) {
        y.clear();
        for(auto [p, q]: x) {
            if(c == '?')y[p-1] += q, y[p+1] += q;
            if(c == '+')y[p+1] += q;
            if(c == '-')y[p-1] += q;
        }
        x = y;
    }
    int t = 0;
    for(char c: a)t += (c == '+' ? 1 : -1);
    double tot = 0;
    for (auto [p, q]: x)tot += q;
    printf("%.10lf", x[t] / tot);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
