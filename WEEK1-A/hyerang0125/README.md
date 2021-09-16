> 🖇 2021 2학기 1주차 - 자료구조

</br>

# 1️⃣ List? Vector?

## List vs. Vector

- STL의 Vector 방식은 메모리 할당을 연속적으로 하고, List는 따로따로 할당을 한다.
- Vector는 배열과 같은 방식으로 사용할 수 있지만 List는 그렇지 않다.

### 메모리 할당

- Vector는 미리 일정 크기의 메모리를 할당해 놓고 그 이상의 값들이 추가되면 새로운 더 큰 메모리를 할당한다.
- List는 값을 넣을 때 마다 메모리를 할당하게 된다.
- 따라서 vector는 메모리 할당을 매번 하지 않기 때문에 List보다 pushback이 빠르다.
- 그러나 중간에 추가하는 insert의 경우 vector는 배열을 계속 재구성 해야하기 때문에 속도가 느리다.

### 메모리 해제

- Vector는 값을 삭제하더라도 메모리 해제를 하지 않는다. 그러나 List의 경우 변수가 해제 될 때마다 메모리에서 해제하게 된다.
- 할당과 마찬가지로 해제 또한 popback의 경우 vector가 훨씬 빠르다. 그러나 역시 중간에 값을 삭제하는 것은 List가 더 빠르다.
- vector의 메모리를 해제해주는 것은 상당히 많은 시간을 소요하므로 특별한 경우만 사용해야 한다.

### 메모리 사용량

- vector의 경우 연속적인 주소에 할당되므로 추가적인 linked list처럼 next의 주소 등 다른 변수들을 가지고 있을 필요가 없다.
- 즉, Vector가 list보다 적은 메모리를 사용한다.

## STL list

``` cpp
// <list> 헤더 추가
#include <list>
// list 생성
list<int> a;
// 리스트 맨 앞에 워소 추가 | 리스트 맨 뒤에 원소 추가 | iterator가 가리키는 부분의 앞에서 원소 추가
a.push_front(x);
a.push_back(x);
a.insert(iterator, x);
// 리스트 맨 앞의 원소 삭제 | 리스트 맨 뒤의 원소 삭제 | iterator가 가리키는 부분의 원소 삭제
a.pop_front();
a.pop_back();
a.erase(iterator);
// beginning iterator 리턴 | end iterator 리턴
a.begin();
a.end();
// 첫 번째 데이터 리턴 | 마지막 데이터
a.front();
a.back();
// 리스트가 비어 있는지 확인 -> 비어있다면 true 리턴
a.empty();
// 리스트 사이즈 리턴
a.size();
```

</br>

## STL vector

``` cpp
//vector 헤더파일 추가
#include <vector>
// 비어있는 vector 생성
vector<int> v;
// 백터 시작점의 주소 값 반환 | 백터 (끝부분 + 1) 주소값 반환 | 백터의 끝 지점을 시작점으로 반환 | 백터의 (시작 + 1) 지점을 끝 부분으로 반환
v.begin();
v.end();
v.rbegin(); // resers begin
v.rend(); //revers end
// 백터의 i번째 데이터 접근(범위 검사 o) | 백터의 i번째 데이터 접근(범위 검사 x) | 백터의 첫번째 데이터 접근 | 백터의 마지막 데이터 접근
v.at(i);
v.[i]; // operator []
v.front();
v.back();
// 리스트의 마지막 부분에 데이터를 추가/삭제, insert, erase는 똑같다.
// 사용자가 원하는 위치에 데이터 삽입 (move로 인해 복사생성자 x) | 백터의 마지막 부분에 새로운 데이터 추가 (move로 인해 복사생성자 x)
v.emplace(iterator, x);
v.emplace_back();
// 백터의 모든 데이터를 지움 (return size = 0)
v.clear();
// 백터의 사이즈를 조정한다. (범위 초과시 0으로 초기화)
v.resize();
// 백터와 백터를 스왑한다.
v.swap(v1);
// 이 외에도 리스트와 동일하게 비어있는지 확인하는 함수와 백터의 크기를 리턴하는 함수가 존재한다.
// heap에 할당된 백터의 실제크기(최대크기) 리턴 | 백터가 시스템에서 반들어질 수 있는 최대 크기 리턴
v.capacity();
v.max_size();
// 백터의 크기 설정 | capacity의 크기를 백터의 실제 크기에 맞춤
v.reserve(숫자);
v.shrink_to_fit();
```

