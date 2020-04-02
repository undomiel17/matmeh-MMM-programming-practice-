#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
int main()
{
setlocale(LC_ALL, "Rus");
struct Bio man1= { "Андреев Вадим Сергеевич", "20.01.1989", "муж", "Москва", "женат", "СПбГу, хим-фак", "89693475490", "andreeeeev58@gmail.com", "спорт, театр", "сантехник"  };
const char* path;
path="notebook.txt";
put_on_file (man1, path);
get_from_file (man1, path);
    return 0;
}
