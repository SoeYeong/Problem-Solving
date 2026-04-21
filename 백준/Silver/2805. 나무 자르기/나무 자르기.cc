#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int Hmax;
vector<int> wood;
void binary_search() {
  int low = 0;
  int high = wood[N - 1];
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    long long sum = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (wood[i] > mid) {
        sum += wood[i] - mid;
      }
      else {
        break;
      }
    }
    
    if (sum == M) {
      Hmax = mid;
      break;
    }
    else if (sum > M) {
      Hmax = max(Hmax, mid);
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  int len;
  for (int i = 0; i < N; i++) {
    cin >> len;
    wood.push_back(len);
  }

  sort(wood.begin(), wood.end());
  binary_search();
  cout << Hmax;

  return 0;
}