#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stack>

using namespace std;

typedef struct
{
    char name[255];
    int count;
    float cost;
    int day;
    int month;
    int year;
}info;

struct Stack
{
    int info;
    Stack* next;
};

int menu();
int addProducts(info*, int);
void showProduct(info*, int);
void showProducts(info*, int);
void writeProductInFile(info*, int, FILE*);
void writeInFile(info*, int);
void lineSearch(info*, int);
int checkInputInt();
void products_QS(info*, int);
void selectionSort(info*, int);
void binary_search(info*, int);
void Quicksort(info*, int);
void push(Stack*&, int);
void pop(Stack*&);



int main()
{

    info* products;
    products = new info[30];

    int counterOfProducts = 0;


    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);

    while (1 == 1 && 1 == 1)
    {
        switch (menu())
        {
        case 1:
            system("cls");
            counterOfProducts = addProducts(products, counterOfProducts);
            break;
        case 2:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов";
            else
                showProducts(products, counterOfProducts);
            break;
        case 3:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов";
            else
                writeInFile(products, counterOfProducts);
            break;
        case 4:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов";
            else
                selectionSort(products, counterOfProducts);
            break;
        case 5:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов";
            else
                products_QS(products, counterOfProducts);
            break;
        case 6:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов";
            else
                lineSearch(products, counterOfProducts);
            break;
        case 7:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов" << endl;
            else
                binary_search(products, counterOfProducts);
            break;
        case 8:
            system("cls");
            if (!counterOfProducts)
                cout << "Нету продуктов" << endl;
            else
                Quicksort(products, counterOfProducts);
            break;
        case 9:
            system("cls");
            return 0;
        default:
            cout << "Введен неправильный вариант" << endl;
            break;
        }

    }
}

int menu()
{
    cout << endl << "Меню:" << endl;
    cout << "1. Добавить новые продукты" << endl;
    cout << "2. Просмотр информации о всех продуктах" << endl;
    cout << "3. Записать информацию в файл" << endl;
    cout << "4. Сортировка выбором продуктов по названию в алфавитном порядке" << endl;
    cout << "5. Быстрая сортировка продуктов в алфавитном порядке" << endl;
    cout << "6. Линейный поиск продуктов хранящихся больше месяца, стоимость которых превышает 100 000 р" << endl;
    cout << "7. Бинарный поиск продуктов хранящихся больше месяца, стоимость которых превышает 100 000 р" << endl;
    cout << "8. Быстрая сортировка продуктов в алфавитном порядке через стеки" << endl;
    cout << "9. Выход" << endl;
    cout << "Выберите один из вариантов: ";
    return checkInputInt();
}

int checkInputInt()
{
    int value;

    while (!scanf_s("%d", &value))
    {
        cout << "Некорректный ввод" << endl;
        rewind(stdin);
    }

    return value;
}

void lineSearch(info* products, int counterOfProducts)
{
    cout << "Введите сегодняшний день, месяц и год числами" << endl;
    int nday, nmonth, nyear;
    cin >> nday >> nmonth >> nyear;
    bool flag = false;

    for (int i = 0;i < counterOfProducts;i++) {
        if (products[i].cost > 1000000) {
            if (nyear == products[i].year)
            {
                if (((nmonth == products[i].month) && (nday > products[i].day)) || (nmonth > products[i].month))
                {
                    cout << products[i].name << endl;
                }
            }

            else {
                if (nyear < products[i].year) {
                    cout << "ERROR!";
                }
                else {
                    if ((nyear - products[i].year) >= 2) {
                        cout << products[i].name;
                    }
                    else {
                        if (nmonth < 12) {
                            cout << products[i].name;
                        }
                        else {
                            if (nday > products[i].day) {
                                cout << products[i].name;
                            }
                        }
                    }
                }
                flag = true;
            }
        }
    }
    if (flag == false) {
        cout << "Такого товара нету(" << endl;
    }
}

int addProducts(info* products, int counterOfProducts)
{
    cout << "Введите наименовае товара" << endl;
    getchar();
    std::cin.getline(products[counterOfProducts].name, 255);

    cout << "Введите количество товара" << endl;
    //	do {
    cin >> products[counterOfProducts].count;
    //	} while (!scanf_s("%d", &products[counterOfProducts].count) || products[counterOfProducts].count < 0);

    cout << "Введите цену товара" << endl;
    //	do {
    cin >> products[counterOfProducts].cost;
    //	} while (!scanf_s("%f", &products[counterOfProducts].cost) || products[counterOfProducts].cost < 0);

    cout << "Введите день поступления товара на склад" << endl;
    //	do {
    cin >> products[counterOfProducts].day;
    //	} while (!scanf_s("%d", &products[counterOfProducts].day) || products[counterOfProducts].day < 0);

    cout << "Введите месяц поступления товара на склад" << endl;
    //	do {
    cin >> products[counterOfProducts].month;
    //	} while (!scanf_s("%d", &products[counterOfProducts].month) || products[counterOfProducts].month < 0);

    cout << "Введите год поступления товара на склад" << endl;
    //	do {
    cin >> products[counterOfProducts].year;
    //	} while (!scanf_s("%d", &products[counterOfProducts].year) || products[counterOfProducts].year < 0);

    counterOfProducts++;
    return counterOfProducts;
}

