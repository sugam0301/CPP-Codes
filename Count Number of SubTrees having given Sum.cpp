int util(Node* root,int x,int &c)
{
if(root==NULL) return 0;
int sum1=root->data+util(root->left,x,c)+util(root->right,x,c);
if(sum1==x) c++;

return sum1;
}
int countSubtreesWithSumX(Node* root, int X)
{
int c=0;
util(root,X,c);
return c;
}
