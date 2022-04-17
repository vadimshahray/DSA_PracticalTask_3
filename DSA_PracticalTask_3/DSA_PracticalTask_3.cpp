#include <conio.h>
#include <stdio.h>
#include <locale.h>

#include "tree.h"
#include "sort_tree.h"


int main()
{
   setlocale(0, "");

   FILE *f = NULL;
   errno_t err = fopen_s(&f, "in.txt", "r");
   
   if (f)
   {
      tree t;
      t.input(f);

      printf_s(t.contains_repeat() ? "Дерево содержит неуникальные узлы." 
                                   : "Все узлы дерева уникальны.");
   }
   else perror("Не удалось открыть файл");

   return 0 * _getch() + err;
}