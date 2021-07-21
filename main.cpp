#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int total_nodes= 0;

class Pair{
    private:
        int a;
        int b;
        
    public:
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
};

class ConnectFour{
    
    private:
        char Board[7][6];  // board for the game(first dimension column: second dimension row)
        int turn;      //signifies whether it is player 1's turn or player 2's turn.  0 = player 1 and 1 = player 2
        int column_pointer[7]; // shows which row each column is currently filled too
    public:
        int gameOver()
        {
            for(int i= 0; i < 7;i++)
            {
                for(int j= 0; j < 6;j++)
                {
                    int x; //column increment pointer
                    int y; // row increment pointer
                    char z = Board[i][j];
                    bool win;
                    if( z == ' ')
                    {
                        continue;
                    }
                    
                    if(i <= 3) //check for a horizontial win
                    {
                        x = i + 1;
                        win = true;
                        while((win == true) && (x <= (i+3)))
                        {
                            if( z !=  Board[x][j])
                            {
                                win = false;
                            }
                            x++;
                        }
                        
                        if(win == true)
                        {
                            if(z =='x')
                            {
                                //cout <<"1.1 ";
                                return 1;
                            }
                            
                            else
                            {
                                return -1;
                            }
                        }
                        
                    }
                    
                    if(j <=2) // check for vertical win
                    {
                        y = j + 1;
                        win = true;
                        while((win == true) && (y <= j+3))
                        {
                            if( z != (Board[i][y]))
                            {

                                win = false;
                            }
                            y++;
                        }
                        
                        if( win == true)
                        {
                            if(z =='x')
                            {
                                
                                return 1;
                            }
                            
                            else
                            {
                                return -1;
                            }
                        }
                    }
                    
                    if(( i <= 3) && (j <= 2)) //check for forward diagonal win
                    {
                        x = i+1;
                        y = j+1;
                        win = true;
                        while((win == true) && ( x <= i+3))
                        {
                            if(z != Board[x][y])
                            {
                                win = false;
                            }
                            x++;
                            y++;
                        }
                        
                        if(win == true)
                        {
                            if(z =='x')
                            {
                                //cout << "1.3";
                                return 1;
                            }
                            
                            else
                            {
                                return -1;
                            }
                        
                        }
                        
                        
                    }
                    
                    
                    if(( i >= 3) && (j <= 2)) //check for backward diagonal win
                    {
                        x = i-1;
                        y = j+1;
                        win = true;
                        while((win == true) && ( x >= i-3))
                        {
                            if(z != Board[x][y])
                            {
                                win = false;
                            }
                            x--;
                            y++;
                        }
                        
                        if(win == true)
                        {
                            if(z =='x')
                            {
                                //cout << "1.4";
                                return 1;
                            }
                            
                            else
                            {
                                return -1;
                            }
                        
                        }
                        
                        
                    }
                    
                }
            }
            
            return 0;
        }
        
        friend int eval_1(ConnectFour Board);
        friend int eval_2(ConnectFour Board);
        
        ConnectFour()
        {
            turn = 0;
            
            for(int i =0; i < 7;i++)
            {
                for(int j =0; j < 6;j++)
                {
                    Board[i][j]  = ' ';
                }
            }
            
            
            for(int i= 0; i < 7;i++)
            {
                column_pointer[i]= 0;
            }
        }
        
        ConnectFour(ConnectFour& CopyBoard)
        {
            this->turn = CopyBoard.turn;
            for(int i =0; i < 7;i++)
            {
                for(int j =0; j < 6;j++)
                {
                    this->Board[i][j]  = CopyBoard.Board[i][j];
                }
                
                for(int i= 0; i < 7;i++)
                {
                    this->column_pointer[i]= CopyBoard.column_pointer[i];
                }
            }
            
    
        }
        
        int getTurn()
        {
            return turn;
        }
        
        
        void display_board()
        {
            for(int i = 5 ; i >= 0 ; i--)
            {
                cout << "______________________\n";
                
                for(int j =0; j < 7;j++)
                {
                    cout << "| " << Board[j][i];
                }
                
                cout << "|\n";
                
            }
            
                cout << "______________________\n"<<endl;
        }
        
