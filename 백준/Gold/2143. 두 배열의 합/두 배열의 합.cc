#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
int arr[1001], brr[1001];
// a의 부 배열의 합(오름차순), b의 부 배열의 합(내림차순)
vector<int> suba, subb;
long long cnt;

int main() {
  cin >> T;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  cin >> M;
  for (int i = 1; i <= M; i++) {
    cin >> brr[i];
    brr[i] += brr[i - 1];
  }

  // 부 배열의 합
  int low, high;
  for (low = 1; low <= N; low++) {
    for (high = low; high <= N; high++) {
      suba.push_back(arr[high] - arr[low - 1]);
    }
  }
  for (low = 1; low <= M; low++) {
    for (high = low; high <= M; high++) {
      subb.push_back(brr[high] - brr[low - 1]);
    }
  }

  // 정렬
  sort(suba.begin(), suba.end());
  sort(subb.begin(), subb.end(), greater<>());

  // 투 포인터로 개수 찾기
  int ptra = 0, ptrb = 0;
  while (ptra < suba.size() && ptrb < subb.size()) {
    int sum = suba[ptra] + subb[ptrb];

    // 종료 조건
    if (ptra == suba.size() - 1 && sum < T) {
      break;
    }
    else if (ptrb == subb.size() - 1 && sum > T) {
      break;
    }

    if (sum > T) {
      ptrb++;
    }
    else if (sum < T) {
      ptra++;
    }
    else {
      // 부 배열의 합 중 연속된 같은 값 개수 찾기
      long long cnta = 1, cntb = 1;
      while (ptra + cnta < suba.size()){
        if (suba[ptra] == suba[ptra + cnta]) {
          cnta++;
        }
        else {
          break;
        }
      }
      while (ptrb + cntb < subb.size()) {
        if (subb[ptrb] == subb[ptrb + cntb]) {
          cntb++;
        }
        else {
          break;
        }
      }
      cnt += cnta * cntb;
      ptra += cnta;
      ptrb += cntb;
    }
  }

  cout << cnt;
  return 0;
}