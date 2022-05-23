#include <iostream>
using namespace std;

// MAX HEAP
void max_heap_insert(int a[], int size)
{
    int temp;
    int i = size;
    temp = a[i];

    while (i > 1 && temp > a[i / 2])
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}

void create_heap_in_max_insert(int a[], int size)
{
    int i;

    for (i = 2; i <= size; i++)
    {
        max_heap_insert(a, i);
    }
}

void display_max_heap(int a[], int size)
{
    cout << "\nMARKS OF STUDENTS :   ";
    for (int i = 1; i <= size; i++)
    {
        cout << a[i] << "   ";
    }
}

void max_element(int a[])
{
    cout << "\nMAXIMUM MARK : " << a[1];
}


// MIN HEAP
void min_heap_insert(int a[], int size)
{
    int temp;
    int i = size;
    temp = a[i];

    while (i > 1 && temp < a[i / 2])
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}


void create_heap_in_min_insert(int a[], int size)
{
    int i;

    for (i = 2; i <= size; i++)
    {
        min_heap_insert(a, i);
    }
}


void display_min_heap(int a[], int size)
{
    cout << "\nMARKS OF STUDENTS :   ";
    for (int i = 1; i <= size; i++)
    {
        cout << a[i] << "   ";
    }
}

void min_element(int a[])
{
    cout << "\nMINIMUM MARK : " << a[1];
}

int main()
{
    int num;
    int i;

    // TAKE INPUT FROM USER
    cout << "\nENTER NO. OF STUDENTS IN SECOND YEAR : ";
    cin >> num;
    int a[num];

    for (i = 1; i <= num; i++)
    {
        cout << "ENTER MARK OF STUDENT " << i << " is ";
        cin >> a[i];
    }

    //************************************ MAX HEAP  *************************************
    
    // int choice;
    // do
    // {
    //     cout<<"\n\n\t\t1.CREATE MAX HEAP\n\t\t2.DISPLAY MAX HEAP\n\t\t3.MAX MARK";

    //     cout << "\nENTER YOUR CHOICE : ";
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         create_heap_in_max_insert(a, sizeof(a) / sizeof(a[0]));
    //         break;
    //     }
    //     case 2:
    //     {
    //         display_max_heap(a, sizeof(a) / sizeof(a[0]));
    //         break;
    //     }
    //     case 3:
    //     {
    //         max_element(a);
    //         break;
    //     }
    //     default:
    //         break;
    //     }
    // } while (choice != 3);


    // ************************************ MIN HEAP  *************************************


    // int choice;
    // do
    // {
    //     cout<<"\n\n\t\t1.CREATE MIN HEAP\n\t\t2.DISPLAY MIN HEAP\n\t\t3.MIN MARK";

    //     cout << "\nENTER YOUR CHOICE : ";
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         create_heap_in_min_insert(a, sizeof(a) / sizeof(a[0]));
    //         break;
    //     }
    //     case 2:
    //     {
    //         display_min_heap(a, sizeof(a) / sizeof(a[0]));
    //         break;
    //     }
    //     case 3:
    //     {
    //         min_element(a);
    //         break;
    //     }
    //     default:
    //         break;
    //     }
    // } while (choice != 3);

    return 0;
}
























