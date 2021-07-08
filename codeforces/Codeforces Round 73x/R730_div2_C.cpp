#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


double N = 100000;

pi read() {
    string s;
    cin >> s;
    int r = 0, flag = 0;

    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (flag) {
            r = r * 10 + (s[i] - '0');
            c++;
        }
        if (s[i] == '.') flag = 1;
    }
    while (c < 4) {
        r *= 10;
        c++;
    }
    return {(ll) r, (ll) 10000};
}

map<pair<pi, pi>, double> ck;

pi pi_min(pi a, pi b) {
    return a.F * b.S < b.F * a.S ? a : b;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

pi norm(pi a) {
    if (a.F == 0) return {0ll, 1ll};
    ll g = gcd(a.F, a.S);
    return {a.F / g, a.S / g};
}

pi pi_add(pi a, pi b) {
    pi c = {a.F * b.S + b.F * a.S, a.S * b.S};
    return norm(c);
}

pi pi_minus(pi a, pi b) {
    return pi_add(a, {-b.F, b.S});
}

pi div2(pi a) {
    return norm({a.F, a.S * 2});
}

double go(pi a, pi b, pi c, pi d) {
    a = norm(a);
    b = norm(b);
    c = norm(c);
    d = norm(d);

    if (ck.find({a, b}) != ck.end()) return ck[{a, b}];
    double &r = ck[{a, b}];

    r = (double)c.F / (double) c.S;
    if (a.F > 0) {
        pi dif = pi_min(a, d);
        pi dif2 = div2(dif);
        pi na = pi_minus(a, dif);

        pi nb = pi_add(b, dif2);
        pi nc = pi_add(c, dif2);
        if (b.F == 0) {
            nb = b;
            nc = pi_add(c, dif);
        }

        r += (1 + go(na, nb, nc, d)) * (double)a.F / (double)a.S;
    }
    if (b.F > 0) {
        pi dif = pi_min(b, d);
        pi dif2 = div2(dif);
        pi nb = pi_minus(b, dif);

        pi na = pi_add(a, dif2);
        pi nc = pi_add(c, dif2);
        if (a.F == 0) {
            na = a;
            nc = pi_add(c, dif);
        }

        r += (1 + go(na, nb, nc, d)) * (double)b.F / (double)b.S;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        pi a = read();
        pi b = read();
        pi c = read();
        pi d = read();

//        printf("%d %d %d %d\n", a, b, c,d);
        ck.clear();
        printf("%.12lf\n", go(a, b, c, d));
    }
}
