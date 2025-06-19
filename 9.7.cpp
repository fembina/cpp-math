#include <iostream>
#include <string>

using namespace std;

bool check_cha_scha(const string& text) {
    for (size_t i = 0; i + 1 < text.length(); i++) {
        if ((text[i] == 'ч' || text[i] == 'щ') && text[i + 1] == 'я') {
            return false; // Ошибка правописания обнаружена
        }
    }
    return true; // Ошибок не найдено
}

int main() {
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    if (check_cha_scha(text)) {
        cout << "Ошибок правописания не обнаружено." << endl;
    } else {
        cout << "Ошибка правописания: после 'ч' или 'щ' не может идти 'я'." << endl;
    }

    return 0;
}