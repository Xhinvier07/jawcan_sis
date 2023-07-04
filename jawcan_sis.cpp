
#include<iostream>
#include<fstream>
#include<stack>
#include<string>
#include <queue>
#include <limits> // Added for input validation
//#include<cstring>
//#include<iomanip>
using namespace std;

//function declarations
void studentAdd(); //function for adding a record
void studentDisplay();//function for displaying record list
void studentDelete();//function for deleting a record

void searchID();//function for searching by ID
void searchName();//function for searching by Name

void displayF();//function for displaying female records
void displayM();//function for displaying male records

void displayCS();//function for displaying cs records
void displayIT();//function for displaying it records
void displayMA();//function for displaying ma records
void displayCE();//function for displaying ce records
void displayCPE();//function for displaying cpe records
void displayEE();//function for displaying ee records
void displayECE();//function for displaying ece records
void displayME();//function for displaying me records

void display1Yr();//function for displaying 1styr records
void display2Yr();//function for displaying 2ndyr records
void display3Yr();//function for displaying 3rdyr records
void display4Yr();//function for displaying 4thyr records

// Student structure
class Student {
public: //public for accessing it globally around the program
    //variables for inputs
    string id;
    string name;
    string birthday;
    string address;
    string gender;
    string degree;
    string yearLvl;
    //functions and subfunctions
    void menu_program();
    void load_data();
    void save_data();
    void sub_search();
    void sub_display();

};

// Node structure for linked list
struct Node {
    Student data;
    Node* next;
};





Node* head = NULL;
Node* tail = NULL;
string database = "students.txt"; // declaring the text filename

// Function to load for fetch data from the database file
void Student::load_data() {
    ifstream file(database);
    if (file.is_open()) {
        while (!file.eof()) { //loading the data until the end of file
            Student student;
            //getting data from the file
            getline(file, student.id);
            getline(file, student.name);
            getline(file, student.birthday);
            getline(file, student.address);
            getline(file, student.gender);
            getline(file, student.degree);
            getline(file, student.yearLvl);

            if (!file.eof()) {
                Node* node = new Node;
                node->data = student;
                node->next = head;
                head = node;
            }
        }
        file.close();//closing the file
    }
    else {
        cout << "Unable to open file " << database << endl; // if the databa doesnt exist
    }

}



// Function to save student records to file
void Student::save_data() {
    ofstream file(database);
    if (file.is_open()) {
        Node* current = head;
        while (current != NULL) { //saving or adding data from the file
            file << current->data.id << endl;
            file << current->data.name << endl;
            file << current->data.birthday << endl;
            file << current->data.address << endl;
            file << current->data.gender << endl;
            file << current->data.degree << endl;
            file << current->data.yearLvl << endl;
            current = current->next;
        }
        file.close();
        cout << "----------------------\n";

    }
    else {
        cout << "Unable to open file " << database << endl;
    }
}

void Student::menu_program() {
    system("cls"); //clearing the console
    int choice;
    do {//loop for the menu
        cout << "===========================================================\n";
        cout << "            See# Student Information System                \n";//main menu
        cout << "===========================================================\n";
        cout << endl;
        cout << "[1] Add New Record\n";//adding new record of student
        cout << "[2] Search Record\n";//searching for record
        cout << "[3] Display Records\n";//display student records
        cout << "[4] Delete Record\n"; //deleting records
        cout << "[0] Exit\n";
        cout << "----------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "----------------------\n";
        switch (choice) {
        case 1:
            studentAdd();//executing adding function
            break;
        case 2:
            sub_search();//executing search function
            break;
        case 3:
            sub_display();//executing display function
            break;
        case 4:
            studentDelete();//executing delete function
            break;
        case 0:
            cout << "Exiting Program...\n";
            system("pause");
            exit(1);
            break;

        default:
            cout << "Invalid Input. Please try again.\n";
            system("pause");
            system("cls");
            menu_program();
            break;
        }
        cout << endl;
    } while (choice != 0);

}

