#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

struct line {
	int x1, y1, x2, y2;

	void print() {
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	}
};

bool onSegment(int x1, int y1, int x2, int y2, int x, int y) {
    return min(x1, x2) <= x && x <= max(x1, x2) &&
           min(y1, y2) <= y && y <= max(y1, y2);
}

int direction(int xi, int yi, int xj, int yj, int xk, int yk) {
    long long val = 1LL * (xk - xi) * (yj - yi) - 1LL * (xj - xi) * (yk - yi);
    if (val == 0) return 0;   // collinear
    return (val > 0) ? 1 : -1; // clockwise / counterclockwise
}

bool lineIntersects(line a, line b) {
    int d1 = direction(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1);
    int d2 = direction(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2);
    int d3 = direction(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1);
    int d4 = direction(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2);

    if (d1 != d2 && d3 != d4) return true;

    if (d1 == 0 && onSegment(a.x1, a.y1, a.x2, a.y2, b.x1, b.y1)) return true;
    if (d2 == 0 && onSegment(a.x1, a.y1, a.x2, a.y2, b.x2, b.y2)) return true;
    if (d3 == 0 && onSegment(b.x1, b.y1, b.x2, b.y2, a.x1, a.y1)) return true;
    if (d4 == 0 && onSegment(b.x1, b.y1, b.x2, b.y2, a.x2, a.y2)) return true;

    return false;
}

bool solve() {
    
	int xl, yl, xr, yr;
	int x1, y1, x2, y2;

	cin >> xl >> yl >> xr >> yr;
	cin >> x1 >> y1 >> x2 >> y2;

	auto inside = [&](int x, int y) {
	    return xl <= x && x <= xr && yl <= y && y <= yr;
	};

	if (inside(x1, y1) || inside(x2, y2))
	    return true;

	line laser = {x1, y1, x2, y2};

	line l1 = {xl, yl, xl, yr};
	line l2 = {xl, yr, xr, yr};
	line l3 = {xr, yl, xr, yr};
	line l4 = {xl, yl, xr, yl};

	// 0 0 5 5
	// 0 5 5 5

	if (lineIntersects(	laser, l1)) {
		// laser.print();
		// l1.print();
		// cout << "intersects l1" << '\n';
		return true;
	}

	if (lineIntersects(	laser,l2)) {
		// laser.print();
		// l2.print();
		// cout << "intersects l2" << '\n';
		return true;
	}

	if (lineIntersects(	laser,l3)) {
		// laser.print();
		// l3.print();
		// cout << "intersects l3" << '\n';
		return true;
	}
	if (lineIntersects(	laser,l4)) {
		// laser.print();
		// l4.print();
		// cout << "intersects l4" << '\n';
		return true;
	}

	return false;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        // solve();

        if (solve()) cout << "STOP\n";
        else cout << "OK\n";
    }
    return 0;
}
    
