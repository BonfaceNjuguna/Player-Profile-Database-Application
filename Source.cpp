#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h> 
#include<conio.h>

using namespace std;

class file
{
    private:
        int StudentId;
        string StudentName;
        int StudentAge;
        long long StudentPhno;
        char module[30];
        string teacherName;


    public:

            
        void input() {

            cout << "\nEnter Student id no: ";
            cin >> StudentId;
            cout << "\nEnter Student age: ";
            cin >> StudentAge;

            string strName = "";
            cout << "\nEnter the Name of Student: ";
            cin >> strName;
            StudentName = strName;

            cout << "\nEnter Student phone no.: ";
            cin >> StudentPhno;

            cout << "\nEnter module name 'c++', 'c#', 'java', 'go', 'php', 'dart', '3D'\nModule Name: ";
            cin >> module;

            cout << "\nEnter the Name of Teacher: ";
            cin >> strName;
            teacherName = strName;
        }
        void output() {
            cout << "\n Student Details: \n";
            cout << "StudentId==>" << StudentId << endl;
            cout << "Student name==>" << StudentName << endl;
            cout << "phone no==>" << StudentPhno << endl;
            cout << "module taken==>" << module << endl;
            cout << "coach assigned==>" << teacherName << endl;
        }


        string retStudentname() {
            return StudentName;
        }


        int retStudentid() {
            return StudentId;
        }

        int retStudentage() {
            return StudentAge;
        }

        long long  rStudentphno() {
            return StudentPhno;
        }

        char* rStudentmodule() {
            return module;
        }

        string rteachername() {
            return teacherName;
        }
};

void writeInFile(file fobj) {

    char arr[] = "     ";
    ofstream fout;
    fout.open("StudentsRecord.txt", ios::out | ios::app);

    fout << fobj.retStudentid(); fout << arr;
    fout << fobj.retStudentname(); fout << arr;
    fout << fobj.retStudentage(); fout << arr;
    fout << fobj.rStudentphno(); fout << arr;
    fout << fobj.rStudentmodule(); fout << arr;
    fout << fobj.rteachername(); fout << arr;

    fout << '\n';


    fout.close();

}

void deleteInRecords(int choice) {

    string deleteString;
    string strName = "";
    if (choice == 1) {   
        cout << "Enter the Student's Id whose record needs to be deleted\n";
        cin >> deleteString;
        deleteString = "id" + deleteString;
        cout << "deleteString: " << deleteString << endl;
    }
    else {              
        cout << "Enter the  Name of Student: ";
        cin >> strName;
        deleteString = strName;
        cout << "deleteString: " << deleteString << endl;
    }


    ifstream readFile;
    ofstream writeFile("sample.txt");

    char charsInLine[1024];

    readFile.open("StudentsRecord.txt");
    int count = 0;
    bool found = false;
    while (!readFile.eof()) {

        readFile.getline(charsInLine, 1024);
        string strLine(charsInLine);
        cout << count << ": " << charsInLine << endl;

        size_t found = strLine.find(deleteString);

        if (found != string::npos) {

            found = true;
            break;
        }

        else {
            writeFile << charsInLine;
            writeFile << "\n";
        }
        count++;

    }

    readFile.close(); 
    writeFile.close();

    remove("StudentsRecord.txt"); 
    rename("sample.txt", "StudentsRecord.txt"); 

   //if no records found with entered Id or Name
    if (found == false) {
        cout << "No records available...!\n";
    }
}

void countStudents() {
    ifstream readFile;
    char charsInLine[1024];
    int countStudent = 0;

    readFile.open("StudentsRecord.txt"); 
    while (!readFile.eof()) {

        readFile.getline(charsInLine, 1024);
        string strLine(charsInLine); 

        
        size_t found = strLine.find("id"); 

        if (found != string::npos) {
            countStudent++;
            cout << charsInLine << endl; 
        }
        else {
            break;
        }
    }

    cout << "Number of Students available in our Records: " << countStudent << endl;
    readFile.close(); 

}

