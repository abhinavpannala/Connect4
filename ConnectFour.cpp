#include<ConnectFour.h>
#include<iostream>
int gameOver();
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
                            {}                             
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
//1st evaluation function
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
//2nd Evaluation Funciton
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