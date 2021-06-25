// # We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

// # (Here, the distance between two points on a plane is the Euclidean distance.)

// # You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

// # Input: points = [[1,3],[-2,2]], K = 1
// # Output: [[-2,2]]
// # Explanation: 
// # The distance between (1, 3) and the origin is sqrt(10).
// # The distance between (-2, 2) and the origin is sqrt(8).
// # Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// # We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

#include<bits/stdc++.h>
// METHOD->1

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = points.size();
        vector<pair<int,pair<int,int>>> v;
        
        //Find all euclidean distances
        int dist;
        for(auto it: points)
        {
            dist = it[0]*it[0] + it[1]*it[1];2
            v.push_back({dist,{it[0],it[1]}});
        }
        sort(v.begin(),v.end());
        
        vector<vector<int>> ans(K);
        for(int i=0;i<K;++i)
        {
            ans[i].push_back(v[i].second.first);
            ans[i].push_back(v[i].second.second);
        }
        return ans;
    }
};


//METHOD-2

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n=points.size();
        //Multimap is sorted in ASC order by key
        multimap<int,int> mymap;    //1st val:DISTANCE...2nd val:INDEX
        for(int i=0;i<n;++i)
            mymap.insert({points[i][0]*points[i][0] + points[i][1]*points[i][1],i});
        
        vector<vector<int>> ans;
        //Store 1st K points from multimap
        int count = 0;
        for(auto it=mymap.begin();count<K;++it,++count)
            ans.push_back(points[it->second]);
        
        return ans;
    }
};