#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h> 
#include<conio.h>

using namespace std;

class file
{
    private:
        int studentId;
        string studentName;
        int studentAge;
        long long studentPhno;
        char module[30];
        string teacherName;


    public:

            //This function takes input from user about Student Details
            //The input taken by this function is stored in the File using writeFile() function
        void input() {

            cout << "\nEnter Student id no: ";
            cin >> studentId;
            cout << "\nEnter Student age: ";
            cin >> studentAge;

            //input Student Name as First Name and Second Name
            string strFname = "", strLname = "";
            cout << "\nEnter the First Name of Student: ";
            cin >> strFname;
            cout << "\nEnter the Last Name of Student: ";
            cin >> strLname;
            studentName = strFname + " " + strLname;//Stores the Student as Fname_Lname

            cout << "\nEnter Student phone no.: ";
            cin >> studentPhno;

            cout << "\nEnter module name 'c++', 'c#', 'java', 'go', 'php', 'dart', '3D'\nModule Name: ";
            cin >> module;

            //Taking input of coach name as Fname and Lname
            cout << "\nEnter the First Name of Teacher: ";
            cin >> strFname;
            cout << "\nEnter the Last Name of Teacher: ";
            cin >> strLname;
            teacherName = strFname + " " + strLname;
        }
        void output() {
            cout << "\n Student Details: \n";
            cout << "studentId==>" << studentId << endl;
            cout << "student name==>" << studentName << endl;
            cout << "phone no==>" << studentPhno << endl;
            cout << "module taken==>" << module << endl;
            cout << "coach assigned==>" << teacherName << endl;
        }


        string retstudentname() {
            return studentName;
        }


        int retstudentid() {
            return studentId;
        }

        int retstudentage() {
            return studentAge;
        }

        long long  rstudentphno() {
            return studentPhno;
        }

        char* rstudentmodule() {
            return module;
        }

        string rteachername() {
            return teacherName;
        }
};

void showAllRecords() {

    ifstream readFile;
    readFile.open("StudentsRecord.txt");
    char charsInLine[1024];
    int count = 0;
    cout << "Students records :\n\n";
    while (!readFile.eof()) {
        readFile.getline(charsInLine, 1024);
        cout << charsInLine << endl;
    }
    readFile.close();

}

void countStudentsInmodule() {

    ifstream readFile;
    readFile.open("StudentsRecord.txt");
    char charsInLine[1024];
    int count = 0;  

   //list of module available
    string modules[7] = { "c++","c#","java","go","php", "dart", "3D" };
    string moduleName = "";


    for (int i = 0; i < 7; i++) {    

        moduleName = modules[i];
       // cout<<"moduleName: "<<moduleName<<endl;
        int countmodule = 0;

        ifstream readFile;
        readFile.open("StudentsRecord.txt");

        while (!readFile.eof()) {

            readFile.getline(charsInLine, 1024);
            string strLine(charsInLine);


            size_t found = strLine.find(moduleName);
            if (found != string::npos) {
                countmodule++;
                //cout<<charsInLine<<endl;

            }
        }

        readFile.close();

        cout << "No. of Students enrolled in " << moduleName << ": " << countmodule << endl;
        countmodule = 0; //initializing again as 0 to count for next module
    }
}

void searchInRecords(int choice) {
    // char module[12];  //string module
    string searchString = "";
    string strFname = "", strLname = "";

    switch (choice) {

    case 1: //string strFname="", strLname="";
        cout << "Enter the First Name of Student: ";
        cin >> strFname;
        cout << "Enter the Last Name of Student: ";
        cin >> strLname;
        searchString = strFname + " " + strLname;  //ex. Aastha_Anand  here Fname= Aastha Lname= Anand
        cout << "Search String: " << searchString << endl;
        break;

    case 2: cout << "Enter the Student Id: ";
        cin >> searchString;
        searchString = "id" + searchString;
        cout << "Search String: " << searchString << endl;
        break;

    case 4: cout << "Enter Student's module name 'c++', 'c#', 'java', 'go', 'php', 'dart', '3D' : ";
        cin >> searchString;
        break;

    case 5: cout << "Wrong Input..! Enter your choice again...\n";
        break;

    }


    ifstream readFile;
    readFile.open("StudentsRecord.txt");
    char charsInLine[1024]; int count = 0;  
    searchString = searchString + " ";

    while (!readFile.eof()) {
        //cout<<"Im inside while\n";
        readFile.getline(charsInLine, 1024);
        //   cout<<"Records row: "<<charsInLine<<endl;

        string strLine(charsInLine);  //Casting a char array to string

        size_t found = strLine.find(searchString); //stores the info whether a particular string(module) form in the line of not

        if (found != string::npos) {
            count++;
            cout << "Records " << count << " : " << charsInLine << endl;  //printing the Record for the module
        }
    }

    readFile.close();
    if (count == 0)
        cout << "NO records found...!\n";
    else {
        cout << "No. of Records found for " << searchString << ": " << count << endl;
    }
}


void clearCompleteDatabase() {
    int x;
    cout << "Do you want to delete the complete database of Stdents...?\n Press 1 to confirm: ";
    cin >> x;

    if (x == 1) {
        remove("StudentsRecord.txt"); //Delete the file
        ofstream writeFile("StudentsRecord.txt");  //Creates a new empty
        writeFile.close(); //closes the file
    }
}

int main() {

    //file fileobj;   //Instance(object) of file class

    while (1) {
        int choice;
        cout << "\n\n=============== AIE STUDENTS MANAGEMENT MENU ===================";
        cout << "\n1: Add a new Student Record";
        cout << "\n2: Show all Students Record";
        cout << "\n3: Delete Student by Student Id from Record";
        cout << "\n4: Delete Student by Student Name from Record";
        cout << "\n5: Search Student using Student Name";
        cout << "\n6: Search Student using Student Id";
        cout << "\n7: Search Student in a specific Module";
        cout << "\n8: Count the No. of Students in all Modules";
        cout << "\n9: Count the Total no. of Student's Record";
        cout << "\n10: Clear the complete database of Students's Record";
        cout << "\n11: Exit from Program";

        cout << "\n\nEnter your choice...!\n";
        cin >> choice;
        system("cls");//clearing the console

        //switch (choice) {

        //case 1: fileobj.input();  //Takes input for the instance
        //    writeInFile(fileobj); //1: Writes the Input Record in File
        //    break;
        //case 2: showAllRecords();
        //    break;
        //case 3: deleteInRecords(1);//3: Delete Student by its Student Id from Record
        //    break;
        //case 4: deleteInRecords(2);//4: Delete Student by its Student Name from Record
        //    break;
        //case 5: searchInRecords(1);//5: Search Student using "Student Name"
        //    break;
        //case 6: searchInRecords(2);//6: Search Student using "Student Id"
        //    break;
        //case 7: searchInRecords(6);//10: Search Student's details of particular "module"
        //    break; v
        //case 8: countStudentsInmodule();//11: Count Students in all modules;
        //    break;
        //case 9: countStudents();//12: Count Students in individual module
        //    break;
        //case 10: clearCompleteDatabase();
        //    break;
        //case 11: cout << "Exiting from program...\n";
        //    exit(0);  //closes the program
        //default: cout << "Wrong Choice..! enter your choice again...\n";
        //    break;

        //}//end of switch;
    }//end of while

}//end of main