void showProduct(info* products, int index)
{
    cout << "Название продукта: " << products[index].name << endl;
    cout << "Количество продукта: " << products[index].count << endl;
    cout << "Цена продукта: " << products[index].cost << endl;
    cout << "День поступления продукта на склад: " << products[index].day << endl;
    cout << "Месяц поступления продукта на склад: " << products[index].month << endl;
    cout << "Год поступления продукта на склад: " << products[index].year << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}

void showProducts(info* products, int counterOfProducts)
{
    cout << "-----------------------Инфорамция о всех продуктах-----------------------" << endl;

    for (int i = 0; i < counterOfProducts; i++)
    {
        showProduct(products, i);
    }
}

void writeProductInFile(info* products, int index, FILE* f)
{
    fputs("\nНаименовае продукта: ", f);
    fwrite(&products[index].name, sizeof(strlen(products[index].name)), 1, f);
    fputs("\nКоличество товара: ", f);
    fprintf(f, "%d", products[index].count);
    fputs("\nЦена товара: ", f);
    fprintf(f, "%f", products[index].cost);
    fputs("\nДень поступления на склад: ", f);
    fprintf(f, "%d", products[index].day);
    fputs("\nМесяц поступления на склад: ", f);
    fprintf(f, "%d", products[index].month);
    fputs("\nГод поступления на склад: ", f);
    fprintf(f, "%d", products[index].year);
    fputs("\n-------------------------------------------------------------------------", f);

}

void writeInFile(info* products, int counterOfProducts)
{
    FILE* file;

    char name[20];
    cout << "Введите имя файла: ";
    cin >> name;
    if ((file = fopen(name, "wb")) == NULL)
    {
        cout << "Ошибка при открытии" << endl;
        exit(1);
    }
    fputs("-----------------------Информация о всех продуктах-----------------------", file);

    for (int i = 0; i < counterOfProducts; i++)
    {
        writeProductInFile(products, i, file);
    }
}

int compareWords(char word1[], char word2[]) {
    for (int let = 0; word1[let] != '\0' && word2[let]; let++) {
        if (word1[let] == word2[let]) continue;
        if (word1[let] > word2[let]) return 1;
        else return -1;
    }
    return 0;
}

void selectionSort(info* products, int counterOfProducts) 
{
    for (int i = 0; i < counterOfProducts - 1; i++) {
        int m = i;
        for (int j = i + 1;j < counterOfProducts;j++)
            if (compareWords(products[m].name, products[j].name)) m = j;
            if (i != m) {
                info t = products[m];
                products[m] = products[i];
                products[i] = t;
            }
    }
}


void products_QS(info* products, int counterOfProducts)
{
    int i = 0, j = counterOfProducts - 1;
    int mid = counterOfProducts / 2;

    while (i <= j) {
        while (compareWords(products[i].name, products[mid].name)) i++;
        while (compareWords(products[mid].name, products[j].name)) j--;

        if (i <= j) {
            info buf = products[i];
            products[i] = products[j];
            products[j] = buf;
            i++; j--;
        }
    }

    if (i < counterOfProducts - 1) products_QS(products + i, counterOfProducts - i);
    if (0 < j) products_QS(products, counterOfProducts - j);
}

void push(Stack*& start, int in)
{

    Stack* tool;
    tool = new Stack;
    tool->info = in;
    tool->next = start;
    start = tool;
}

void pop(Stack*& start)

{
    Stack* tool;
    if (start == NULL)
    {
        cout << "Стек пуст\n";
        return;
    }
    tool = start->next;
    delete start;
    start = tool;
}

void partition(info* products, int counterOfProducts)
{
    int i = 0, j = counterOfProducts - 1;
    int mid = counterOfProducts / 2;

    while (i <= j) {
        while (compareWords(products[i].name, products[mid].name)) i++;
        while (compareWords(products[mid].name, products[j].name)) j--;

        if (i <= j) {
            info buf = products[i];
            products[i] = products[j];
            products[j] = buf;
            i++; j--;
        }
    }
}


void Quicksort(info* products, int countOfProducts)
{
    int left = 0, right = countOfProducts - 1, i = 0, j = 0;
    Stack* start = new Stack;
    push(start, right);
    push(start, left);

    while (start != NULL) {
        left = (*start).info;
        right = (*(start->next)).info;
        pop(start);
        pop(start);
    }
    partition(products, countOfProducts);

    if (left < j)
    {
        push(start, j);
        push(start, left);
    }

    if (i < right)
    {
        push(start, right);
        push(start, i);
    }
}

void binary_search(info* products, int counterOfProducts)
{
    cout << "Введите сегодняшний день, месяц и год числами" << endl;
    int nday, nmonth, nyear;
    cin >> nday >> nmonth >> nyear;
    int left = 0, right = counterOfProducts - 1;
    int mid;
    bool flag = false;
    selectionSort(products, counterOfProducts);
           
    mid = (left + right) / 2;
        if (products[mid].cost > 100000) {
            if (nyear == products[mid].year)
            {
                if (((nmonth == products[mid].month) && (nday > products[mid].day)) || (nmonth > products[mid].month))
                {
                    cout << products[mid].name << endl;

                }
            }

            else {
                if (nyear < products[mid].year) {
                    cout << "Нету продуктов!";
                }
                else {
                    if ((nyear - products[mid].year) >= 2) cout << products[mid].name;
                    
                    else {
                        if (nmonth < 12) {
                            cout << products[mid].name;
                        }
                        else {
                            if (nday > products[mid].day) {
                                cout << products[mid].name;
                            }
                        }
                    }
                }
            }
        }
    }



