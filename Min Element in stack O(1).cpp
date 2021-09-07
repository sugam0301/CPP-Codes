int _stack :: getMin()
{
    if(s.empty())
       return -1;
   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
        return -1;
        
    int t=s.top();
    s.pop();
    if(t<=minEle)
    {
        int res=minEle;
        minEle=2*minEle-t;
        return res;
    }
    else
     return t;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.size()==0)  //if size is 0 make that element as min
    {
        s.push(x);
        minEle=x;
    }
    
    else if(x<=minEle)
    {
        s.push(2*x-minEle);
        minEle=x;
    }
    
    else
        s.push(x);

    
}
