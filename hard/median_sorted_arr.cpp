#include<iostream>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        cout<<"Here 1"<<endl;
        vector<int> v; // will hold nums1 and nums 2
        v = nums1;
        for(int i = 0; i < nums2.size(); i++)
            v.push_back(nums2[i]);
        
        for(int i = 0; i < (v.size()-1); i++)
            for(int j = 0; j < v.size()-1-i; j++){
                int temp;
                if(v[j] > v[j+1]){
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        
     
       if(v.size() % 2 == 0 && v.size()/2 != 0){
           return ((double)v[(v.size()/2)-1] +(double)v[(v.size()/2)])/2.0;
       }
       return (double) v[v.size()/2]; 
        
    }
};