//record searching menu
void Student::sub_search() {
    system("cls");
    int choice;
    do {
        cout << "===========================================================\n";
        cout << "                See#SIS Search Record List                 \n";
        cout << "===========================================================\n";
        cout << endl;
        cout << "[1] Search ID\n";
        cout << "[2] Search Name\n";
        cout << "[0] Back\n";
        cout << "----------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "----------------------\n";
        switch (choice) {
        case 1:
            searchID();
            break;
        case 2:
            searchName();
            break;

        case 0:
            menu_program();
            break;

        default:
            cout << "Invalid Input. Please try again.\n";
            system("pause");
            sub_search();
            break;
        }
        cout << endl;
    } while (choice != 0);

}

//record displaying menu
void Student::sub_display() {
    system("cls");
    int choice;
    do {
        cout << "===========================================================\n";
        cout << "                See#SIS Display Record List                 \n";
        cout << "===========================================================\n";
        cout << endl;
        cout << "[1]  Display All\n";
        cout << "[2]  Display Males\n";
        cout << "[3]  Display Females\n";
        cout << "[4]  Display BSCS\n";
        cout << "[5]  Display BSIT\n";
        cout << "[6]  Display BMA\n";
        cout << "[7]  Display BSCE\n";
        cout << "[8]  Display BSCPE\n";
        cout << "[9]  Display BSEE\n";
        cout << "[10] Display BSECE\n";
        cout << "[11] Display BSME\n";
        cout << "[12] Display 1st Year\n";
        cout << "[13] Display 2nd Year\n";
        cout << "[14] Display 3rd Year\n";
        cout << "[15] Display 4th Year\n";

        cout << "[0] Back\n";
        cout << "----------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "----------------------\n";
        switch (choice) {
        case 1:
            studentDisplay();
            break;
        case 2:
            displayM();
            break;
        case 3:
            displayF();
            break;
        case 4:
            displayCS();
            break;
        case 5:
            displayIT();
            break;

        case 6:
            displayMA();
            break;

        case 7:
            displayCE();
            break;

        case 8:
            displayCPE();
            break;

        case 9:
            displayEE();
            break;

        case 10:
            displayECE();
            break;

        case 11:
            displayME();
            break;

        case 12:
            display1Yr();
            break;

        case 13:
            display2Yr();
            break;

        case 14:
            display3Yr();
            break;

        case 15:
            display4Yr();
            break;

        case 0:
            menu_program();
            break;

        default:
            cout << "Invalid Input. Please try again.\n";
            system("pause");
            sub_search();
            break;
        }
        cout << endl;
    } while (choice != 0);

}


// Main function
int main() {
    Student menu;
    menu.load_data();
    menu.menu_program();
    return 0;
}


