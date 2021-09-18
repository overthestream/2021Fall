#include <iostream>
#include <cstdlib>
#define MAX 100000

using namespace std;

class Unit
{
public:
    int real;
    int absNum;
    Unit():real(0), absNum(0) {}

};
class Heap
{
public:

    Unit arr[MAX];//default constructor
    int lastIndex;
    Heap(): lastIndex(0) {}

    void mySwap(Unit * a, Unit * b){ //기본으로 제공되는 std::swap() 알아보자
        Unit temp =*a;
//        printf("temp : %d, %d", temp.real, temp.absNum);
        a->real = b->real;
        a->absNum = b->absNum;
        b->real = temp.real;
        b->absNum = temp.absNum;
    }
    void push(int a)
    {
        arr[lastIndex].real=a; //lastIndex를 lastIndex가 아니라 인덱스로 사용해버렸다.
        arr[lastIndex].absNum = abs(a); //lastIndex인덱스를 절대로 넘어가지 않는다.

        int parent = (lastIndex-1)/2;
        while (arr[parent].absNum > arr[lastIndex].absNum || arr[parent].real > arr[lastIndex].real){//parent >=0 이 조건은 필요가 없는 것이 어짜피 parent는 음수로 내려가지 않는다.

            mySwap(&arr[parent], &arr[lastIndex]);
            lastIndex=parent;
            parent=(parent-1)/2;
        }
        ++lastIndex;
    }
    int pop(){ //뺄 때 절댓값이 같은 경우를 컨트롤 하지말고 넣을 때 real까지 고려해서 넣으면 편하지.
        if (arr[0].real == 0){
            return 0;
        }
        int res = arr[0].real;
        mySwap(&arr[0], &arr[lastIndex]);
        if (lastIndex>=1){
        --lastIndex;
        }
        else{
            arr[0].real=0;
            arr[0].absNum=0;
        }
        return res;

    }
    void printHeap(){
        for (int i=0; i<lastIndex; ++i){
            printf("arr[%d] : %d, %d\n", i, arr[i].real, arr[i].absNum);
        }
    }


};
Heap heap;

int main()
{

    int N;
    scanf("%d", &N);
    while (N--)
    {
        int a;
        scanf("%d", &a);
        if (a!=0){

        heap.push(a);
        }
        else{

            printf("%d\n", heap.pop());
        }
    }





}