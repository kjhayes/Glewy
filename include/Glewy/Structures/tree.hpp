#ifndef GLEWY_TREE_HPP
#define GLEWY_TREE_HPP

#include<vector>

namespace gly
{

class Tree
{
    protected:
        Tree* parent;        
        
        std::vector<Tree*> children;

        ~Tree();

    public:
        Tree(Tree*);
        virtual void AddChild(Tree*);
        virtual void GiveChild(Tree*, const int&);
        virtual int IndexInParent();
        virtual void SetIndex(const int&);
        virtual void Destroy();
};

}

#endif