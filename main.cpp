#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int total_nodes= 0;
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