</br>

# 2️⃣ Stack?

## Stack 특징

- LIFO(Last-In-First-Out) : 나중에 넣은 데이터가 먼저 나오는 구조
- 데이터를 push 하면 항상 top에  들어가고, pop하면 가장 최근에 push한 데이터(top에 있는 데이터)가 나온다.
- 맨 위 요소만 접근 가능
</br>

## 시간복잡도

- 삽입/삭제하는 경우 : O(1)

## STL stack

``` cpp
// <stack> 헤더 추가
#include <stack> 
// s라는 이름의 빈 stack 생성
stack<int> s;
// 스택이 비어있는지 확인 - 비어있다면 true 반환
s.empty();
// 스택에 존재하는 원소의 수를 반환
s.size();
// 스택 맨 위의 원소를 리턴
s.top();
// 스택에 원소 x 추가
s.push(x);
// 가장 최근에 푸시한 데이터 삭제
s.pop();

```

</br>

# 3️⃣ Queue?

## Queue 특징

- FIFO(First-In-First-Out) : 먼저 넣은 데이터가 먼저 나오는 구조
- 데이터가 push되는 곳을 front, pop되는 곳을 back이라 한다.
</br>

## 시간 복잡도

- 삽입/삭제하는 경우 : O(1)

## STL queue

``` cpp
// <queue> 헤더 추가
#include <queue> 
// s라는 이름의 빈 queue 생성
queue<int> q;
// 큐가 비어있는지 확인 - 비어있다면 true 반환
q.empty();
// 큐에 존재하는 원소의 수를 반환
q.size();
// 제일 최상위 데이터를 리턴
q.front();
// 큐에 데이터 x 추가
q.push(x);
// 가장 최근에 푸시한 데이터 삭제
q.pop();

```

</br>

# 4️⃣ Priority_Queue?

## Priority_Queue 특징

- 일반적인 큐(Queue)는 FIFO 구조이다. 그러나 우선순위 큐(Priority Queue)는 들어간 순서에 상관없이 우선순위가 높은 데이터가 먼저 나온다.
- 우선순위 큐는 힙(Heap)이라는 자료구조를 가지고 구현할 수 있다.

## Heap

1. 힙은 CBT(Complete Binary Tree, 완전 이진 트리)이다.
2. 모든 노드에 저장된 값(우선순위)들은 자식노드들의 것보다 (우선순위가) 크거나 같다.
3. 힙에 저장된 노드를 뺄 때마다 우선순위가 높은 데이터 먼저 빠져나오게 된다.

+) 직접 연결된 자식-부모 노드 간의 크기만 비교하면 된다. 입으로 우선순위 큐를 구현할 때에는 노드에 저장된 값을 우선순위로 본다.

</br>

### Max Heap

- CBT이면서, 루트 노드로 올라갈 수록 저장된 값이 커지는 구조이다.
- 우선순위는 값이 큰 순서대로 매긴다.

### Min Heap

- CBT이면서, 루트 노드로 올라갈 수록 값이 작아지는 구조이다.
- 우선순위 값이 작은 순서대로 매긴다.

+) Max Heap이던 Min Heap이던 루트 노드에는 우선순위가 높은 것이 자리잡게 된다.

</br>

## 시간 복잡도

- 삽입 / 삭제하는 경우 : 힙의 높이만큼 -> O(h) = O(lon2 n)

## STL priority_queue

``` cpp
// priority_queue는 queue 헤더파일에서 제공한다.
#include <queue>
// priority_queue 선언하기, 기본적으로 우선순위 큐는 Max Heap으로 구성되어 있다. (자료형만 작성시 모두 기본형으로 선언됨)
priority_queue<int> pq;
// Container는 벡터와 같은 컨테이너를 말하고, Compare는 비교 함수이다.
priority_queue<자료형, Container<자료형>, Compare>
// Min Heap으로 선언하기 예시
priority_queue<int, vector<int>, greater<int>> pq;
// c++14 버전 이후에는 자료형 추론이 가능해서, 마지막 operator를 grater<>와 같이 자료형을 명시해서 적어주지 않아도 컴파일이 가능한다. (그러나 자료형을 명시해주는 것이 안전함)
```
