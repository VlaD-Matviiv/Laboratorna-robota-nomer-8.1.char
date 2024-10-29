// Lab 8.1
// Функції рядків char

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;


bool Include(const char* s, const char* cs)
{
    while (*cs)
    {
        if (strchr(s, *cs) == nullptr)
            return false; 
        cs++;
    }
    return true; 
}


char* Change(const char* s)
{
    size_t length = strlen(s);
    char* t = new char[length * 2 + 1]; 
    t[0] = '\0'; 
    const char* p = s;

    while (*p)
    {
        if (strncmp(p, "while", 5) == 0)
        {
            strcat(t, "**"); 
            p += 5; 
        }
        else
        {
            strncat(t, p, 1); 
            p++; 
        }
    }
    return t; 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char str[101];
    cout << "Введіть рядок: ";
    cin.getline(str, sizeof(str));

    const char* cs = "while";
    if (Include(str, cs))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    char* modifiedString = Change(str); 
    cout << "Змінений рядок: " << modifiedString << endl;

    delete[] modifiedString; 
    return 0;
}

