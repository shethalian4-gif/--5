#include <iostream>
using namespace std;

// Функция извлекает цифровые слова, разделённые цифрой '0',
// и записывает их через запятую в круглых скобках.
void extractWords(const char row[], char result[], int maxLength)
{
    int pos = 0;
    int wordStart = 0;
    bool firstWord = true;

    result[pos++] = '(';

    for (int i = 0; ; i++)
    {
        if (row[i] == '0' || row[i] == '\0')
        {
            // Если между разделителями есть символы, это отдельное слово.
            if (i > wordStart)
            {
                if (!firstWord && pos < maxLength - 2)
                    result[pos++] = ',';

                for (int j = wordStart; j < i && pos < maxLength - 2; j++)
                    result[pos++] = row[j];

                firstWord = false;
            }

            if (row[i] == '\0')
                break;

            wordStart = i + 1;
        }
    }

    if (pos < maxLength - 1)
        result[pos++] = ')';

    result[pos] = '\0';
}

int main()
{
    const int ROWS = 3;
    const int RESULT_SIZE = 60;

    // Исходный двумерный массив.
    char data[ROWS][16] =
    {
        "123023402303450",
        "234450234567010",
        "234455677670450"
    };

    char result[RESULT_SIZE];

    cout << "Результат обработки массива:" << endl;

    for (int i = 0; i < ROWS; i++)
    {
        extractWords(data[i], result, RESULT_SIZE);
        cout << result << endl;
    }

    return 0;
}
