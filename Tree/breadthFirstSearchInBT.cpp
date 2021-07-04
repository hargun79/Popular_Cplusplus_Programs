// Breadth first or level order traversal of a binary tree.

vector<int> v;
 
void bfs(Node *node)
{
 queue<Node*> q;
 q.push(node);
 while(!q.empty())
 {
  Node *t=q.front();
  q.pop();
  v.push_back(t->data);
  if(t->left)
   q.push(t->left);
  if(t->right)
   q.push(t->right);
 }
}
   
//Function to return the level order traversal of a tree.
vector<int> levelOrder(Node* node)
{
 v.clear();
 bfs(node);
 return v;
}
