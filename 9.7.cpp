#include <iostream>
#include <string>
#include <locale>

using namespace std;

bool check_cha_scha(const wstring& text) {
    for (size_t i = 0; i + 1 < text.length(); i++) {
        if ((text[i] == L'ч' || text[i] == L'щ') && text[i + 1] == L'я') {
            return false; // Ошибка правописания
        }
    }
    return true;
}

int main() {
    // Устанавливаем локаль для корректного ввода/вывода Unicode
    locale::global(locale(""));

    wstring text;
    wcout << L"Введите текст: ";
    getline(wcin, text);

    if (check_cha_scha(text)) {
        wcout << L"Ошибок правописания не обнаружено." << endl;
    } else {
        wcout << L"Ошибка правописания: после 'ч' или 'щ' не может идти 'я'." << endl;
    }

    return 0;
}