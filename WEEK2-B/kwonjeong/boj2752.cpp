// BOJ 2752번 : 세수정렬
#include <iostream>
using namespace std;

int main() {
    int arr[3];
    for(int i = 0; i < 3; i++)
        cin >> arr[i];

    for(int i = 0; i < 3; i++){
        int min = i;
        for(int j = i + 1; j < 3; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(int i = 0; i < 3; i++)
        cout << arr[i] << " ";


    return 0;
}
