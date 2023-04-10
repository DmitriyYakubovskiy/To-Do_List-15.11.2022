#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <chrono>
#include <thread>
#include <ctype.h>
using namespace std;
time_t now = time(0);
tm* ltm = localtime(&now);
struct ListDel
{
    string name;
    int priority;
    string description;
    int day;
    int month;
    int year;
    int hours;
    int minutes;
};
map <int, string> Mon = { {1, "Январь"},
{2, "Февраль"},
{3, "Март"},
{4, "Апрель"},
{5, "Май"},
{6, "Июнь"},
{7, "Июль"},
{8, "Август"},
{9, "Сентябрь"},
{10, "Октябрь"},
{11, "Ноябрь"},
{12, "Декабрь"},
};
map <int, int> MonNom = { {1, 31},
{2, 28},
{3, 31},
{4, 30},
{5, 31},
{6, 30},
{7, 31},
{8, 31},
{9, 30},
{10, 31},
{11, 30},
{12, 31},
};
void FillArr(ListDel* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        system("cls");
        cout << "Дело под номером " << i + 1 << endl;
        cout << "Название дела: ";
        cin.seekg(cin.eof());
        getline(cin, arr[i].name);
        cin.seekg(cin.eof());

        char str[256];
        cout << "Приоритет: ";

        cin.seekg(cin.eof());
        cin.getline(str, 256);
        cin.seekg(cin.eof());

        if (atoi(str) != 0 && atoi(str) > 0)
        {
            arr[i].priority = atoi(str);
        }
        else
        {
            system("cls");
            cout << "Неправильный ввод приоритета!" << endl;
            i--;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "3" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "2" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "1" << endl;
            continue;
        }

        cout << "Описание: ";
        cin.seekg(cin.eof());
        getline(cin, arr[i].description);
        cin.seekg(cin.eof());


        cout << "Дата и время";
        cout << "\nВведите день: ";
        cin >> arr[i].day;
        cout << "Введие номер месяца: ";
        cin >> arr[i].month;
        cout << "Введите год: ";
        cin >> arr[i].year;
        cout << "Введите час: ";
        cin >> arr[i].hours;
        cout << "Введите минуты: ";
        cin >> arr[i].minutes;
        if (arr[i].hours > 24 || arr[i].hours < 0 || arr[i].minutes>60 || arr[i].minutes < 0 || arr[i].month>12 || arr[i].month < 1 || arr[i].day>31 || arr[i].day < 1)
        {
            system("cls");
            cout << "Неправильный ввод времени!" << endl;
            i--;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "3" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "2" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "1" << endl;
            continue;
        }
    }
    cout << endl;
}
void Print(ListDel* arr, int size)
{
    system("cls");
    for (int i = 0; i < size; i++)
    {
        cout << "Дело под номером " << i + 1 << endl;
        cout << "Название дела: " << arr[i].name
            << "\nПриоритет: " << arr[i].priority <<
            "\nОписание: " << arr[i].description <<
            "\nДата и время: ";
        if (arr[i].day < 10)
        {
            cout << "0" << arr[i].day << ".";
        }
        else
        {
            cout << arr[i].day << ".";
        }
        if (arr[i].month < 10)
        {
            cout << "0" << arr[i].month << ".";
        }
        else
        {
            cout << arr[i].month << ".";
        }
        cout << arr[i].year << "\t";
        if (arr[i].hours < 10)
        {
            cout << "0" << arr[i].hours;
        }
        else
        {
            cout << arr[i].hours;
        }
        cout << ":";
        if (arr[i].minutes < 10)
        {
            cout << "0" << arr[i].minutes;
        }
        else
        {
            cout << arr[i].minutes;
        }
        cout << "\n\n";

    }
}
void SortArr(ListDel* arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].priority < arr[j + 1].priority)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void SortArrDate(ListDel* arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].year > arr[j + 1].year)
            {
                swap(arr[j], arr[j + 1]);
            }
            else if (arr[j].year == arr[j + 1].year)
            {
                if (arr[j].month > arr[j + 1].month)
                {
                    swap(arr[j], arr[j + 1]);
                }
                else if (arr[j].month == arr[j + 1].month)
                {
                    if (arr[j].day > arr[j + 1].day)
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                    else if (arr[j].day == arr[j + 1].day)
                    {
                        if (arr[j].hours > arr[j + 1].hours)
                        {
                            swap(arr[j], arr[j + 1]);
                        }
                        else if (arr[j].hours == arr[j + 1].hours)
                        {
                            if (arr[j].minutes > arr[j + 1].minutes);
                            {
                                swap(arr[j], arr[j + 1]);
                            }
                        }
                    }
                }
            }
        }
    }
}
void SortArrDay(ListDel* arr, int size, int k)
{

    if (k == 3)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].year == 2022)
            {
                if (arr[i].month == (1 + ltm->tm_mon))
                {
                    if (arr[i].day == (ltm->tm_mday))
                    {
                        cout << "Название дела: " << arr[i].name
                            << "\nПриоритет: " << arr[i].priority <<
                            "\nОписание: " << arr[i].description <<
                            "\nДата и время: ";
                        if (arr[i].day < 10)
                        {
                            cout << "0" << arr[i].day << ".";
                        }
                        else
                        {
                            cout << arr[i].day << ".";
                        }
                        if (arr[i].month < 10)
                        {
                            cout << "0" << arr[i].month << ".";
                        }
                        else
                        {
                            cout << arr[i].month << ".";
                        }
                        cout << arr[i].year << "\t";
                        if (arr[i].hours < 10)
                        {
                            cout << "0" << arr[i].hours;
                        }
                        else
                        {
                            cout << arr[i].hours;
                        }
                        cout << ":";
                        if (arr[i].minutes < 10)
                        {
                            cout << "0" << arr[i].minutes;
                        }
                        else
                        {
                            cout << arr[i].minutes;
                        }
                        cout << "\n\n";
                        k = 0;
                    }
                }
            }
        }
    }


    else if (k == 4)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].year == 2022)
            {
                int e = arr[i].month - MonNom[1 + ltm->tm_mon];
                if (e < 0)
                {
                    if (arr[i].month == (1 + ltm->tm_mon))
                    {

                        if ((arr[i].day >= (ltm->tm_mday) && arr[i].day <= (ltm->tm_mday) + 7))
                        {
                            cout << "Название дела: " << arr[i].name
                                << "\nПриоритет: " << arr[i].priority <<
                                "\nОписание: " << arr[i].description <<
                                "\nДата и время: ";
                            if (arr[i].day < 10)
                            {
                                cout << "0" << arr[i].day << ".";
                            }
                            else
                            {
                                cout << arr[i].day << ".";
                            }
                            if (arr[i].month < 10)
                            {
                                cout << "0" << arr[i].month << ".";
                            }
                            else
                            {
                                cout << arr[i].month << ".";
                            }
                            cout << arr[i].year << "\t";
                            if (arr[i].hours < 10)
                            {
                                cout << "0" << arr[i].hours;
                            }
                            else
                            {
                                cout << arr[i].hours;
                            }
                            cout << ":";
                            if (arr[i].minutes < 10)
                            {
                                cout << "0" << arr[i].minutes;
                            }
                            else
                            {
                                cout << arr[i].minutes;
                            }
                            cout << "\n\n";
                        }
                    }
                    else if (arr[i].month == (1 + ltm->tm_mon) + 1 || arr[i].month == 1)
                    {
                        if ((arr[i].day >= 1 && arr[i].day <= (ltm->tm_mday) + e))
                        {
                            cout << "Название дела: " << arr[i].name
                                << "\nПриоритет: " << arr[i].priority <<
                                "\nОписание: " << arr[i].description <<
                                "\nДата и время: ";
                            if (arr[i].day < 10)
                            {
                                cout << "0" << arr[i].day << ".";
                            }
                            else
                            {
                                cout << arr[i].day << ".";
                            }
                            if (arr[i].month < 10)
                            {
                                cout << "0" << arr[i].month << ".";
                            }
                            else
                            {
                                cout << arr[i].month << ".";
                            }
                            cout << arr[i].year << "\t";
                            if (arr[i].hours < 10)
                            {
                                cout << "0" << arr[i].hours;
                            }
                            else
                            {
                                cout << arr[i].hours;
                            }
                            cout << ":";
                            if (arr[i].minutes < 10)
                            {
                                cout << "0" << arr[i].minutes;
                            }
                            else
                            {
                                cout << arr[i].minutes;
                            }
                            cout << "\n\n";

                        }
                    }
                }
                else
                {
                    cout << "Название дела: " << arr[i].name
                        << "\nПриоритет: " << arr[i].priority <<
                        "\nОписание: " << arr[i].description <<
                        "\nДата и время: ";
                    if (arr[i].day < 10)
                    {
                        cout << "0" << arr[i].day << ".";
                    }
                    else
                    {
                        cout << arr[i].day << ".";
                    }
                    if (arr[i].month < 10)
                    {
                        cout << "0" << arr[i].month << ".";
                    }
                    else
                    {
                        cout << arr[i].month << ".";
                    }
                    cout << arr[i].year << "\t";
                    if (arr[i].hours < 10)
                    {
                        cout << "0" << arr[i].hours;
                    }
                    else
                    {
                        cout << arr[i].hours;
                    }
                    cout << ":";
                    if (arr[i].minutes < 10)
                    {
                        cout << "0" << arr[i].minutes;
                    }
                    else
                    {
                        cout << arr[i].minutes;
                    }
                    cout << "\n\n";

                }
            }
        }
    }


    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i].year == 2022)
            {
                if (arr[i].month == (1 + ltm->tm_mon))
                {
                    if ((arr[i].day >= (ltm->tm_mday) && arr[i].day <= (ltm->tm_mday) + 30))
                    {
                        cout << "Название дела: " << arr[i].name
                            << "\nПриоритет: " << arr[i].priority <<
                            "\nОписание: " << arr[i].description <<
                            "\nДата и время: ";
                        if (arr[i].day < 10)
                        {
                            cout << "0" << arr[i].day << ".";
                        }
                        else
                        {
                            cout << arr[i].day << ".";
                        }
                        if (arr[i].month < 10)
                        {
                            cout << "0" << arr[i].month << ".";
                        }
                        else
                        {
                            cout << arr[i].month << ".";
                        }
                        cout << arr[i].year << "\t";
                        if (arr[i].hours < 10)
                        {
                            cout << "0" << arr[i].hours;
                        }
                        else
                        {
                            cout << arr[i].hours;
                        }
                        cout << ":";
                        if (arr[i].minutes < 10)
                        {
                            cout << "0" << arr[i].minutes;
                        }
                        else
                        {
                            cout << arr[i].minutes;
                        }
                        cout << "\n\n";
                    }
                }
            }
        }
    }

}
void ForDelInArr(ListDel* arr, ListDel* buf, int size, string name)
{
    int k = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].name == name)
            {
                swap(arr[j + 1], arr[j]);
                k++;
            }
        }
    }
    if (k > 0)
    {
        arr[size - 1].day = 35;
    }
    for (int i = 0; i < size - 1; i++)
    {
        buf[i] = arr[i];
    }
}
void AddInArr(ListDel* arr, int size)
{
    for (int i = 0; i < 1; i++)
    {
        system("cls");
        cout << "Дело под номером " << size + 1 << endl;
        cout << "Название дела: ";
        cin.seekg(cin.eof());
        getline(cin, arr[size].name);
        cin.seekg(cin.eof());
        char str[256];
        cout << "Приоритет: ";
        cin.seekg(cin.eof());
        cin.getline(str, 256);
        cin.seekg(cin.eof());

        if (atoi(str) != 0 && atoi(str) > 0)
        {
            arr[size].priority = atoi(str);
        }
        else
        {
            system("cls");
            cout << "Неправильный ввод приоритета!" << endl;
            i--;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "3" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "2" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "1" << endl;
            continue;
        }
        cout << "Описание: ";
        cin.seekg(cin.eof());
        getline(cin, arr[size].description);
        cin.seekg(cin.eof());
        cout << "Дата и время";
        cout << "\nВведите день: ";
        cin >> arr[size].day;
        cout << "Введие номер месяца: ";
        cin >> arr[size].month;
        cout << "Введите год: ";
        cin >> arr[size].year;
        cout << "Введите час: ";
        cin >> arr[size].hours;
        cout << "Введите минуты: ";
        cin >> arr[size].minutes;
        if (arr[size].hours > 24 || arr[size].hours < 0 || arr[size].minutes>60 || arr[size].minutes < 0 || arr[size].month>12 || arr[size].month < 1 || arr[size].day>31 || arr[size].day < 1)
        {
            system("cls");
            cout << "Неправильный ввод!" << endl;
            i--;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "3" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "2" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout << "1" << endl;
        }
        cout << endl;
    }
}
int SearchInArr(ListDel* arr, int size, string name)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].name == name)
        {
            return i;
        }
    }
}
int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введите количество дел: ";
    cin >> size;
    ListDel* arr = new ListDel[size];
    FillArr(arr, size);

    while (true)
    {
        cout << "Введие 1, чтобы вывести список дел\n"
            << "Введие 2, чтобы отсортировать список дел\n"
            << "Введие 3, чтобы показать список на день\n"
            << "Введие 4, чтобы показать список дел на неделю\n"
            << "Введие 5, чтобы показать список дел на " << Mon[(1 + ltm->tm_mon)] << "\n"
            << "Введите 6, чтобы удалить дело\n"
            << "Введите 7, чтобы добавить дело\n"
            << "Введите 8, чтобы изменить дело\n"
            << "Введите 0, чтобы завершить программу\n"
            << ">> ";
        int k;
        cin >> k;
        system("cls");
        if (k == 1)
        {
            Print(arr, size);
        }
        if (k == 2)
        {
            system("cls");
            int vib;
            cout << "Введите 1, чтобы отсортировать по приоритету\n"
                << "Введите 2, чтобы отсортировать по дате\n";
            cout << ">>";
            cin >> vib;
            if (vib == 1)
            {
                SortArr(arr, size);
            }
            if (vib == 2)
            {
                SortArrDate(arr, size);
            }
        }
        if (k == 3)
        {
            cout << "Вывод:\n\n";
            SortArrDay(arr, size, 3);
            cout << endl;
        }
        if (k == 4)
        {
            cout << "Вывод:\n\n";
            SortArrDay(arr, size, 4);
            cout << endl;
        }
        if (k == 5)
        {
            cout << "Вывод:\n\n";
            SortArrDay(arr, size, 5);
            cout << endl;
        }
        if (k == 6)
        {
            Print(arr, size);
            int chet = 0;
            string name;
            cout << "Введите название дела: ";
            cin.seekg(cin.eof());
            getline(cin, name);
            cin.seekg(cin.eof());
            ListDel* buf = new ListDel[size];
            ForDelInArr(arr, buf, size, name);
            if (arr[size - 1].day == 35 || size == 1)
            {
                size = size - 1;
                arr = new ListDel[size];
                for (int i = 0; i < size; i++)
                {
                    arr[i] = buf[i];
                }
                delete[] buf;
            }
            else
            {
                cout << "\nНет такого дела!" << endl;
            }
            cout << endl;
        }
        if (k == 7)
        {
            ListDel* buf = new ListDel[size];
            for (int i = 0; i < size; i++)
            {
                buf[i] = arr[i];
            }
            arr = new ListDel[size + 1];
            for (int i = 0; i < size; i++)
            {
                arr[i] = buf[i];
            }
            AddInArr(arr, size);
            delete[] buf;
            size = size + 1;
        }
        if (k == 8)
        {
            Print(arr, size);
            string name;
            cout << "Введите название дела: ";
            cin.seekg(cin.eof());
            getline(cin, name);
            cin.seekg(cin.eof());
            int g = SearchInArr(arr, size, name);
            if (g >= 0 && g <= size)
            {
                cout << "\nВведите 1, чтобы изменить имя\n" <<
                    "Введите 2, чтобы изменить приоритет\n" <<
                    "Введите 3, чтобы изменить описание\n" <<
                    "Введите 4, чтобы изменить дату и время\n" <<
                    "Введите 5, чтобы все изменить\n>> ";
                int j;
                cin >> j;
                if (j == 1)
                {
                    cout << "Название дела: ";
                    cin.seekg(cin.eof());
                    getline(cin, arr[g].name);
                    cin.seekg(cin.eof());
                }
                if (j == 2)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        char str[256];
                        cout << "Приоритет: ";

                        cin.seekg(cin.eof());
                        cin.getline(str, 256);
                        cin.seekg(cin.eof());

                        if (atoi(str) != 0 && atoi(str) > 0)
                        {
                            arr[g].priority = atoi(str);
                        }
                        else
                        {
                            system("cls");
                            cout << "Неправильный ввод приоритета!" << endl;
                            i--;
                            this_thread::sleep_for(chrono::milliseconds(1000));
                            cout << "3" << endl;
                            this_thread::sleep_for(chrono::milliseconds(1000));
                            cout << "2" << endl;
                            this_thread::sleep_for(chrono::milliseconds(1000));
                            cout << "1" << endl;
                            continue;
                        }
                    }
                }
                if (j == 3)
                {
                    cout << "Описание: ";
                    cin.seekg(cin.eof());
                    getline(cin, arr[g].description);
                    cin.seekg(cin.eof());
                }
                if (j == 4)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        cout << "Дата и время";
                        cout << "\nВведите день: ";


                        cin >> arr[g].day;
                        cout << "Введие номер месяца: ";

                        cin >> arr[g].month;
                        cout << "Введите год: ";
                        cin >> arr[g].year;
                        cout << "Введите час: ";
                        cin >> arr[g].hours;
                        cout << "Введите минуты: ";
                        cin >> arr[g].minutes;
                        if (arr[g].hours > 24 || arr[g].hours < 0 || arr[g].minutes>60 || arr[g].minutes < 0 || arr[g].month>12 || arr[g].month < 1 || arr[g].day>31 || arr[g].day < 1)
                        {
                            cout << "Неправильно введено время!";
                            i--;
                        }
                    }
                }
                if (j == 5)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        cout << "Дело под номером " << g + 1 << endl;
                        cout << "Название дела: ";
                        cin.seekg(cin.eof());
                        getline(cin, arr[g].name);
                        cin.seekg(cin.eof());
                        cout << "Приоритет: ";
                        cin >> arr[g].priority;
                        cout << "Описание: ";
                        cin.seekg(cin.eof());
                        getline(cin, arr[g].description);
                        cin.seekg(cin.eof());
                        cout << "Дата и время";
                        cout << "\nВведите день: ";
                        cin >> arr[g].day;
                        cout << "Введие номер месяца: ";
                        cin >> arr[g].month;
                        cout << "Введите год: ";
                        cin >> arr[g].year;
                        cout << "Введите час: ";
                        cin >> arr[g].hours;
                        cout << "Введите минуты: ";
                        cin >> arr[g].minutes;
                        if (arr[g].hours > 24 || arr[g].hours < 0 || arr[g].minutes>60 || arr[g].minutes < 0 || arr[g].month>12 || arr[g].month < 1 || arr[g].day>31 || arr[g].day < 1)
                        {
                            cout << "Неправильно введено время!";
                            i--;
                        }
                    }
                }
            }
            else
            {
                cout << "\nДелo не найдено!" << endl;
            }
            cout << endl;
        }
        if (k == 0)
        {
            break;
        }
    }
    cout << "Good Bye!";
    delete[]arr;
}
