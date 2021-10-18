Node* divide(int N, Node *head)
    {
        Node *curr=head;
        Node *oS=NULL,*oE=NULL,*eS=NULL,*eE=NULL;
        
        for(int i=0;i<N;i++)
        {
            if(curr->data % 2 ==0)
            {
                if(eS==nullptr)
                    eS = eE = curr;
                else
                {
                    eE->next = curr;
                    eE=eE->next;
                }
            }
            else
            {
                if(oS==nullptr)
                    oS=oE=curr;
                else
                {
                    oE->next = curr;
                    oE = oE->next;
                }
            }
            
            curr=curr->next;
        }
        
        if(!eE || !oE)
            return head;

        eE->next = oS;

        oE->next = NULL;
        
        return eS;
    }
