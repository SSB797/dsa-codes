#include <bits\stdc++.h>
using namespace std;

class Node
{
public:
  string name;
  int chCount;
  Node *child[50];
  Node *root;
  Node()
  {
    root = NULL;
  }
  void insert();
  void display();
};

/*
  Here, Let the Book Be "DSA" and it has 2 chapters namely "BST" & "AVL" and each chapter has 2 sections i.e (BST:- Section 1  --> Leftsubtree and section 2 --> Rightsubtree).
               (AVL:- Section 1 --> LL rotation and section 2 --> RR rotation).
  and no sub sections. Then the tree will be as follows:-

           DSA              Here,
         /    \                 DSA will be the "root".
       BST    AVL               BST and AVL will be the "root->child[i]".
     /   \   /  \                LST, RST, LL, RR will be the "root->child[i]->child[j]".
   LST  RST LL  RR   The children of LST, RST, LL, RR will be the "root->child[i]->child[j]->child[k]".
           
                                  

  Here,
    BST --> Binary Search Tree.
    AVl --> AVl Tree.
    LST --> Left Sub Tree.
    RST --> Right Sub Tree.
    LL --> Single Left rotation.
    RR --> Single Right rotation.
*/
void Node::insert()
{
  root = new Node();
  cout << "Enter the name of the book: ";
  cin >> root->name;
  cout << "Enter total number of chapters: ";
  cin >> root->chCount;

  for (int i = 0; i < root->chCount; i++)
  {
    root->child[i] = new Node();
    cout << "Enter the name of the chapter " << i + 1 << " : ";
    cin >> root->child[i]->name;

    cout << "Enter the number of sections in chapter " << i + 1 << " : ";
    cin >> root->child[i]->chCount;

    for (int j = 0; j < root->child[i]->chCount; j++)
    {
      root->child[i]->child[j] = new Node();
      cout << "Enter the name of the section " << j + 1 << " of chapter " << i + 1 << " : ";
      cin >> root->child[i]->child[j]->name;

      cout << "Enter the number of sub-sections " << j + 1 << " of the chapter " << i + 1 << " : ";
      cin >> root->child[i]->child[j]->chCount;

      for (int k = 0; k < root->child[i]->child[j]->chCount; k++)
      {
        root->child[i]->child[j]->child[k] = new Node();
        cout << "Enter the name of the sub-section " << k << " : ";
        cin >> root->child[i]->child[j]->child[k]->name;
      }
    }
  }
}

void Node::display()
{
  if (root != NULL)
  {
    cout << "*********** Hierarchy of Book ***********" << endl;
    cout << "Book name is: " << root->name << endl;

    for (int i = 0; i < root->chCount; i++)
    {
      cout << "Name of the chapter " << i + 1 << " is: " << root->child[i]->name << endl;

      for (int j = 0; j < root->child[i]->chCount; j++)
      {
        cout << "Enter the name of the section " << j + 1 << " of chapter " << i + 1 << " is: " << root->child[i]->child[j]->name << endl;

        for (int k = 0; k < root->child[i]->child[j]->chCount; k++)
        {
          cout << "Enter the name of the sub-section " << k + 1 << " is: " << root->child[i]->child[j]->child[k]->name << endl;
        }
      }
    }
  }
}

int main()
{
  Node n;
  int ch;
  do
  {
    cout << "******** MENU *******" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Display" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter the choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
      n.insert();
      break;
    }
    case 2:
    {
      n.display();
      break;
    }

    case 3:
    {
      cout << "End of the Book." << endl;
      break;
    }
    }
  } while (ch != 3);
}
