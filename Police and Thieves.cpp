int catchThieves(char arr[], int n, int k) 
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            {
                for(int j=i-k;j<=i+k;j++)
                {
                    if(j<0 || j>=n)
                        continue;
                    if(arr[j]=='T')
                    {
                        cnt++;
                        arr[j] = 'N';
                        break;
                    }
                    // break;
                }
            }
        }
        return cnt;
    }
