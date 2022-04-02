class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        //first store the last occurance of each ch
        unordered_map<char,int>mp;
        int n=s.size();
        
        for (int i=n-1;i>=0;i--)
        {
            if(mp[s[i]] == 0)
            {
                mp[s[i]]=i;
            }
        }
        
        //traversing:
        vector<int>ans;
        for (int i=0;i<n;i++)
        {
            int start=i;
            int end=mp[s[i]];
            int j=start+1;
            
            while(j<end)
            {
                if (mp[s[j]]>end)
                {
                    end=mp[s[j]];
                }
                j+=1;
            }
            ans.push_back(end-start+1);
            i=end;
        }
        
        return ans;
    }
};
