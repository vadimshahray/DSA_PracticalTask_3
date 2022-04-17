#ifndef H_SORT_TREE
#define H_SORT_TREE

#include "tree.h"

struct sort_tree
{
private:
   tree *root = NULL;

public:
   bool push(int e);
   void clear();
};

#endif // !H_SORT_TREE