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

vector<pii> drawLineDDA(int x0, int y0, int x1, int y1) {

	int dx = x1 - x0;
	int dy = y1 - y0;

	int step = max(abs(dx), abs(dy));

	float step_x = (float) dx / (float) step;
	float step_y = (float) dy / (float) step;

	float x = x0;
	float y = y0;

	vector<pii> res;

	for (int i = 0; i <= step; ++i) {

		res.push_back({round(x), round(y)});

		x += step_x;
		y += step_y;
	}
	return res;
}

vector<pii> drawLineBresenham(int x0, int y0, int x1, int y1) {

	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);

	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;

	int err = dx - dy;

	vector<pii> res;
	while (1) {
		res.push_back({x0, y0});

		if (x0 == x1 && y0 == y1)
			break;

		int e2 = 2 * err;

		if (e2 > -dy) {
			err -= dy;
			x0 += sx;
		}

		if (e2 < dx) {
			err += dx;
			y0 += sy;
		}
	}

	return res;
}

int main() {
    
	int x0 = 0, y0 = 0;
	int x1 = 6, y1 = 3;

	auto dda = drawLineDDA(x0, y0, x1, y1);
	auto bresenham = drawLineBresenham(x0, y0, x1, y1);

	int n = dda.size();
	for (int i = 0; i < n; ++i) {
		pii d = dda[i];
		pii b = bresenham[i];

		cout << d.first << ' ' << d.second << " | " << b.first << ' ' << b.second << '\n';
	}

    return 0;
}