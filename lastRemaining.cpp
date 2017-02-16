class Solution {
public:
    int lastRemaining(int n) {
        if(n==0 || n==1)
            return n;
        stack<int> q1,q2;
        
        for(int i=n;i>=1;i--)
            q1.push(i);
            
        while(q1.size()!=1 && q2.size()!=1){
            if(q2.size()==0){
                int i=1;
                while(!q1.empty()){
                    int t = q1.top();
                    q1.pop();
                    if(i%2 == 0){
                        q2.push(t);
                    }
                    i++;
                }
            }
            
            else{
                int i=1;
                while(!q2.empty()){
                    int t = q2.top();
                    q2.pop();
                    if(i%2 == 0){
                        q1.push(t);
                    }
                    i++;
                }
            }
            
        }
        if(q1.size()==0)
            return q2.top();
        return q1.top();
    }
};