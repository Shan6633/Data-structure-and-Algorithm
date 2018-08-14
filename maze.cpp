//
//  maze.cpp
//  counting_sort
//
//  Created by liushan on 8/13/18.
//  Copyright © 2018 liushan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<char>> maze, int x, int y){
    helper(maze, x, y);
}

bool mazefun(vector<vector<char>> maze, int x, int y,int targetX, int targetY,string path){

    if(x<0 || y<0 || x>maze.size()-1 || y>maze[0].size()-1 || maze[x][y] == 'X')
        return false;
    if(x == targetX && y == targetY){
        cout<<path;
        return true;
    }
    maze[x][y] = 'X';
    int index_x[] = {1,0,-1,0};
    int index_y[] = {0,1,0,-1};
    char rounte[] = {'D','R','U','L'};
    for (int i = 0;i<4;i++){
        path = path + ' ' + rounte[i];
        if (mazefun(maze, x+index_x[i], y+index_y[i], targetX, targetY,path)){

            //cout<<rounte[i];
            return true;
        }
    }
    return false;


//    return (mazefun(maze,x+1,y,targetX,targetY) || mazefun(maze,x,y+1,targetX,targetY)
//            || mazefun(maze, x-1, y, targetX, targetY) || mazefun(maze, x, y-1, targetX, targetY));

}

int main(int argc, char *argv[]){
    vector<vector<char>> ma = {{'.','X','.','.','.'},{'.','X','.','.','.'},{'.','X','.','.','.'},{'.','.','.','.','.'},{'.','X','.','.','.'}};
    cout<<ma[0][1]<<ma[1][1]<<endl;

//    cout<<ma.size();
    //aaa
    string path;
    mazefun(ma, 0, 0, 3, 4,path);
    cout<<endl;
}