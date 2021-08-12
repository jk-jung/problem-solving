class IndexTree {
public:
    int n, size;
    vector<int> d;

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        while (x) {
            d[x] += v;
            x >>= 1;
        }
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s], s++;
            if ((e & 1) == 0) r += d[e], e--;
            s >>= 1, e >>= 1;
        }
        return r;
    }
};