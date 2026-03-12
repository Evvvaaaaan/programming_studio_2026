#include <iostream>
using namespace std;

void my_sort(int arr[], int size) {
    for(int i = 0; i < size -1 ; i++ ) {
        for(int j =0; j < size - 1 -i; j++ ) {
            if(arr[j]> arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
} 

int main() {
    int list[10] = {23, 11, 15, 8, 17, 33, 7, 14, 19, 21};
    int i;
        my_sort(list, 10);
        for(i = 0; i < 10; i++ ) {
            cout << list[i] << "\n";
        }
    return 0;


}
