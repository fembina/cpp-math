#include <iostream>
#include <vector>

using namespace std;

// Функция для поиска максимума в массиве
int findMax(const vector<int>& arr) {
    int maxVal = arr[0];

    for (int val : arr) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    
    return maxVal;
}

int main() {
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxValue = findMax(arr);

    cout << "Максимальный элемент массива: " << maxValue << endl;

    return 0;
}