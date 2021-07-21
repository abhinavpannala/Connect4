#ifndef PAIR_H
#define PAIR_H

class Pair{
    private:
        int a;
        int b   
    public:
        Pair();
        Pair(int,int);
        Pair operator=(cont Pair);
        Pair(Pair);
        int get_a();
        void set_a(int);
        int get_b();
        void set_b(int);       
};
#endif
