#include <iostream>
#include <vector>

using namespace std;

int N, M;

void combination(int start, vector<int>& v, vector<int>& vec, int n, int k) {
    if (v.size() == k) {
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < n; i++) {
        v.push_back(vec[i]);
        combination(i + 1, v, vec, n, k);
        v.pop_back();
    }
}

int main() {
    cout << "Select N (from 1 to 8) : ";
    cin >> N;
    cout << "Select M (less than or equal to N) : ";
    cin >> M;

    if (N < 1 || N > 8 || M < 1 || M > N) {
        cout << "Invalid input. N should be between 1 and 8, and M should be between 1 and N." << endl;
        return 1;
    }

    vector<int> vec;
    for (int i = 1; i <= N; i++) {
        vec.push_back(i);
    }

    vector<int> v;
    combination(0, v, vec, N, M);

    return 0;
}
