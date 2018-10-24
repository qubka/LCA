#include <iostream> 
#include <vector>
#include <cassert>

#define BOOST_TEST_MODULE Simple testlca
#include <boost/test/unit_test.hpp>

using namespace std; 

struct Node 
{ 
    int value; 
    struct Node *left, *right; 
}; 

class CreateTree
{
    public:
        CreateTree();
        ~CreateTree();
        void insert(int key);
        int lca(int number1, int number2);
        void print();
    private:
        void destroy(Node *leaf);
        void insert(int key, Node *leaf);
        bool find(Node *leaf, vector<int> &path, int key);
        int lca(Node *leaf, int number1, int number2);
        void print(Node *leaf);
        Node *root;
};

CreateTree::CreateTree()
{
	root = NULL;
}

CreateTree::~CreateTree()
{
	destroy(root);
}

void CreateTree::insert(int key)
{
	if(root != NULL)
    {
		insert(key, root);
	}
    else
    {
		root = new Node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void CreateTree::insert(int key, Node *leaf)
{
	if(key < leaf->value)
    {
		if(leaf->left != NULL)
        {
			insert(key, leaf->left);
		}
        else
        {
			leaf->left = new Node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
    else if(key >= leaf->value)
    {
		if(leaf->right != NULL)
        {
			insert(key, leaf->right);
		}
        else
        {
			leaf->right = new Node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

int CreateTree::lca(int number1, int number2) 
{ 
    return lca(root, number1, number2);
}

int CreateTree::lca(Node *leaf, int number1, int number2) 
{ 
    vector<int> path1, path2; 

    if(!find(leaf, path1, number1) || !find(leaf, path2, number2)) 
    {
        return -1; 
    }

    unsigned int i; 
    for(i = 0; i < path1.size() && i < path2.size(); i++) 
    {
        if(path1[i] != path2[i]) 
        {
            break;
        }
    }
    
    return path1[i-1]; 
}

void CreateTree::destroy(Node *leaf)
{
	if(leaf != NULL)
    {
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

bool CreateTree::find(Node *root, vector<int> &path, int index) 
{ 
    if(root == NULL) 
    {
        return false; 
    }
    
    path.push_back(root->value); 

    if(root->value == index) 
    {
        return true; 
    }
    
    if((root->left && find(root->left, path, index)) || (root->right && find(root->right, path, index))) 
    {
        return true; 
    }
    
    path.pop_back(); 
    return false; 
}

void CreateTree::print()
{
    cout << "\n";
	print(root);
	cout << "\n";
}

void CreateTree::print(Node *leaf)
{
	if(leaf != NULL)
    {
		print(leaf->left);
		cout << leaf->value << "|";
		print(leaf->right);
	}
}

/*int main() 
{
    CreateTree *tree = new CreateTree();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(6);
	tree->insert(7);

    assert(tree->lca(4, 5) == 4);
    assert(tree->lca(4, 6) == 4);
    assert(tree->lca(3, 4) == 3);
    assert(tree->lca(1, 3) == 1);
    assert(tree->lca(1, 7) == 1);

    tree->print();
    delete tree;
}*/

BOOST_AUTO_TEST_CASE(simple_test) 
{
    CreateTree *tree = new CreateTree();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(6);
	tree->insert(7);

    BOOST_CHECK_EQUAL(tree->lca(4, 5), 4);

    tree->print();
    delete tree;
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    CreateTree *tree = new CreateTree();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(6);
	tree->insert(7);

    BOOST_CHECK_EQUAL(tree->lca(4, 6), 4);

    tree->print();
    delete tree;
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    CreateTree *tree = new CreateTree();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(6);
	tree->insert(7);

    BOOST_CHECK_EQUAL(tree->lca(3, 4), 3);

    tree->print();
    delete tree;
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    CreateTree *tree = new CreateTree();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(6);
	tree->insert(7);

    BOOST_CHECK_EQUAL(tree->lca(1, 3), 1);

    tree->print();
    delete tree;
}

BOOST_AUTO_TEST_CASE(simple_test) 
{
    CreateTree *tree = new CreateTree();

	tree->insert(1);
	tree->insert(2);
	tree->insert(3);
	tree->insert(4);
	tree->insert(5);
	tree->insert(6);
	tree->insert(7);

    BOOST_CHECK_EQUAL(tree->lca(1, 7), 1);

    tree->print();
    delete tree;
}