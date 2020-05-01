#include<iostream>
#include<array>
using namespace std;

array<int, 5>arr = { 1,2,4,0,3 };

int main() {
	int j = 1;
	for (int i = 0; i < arr.size(); j++) {
		i = arr[i];
		cout << i << " ";
		if (i == 0 || j > arr.size()) {
			if (j != arr.size()) cout << "False\n";
			else cout << "True\n";
			break;
		}
	}

	getchar();
	return 0;
}

/*정수 배열 arr이 있습니다. arr안의 각 원소의 값은 다음 원소의 인덱스입니다.
이렇게 서로 이어지는 원소들의 배열이 있을때, arr[0]부터 시작하여 모든 원소를 들린 다음 다시 arr[0]로 도착할 수 있는지 찾으시오.
단, 시간복잡도는 O(n), 공간복잡도는 O(1).

예제)
Input: [1, 2, 4, 0, 3]
Output: True
// 1 -> 2 -> 4 -> 3 -> 0 -> 1

Input: [1, 4, 5, 0, 3, 2]
Output: False
// 1 -> 4 -> 3 -> 0 -> 1
// arr[2], arr[5]를 들리지 않았습니다.

Input: [1, 2, 2, 0]
Output: False
// 1 -> 2 -> 2 -> 2 -> …
// arr[0]로 돌아오지 못합니다.
*/