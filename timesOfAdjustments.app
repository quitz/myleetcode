// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int len = A.size();     //length of the vector
    int idx_first=-1,idx_last=-1;    //index of the array which marks the difference of two arrays
    if(len==0 || len==1)
        return len;         //base case
    vector<int> B(A);       
    sort(B.begin(),B.end());    //sort the new array
    for(int i=0;i<len;i++){     //find the index where elements in two                            arrays are not equal at the first                              time
        if(A[i] != B[i]){
            idx_first = i;
            break;
        }
    }                       
    if(idx_first==-1)            //this two arrays are equal
        return 0;
    for(int j=len-1;j>=0;j--){//find the index where elements in two                            arrays are not equal at the last                              time
        if(A[j] != B[j]){
            idx_last = j;
            break;
        }
    }
    return idx_last - idx_first +1;         
}