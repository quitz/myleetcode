class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s = (C-A)*(D-B) +(G-E)*(H-F);
        if(E>=C || G<=A || D<=F || H<=B )
            return s;
        int t1 = max(A,E), t2=min(C,G), t3=max(B,F),t4=min(D,H);
        
        return s-(t2-t1)*(t4-t3);
    }
};