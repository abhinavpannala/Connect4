#include <pair.h>
#include <iostream>
Pair()
        {
            a = -1;
            b= -1;
        }
Pair(int i_a, int i_b)
        {
            a= i_a;
            b = i_b;
        }
Pair operator=(const Pair &Copy_Pair)
        {
            this->a = Copy_Pair.a;
            this->b = Copy_Pair.b;
            return *this;
        }
Pair(Pair &Copy_Pair)
        {
            this->a = Copy_Pair.a;
            this->b = Copy_Pair.b;
        }
int get_a()
        {
            return a;
        }
void set_a(int new_a)
        {
             a = new_a;
        }
int get_b()
        {
            return b;
        }
void set_b(int new_b)
        {
            b= new_b;
        }