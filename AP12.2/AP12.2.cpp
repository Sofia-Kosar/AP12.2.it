#include <iostream>
#include <windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info  info;
};

void Input(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info Delete(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

void DeleteAfter(Elem*& first, Info value)
{
    Elem* a = first;
    Elem* b = NULL;

    while (a != NULL && a->info != value)
    {
        a = a->link;
    }

    while (a != NULL && a->link != NULL)
    {
        b = a->link;
        a->link = b->link;
        delete b;
    }
}
void PrintList(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << " ";
        first = first->link;
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;
    int n;
    cout << "¬вед≥ть к≥льк≥сть елемент≥в: ";
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        int value;
        cout << "¬вед≥ть значенн€ " << i << "-го елемента: ";
        cin >> value;
        Input(first, last, value);
    }

    int value;
    cout << "¬вед≥ть значенн€, п≥сл€ €кого будуть видален≥ елементи: ";
    cin >> value;

    DeleteAfter(first, value);

    cout << "«м≥нений список: ";
    PrintList(first);

    return 0;
}
