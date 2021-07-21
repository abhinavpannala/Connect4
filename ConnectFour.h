#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
class ConnectFour{
    private:
        char Board[7][6];  // board for the game(first dimension column: second dimension row)
        int turn;      //signifies whether it is player 1's turn or player 2's turn.  0 = player 1 and 1 = player 2
        int column_pointer[7]; // shows which row each column is currently filled too
    public:
        friend int eval_1(ConnectFour Board);
        friend int eval_2(ConnectFour Board);
        ConnectFour();
        ConnectFour(ConnectFour&);
        int getTurn();
        void display_board();
        bool make_move(int);
        
#endif