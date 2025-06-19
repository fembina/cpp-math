#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    // Поиск подстрок "чя" и "щя" в строке
    if (text.find("чя") != string::npos || text.find("щя") != string::npos) {
        cout << "Ошибка правописания: после 'ч' или 'щ' не может идти 'я'." << endl;
    } else {
        cout << "Ошибок правописания не обнаружено." << endl;
    }

    return 0;
}