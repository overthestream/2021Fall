### 선택 정렬
```c
void selection_sort(int num[], int n){
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){ // j에 i의 다음 값을 넣음
            if(num[j] < num[min]) // j가 i보다 작으면
                min = j; // min에 j를 넣음
        }
        temp = num[i]; // i와 min의 자리를 교환
        num[i] = num[min];
        num[min] = temp;

        print_array(num, n);
    }
}
```
- 선택 정렬(selection sort) : 정렬되지 않은 2개 이상의 원소의 집합에서 최소값을 찾아서 정렬 리스트로 이동
***

### 버블 정렬
```c
void bubble_sort(int num[], int n){
    int i, j, swap, temp;

    for(i = 0; i < n - 1; i++){
        swap = 0; // swap 0으로 설정
        for(j = 0; j < n - 1; j++){
            if(num[j] > num[j + 1]){ // j가 j + 1보다 크면
                temp = num[j]; // 위치 바꾸기
                num[j] = num[j + 1];
                num[j + 1] = temp;
                swap = 1; // swap 1로 설정
            }
        }
        if(swap == 0) break; // swap이 0이 되면 멈추고 출력
        print_array(num, n);
    }
}
```
- 버블 정렬(bubble sort) : 항목의 키 값을 풍선에 비유한 것으로 값이 클수록 더 높이 올라감
***
### 삽입 정렬
```c
void insertion_sort(int num[], int n){
    int i, j, pivot;
    for(i = 1; i < n; i++){ // i는 1부터 시작
        pivot = num[i]; // i의 값을 pivot에 넣음
        for(j = i - 1; j >= 0 && pivot < num[j]; j--)
            // j에는 i - 1의 값을 넣고 j가 0보다 같거나 클 때, i의 값이 j보다 크면
            // j + 1에 j 값을 넣음
            num[j + 1] = num[j];

        num[j + 1] = pivot; // 그리고 .j + 1에는 i 값을 넣음
        print_array(num, n);
    }
}
```
- 삽입 정렬(insertion sort) : 이미 정렬되어 있는 서브 리스트에 새로운 원소를 추가하는 과정
***
### 퀵 정렬
```c
void quicksort(int num[], int left, int right){
    int pivot, i, j, temp;
    if(left < right){ // right가 더 클 때
        i = left;
        j = right + 1; // j에 right + 1
        pivot = num[left]; // pivot에는 left 값을 넣음
        do{ // i가 j보다 작을 때 반복
            do{ i++; } while(num[i] < pivot); // i가 pivot보다 작을 때 i 증가
            do{ j--; } while(num[j] > pivot); // j가 pivot보다 클 대 j 증가
            if(i < j){ // i가 j보다 작을 때
                temp = num[i]; // i와 j의 위치 바꿈
                num[i] = num[j];
                num[j] = temp;
                print_array(num, 10);
            }
        } while(i < j);
        // i가 j보다 클 때 위치 바꿈
        temp = num[left]; // left와 j의 위치 바꿈
        num[left] = num[j];
        num[j] = temp;

        if(left != j) print_array(num, 10);
        // j를 기준으로 정렬 범위를 조정하여 왼쪽고 ㅏ오른쪽 서브 리스트에 대해 각각 quicksort 함수 호출
        // 재귀적으로 진행
        quicksort(num, left, j - 1);
        quicksort(num, j + 1, right);
    }
}
```
- 퀵 정렬(quick sort) : 임의의 기준 수(pivot) x를 선택해 정렬 대상 수들을 x 값보다 작은 그룹과 큰 그룹으로 분할
***
### 힙 정렬
```c
void makeheap(int heap[], int root, int n){ // 재정렬할 root, 노드 수
    int child, temp;
    temp = heap[root];
    child = 2 * root; // 왼쪽 자식 노드

    while(child <= n){
        if((child < n) && (heap[child] < heap[child + 1])) // 무엇이 더 큰 것인지
            child++;

        if(temp > heap[child]) // 부모와 자식 노드 중 큰 것 비교
            break;
        else{ // 자식 노드를 부모 위치로 이동
            heap[child / 2] = heap[child];
            child *= 2; // 한 레벨 낮추기
        }
    }
    heap[child / 2] = temp;
}

void heapsort(int heap[], int n){ // 원소 개수
    int i, temp;
    for(i = n / 2; i > 0; i--) // 초기 최대 힙
        makeheap(heap, i, n);

    printheap(heap, 1, n);
    for(i = n - 1; i > 0; i--){ // n - 1 반복
        temp = heap[1]; // max 값을 마지막 원소와 교환
        heap[1] = heap[i + 1];
        heap[i + 1] = temp;
        makeheap(heap, 1, i); // 재정렬할 노드, 노드의 수
        printheap(heap, 1, n);
    }
}
```
- 힙 정렬(heap sort) : 이진 트리의 한 종류인 최대 힙을 이용한 정렬 방법
***
### 합병 정렬
```c
void mergesort(int num[], int left, int right){
    int mid;
    if(right > left){ // 오른쪽이 더 크면
        mid = (right + left) / 2; // 둘을 더해 나눈 값 mid에 저장
        mergesort(num, left, mid); // 재귀 호출
        mergesort(num, mid + 1, right); // left를 mid + 1로 대체해 재귀호출
        merge(num, left, mid + 1, right); // merge 함수
        print_array(num, 9);
    }
}

void merge(int num[], int left, int mid, int right){
    int i, left_end, num_items, tmp_pos;
    int temp[100];

    left_end = mid - 1;
    tmp_pos = left;
    num_items = right - left + 1; // right에서 left 빼고 1 더해 item에 넣음

    while((left <= left_end) && (mid <= right)){ // mid - 1보다 left가 작을 때 && mid가 right보다 작을 때
        if(num[left] <= num[mid]){ // left가 mid보다 작다면
            temp[tmp_pos] = num[left]; // temp에 left 값 넣음
            tmp_pos = tmp_pos + 1; // pos 값 증가
            left = left + 1; // left 값 증가
        }
        else{
            temp[tmp_pos] = num[mid]; // temp에 mid 값 넣음
            tmp_pos = tmp_pos + 1; // pos 값 증가
            mid = mid + 1; // mid 값 증가
        }
    }

    while(left <= left_end){ // left가 left_end 보다 작을 때
        temp[tmp_pos] = num[left]; // 첫번째 세그먼트에 남아있는 항목 추가
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }

    while(mid <= right){ // mid가 right 보다 작을 때
        temp[tmp_pos] = num[mid]; // 두번째 세그먼트에 남아있는 항목 추가
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }

    for(i = 0; i < num_items; i++){
        num[right] = temp[right]; // temp 배열을 num 배열에 복사
        right = right - 1;
    }
}
```
- 합병 정렬(merge sort) : 레코드 리스트를 반으로 나누어 2개의 서브 리스트로 분할하고 각 서브 리스트에 이 과정을 재귀적으로 적용해 더 이상 분할이 불가능할 때까지 반복