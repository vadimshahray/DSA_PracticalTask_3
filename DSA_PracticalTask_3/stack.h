#ifndef H_STACK
#define H_STACK

#include "item.h"

template <typename T>
struct stack
{
   private:
   item<T> *_top = NULL;

   public:
   /// <summary>
   /// ��������� ������� e � ����
   /// </summary>
   void push(T *e);

   /// <summary>
   /// ����������� ������� ������� �� �����
   /// </summary>
   void pop();

   /// <summary>
   /// ���������� ������� ������� �����
   /// </summary>
   T *top();

   /// <summary>
   /// ���������, ������ �� ����
   /// </summary>
   bool empty();

   /// <summary>
   /// ������� ����
   /// </summary>
   void clear();
};

#endif // !H_STACK