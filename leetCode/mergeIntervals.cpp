/*
Given a collection of intervals, merge all overlapping intervals.
*/

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
    
    static bool compare(const Interval &a, const Interval &b){
        if(a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(),intervals.end(),compare);
        
        ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start <= ans[ans.size()-1].end){
                ans[ans.size()-1].end = max(intervals[i].end,ans[ans.size()-1].end);
            }else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};