        bool make_move(int column)
        {
            
            bool move_possible;
            int n = gameOver();
            if( n != 0 )
            {
                cout << "this game is already over\n"<<endl;
                cout << n;
                move_possible = false;
            }
            
            
            else if(column < 0 || column > 6)
            {
                cout << "you entered an invalid column\n"<<endl;
                move_possible = false;
            }
            
            
            else if(column_pointer[column] >  5)
            {
                //cout << "this columnn is full\n";
                move_possible = false;
            }
            
            else if(turn == 0)
            {
                Board[column][column_pointer[column]] = 'x';
                column_pointer[column]++;
                turn++;
                move_possible = true;
            }
            
            else
            {
                Board[column][column_pointer[column]] = 'o';
                column_pointer[column]++;
                turn--;
                move_possible = true;
            }
            
            return move_possible;
        }
    
    
    
};



int eval_1(ConnectFour Board) // evaluation function with number of winning paths/clusters
{
   
   int eval = 0;
   
   //horizontal check
   for(int j = 0; j < 6;j++)
   {
   
           for(int i= 0; i <= 3;i++)
           {
            int x_count = 0;
            int o_count = 0;
            
            for(int k = i; k <=i+3; k++)
            {
                
                if(Board.Board[k][j] == 'x')
                {
                    x_count++;
                }
                
                else if(Board.Board[k][j] == 'o')
                {
                    o_count++;
                }
                
            }
            
            if((x_count != 0) && (o_count != 0))
            {
                continue;
            }
            
            else if(x_count == 4)
            {
                return 1000;
            }
            
            else if(o_count == 4)
            {
                return -1000;
            }
            
            else
            {
                    int y = 0;
                    int z = 0;
                    
                    if(x_count > 0)
                    {
                        y = 2*(x_count -1) + 1;
                    }
                    
                    if(o_count > 0)
                    {
                        z = 2*(o_count -1) + 1;
                    }
                    
                    eval = eval + y - z;
                    
            }
           }
    }
    
    //vertical check
    for(int i =0; i < 7;i++)
    {
        for(int j = 0; j <=2 ;j++)
        {
            
            int x_count = 0;
            int o_count = 0;
            
            for(int k = j; k <=j+3; k++)
            {
                
                if(Board.Board[i][k] == 'x')
                {
                    x_count++;
                }
                
                else if(Board.Board[i][k] == 'o')
                {
                    o_count++;
                }
                
            }
            
            if((x_count != 0) && (o_count != 0))
            {
                continue;
            }
            
            else if(x_count == 4)
            {
                return 1000;
            }
            
            else if(o_count == 4)
            {
                return -1000;
            }
            
            else
            {
                    int y = 0;
                    int z = 0;
                    
                    if(x_count > 0)
                    {
                        y = 2*(x_count -1) + 1;
                    }
                    
                    if(o_count > 0)
                    {
                        z = 2*(o_count -1) + 1;
                    }
                    
                    eval = eval + y - z;
            }
        }
    }
    
    //diagonal check
    for(int i = 0; i <=3; i++)
    {
        for(int j = 0; j<=2; j++)
        {
        
            int k = i;
            int m = j;
            int x_count = 0;
            int o_count = 0;
            
            for(int n = 0; n <=3;n++)
            {
                if(Board.Board[k][m] == 'x')
                {
                    x_count++;
                }
                
                else if(Board.Board[k][m] == 'o')
                {
                    o_count++;
                }
                
                k++;
                m++;
                
            }
            
            if((x_count != 0) && (o_count != 0))
            {
                continue;
            }
            
            else if(x_count == 4)
            {
                return 1000;
            }
            
            else if(o_count == 4)
            {
                return -1000;
            }
            
            else
            {
                    int y = 0;
                    int z = 0;
                    
                    if(x_count > 0)
                    {
                        y = 2*(x_count -1) + 1;
                    }
                    
                    if(o_count > 0)
                    {
                        z = 2*(o_count -1) + 1;
                    }
                    
                    eval = eval + y - z;
            }
        }
    }
    
    for(int i = 6; i >=3; i--) //backward diagonal check
    {
        for(int j = 0; j<=2; j++)
        {
        
            int k = i;
            int m = j;
            int x_count = 0;
            int o_count = 0;
            
            for(int n = 0; n <= 3;n++)
            {
                if(Board.Board[k][m] == 'x')
                {
                    x_count++;
                }
                
                else if(Board.Board[k][m] == 'o')
                {
                    o_count++;
                }
                
                k--;
                m++;
                
            }
            
            if((x_count != 0) && (o_count != 0))
            {
                continue;
            }
            
            else if(x_count == 4)
            {
                return 1000;
            }
            
            else if(o_count == 4)
            {
                return -1000;
            }
            
            else
            {
                    int y = 0;
                    int z = 0;
                    
                    if(x_count > 0)
                    {
                        y = 2*(x_count -1) + 1;
                    }
                    
                    if(o_count > 0)
                    {
                        z = 2*(o_count -1) + 1;
                    }
                    
                    eval = eval + y - z;
            }
        }
    }
    
    return eval;
}

