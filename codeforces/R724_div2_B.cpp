#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))

bool sf(string &a, string &b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

vector<string> gen() {
    vector<string> r;
    string A, B, C;
    for (char a = 'a'; a <= 'z'; a++) {
        A = string(1, a);
        r.push_back(A);
        for (char b = 'a'; b <= 'z'; b++) {
            B = string(1, b);
            r.push_back(A + B);
            for (char c = 'a'; c <= 'z'; c++) {
                C = string(1, c);
                r.push_back(A + B + C);
            }
        }
    }
    sort(r.begin(), r.end(), sf);
    return r;
}

void solve(string &s, vector<string> &g) {
    for(int i=0;i<g.size();i++){
        if(s.find(g[i]) == -1){
            cout << g[i]<<endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    string s;
    cin >> t;

    auto g = gen();
    while (t--) {
        cin >> n >> s;
        solve(s, g);
    }
}
