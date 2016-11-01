//
//  main.cpp
//  3sum
//
//  Created by quitz on 16-3-16.
//  Copyright (c) 2016年 quitz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> a;
    vector<int> r(nums);
    sort(r.begin(), r.end());
    int l = (int)nums.size();
    int i,j,k;
    for(i=0;i<l;i++)
        for(j=l-1;j>i+1;j--)
            for(k=j-1;k>i;k--){
                if(r[i] + r[j] +r[k] == 0){
                    vector<int> rr;
                    rr.push_back(r[i]);
                    rr.push_back(r[k]);
                    rr.push_back(r[j]);
                    a.push_back(rr);
                }
            }
    a.erase(unique(a.begin(), a.end()),a.end());
    return a;
}

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> a;
    vector<int> r(nums);
    sort(r.begin(), r.end());
    int l = (int)nums.size();
    int i,j,k;
    for(i=0;i<l-2;i++){
        j = i+1;
        k = l-1;
        while(j<k){
            if(nums[i] + nums[j] + nums[k] == 0){
                vector<int> rr;
                rr.push_back(r[i]);
                rr.push_back(r[j]);
                rr.push_back(r[k]);
                a.push_back(rr);
                
                while(j<k && nums[j] == nums[j+1])
                    j++;
                while(j<k && nums[k] == nums[k-1])
                    k--;
                
                j++;
                k--;
            }
            else if(nums[i] + nums[j] + nums[k] > 0)
                k--;
            else
                j++;
            
        }
        if(i<l-2){
            while(nums[i] == nums[i+1]){
                i++;
            }
        }
    }
    return a;
    
}

int threeSumClosest(vector<int>& nums, int target) {
    int a=0;
    sort(nums.begin(), nums.end());
    int i,j,k,diffmax=999999;
    int l = nums.size();
    int t;
    for(i=0;i<l-2;i++){
        j = i+1;
        k = l-1;
        while(j<k){
            t = nums[i] + nums[j] + nums[k];
            if( t == target)
                return target;
            else if (t > target){
                k--;
            }
            else{
                j++;
            }
            
            if(abs(t-target)<diffmax){
                a = t;
                diffmax = abs(t - target);
            }
            
        }
    }
    return a;
}*/
int main(int argc, const char * argv[])
{

	/*
    // insert code here...
    int n,a;
    cin>>n;
    //vector<vector<int>> rr;
    vector<int> r;
    for(int i=0;i<n;i++){
        cin>>a;
        r.push_back(a);
    }
    
    int t;
    cin>>t;
    cout<<threeSumClosest(r, t);*/
	//int i = 5;
	char a = '#';
	char i = '6';
	cout<<int(a)<<endl;
    return 0;
}