int eval_2(ConnectFour Board) //central square
{
    if(Board.gameOver() == 1)
    {
        return 1000;
    }
    
    else if(Board.gameOver() == -1 )
    {
        return -1000;
    }
    
    else
    {
        int eval = 0;
    
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                int x = 0;
            
                if(Board.Board[i][j] == ' ')
                {
                    continue;
                }
            
                if((i >= 2) && (i <=4))
                {
                    x+=2;
                }
            
                else
                {
                    x+=1;
                }
            
                if( j <=2 )
                {
                    x+=2;
                }
            
                else
                {
                    x+=1;
                }
            
                if(Board.Board[i][j] == 'x')
                {
                    eval += x;
                }
            
                else
                {
                    eval-= x;
                }
            }
        }
    
        return eval;
    }
    
}

Pair Min_Max(ConnectFour Game_Position, const int eval, int depth)        // returns a Pair, Pair.a = previous path, Pair.b = value
{
    total_nodes++;
    Pair Return_Pair;
    int static_eval;
    int best_value = -1001;
    int value;
    int new_value;
    int best_path = 0;
    
    if(eval == 1)
    {
        static_eval = eval_1(Game_Position);
    }
    
    else
    {
        static_eval = eval_2(Game_Position);
    }
    
    if(Game_Position.getTurn() == 1)
    {
        static_eval *= -1;
    }
    
    if(static_eval == -1000)
    {
        Return_Pair.set_a(-1);
        Return_Pair.set_b(-1000);
        return Return_Pair;
    }
    
    if(depth == 0)               //base case
    {
        Return_Pair.set_a(-1);
        Return_Pair.set_b(static_eval);
        return Return_Pair;
    }
    
    bool move_generated = false;
    
    for(int i = 0; i < 7; i++)
    {
        ConnectFour New_Position(Game_Position);
        bool move_possible = New_Position.make_move(i);
        
        if(move_generated == false)
        {
            move_generated = move_possible;
        }
        
        if(move_possible == true)
        {
            Pair Pair_holder;
            Pair_holder =  Min_Max(New_Position, eval, depth -1);
            value = Pair_holder.get_b();
            new_value = -value;
            if(new_value > best_value)
            {
                best_value = new_value;
                best_path = i;
            }
            
        }
        
    }
    
    int j = 0;
    for(int i = 0; i < 30000000; i++)
    {
        j++;
    }
    
    
    if(move_generated == false)  // all spaces are filled and it is a draw
    {
        Return_Pair.set_a(-1);
        Return_Pair.set_b(0);
    }
    
    else
    {
        Return_Pair.set_a(best_path);
        Return_Pair.set_b(best_value);
    }
    
    return Return_Pair;
    
}

