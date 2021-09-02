# 🖇 2021 2학기 1주차 - 자료구조

## 1️⃣ List?

---

</br>

## 2️⃣ Stack?

---

### 특징

- LIFO(Last-In-First-Out) : 나중에 넣은 데이터가 먼저 나오는 구조
- 데이터를 push 하면 항상 top에  들어가고, pop하면 가장 최근에 push한 데이터(top에 있는 데이터)가 나온다.
- 맨 위 요소만 접근 가능
</br>

### 시간복잡도

- 삽입/삭제하는 경우 : O(1)

### STL stack

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

## 3️⃣ Queue?

---

### 특징

- FIFO(First-In-First-Out) : 먼저 넣은 데이터가 먼저 나오는 구조
- 데이터가 push되는 곳을 front, pop되는 곳을 back이라 한다.
</br>

### 시간 복잡도

- 삽입/삭제하는 경우 : O(1)

</br>

## 4️⃣ Priority_Queue?

---
