## sort algorithm
algorithm 헤더파일에 존재. <br>
sort(start,end) -> 범위(start 포함, end 포함 x) 에 있는 요소를 오름차순으로 정렬 <br>
 
```c++
template <typename T>
  void sort(T start, T end, Compare comp);
```
3번째 인자 없을 경우 default 로 정렬
* sort(arr, arr+n) <br>
* sort(v.begin(), v.end()) <br>
* sort(v.begin(), v.end(), greater<자료형>()) - 내림차순 <br>
* sort(v.begin(), v.end(), less<자료형>()) - 오름차순 <br>
  
  
## stable sort (안정정렬)
중복된 키를 순서대로 정렬하는 정렬 알고리즘<br>
  정렬했을 경우 중복된 값의 순서가 변하지 않는 것 cf. 변하면 불안정 정렬 (unstable sort)

### 1. stable sort algorithm <br>
* Insertion Sort
* Merge Sort
* Bubble Sort
* Counting Sort
### 2. unstable sort algorithm <br>
* Selection sort
* Heap Sort
* Shell Sort
* Quick Sort

> 10814 : 나이순 정렬에서 원래는 구조체를 사용하려고 했으나, 너무 규모가 커질 것 같아 stable sort로 변경

## vector vs array
배열은 정적 할당 <br>
벡터는 동적 배열구조 클래스 <br>

#### 벡터의 단점
- 중간에 값을 삽입하거나 삭제하기 어려움. 주소값을 모두 이동해야 하기 때문
- 다량의 데이터에서 검색이 느림
#### 벡터의 장점
- 마지막 위치에 추가, 삭제는 쉬움
- 개별 원소 접근 가능, 접근 속도 빠름
- 랜덤으로 원소 순회 가능

#### boj10867 문제에 쓰인 벡터 
push_back : 벡터 맨 뒤에 값을 넣는 함수 <br>
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int count;
	cin >> count;

	vector<int> array;
	int input;

	for (int i = 0; i < count; i++) {
		cin >> input;
		array.push_back(input);
	}

	sort(array.begin(), array.end());

	array.erase(unique(array.begin(), array.end()), array.end());

	for (auto i : array) {
		cout << i << " ";
	}
}
```
