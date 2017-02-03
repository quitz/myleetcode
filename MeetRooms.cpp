/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(auto i:intervals){
            mp[i.start]++;
            mp[i.end]--;
        }
        int r=0,cnt=0;
        for(auto i:mp){
            r += i.second;
            cnt = max(cnt,r);
        }
        return cnt;
    }
    
    static bool comp(const Interval &a, const Interval &b){
        return a.end<b.end;
    }
};