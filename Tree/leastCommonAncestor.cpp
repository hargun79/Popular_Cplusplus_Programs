// To find the least common ancestor of two given nodes

Node * LCA(Node* root ,int n1 ,int n2 )
{
 Node *lnode, *rnode;
 if(!root)
  return NULL;
 if(root->data==n1 || root->data==n2)
  return root;
 lnode=LCA(root->left,n1,n2);
 rnode=LCA(root->right,n1,n2);
 if(lnode && rnode)
  return root;
 return (lnode != NULL) ? lnode : rnode;
}
