
using namespace std;
int a[N], n, m;
struct data {
    int len;
    ll sum, add, sumh, tag, addh;
} s[N];
void pushup(int now) {
    s[now].sum = s[lson].sum + s[rson].sum;
    s[now].sumh = s[lson].sumh + s[rson].sumh;
}
void mark_adh(int now, ll v, int t) {
    s[now].addh += v;
    if (t)
        s[now].sumh += v * s[now].len;
}
void mark_add(int now, ll v) {
    if (s[now].tag) {
        mark_adh(now, -v * s[now].tag, 0);
    }
    s[now].add += v;
    s[now].sum += 1ll * s[now].len * v;
}
void mark_tag(int now, ll v) {
    s[now].tag += v;
    s[now].sumh += s[now].sum * v;
}
void pushdown(int now) {
    if (s[now].add) {
        mark_add(lson, s[now].add);
        mark_add(rson, s[now].add);
        s[now].add = 0;
    }
    if (s[now].addh) {
        mark_adh(lson, s[now].addh, 1);
        mark_adh(rson, s[now].addh, 1);
        s[now].addh = 0;
    }
    if (s[now].tag) {
        mark_tag(lson, s[now].tag);
        mark_tag(rson, s[now].tag);
        s[now].tag = 0;
    }
}
void build(int l, int r, int now) {
    s[now].len = r - l + 1;
    if (l == r) {
        s[now].sum = a[l];
        s[now].sumh = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, lson);
    build(mid + 1, r, rson);
    pushup(now);
}
void update(int l, int r, int now, int L, int R, int v) {
    if (l >= L && r <= R) {
        mark_add(now, v);
        return;
    }
    pushdown(now);
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(l, mid, lson, L, R, v);
    if (R > mid)
        update(mid + 1, r, rson, L, R, v);
    pushup(now);
}
ll query(int l, int r, int now, int L, int R) {
    if (l >= L && r <= R) {
        return s[now].sumh;
    }
    pushdown(now);
    int mid = (l + r) >> 1;
    ll re = 0;
    if (L <= mid)
        re += query(l, mid, lson, L, R);
    if (R > mid)
        re += query(mid + 1, r, rson, L, R);
    return re;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<std::pair<int, int>>> Q(n + 1);
    std::vector<unsigned> res(q + 1);
    for (int i = 1; i <= q; ++i) {
        int l, r;
        std::cin >> l >> r;
        Q[r].emplace_back(l, i);
    }

    std::vector<int> last(n);

    build(1, n, 1);
    for (int i = 1; i <= n; ++i) {
        update(1, n, 1, last[a[i]] + 1, i, 1);
        dbg("upd:", last[a[i]] + 1, i);
        last[a[i]] = i;
        mark_tag(1, 1);
        dbg("mark_tag");
        for (auto [l, id] : Q[i]) {
            dbg("q", l, i, id);
            res[id] = query(1, n, 1, l, i);
        }
    }
    for (int i = 1; i <= q; ++i) std::cout << res[i] << "\n";
    return 0;
}
signed main() {
    File();
    Main();
}