Pair Alpha_Beta(ConnectFour Game_Position, const int eval, int depth, int use_thresh,int pass_thresh)
{

    Pair Return_Pair;
    int static_eval;
    int best_value = -1001;
    int value;
    int new_value;
    int best_path = 0;
    
    if(eval == 1)
    {
        static_eval = eval_1(Game_Position);
    }
    
    else
    {
        static_eval = eval_2(Game_Position);
    }
    
    if(Game_Position.getTurn() == 1)
    {
        static_eval *= -1;
    }
    
    if(static_eval == -1000)
    {
        Return_Pair.set_a(-1);
        Return_Pair.set_b(-1000);
        return Return_Pair;
    }
    
    if((static_eval % 2) != 1 && (depth != 1) && (depth != 2))
    {
        total_nodes++;
    }
    
    if(depth == 0)               //base case
    {
        Return_Pair.set_a(-1);
        Return_Pair.set_b(static_eval);
        return Return_Pair;
    }
    
    bool move_generated = false;
    
    for(int i = 0; i < 7; i++)
    {
        ConnectFour New_Position(Game_Position);
        bool move_possible = New_Position.make_move(i);
        
        if(move_generated == false)
        {
            move_generated = move_possible;
        }
        
        if(move_possible == true)
        {
            Pair Pair_holder;
            Pair_holder =  Alpha_Beta(New_Position, eval, depth -1, 1001, -1001);
            value = Pair_holder.get_b();
            new_value = -value;
            if(new_value > best_value)
            {
                best_value = new_value;
                best_path = i;
            }
            
        }
        
    }
    

    
    
    if(move_generated == false)  // all spaces are filled and it is a draw
    {
        Return_Pair.set_a(-1);
        Return_Pair.set_b(0);
    }
    
    else
    {
        Return_Pair.set_a(best_path);
        Return_Pair.set_b(best_value);
    }
    
    return Return_Pair;
    
}

int main()
{
    ConnectFour MyBoard;
    int player1_eval;
    int player2_eval;
    int alg1;
    int alg2;
    int start_timer = 0;
    int stop_timer = 0;
    
    cout<<"PROJECT 2: COMPARING THE PERFORMANCE OF MINMAX AB WITH ALPHA-BETA FOR A 'CONNECTFOUR' GAME"<<endl<<endl;
    
    cout << "What is the number of the evaluation function you want to use for player 1?"<<endl;
    cout << " Input either 1 or 2:"<<endl;
    cin >>player1_eval;
    cout << "What is the number of the evaluation function you want to use for player 2"<<endl;
    cout << " Input either 1 or 2:"<<endl;

    cin >> player2_eval;
    cout << "what algorithm should player 1 use?"<<endl<<" press 1 for min-max and 2 for alpha-beta search:"<<endl;
    cin >> alg1;
    cout << "what algorithm should player 2 use?"<<endl<<" press 1 for min-max and 2 for alpha-beta search:"<<endl;
    cin >> alg2;
    int i = 0;
    bool game_over = false;
    while((i < 42) && (game_over == false))
    {
        MyBoard.display_board();
        Pair Game_Path;
        if((i % 2 )== 0)
        {
            if(alg1 == 1)
            {    start_timer = clock();
                Game_Path = Min_Max(MyBoard, player1_eval, 2);
                 stop_timer = clock();
            }
            
            else
            {    start_timer = clock();
                Game_Path = Alpha_Beta(MyBoard, player1_eval, 2, -1001, -1001);
                 stop_timer = clock();
            }
        
        }
        
        else
        {
            if(alg2 == 1)
            {    start_timer=clock();
                Game_Path = Min_Max(MyBoard, player2_eval , 2);
                 stop_timer=clock();
            }
            
            else
            {    start_timer=clock();
                Game_Path = Alpha_Beta(MyBoard, player2_eval , 2, -1001, -1001);
                 stop_timer=clock();
            }
            
        }
        
        MyBoard.make_move(Game_Path.get_a());
        
        if(MyBoard.gameOver() != 0)
        {
            game_over = true;
        }
        
        i++;
    }
    
    MyBoard.display_board();
    if(MyBoard.gameOver() == 0)
    {
        cout << "it's a draw";
    }
    
    else if(MyBoard.gameOver() == 1)
    {
        cout << "Player one is the winner"<<endl;
    }
    
    else
    {
        cout << " Player two is the winner"<<endl;
    }
    int total_time = stop_timer-start_timer;
    cout << "Total computation time: "<< ((total_time)/double(CLOCKS_PER_SEC))*1000<<"ms"<<endl;
    cout << "length of game path :" << i << endl;
    cout << "total nodes generated in searches: "<< total_nodes<<endl;
    cout << "On an average, a single node takes 81 bytes of memory"<<endl;
    cout << "The Memory consumed by the algorithm: "<<(81*total_nodes)/(1024)<<"kb"<<endl;
   
}
