#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> numbers(N);

  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  sort(numbers.begin(), numbers.end(),
       [](const int& a, const int& b) { return abs(a) < abs(b); });

  for (int num : numbers) {
    cout << num << " ";
  }

  return 0;
}