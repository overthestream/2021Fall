#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n - 1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int result = 1;
    int max = arr[n - 1];
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > max){
            result++;
            max = arr[i];
        }
    }

    cout << result;
}
