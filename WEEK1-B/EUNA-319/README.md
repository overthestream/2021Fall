## 백준 12605 알고리즘 정리 ##
<br>

### 사용한 알고리즘 : STACK ###

- 후입 선출(LIFO: Last-In, First-Out)
- 연산: push(), pop()
- 선형 리스트의 특별한 형태
- 원소들의 리스트로 정의 가능
<br><br>

### STACK의 구현 ###
#### top pointer ####
- 스택에 가장 나중에 삽입된 원소를 가리키며, 그 위치에 해당하는 배열 인덱스 값을 가짐
- 주소값을 갖는 변수 자료형인 포인터와는 다른 포인터
- 0 ~ Upper bound(STACKSIZE-1)의 값을 가질 수 있음
#### push() ####
- 스택이 가득 찬 상태: top >= STACKSIZE -1
- full stack이 아닐 경우: top을 먼저 증가시킨 후, 증가시킨 인덱스에 값을 삽입
#### pop() ####
- empty stack: top<=-1
- empty stack이 아닐 경우: stack 포인터가 가리키는 원소 반환 후 top을 감소시킴
<br><br>

### 문제 풀 때 생각한 flow ###
  ```c++
    com=stack[top--]; // 오른쪽 기준 가장 가까운 막대기의 높이 반환
    count++;
    while(top>-1){
        pre = stack[top--];
        if(com<pre) {// pre가 비교 숫자 com보다 높거나 같다면
            count++; // 개수 증가
            com = pre; // com update
        }
    }
  ```
- 우선 stack에 모든 막대기를 넣는다
- 그 이후 가장 처음으로 pop되는 막대기는 맨 오른쪽에서 무조건 보이므로 count를 증가시킨다
- 하나씩 pop하며 com 변수에 담기는 막대기의 높이와 비교한다 이때 자신보다 높은 막대기가 나오면 com을 그 막대기로 바꾼다<br>
  ** 문제를 풀면서 틀렸던 이유: 제대로 문제를 안읽어서 자신과 같은 높이인 막대기도 그 앞에 더 높은 막대기가 없다면 세는 것으로 인식했다 :( **
  <br><br>

### 새롭게 공부한 내용 ###
- 우선 나는 C언어만으로 코딩문제를 해결해 왔기 때문에 C++로 알고리즘 푸는 것이 익숙해서 우선 문제를 풀고 따로 구글링해서 문제 풀이보다는 관련 개념을 찾아봤다
```c++
1) c++ stl 라이브러리 #include <stack> 사용
   stack<int> s; // int형 스택 생성
2) stack에 push()
   s.push(삽입하고 싶은 원소) // 스택에 원소 삽입
3) stack에서 pop()
   s.pop() // 스택에서 원소 pop
4) top 조회하기
   s.top() // top에 있는 원소를 반환
   // stack의 처음이 아니라는 것에 유의해야 함
5) 스택의 상태
   s.empty() // 스택이 비어있으면 true, 아니면 false를 반환
   s.size() // 스택 사이즈를 반환
```