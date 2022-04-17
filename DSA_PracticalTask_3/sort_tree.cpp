#include "tree.h"
#include "stack.h"
#include "sort_tree.h"


bool sort_tree::push(int e)
{
   if (!root)
   {
      root = new tree(e);
      return true;
   }

   // added - добавлен ли элемент e в дерево, unique - уникален ли элемент e
   bool added = true, unique = true;
   tree *t = root;

   do
   {
      if (e >= t->elem)
      {
         unique = e != t->elem;

         if (added = t->right == NULL)
            t->right = new tree(e);
         else
            t = t->right;
      }
      else
      {
         if (added = t->left == NULL)
            t->left = new tree(e);
         else 
            t = t->left;
      }
   } while(!added);

   return unique;
}

void sort_tree::clear()
{
   if (!this->root) return;

   stack<tree> s;
   tree *t = this->root;

   do
   {
      if (t == NULL) // Дошли до листа
      {
         tree *d = s.top();

         t = d->right;
         s.pop();

         delete d;
      }

      if (t != NULL)
      {
         s.push(t);
         t = t->left;
      }

   } while (!s.empty());
}