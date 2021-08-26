using namespace std;
#include<math.h>

void toh(int n,int A,int B,int C);

int main()
{
int t;cin>>t;
int n;
while(t--)
{
cin>>n;
toh(n,1,2,3);
cout<<pow(2,n)-1;
cout<<endl;
}

return 0;
}


void toh(int n,int A,int B,int C)
{
if(n==1) 
{
    cout<<"move disk"<<" "<<1<<" "<<"from rod"<<" "<<A<<" "<<"to rod"<<" "<<C<<endl;
    return;
}
   toh(n-1,A,C,B);
   cout<<"move disk"<<" "<<n<<" "<<"from rod"<<" "<<A<<" "<<"to rod"<<" "<<C<<endl;
   toh(n-1,B,A,C);

}
