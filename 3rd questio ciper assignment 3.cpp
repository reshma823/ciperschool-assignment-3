class Solution {
public:

    bool isvalid(int m,vector<int>& w,int D)
    {
        int d = 1;
        bool isship = true;
        int total=0;
        for(int i = 0;i<w.size();i++)
        {
            if(w[i]>m)
                isship = false;
            if(w[i]+total<=m)
                total+=w[i];
            else
            {
                d++;
                total = w[i];
            }
            if(d>D) return false;
        }
        if(isship==false) return false;
        else return (d<=D);
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1;
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r)
        {
            int mid = (l+r)/2;
            if(isvalid(mid,weights,D))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};
