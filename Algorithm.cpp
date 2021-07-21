#include<Algorithm.h>
#include<ConnectFour.h>
#include<pair.h>
#include<iostream>
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