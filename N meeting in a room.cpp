struct meeting
    {
        int shuru;
        int khtm;
        int pos;
    };
    
    static bool mycmp(struct meeting &m1,struct meeting &m2)
    {
        if(m1.khtm<m2.khtm)
            return true;
        else if(m1.khtm>m2.khtm)
            return false;
        else
            return m1.pos<m2.pos;
            
    }
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i=0;i<n;i++)
        {
            meet[i].shuru=start[i];
            meet[i].khtm=end[i];
            meet[i].pos=i+1;
        }
        sort(meet,meet+n,mycmp);
        
        int ending=meet[0].khtm;
        int res=1;
        for(int i=1;i<n;i++)
        {
            if(meet[i].shuru > ending)
            {
                res++;
                ending=meet[i].khtm;
            }
        }
        
        return res;
    }
