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

            //This function takes input from user about Player Details
            //The input taken by this function is stored in the File using writeFile() function
        void input() {

            cout << "\nEnter Student id no: ";
            cin >> studentId;
            cout << "\nEnter Student age: ";
            cin >> studentAge;

            //input Player Name as First Name and Second Name
            string strFname = "", strLname = "";
            cout << "\nEnter the First Name of Student: ";
            cin >> strFname;
            cout << "\nEnter the Last Name of Student: ";
            cin >> strLname;
            studentName = strFname + " " + strLname;//Stores the Player as Fname_Lname

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
        cout << "\n9: Count the Total no. of Player's Record";
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
        //case 3: deleteInRecords(1);//3: Delete Player by its Player Id from Record
        //    break;
        //case 4: deleteInRecords(2);//4: Delete Player by its Player Name from Record
        //    break;
        //case 5: searchInRecords(1);//5: Search Player using "Player Name"
        //    break;
        //case 6: searchInRecords(2);//6: Search Player using "Player Id"
        //    break;
        //case 7: searchInRecords(6);//10: Search Player's details of particular "Game"
        //    break; v
        //case 8: countPlayersInGame();//11: Count Players in all Games;
        //    break;
        //case 9: countPlayers();//12: Count Players in individual game
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