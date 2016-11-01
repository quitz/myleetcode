
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

string solution(int A, int B, int C, int D) {
    // write your code in C++11 (g++ 4.8.2)
    string res;     
    int flag=0;         //mark whethe there is a solution 
    if(A<0 || B<0 || C<0 || D<0)
        return "NOT POSSIBLE";     //if there are some negative                           integers, just return 'not possible'
    vector<int> ele;
    vector<bool> u(4,false);    //record the usage of the four                                    elements
    ele.push_back(A);
    ele.push_back(B);
    ele.push_back(C);
    ele.push_back(D);
    sort(ele.begin(),ele.end()); //put the four element into a vector                         and sort
    for(int i=3;i>=0;i--){
        u[i] = true;
        if(ele[i]==2){               //first condition: 
            for(int j=3;j>=0;j--){   
                if(u[j] == false && ele[j]<=3){   
                    u[j] = true;
                    
                    for(int m=3;m>=0;m--){
                        if(u[m] == false && ele[m]<=5){   
                            u[m] = true;
                            for(int n=3;n>=0;n--){
                                if(u[n] == false){
                                    res+= to_string(ele[i]);
                                    res+= to_string(ele[j]);
                                    res+= ':';
                                    res+= to_string(ele[m]);
                                    res+= to_string(ele[n]);
                                    flag=1;
                                }
                            }
                        }
                    }
                }
            }
            u[i] = false;
        }
        else if(ele[i]==1 || ele[i]==0){   //second condition
            for(int j=3;j>=0;j--){   
                if(u[j] == false && ele[j]<=9){   
                    u[j] = true; 
                    
                    for(int m=3;m>=0;m--){
                        if(u[m] == false && ele[m]<=5){   
                            u[m] = true;
                            //cout<<"line56"<<endl;
                            for(int n=3;n>=0;n--){
                                if(u[n] == false){
                                    //cout<<'line59'<<endl;
                                    res += to_string(ele[i]);
                                    res += to_string(ele[j]);
                                    res += ':';
                                    res += to_string(ele[m]);
                                    res += to_string(ele[n]);
                                    flag=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        else{   
            u[i] = false;
            continue;
        }
    
    }
    if(flag==0)
        res = "NOT POSSIBLE";
    return res;
}
