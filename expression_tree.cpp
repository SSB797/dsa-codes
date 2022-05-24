#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

/** class TreeNode **/
class TreeNode
{
public:
    char data;
    TreeNode *left, *right;
    /** constructor **/
    TreeNode(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/** class StackNode **/
class StackNode
{
public:
    TreeNode *treeNode;
    StackNode *next;
    /** constructor **/
    StackNode(TreeNode *treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }
};

class ExpressionTree
{
private:
    StackNode *stop;
    StackNode *s1;
    
    StackNode *s2;
    

public:
    /** constructor **/
    ExpressionTree()
    {
        stop = NULL;
        s1 = NULL;
        s2 = NULL;
    }

    /** function to clear tree **/
    void clear()
    {
        stop = NULL;
    }

    /** function to push a node **/
    StackNode *push(TreeNode *ptr, StackNode *top)
    {
        if (top == NULL)
            top = new StackNode(ptr);
        else
        {
            StackNode *nptr = new StackNode(ptr);
            nptr->next = top;
            top = nptr;
        }
        return top;
    }

    /** function to pop a node **/
    TreeNode *pop(StackNode *top)
    {
        if (top == NULL)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            TreeNode *ptr = top->treeNode;
            return ptr;
        }
    }

    /** function to get top node **/
    TreeNode *peek(StackNode *top)
    {
        return top->treeNode;
    }

    /** function to insert character **/
    void insert(char val)
    {
        if (isDigit(val) || ischar(val))
        {
            TreeNode *nptr = new TreeNode(val);
            stop = push(nptr, stop);
        }
        else if (isOperator(val))
        {
            TreeNode *nptr = new TreeNode(val);
            nptr->left = pop(stop);
            stop=stop->next;
            nptr->right = pop(stop);
            stop=stop->next;
            stop = push(nptr, stop);
        }
        else if (!isspace(val))
        {
            cout << "Invalid Expression" << endl;
            return;
        }
    }

    /** function to check if digit **/
    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    /** function to check if char **/
    bool ischar(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }

    /** function to check if space **/
    bool isspace(char ch)
    {
        return ch == ' ';
    }

    /** function to check if operator **/
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    /** function to convert character to digit **/
    int toDigit(char ch)
    {
        return ch - '0';
    }

    /** function to build tree from input */

    void buildTree(string eqn)
    {
        for (int i = eqn.length() - 1; i >= 0; i--)
            insert(eqn[i]);
        
    }

    /** function to get postfix expression */
    void postfix()
    {
        postOrder(peek(stop));
    }
    void infix()
    {
        inOrder(peek(stop));
    }

    /** in order traversal */
    void inOrder(TreeNode *ptr)
    {
        if (ptr != NULL)
        {
            inOrder(ptr->left);
            cout << ptr->data;
            inOrder(ptr->right);
        }
    }

    /** post order traversal */
    void postOrder(TreeNode *ptr)
    {
        TreeNode *temp = NULL;

        s1 = push(ptr, s1);
        
        while (s1 != NULL)
        {
            
            temp = pop(s1);
            
            s1 = s1->next;
            s2 = push(temp, s2);
            if (temp->left != NULL)
            {
                s1 = push(temp->left, s1);
            }
            if (temp->right != NULL)
            {
                s1 = push(temp->right, s1);
            }
        }
       
        while (s2 != NULL)
        {
            
            temp = pop(s2);
            s2=s2->next;
            cout << temp->data;
        }
        cout << endl;
    }
};

/** Main Contains menu **/
int main()
{
    string s;
    cout << "Expression Tree Test" << endl;
    ExpressionTree et;
    cout << "\nEnter equation in Prefix form: ";
    cin >> s;
    et.buildTree(s);

    cout<<"Postorder traversal(non recursive) :"<<endl;
    et.postfix();

    cout<<"Deleting the tree...."<<endl;
    et.clear();
    cout<<"Tree deleted succcessfully"<<endl;

    return 0;
}