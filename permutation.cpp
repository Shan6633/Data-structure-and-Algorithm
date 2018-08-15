//
//  permutation.cpp
//  counting_sort
//
//  Created by liushan on 8/14/18.
//  Copyright © 2018 liushan. All rights reserved.
//

//
// Created by liushan on 8/14/18.
//
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void BFS(vector<int> &nums,int n,vector<vector<int>> &res){
    if (n==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i = n;i<nums.size();i++){
        swap(nums[i],nums[n]);
        BFS(nums,n+1,res);
        swap(nums[i],nums[n]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    BFS(nums,0,result);
    return result;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result;
    result =permute(nums);
    //swap(nums[0],nums[1]);
    //cout<<nums[0];
    for(auto i:result){
        for(auto c:i){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}

