#include <stdio.h>
#include "tree.h"
#include "stack.h"
#include "sort_tree.h"


bool tree::contains_repeat()
{
   bool contains = false;

   tree *t = this;
   stack<tree> s;
   sort_tree st;

   do
   {
      if (t == NULL) // Долшли до листа
      {
         t = s.top()->right;
         s.pop();
      }

      if (t != NULL)
      {
         contains = !st.push(t->elem);

         s.push(t);
         t = t->left;
      }

   } while (!s.empty() && !contains);

   s.clear();
   st.clear();

   return contains;
}

void tree::input(FILE *f)
{
   if (!f) return;

   int v = 0; // Значение узла
   char c = 0; // Символ, считанный из файла
   stack<tree> s;
   tree *t = this;

   fscanf_s(f, "%d", &t->elem);

   while (fscanf_s(f, "%c", &c, 1) != EOF)
   {
      switch (c)
      {
         case '[':
            s.push(t);
            if (fscanf_s(f, "%d", &v)) // Узел имеет левого потомка
               t = t->left = new tree(v); break;
         case ',':
            fscanf_s(f, "%d", &v); // Считываем правого потомка
            t = s.top()->right = new tree(v); break;
         default: // Поднимаемся вверх по поддереву
            t = s.top();
            s.pop();
      }
   }
}