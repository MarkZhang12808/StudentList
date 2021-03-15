//Mark Zhang - 14 March 2021 - Student List: list containing student information. User can alter the list using commands
//The list acts as a database storing the students' names, student ID numbers, and GPAs
//User may use commands to: add students to the list, delete students from the list, print the list, or quit the program

#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Student {
  //Student struct has 4 values: first name, last name, ID number, and GPA
  char firstName[50];
  char lastName[50];
  int idNumber;
  double GPA;
};

void deleteStudent(vector<Student*>* StudentList);
void printList(vector<Student*> StudentList);
 
Student* addStudent() { //function to add students by creating a new student struct
Student* newStudent = new Student();
//asks user to enter the 4 parameters to create a student: (1) First name (2) Last name (3) ID number (4) GPA
    cout << "\nEnter Student's first name:";
    cin >> newStudent -> firstName;
    cin.clear();
    cin.ignore(999, '\n');
    cout << "\nEnter Student's last name:";
    cin >> newStudent -> lastName;
    cin.clear();
    cin.ignore(999, '\n');
    cout << "\nEnter Student's ID number:";
    cin >> newStudent -> idNumber;
    cin.clear();
    cin.ignore(999, '\n');
    cout << "\nEnter Student's GPA:";
    cin >> newStudent -> GPA;
    cin.clear();
    cin.ignore(999, '\n');
    return newStudent;
}

int main() {
  //main function from which user can choose commands to call functions that alter the list 
  char input[10];
  bool onQuit = false; 
  vector<Student*> StudentList; //the vector of students
  while (onQuit == false) {
  cout << "Enter a command: add, print, delete, print\n";
  cin.getline (input, 10); 
  if (strcmp(input, "quit") == 0) { //If user enters "QUIT" command, exit the program
    exit(0);
  }
  else if (strcmp(input, "add") == 0) { //if user enters "ADD" use the addStudent function to add a new student
     
    StudentList.push_back(addStudent()); 
    cout << "Student added\n";
  }
  else if (strcmp(input, "print") == 0) { //If user enters "Print" use printList function to print student list
       
       printList(StudentList);
  }
  else if (strcmp(input, "delete") == 0) { //If user enters "DELETE" use the delete student function to delete a student from the list
     
    deleteStudent(&StudentList);
    cin.clear();
    cin.ignore(999, '\n');
  }
  else //in case user enters something else
   {
    cout << "\nYour command was invalid. Please enter one of the following: add, print, delete, quit";
  }

  }  
  return 0;
}

void printList(vector<Student*> StudentList) {
  //function to print list
    if (StudentList.empty() == true) {
    cout << "Student list is empty. Please add students before printing! \n";
  }
  else {
   
  for (vector<Student*>:: iterator printAll = StudentList.begin(); printAll != StudentList.end(); ++printAll) {
    cout << (*printAll) -> firstName << " ";
    cout << (*printAll) -> lastName << ", ";
    cout << (*printAll) -> idNumber << ", ";
    cout << setprecision(2)<< fixed << (*printAll) -> GPA << "\n"; 
   }
}
}
void deleteStudent(vector<Student*>* StudentList) {
  //function to delete student using their ID number
  int StudentIDinput; 
  cout << "Which Student do you want to delete? \n";
  cin >> StudentIDinput;
  if (StudentList -> empty() == true) {
      cout << "Student List is Empty, Nothing to Delete! \n";
	  
      return;
  }
  else {
    //iterator finds student based on id number  
    for (vector<Student*>:: iterator find = StudentList -> begin(); find != StudentList -> end(); ++find) {
      if ((*find) -> idNumber == StudentIDinput) {
	delete *find;
	StudentList -> erase(find);
	return;
    }
      else {
	 
    }
  }
  }
} 
