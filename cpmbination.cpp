//
// Created by liushan on 8/14/18.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void helper(vector<int> &nums,vector<vector<int>> &res,int n,vector<int> &tmp){
    if(nums.empty()){
        res.push_back(nums);
        return;
    }

    for (vector<int>::iterator i = nums.begin();i<nums.end();i++){
        int  p = *i;
        res.push_back(nums);
        nums.erase(i);
        helper(nums, res,n+1,tmp);
        nums.insert(i,p);
    }

}

vector<vector<int>> combination(vector<int> &nums){
    vector<vector<int>> result;
    helper(nums, result,0,nums);
    return result;
}

int  main(){
    vector<vector<int>> a;
    vector<int> p ={2,6,8};
    a=combination(p);
    for(auto i:a){
        for(auto c:i){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}