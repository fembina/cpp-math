#include <iostream>

using namespace std;

struct Baggage {
    int itemCount;
    double totalWeight;
};

int main() {
    const int n = 10;
    Baggage passengers[n];

    cout << "Введите количество вещей и общий вес для 10 пассажиров:\n";
    for (int i = 0; i < n; i++) {
        cin >> passengers[i].itemCount >> passengers[i].totalWeight;
    }

    // Вычисляем среднее количество вещей
    int sumItems = 0;
    for (int i = 0; i < n; i++) {
        sumItems += passengers[i].itemCount;
    }
    double averageItems = static_cast<double>(sumItems) / n;

    // Считаем пассажиров, у которых количество вещей больше среднего
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (passengers[i].itemCount > averageItems) {
            count++;
        }
    }

    cout << "Число пассажиров, у которых количество вещей превышает среднее: " << count << endl;

    return 0;
}