// Function to add a new student record
void studentAdd() {
    Student menu;
    string id;
    string name;
    string birthday;
    string month;
    int day;
    int year;
    string address;
    string gender;
    string degree;
    string yearLvl;
    bool checkletter = false;
    bool checkletter1 = false;
    bool checkletter2 = false;

    // Input for student ID
loop:
    Node* node = new Node;
    Node* previous = nullptr; // Changed from NULL
    Node* current = head;

    while (true) {
        cout << "Enter student ID (9 digits): ";
        getline(cin, id);

        if (id.size() == 9) {
            // Checking the length of the inputted characters if it is 9
            break;
        }

        cout << "Invalid Input! ex.(202212345)" << endl;
    }

    // Checking if the inputted ID exists in the database file
    while (current != nullptr) { // Changed from NULL
        if (current->data.id == id) {
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current != nullptr) { // Changed from NULL
        if (previous == nullptr) { // Changed from NULL
            head = current->next;
        }
        else {
            previous->next = current->next;
        }

        delete current; // Added to free memory

        cout << "Record Exists. Try again." << endl;
        goto loop; // Looping for checking if the ID already exists in the database
    }

    // Input for student name
    while (!checkletter) {
        cout << "Enter student Name: ";
        getline(cin, name);
        checkletter = true;

        for (int i = 0; i < name.length(); i++) {
            if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '.') {
                checkletter = false; // Checking if the inputted characters contain valid characters
                break;
            }

            if (name[i] >= 'a' && name[i] <= 'z') {
                name[i] = name[i] - 32; // Converting the inputted name to uppercase
            }
        }

        if (!checkletter) {
            cout << "Invalid Input. Characters only." << endl;
        }
    }

    // Input for student birth month
    while (true) {
        cout << "Enter student Birthmonth (ex. January, February): ";
        getline(cin, month);

        for (int i = 0; i < month.length(); i++) {
            if (month[i] >= 'a' && month[i] <= 'z') {
                month[i] = month[i] - 32; // Converting to uppercase
            }
        }

        if (month != "JANUARY" && month != "FEBRUARY" && month != "MARCH" && month != "APRIL" &&
            month != "MAY" && month != "JUNE" && month != "JULY" && month != "AUGUST" &&
            month != "SEPTEMBER" && month != "OCTOBER" && month != "NOVEMBER" && month != "DECEMBER") {
            cout << "Invalid Input. Valid months only (ex. January, December, March, etc.)." << endl;
        }
        else {
            break;
        }
    }

    // Input for student birth date
    while (true) {
        cout << "Enter student Birthdate (ex. 1, 2, 18, 31): ";
        cin >> day;

        if (cin.fail()) {
            cout << "Invalid Input. Numeric value required.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (day >= 1 && day <= 31) {
            // Day restriction from 1 to 31
            break;
        }
        else {
            cout << "Invalid Input. Valid days only (1 to 31)."<<endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
    }

    // Input for student birth year
    while (true) {
        cout << "Enter student Birthyear (ex. 1990, 2000, 2003): ";
        cin >> year;

        if (cin.fail()) {
            cout << "Invalid Input. Numeric value required.";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (year >= 1950 && year <= 2007) {
            // Year restriction from 1950 to 2007
            break;
        }
        else {
            cout << "Invalid Input. Valid years only (1950 to 2007)." << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
    }

    birthday = month + " " + to_string(day) + ", " + to_string(year); // Converting the inputted field for birthday into a fixed format
    cin.ignore(); // Ignore remaining input

    // Input for student address
    cout << "Enter student Address: ";
    getline(cin, address);

    // Input for gender (Male or Female)
    while (true) {
        cout << "Enter student Gender (Male or Female): ";
        getline(cin, gender);

        for (int i = 0; i < gender.length(); i++) {
            if (gender[i] >= 'a' && gender[i] <= 'z') {
                gender[i] = gender[i] - 32; // Converting to uppercase
            }
        }

        if (gender != "MALE" && gender != "FEMALE") {
            cout << "Invalid Input. Male or Female only." << endl;
        }
        else {
            break;
        }
    }

    // Input for student degree
    while (true) {
        cout << "Enter student Degree (ex. BSCS, BSIT): ";
        getline(cin, degree);

        for (int i = 0; i < degree.length(); i++) {
            if (!isalpha(degree[i]) && degree[i] != ' ') {
                checkletter = false;
                break;
            }

            if (degree[i] >= 'a' && degree[i] <= 'z') {
                degree[i] = degree[i] - 32; // Converting to uppercase
            }
        }

        if (degree != "BSCS" && degree != "BSIT" && degree != "BMA" && degree != "BSCE" &&
            degree != "BSCPE" && degree != "BSEE" && degree != "BSECE" && degree != "BSME") {
            cout << "Invalid Input. BSCS, BSIT, BMA, BSCE, BSCPE, BSEE, BSECE, BSME only." << endl;
        }
        else {
            break;
        }
    }

    // Input for year level
    while (true) {
        cout << "Enter student Year Level (1, 2, 3, 4): ";
        getline(cin, yearLvl);

        if (yearLvl != "1" && yearLvl != "2" && yearLvl != "3" && yearLvl != "4") {
            cout << "Invalid Input. 1, 2, 3, 4 only." << endl;
        }
        else {
            break;
        }
    }

    // Assigning the inputted values to the linked list which will be transferred to the text file database
    node->data.id = id;
    node->data.name = name;
    node->data.birthday = birthday;
    node->data.address = address;
    node->data.gender = gender;
    node->data.degree = degree;
    node->data.yearLvl = yearLvl;

    node->next = head;
    head = node;
    menu.save_data();
    cout << "Student record added successfully." << endl;
    cout << "----------------------\n";
    system("pause");
    system("cls");
}

//function for deleting student record by ID only
void studentDelete() {
    Student menu;
    Node* current = head;

    cout << "Enter student ID to be deleted: ";
    string id;
    getline(cin, id);

    // Find the node to delete

    Node* previous = NULL;
    while (current != NULL) {
        if (current->data.id == id) {
            break;
        }
        previous = current;
        current = current->next;
    }

    // Delete the node if found
    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        }
        else {
            previous->next = current->next;
        }
        delete current;
        menu.save_data();

        cout << "Student record deleted successfully." << endl;
        cout << "----------------------\n";
    }
    else {
        cout << "Student record not found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display all student records
void studentDisplay() {
    int record = 1;
    cout << "------------------------------------\n";
    cout << "------- STUDENT RECORDS LIST -------\n";
    cout << "------------------------------------\n";

    stack<Node*> recordStack;  // Stack to store student records

    Node* current = head;
    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
    }
    else {
        // Push all the records onto the stack
        while (current != NULL) {
            recordStack.push(current);
            current = current->next;
        }

        // Display records in reverse order using the stack
        while (!recordStack.empty()) {
            current = recordStack.top();
            recordStack.pop();

            cout << endl;
            cout << "STUDENT RECORD " << record << endl;
            cout << "Student ID: " << current->data.id << endl;
            cout << "Student Name: " << current->data.name << endl;
            cout << "Student Birthday: " << current->data.birthday << endl;
            cout << "Student Address: " << current->data.address << endl;
            cout << "Student Gender: " << current->data.gender << endl;
            cout << "Student Degree: " << current->data.degree << endl;
            cout << "Student Year Level: " << current->data.yearLvl << endl;
            cout << "---------------------------\n";
            record++;
        }
    }

    system("pause");
    system("cls");
}

// Function to display male students
void displayM() {
    int record = 1;
    cout << "-----------------------------------------\n";
    cout << "------- MALE STUDENT RECORDS LIST -------\n";
    cout << "-----------------------------------------\n";

    stack<Node*> recordStack;  // Stack to store male student records

    Node* current = head;
    bool foundGender = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push male student records onto the stack
    while (current != NULL) {
        if (current->data.gender == "MALE") {
            foundGender = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display male student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundGender) {
        cout << endl;
        cout << "No Male student records found." << endl;
    }

    system("pause");
    system("cls");
}

//function to display female students
void displayF() {
    int record = 1;
    cout << "-------------------------------------------\n";
    cout << "------- FEMALE STUDENT RECORDS LIST -------\n";
    cout << "-------------------------------------------\n";

    Node* current = head;
    stack<Node*> femaleStack; // Stack to store female student records

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    while (current != NULL) {
        if (current->data.gender == "FEMALE") {
            femaleStack.push(current); // Push female records onto the stack
        }
        current = current->next;
    }

    if (femaleStack.empty()) {
        cout << endl;
        cout << "No Female student records found." << endl;
    }
    else {
        while (!femaleStack.empty()) {
            current = femaleStack.top(); // Get the top record from the stack
            femaleStack.pop(); // Pop the top record from the stack

            cout << endl;
            cout << "STUDENT RECORD " << record << endl;
            cout << "Student ID: " << current->data.id << endl;
            cout << "Student Name: " << current->data.name << endl;
            cout << "Student Birthday: " << current->data.birthday << endl;
            cout << "Student Address: " << current->data.address << endl;
            cout << "Student Gender: " << current->data.gender << endl;
            cout << "Student Degree: " << current->data.degree << endl;
            cout << "Student Year Level: " << current->data.yearLvl << endl;
            cout << "---------------------------\n";
            record++;
        }
    }

    system("pause");
    system("cls");
}

// Function to display CS students
void displayCS() {
    int record = 1;
    cout << "---------------------------------\n";
    cout << "------- BSCS RECORDS LIST -------\n";
    cout << "---------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSCS student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSCS student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSCS") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSCS student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSCS student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display IT students
void displayIT() {
    int record = 1;
    cout << "---------------------------------\n";
    cout << "------- BSIT RECORDS LIST -------\n";
    cout << "---------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSIT student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSIT student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSIT") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSIT student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSIT student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display MA students
void displayMA() {
    int record = 1;
    cout << "--------------------------------\n";
    cout << "------- BMA RECORDS LIST -------\n";
    cout << "--------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BMA student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BMA student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BMA") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BMA student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BMA student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display CE students
void displayCE() {
    int record = 1;
    cout << "---------------------------------\n";
    cout << "------- BSCE RECORDS LIST -------\n";
    cout << "---------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSCE student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSCE student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSCE") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSCE student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSCE student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display CPE students
void displayCPE() {
    int record = 1;
    cout << "----------------------------------\n";
    cout << "------- BSCPE RECORDS LIST -------\n";
    cout << "----------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSCPE student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSCPE student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSCPE") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSCPE student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSCPE student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display EE students
void displayEE() {
    int record = 1;
    cout << "---------------------------------\n";
    cout << "------- BSEE RECORDS LIST -------\n";
    cout << "---------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSEE student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSEE student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSEE") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSEE student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSEE student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display ECE students
void displayECE() {
    int record = 1;
    cout << "----------------------------------\n";
    cout << "------- BSECE RECORDS LIST -------\n";
    cout << "----------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSECE student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSECE student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSECE") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSECE student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSECE student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display ME students
void displayME() {
    int record = 1;
    cout << "----------------------------------\n";
    cout << "------- BSME RECORDS LIST -------\n";
    cout << "----------------------------------\n";

    stack<Node*> recordStack;  // Stack to store BSME student records

    Node* current = head;
    bool foundDegree = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Push BSME student records onto the stack
    while (current != NULL) {
        if (current->data.degree == "BSME") {
            foundDegree = true;
            recordStack.push(current);
        }
        current = current->next;
    }

    // Display BSME student records in reverse order using the stack
    while (!recordStack.empty()) {
        current = recordStack.top();
        recordStack.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundDegree) {
        cout << endl;
        cout << "No BSME student records found." << endl;
    }

    system("pause");
    system("cls");
}

#include <queue>

// Function to display 1st year students
void display1Yr() {
    int record = 1;
    cout << "---------------------------------------------\n";
    cout << "------- 1ST YEAR STUDENT RECORDS LIST -------\n";
    cout << "---------------------------------------------\n";

    queue<Node*> recordQueue;  // Queue to store 1st year student records

    Node* current = head;
    bool foundYear = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Enqueue 1st year student records into the queue
    while (current != NULL) {
        if (current->data.yearLvl == "1") {
            foundYear = true;
            recordQueue.push(current);
        }
        current = current->next;
    }

    // Display 1st year student records in the order they were enqueued
    while (!recordQueue.empty()) {
        current = recordQueue.front();
        recordQueue.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundYear) {
        cout << endl;
        cout << "No 1st Year student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to display 2nd year students
void display2Yr() {
    int record = 1;
    cout << "---------------------------------------------\n";
    cout << "------- 2ND YEAR STUDENT RECORDS LIST -------\n";
    cout << "---------------------------------------------\n";

    queue<Node*> recordQueue;  // Queue to store 2nd year student records

    Node* current = head;
    bool foundYear = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Enqueue 2nd year student records into the queue
    while (current != NULL) {
        if (current->data.yearLvl == "2") {
            foundYear = true;
            recordQueue.push(current);
        }
        current = current->next;
    }

    // Display 2nd year student records in the order they were enqueued
    while (!recordQueue.empty()) {
        current = recordQueue.front();
        recordQueue.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundYear) {
        cout << endl;
        cout << "No 2nd Year student records found." << endl;
    }

    system("pause");
    system("cls");
}


// Function to display 3rd year students
void display3Yr() {
    int record = 1;
    cout << "---------------------------------------------\n";
    cout << "------- 3RD YEAR STUDENT RECORDS LIST -------\n";
    cout << "---------------------------------------------\n";

    queue<Node*> recordQueue;  // Queue to store 3rd year student records

    Node* current = head;
    bool foundYear = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Enqueue 3rd year student records into the queue
    while (current != NULL) {
        if (current->data.yearLvl == "3") {
            foundYear = true;
            recordQueue.push(current);
        }
        current = current->next;
    }

    // Display 3rd year student records in the order they were enqueued
    while (!recordQueue.empty()) {
        current = recordQueue.front();
        recordQueue.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << current->data.id << endl;
        cout << "Student Name: " << current->data.name << endl;
        cout << "Student Birthday: " << current->data.birthday << endl;
        cout << "Student Address: " << current->data.address << endl;
        cout << "Student Gender: " << current->data.gender << endl;
        cout << "Student Degree: " << current->data.degree << endl;
        cout << "Student Year Level: " << current->data.yearLvl << endl;
        cout << "---------------------------\n";
        record++;
    }

    if (!foundYear) {
        cout << endl;
        cout << "No 3rd Year student records found." << endl;
    }

    system("pause");
    system("cls");
}


// Function to display 4th year students
void display4Yr() {
    int record = 1;
    cout << "---------------------------------------------\n";
    cout << "------- 4TH YEAR STUDENT RECORDS LIST -------\n";
    cout << "---------------------------------------------\n";

    queue<Node*> recordQueue;  // Queue to store 4th year student records

    Node* current = head;
    bool foundYear = false;

    if (head == NULL) {
        cout << endl;
        cout << "No student records found." << endl;
        system("pause");
        system("cls");
        return;
    }

    // Enqueue 4th year student records into the queue
    while (current != NULL) {
        if (current->data.yearLvl == "4") {
            foundYear = true;
            recordQueue.push(current);
        }
        current = current->next;
    }

    // Dequeue and display the 4th year student records from the queue
    while (!recordQueue.empty()) {
        Node* student = recordQueue.front();
        recordQueue.pop();

        cout << endl;
        cout << "STUDENT RECORD " << record << endl;
        cout << "Student ID: " << student->data.id << endl;
        cout << "Student Name: " << student->data.name << endl;
        cout << "Student Birthday: " << student->data.birthday << endl;
        cout << "Student Address: " << student->data.address << endl;
        cout << "Student Gender: " << student->data.gender << endl;
        cout << "Student Degree: " << student->data.degree << endl;
        cout << "Student Year Level: " << student->data.yearLvl << endl;
        cout << "---------------------------\n";

        record++;
    }

    if (!foundYear) {
        cout << endl;
        cout << "No 4th Year student records found." << endl;
    }

    system("pause");
    system("cls");
}

// Function to search by ID
void searchID() {
    cout << "Enter student ID to be searched: ";
    string id;
    getline(cin, id);

    stack<Node*> recordStack;  // Stack to store student records

    Node* current = head;

    while (current != NULL) {
        if (current->data.id == id) {
            // Student record found, display the information
            cout << "Student ID: " << current->data.id << endl;
            cout << "Student Name: " << current->data.name << endl;
            cout << "Student Birthday: " << current->data.birthday << endl;
            cout << "Student Address: " << current->data.address << endl;
            cout << "Student Gender: " << current->data.gender << endl;
            cout << "Student Degree: " << current->data.degree << endl;
            cout << "Student Year Level: " << current->data.yearLvl << endl;
            cout << "---------------------------\n";

            while (!recordStack.empty()) {
                // Clear the stack by popping all elements
                recordStack.pop();
            }

            system("pause");
            system("cls");
            return;
        }
        recordStack.push(current);  // Push the current record to the stack
        current = current->next;
    }

    // No match found, display not found message
    cout << "Student record not found." << endl;

    while (!recordStack.empty()) {
        // Clear the stack by popping all elements
        recordStack.pop();
    }

    system("pause");
    system("cls");
}


// Function to search by name
void searchName() {
    cout << "Enter student name to be searched: ";
    string name;
    getline(cin, name);
    for (int i = 0; i < name.length(); i++) {
        if (name[i] >= 'a' && name[i] <= 'z') {
            name[i] = name[i] - 32; // Convert to uppercase
        }
    }

    Node* current = head;
    bool found = false;

    while (current != NULL) {
        // If the inputted name is found in one of the database records, display the information
        if (current->data.name == name) {
            cout << "Student ID: " << current->data.id << endl;
            cout << "Student Name: " << current->data.name << endl;
            cout << "Student Birthday: " << current->data.birthday << endl;
            cout << "Student Address: " << current->data.address << endl;
            cout << "Student Gender: " << current->data.gender << endl;
            cout << "Student Degree: " << current->data.degree << endl;
            cout << "Student Year Level: " << current->data.yearLvl << endl;
            cout << "---------------------------\n";
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Student record not found." << endl;
    }

    system("pause");
    system("cls");
}
