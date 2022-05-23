#include <bits\stdc++.h>
#include <fstream>
using namespace std;

class Student
{
public:
  int rollno;
  string name;
  char division;
  string address;

  void insert();
  int search(int rollno);
  void display(Student s);
  void read();
  void delete_record(int rollno);
};

void Student::insert()
{
  Student s;
  cout << "Enter the name of the student: ";
  cin >> s.name;

  cout << "Enter the rollno: ";
  cin >> s.rollno;

  cout << "Enter the division: ";
  cin >> s.division;

  cout << "Enter student's address: ";
  cin >> s.address;

  ofstream write;
  write.open("Assg_14.txt", ios::app); // Here, app --> append.
  write << "\n"
        << s.name;
  write << "\n"
        << s.rollno;
  write << "\n"
        << s.division;
  write << "\n"
        << s.address;

  write.close();
}

void Student::display(Student s)
{
  cout << "Name: " << s.name << endl;
  cout << "Rollno: " << s.rollno << endl;
  cout << "Division: " << s.division << endl;
  cout << "Address: " << s.address << endl;
  cout << endl;
}

void Student::read()
{
  Student s;
  ifstream read;
  read.open("Assg_14.txt");
  while (!read.eof())
  {
    read >> s.name;
    read >> s.rollno;
    read >> s.division;
    read >> s.address;

    display(s);
  }
  read.close();
}

int Student::search(int rollno)
{
  Student s;
  ifstream read;
  read.open("Assg_14.txt");
  while (!read.eof())
  {
    read >> s.name;
    read >> s.rollno;
    read >> s.division;
    read >> s.address;
    if (rollno == s.rollno)
    {
      cout << "Student's Record found!" << endl;
      return rollno;
    }
  }
  read.close();
  cout << "Student's record no found!" << endl;
  return -1;
}

void Student::delete_record(int roll_no)
{
  roll_no = search(roll_no);
  if (roll_no == -1)
  {
    cout << "Student record to be deleted is not present in the file." << endl;
    return;
  }
  else
  {
    Student s;
    ofstream write;
    write.open("temp.txt", ios::app);

    ifstream read;
    read.open("Assg_14.txt");

    while (read.eof() == 0)
    {
      read >> s.name;
      read >> s.rollno;
      read >> s.division;
      read >> s.address;

      if (s.rollno != roll_no) // Here, Data of student except the data which we want to delete will be copied in "temp.txt" and then we will delete "Assg_14.txt" file.
      {
        write << "\n"
              << s.name;
        write << "\n"
              << s.rollno;
        write << "\n"
              << s.division;
        write << "\n"
              << s.address;
      }
    }
    write.close();
    read.close();

    remove("Assg_14.txt");
    rename("temp.txt", "Assg_14.txt");

    cout << "Student record to be deleted is deleted successfully!." << endl;
  }
}
int main()
{
  Student s;
  int choice;
  do
  {
    cout << "********* Student Record! ************" << endl;
    cout << "Enter 1 for adding a record" << endl;
    cout << "Enter 2 for displaying the records" << endl;
    cout << "Enter 3 for searching a record" << endl;
    cout << "Enter 4 for deleting a record" << endl;
    cout << "Enter 0 to exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      s.insert();
      break;
    }
    case 2:
    {
      s.read();
      break;
    }
    case 3:
    {
      int rollno;
      cout << "Enter the rollno to be searched: ";
      cin >> rollno;
      s.search(rollno);
      break;
    }
    case 4:
    {
      int roll_no;
      cout << "Enter rollno of the student to be deleted: ";
      cin >> roll_no;
      s.delete_record(roll_no);
      break;
    }
    case 0:
    {
      cout << "End of the program." << endl;
      break;
    }
    }
  } while (choice != 0);
}
