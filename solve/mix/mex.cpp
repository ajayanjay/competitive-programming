#include <bits/stdc++.h>
using namespace std;

struct Mex {
	unsigned long long MAX_SIZE;
	vector<bool> mex_vec;
	int ptr = 0;

	Mex(unsigned long long MAX_SIZE) : MAX_SIZE(MAX_SIZE), mex_vec(MAX_SIZE + 1, true) {};
	
	int mex() { return ptr; }

	void insert(int new_val) {
		if (new_val > MAX_SIZE) return;

		mex_vec[new_val] = true;
		while (mex_vec[ptr]) ++ptr;
	}

	void remove(int new_val) {
		if (new_val > MAX_SIZE) return;

		mex_vec[new_val] = false;
		if (new_val < ptr) ptr = new_val;
	}
};