//show all records
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
//count the number of Students in a module
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
        int countmodule = 0;

        ifstream readFile;
        readFile.open("StudentsRecord.txt");

        while (!readFile.eof()) {

            readFile.getline(charsInLine, 1024);
            string strLine(charsInLine);


            size_t found = strLine.find(moduleName);
            if (found != string::npos) {
                countmodule++;
            }
        }

        readFile.close();

        cout << "No. of Students enrolled in " << moduleName << ": " << countmodule << endl;
        countmodule = 0; 
    }
}

//search the record
//void searchInRecords(int choice) {
//    string searchString = "";
//    string strName = "";
//
//    switch (choice) {
//
//    case 1:
//        cout << "Enter the Name of Student: ";
//        cin >> strName;
//        searchString = strName;
//        cout << "Search String: " << searchString << endl;
//        break;
//
//    case 2: cout << "Enter the Student Id: ";
//        cin >> searchString;
//        searchString = searchString;
//        cout << "Search String: " << searchString << endl;
//        break;
//
//    case 4: cout << "Enter Student's module name 'c++', 'c#', 'java', 'go', 'php', 'dart', '3D' : ";
//        cin >> searchString;
//        break;
//
//    case 5: cout << "Wrong Input..! Enter your choice again...\n";
//        break;
//
//    }
//
//
//    ifstream readFile;
//    readFile.open("StudentsRecord.txt");
//    char charsInLine[1024]; int count = 0;  
//    searchString = searchString + " ";
//
//    while (!readFile.eof()) {
//        readFile.getline(charsInLine, 1024);
//
//        string strLine(charsInLine);  
//
//        size_t found = strLine.find(searchString); //stores the info whether a particular string(module) form in the line of not
//
//        if (found != string::npos) {
//            count++;
//            cout << "Records " << count << " : " << charsInLine << endl;
//        }
//    }
//
//    readFile.close();
//    if (count == 0)
//        cout << "NO records found...!\n";
//    else {
//        cout << "No. of Records found for " << searchString << ": " << count << endl;
//    }
//}

//clear records
void clearCompleteDatabase() {
    int x;
    cout << "Do you want to delete the complete database of Students...?\n Press 1 to confirm: ";
    cin >> x;

    if (x == 1) {
        remove("StudentsRecord.txt");
        ofstream writeFile("StudentsRecord.txt"); 
        writeFile.close();
    }
}

int main() {

    file fileobj;   

    while (1) {
        int choice;
        cout << "\n\n= AIE StudentS MANAGEMENT MENU =";
        cout << "\n1: Add a new Student Record";
        cout << "\n2: Show all Students Record";
        cout << "\n3: Delete Student by Student Id from Record";
        //cout << "\n4: Delete Student by Student Name from Record";
        //cout << "\n5: Search Student using Student Name";
        //cout << "\n4: Search Student using Student Id";
        cout << "\n4: Search Student in a specific Module";
        //cout << "\n8: Count the No. of Students in all Modules";
        //cout << "\n9: Count the Total no. of Student's Record";
        cout << "\n5: Clear the complete database of Students's Record";
        cout << "\n6: Exit from Program";

        cout << "\n\nEnter your choice...!\n";
        cin >> choice;
        system("cls");

        switch (choice) {

        case 1: fileobj.input();
            writeInFile(fileobj);
            break;
        case 2: showAllRecords();
            break;
        case 3: deleteInRecords(1);
            break;
        //case 4: deleteInRecords(2);
        //    break;
        //case 5: searchInRecords(1);
        //    break;
        //case 4: searchInRecords(2);
        //    break;
        case 4: countStudentsInmodule();
            break;
        //case 8: countStudentsInmodule();
        //    break;
        //case 9: countStudents();
        //    break;
        case 5: clearCompleteDatabase();
            break;
        case 6: cout << "Exiting from program...\n";
            exit(0);  
        default: cout << "Wrong Choice..! enter your choice again...\n";
            break;

        }
    }
}