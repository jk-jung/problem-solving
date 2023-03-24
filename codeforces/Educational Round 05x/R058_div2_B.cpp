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

bool solve() {
    string v;
    cin >> v;
    int n = v.size();
    int s = 0;
    int e = n - 1;
    while (s < n && v[s] != '[')s++;
    if (s == n) return false;
    while (s < n && v[s] != ':')s++;
    if (s == n) return false;

    while (e >= 0 && v[e] != ']')e--;
    if (e < 0) return false;
    while (e >= 0 && v[e] != ':')e--;
    if (e < 0) return false;
    if(s >= e) return false;

    int r = 4;
    for (int i = s + 1; i < e; i++)if (v[i] == '|')r++;
    cout << r << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (!solve()) {
        cout << "-1\n";
    }
}
