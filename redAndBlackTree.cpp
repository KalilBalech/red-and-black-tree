#include <redAndBlackTree.h>

long IndexPointsAluno::size()
{
  return rbTree.size();
}

void IndexPointsAluno::add(double key, long idx)
{
  rbTree.add(key, idx);
}

void IndexPointsAluno::find(std::vector<long> &res, double first, double last)
{
  rbTree.find(res, first, last);
}

long RedAndBlackTree::size()
{
  long RBSize = 0;
  validate(root, &RBSize);
  return RBSize;
}

void RedAndBlackTree::validate(rbNode *p, long *RBSize)
{

  if (p == root)
    *RBSize = 0;
  if(p != nil){
    (*RBSize)++;
    validate(p->left, RBSize);
    validate(p->right, RBSize);
  }
}

void RedAndBlackTree::add(double key, long idx)
{
  rbNode *newrbNode = new rbNode;
  newrbNode->parent = nil;
  newrbNode->key = key;
  newrbNode->idx = idx;
  newrbNode->left = nil;
  newrbNode->right = nil;
  newrbNode->color = 'r';

  rbNode *q = nil;
  rbNode *p = root;

  while (p != nil)
  {
    q = p;
    if (newrbNode->key < p->key)
    {
        p = p->left;
    }
    else
    {
        p = p->right;
    }
  }
  newrbNode->parent = q;
  if (q == nil)
    root = newrbNode;
  else if (newrbNode->key < q->key)
    q->left = newrbNode;
  else
    q->right = newrbNode;
  balance(newrbNode);
}

void RedAndBlackTree::balance(rbNode *t)
{
  rbNode *p = new rbNode;

  while (t->parent->color == 'r')
  {
    if (t->parent == t->parent->parent->right)
    {
      p = t->parent->parent->left;
      if (p->color == 'r')
      {
        p->color = 'b';
        t->parent->color = 'b';
        t->parent->parent->color = 'r';
        t = t->parent->parent;
      }
      else
      {
        if (t == t->parent->left)
        {
          t = t->parent;
          rightrotation(t);
        }
        t->parent->color = 'b';
        t->parent->parent->color = 'r';
        leftrotation(t->parent->parent);
      }
    }
    else
    {
      p = t->parent->parent->right;
      if (p->color == 'r')
      {
        p->color = 'b';
        t->parent->color = 'b';
        t->parent->parent->color = 'r';
        t = t->parent->parent;
      }
      else
      {
        if (t == t->parent->right)
        {
          t = t->parent;
          leftrotation(t);
        }
        t->parent->color = 'b';
        t->parent->parent->color = 'r';
        rightrotation(t->parent->parent);
      }
    }
  }
  root->color = 0;
}

void RedAndBlackTree::find(std::vector<long> &res, double first, double last)
{
  res.resize(0);
  findDepth(res, first, last, root);
}

void RedAndBlackTree::findDepth(std::vector<long> &res, double first, double last, rbNode *p)
{
  if (p == nil)
    return;
  if (p->key < first)
    findDepth(res, first, last, p->right);
  else if (p->key > last)
    findDepth(res, first, last, p->left);
  else
  {
    res.push_back(p->idx);
    findDepth(res, first, last, p->left);
    findDepth(res, first, last, p->right);
  }
}

void RedAndBlackTree::leftrotation(rbNode *p)
{
  rbNode *y = p->right;
  p->right = y->left;
  if (y->left != nil)
    y->left->parent = p;
  y->parent = p->parent;
  if (p->parent == nil)
    root = y;
  else if (p == p->parent->left)
    p->parent->left = y;
  else
    p->parent->right = y;
  y->left = p;
  p->parent = y;
}

void RedAndBlackTree::rightrotation(rbNode *p)
{
  rbNode *y = p->left;
  p->left = y->right;
  if (y->right != nil)
    y->right->parent = p;
  y->parent = p->parent;
  if (p->parent == nil)
    root = y;
  else if (p == p->parent->right)
    p->parent->right = y;
  else
    p->parent->left = y;
  y->right = p;
  p->parent = y;
}