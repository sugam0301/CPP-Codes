bool ispar(string x)
    {
        // Your code here
        stack<char>s;
        for(char i:x)
        {
            
            if(i=='(' || i=='{' || i=='[')
                s.push(i);
            else
            {
                if(s.empty())
                    return false;
                else if(s.top()=='(' && i==')' ||s.top()=='{' &&  i=='}' ||s.top()=='[' && i==']' )
                    s.pop();
                
                else
                    return false;
            
            }
        }
            return s.empty();
    }
