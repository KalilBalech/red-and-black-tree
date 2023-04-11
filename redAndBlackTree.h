#include <vector>

struct rbNode
{
    double key;
    long idx;   
    char color;
    rbNode* parent;
    rbNode* left;
    rbNode* right;
};

class RedAndBlackTree
{
    rbNode* nil;
    rbNode* root;

public:
    RedAndBlackTree()
    {
        nil = new rbNode;
        nil->color = 'b';
        root = nil;
    }

    long size();
    void validate(rbNode*, long *);

    void add(double key, long idx);
    void balance(rbNode*);

    void find(std::vector<long> &res, double first, double last);
    void findDepth(std::vector<long> &res, double first, double last, rbNode*);

    void leftrotation(rbNode*);
    void rightrotation(rbNode*);
};

class IndexPointsAluno
{

public:
    long size();
    void add(double key, long idx);
    void find(std::vector<long> &res, double first, double last);

private:
    RedAndBlackTree rbTree;
};
