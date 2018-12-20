#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
//#include <person.h>

using namespace std;

template <class var>

void print(var textline){
    cout << textline;
}



//structs
struct course {
    int level;
    string subjects[10];
};

struct record{
    int Semester;
    int credit_hour;
    string course_name;
    int Mark;
    string Grade;
};


class person
{
    public:
        person()
        {
            //set empty student name = ""
            status = "null";
        }
        //setter functions for student
        void setName(string val){
            name = val;
        }

        void setStatus(string val){
            status = val;
        }

        void setAge(int val){
            age = val;
        }

        void setID(int val){
            object_id = val;
        }

        void setIndex(int val){
            index = val;
        }

        void setResidence(string val){
            residence = val;
        }

        void listItems(vector <string> arrayVar){
            int len = arrayVar.size();
            for (int i=0;i<len;i++){
                cout<<arrayVar[i];
                if ((i+1)%3 == 0){
                    cout<<"\n";
                }else{
                    cout<<"\t\t";
                }
            }
        }


        //getter functions for student
        string getName(){
            return name;
        }

        string getStatus(){
            return status;
        }

        int getAge(){
            return age;
        }

        string getResidence(){
            return residence;
        }

        string getType(){
            return "person";
        }

        int getID(){
            return object_id;
        }

        int getIndex(){
            return index;
        }

        void getInfo(){
            cout << "\nname       : " << getName() << "\nage        : " << getAge() << "\nperson ID    : " << getID() <<endl;
        }

    private:
        string name;
        int age;
        int index;
        int object_id;
        string status;
        string residence;
};


struct student{
    person details;
    int level;
    string course;
    string department;
    vector<string> subjects;
    vector<record> academic_records;
};

struct staff{
    person details;
    string job;
    string department;
    vector<string> subjects;
};


//###  functions prototypes  ##########
void addStudent(),editStudent(),manageStudent(),calGPA(student obj);
void addStaff(),editStaff(),manageStaff(),calGpa(student obj);
string lower(string line),calgrade(double score);

student Student_Container[100000];
staff Staff_Container[100000];


int student_base_id=10900000;
int staff_base_id=11900000;
int student_count = 0;
int staff_count = 0;
string opt;int num;

int main()
{
    cout<<"Welcome to the School Management system"<<endl;
    string option;

    //this is the engine that runs the app
    //functions are at the bottom of this file
    while (true){
         cout<<"select an option :"<<endl;
       cout<<"1. student"<<endl<<"2. staff"<<endl<<"#. exit"<<endl;
       cout<<endl;
       cin >> opt;
       if (opt == "1"){
            cout<<"Options for student"<<endl;//change this print statement
            while (true){
                cout<<"1. Add "<<endl<<"2. Edit "<<endl<<"3. Manage"<<endl<<"#. exit"<<endl;
                cout<<"select an option : "<<endl;
                cin >> option;
                if (option == "1"){
                    addStudent();//to add students...
                }
                else if (option == "2"){
                    editStudent();//edit stuent object
                }
                else if (option == "3"){
                    manageStudent();//delete student object;
                }
                else if (option == "#"){
                    break;
                }
                cin.clear();
            }
        }
        else if (opt == "2"){
            cout<<"staff"<<endl;
            while (true){
                cout<<"1. add "<<endl<<"2. edit "<<endl<<"3. manage"<<endl<<"#. exit"<<endl;
                cout<<"select an option : "<<endl;
                cin >> option;
                if (option == "1"){
                    addStaff();
                }
                else if (option == "2"){
                    editStaff();
                }
                else if (option == "3"){
                    manageStaff();
                }
                else if (option == "#"){
                    break;
                }
                cin.clear();
            }
        }
        else if (opt == "#"){
            break;
        }
    }
    return 0;
}


void addStudent(){
    //add student detail....read class and struct
    cin.clear();
    cout<<endl;
    cout<<endl;
    cout<<"##############  NEW STUDENT ########"<<endl;
    student newp;
    cout<<"Assigned Student's ID : "<<student_base_id+student_count<<endl;
    newp.details.setID(student_base_id+student_count);newp.details.setIndex(student_count);student_count++;
    string opt;int num;
    cout<<"Enter Student's Name : "<<endl;
    cin.ignore();getline(cin, opt);cin.clear();
    newp.details.setName(opt);
    cout<<"Enter Student's Age : "<<endl;
    cin >> num;
    while (cin.fail()){
        cout<<" Invalid ..... Try Again : "<<endl;
        cin.clear();cin.ignore();cin >> num;
    }
    newp.details.setAge(num);
    //list department for student to choose from
    cout<<"Enter Department's Name : "<<endl;
    cin >> opt;
    newp.department = opt;
    //list course using department
    cout<<"Enter the student's course : "<<endl;
    cin >> opt;
    newp.course = opt;
    //set controls
    cout<<"Enter the level of student  : ";
    cin >> num;
    while (cin.fail()){
        cout<<"Invalid.......Try Again : "<<endl;
        cin.clear();cin.ignore();cin >> num;
    }
    while (num != 100 && num != 200 && num != 300 && num != 400){
        cout<<" Invalid...... Enter correct Level  : ";
        cin >> num;
        while (cin.fail()){
            cout<<" Invalid.....Enter level like 100,200,300,400 : "<<endl;
            cin.clear();cin.ignore();cin >> num;
        }
    }
    newp.level = num;

    //pushing to array
    Student_Container[newp.details.getIndex()] = newp;

    cout<<"Do you want to add another student? (yes/no) : "<<endl;
    cin >> opt;
    if (opt == "yes"){
        addStudent();
    }
    else{
        //pass
    }

};

void editStudent(){
//search student
int pass = 1;
cout<<"( Edit ) Enter students ID or 0 to exit : "<<endl;
int student_id;
cin >> student_id;
while (cin.fail()){
    cout<<" Invalid.......Try Again : "<<endl;
    cin.clear();cin.ignore();cin >> student_id;
}
if (student_id != 0){

    student_id -= student_base_id;
    //controls
    while (student_id < 0 || student_id >= student_count){
        cout<<"Invalid.........Enter Students ID or 0 to exit : "<<endl;
        cin >> student_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            cout<<" Invalid ........Enter a valid student ID(109.... or 119....)  : "<<endl;
            cin >> student_id;
        }
        if(student_id != 0){
            student_id -= student_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        cout<<"Student Found"<<endl;
        student obj = Student_Container[student_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true){
            cout<<"1. name "<<endl<<"2. age "<<endl<<"3. level "<<endl<<"4. course "<<endl<<"5. department "<<endl<<"6. student subjects "<<endl<<"0. exit"<<endl;
            cout<<"Enter corresponding number to edit what you want  : "<<endl;
            string edit;
            cin >> edit;
            if (edit == "1"){
                cout<<"Students name : "<<endl<<obj.details.getName();
                cout<<"Enter new student's name : "<<endl;
                cin.ignore();getline(cin, opt);cin.clear();
            }
            else if (edit == "2"){
                cout<<"Students age : "<<endl<<obj.details.getAge();
                cout<<"Enter new age : "<<endl;
                cin >> num;
                while (cin.fail()){
                    cout<<" Invalid ......Try Again : "<<endl;
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                cout<<"Students level : "<<endl<<obj.level;
                cout<<"Enter student's level : "<<endl;
                cin >> num;
                while (cin.fail()){
                    cout<<"Invalid......Try Again : "<<endl;
                    cin.clear();cin.ignore();cin >> num;
                }
                while (num != 100 && num != 200 && num != 300 && num != 400){
                    cout<<"Change to 100,200,300 or 400 : "<<endl;
                    cin >> num;
                    while (cin.fail()){
                        cout<<" Invalid......Try Again : "<<endl;
                     cin.clear();cin.ignore();cin >> num;
                    }
                }
                obj.level = num;
            }
            else if (edit == "4"){
                cout<<"Students course : "<<endl<<obj.course;
                cin.ignore();getline(cin, opt);cin.clear();
                obj.course = opt;
            }
            else if (edit == "5"){
                cout<<"Students Department : "<<endl<<obj.department;
                cout<<"Enter new student's department : "<<endl;
                cin.ignore();getline(cin, opt);cin.clear();
                obj.department = opt;
            }
            else if (edit == "6"){
                cout<<"Students subject : "<<endl;//list obj.subjects;
                while (true){
                    cout<<"1. add subject"<<endl<<"2. remove subject"<<endl<<"0. exit"<<endl;
                    cout<<"select an option : "<<endl;
                    cin >> opt;
                    if (opt == "1"){
                        cin.ignore();
                        while (true){
                            cout<<"Enter subject to add or  0 to leave : "<<endl;
                            getline(cin, opt);
                            if (opt== "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(opt);
                               record _new;
                               _new.course_name = opt;
                               _new.Mark = -1;
                               obj.academic_records.push_back(_new);
                            }
                        }

                    }
                    else if (opt == "2"){
                        cin.ignore();
                        while (true){
                            cout<<"Enter subject to remove or use 0 to leave : "<<endl;
                            getline(cin, opt);
                            if (opt == "0"){
                                break;
                            }
                            else{
                                int leng = obj.subjects.size();
                                for (int i=0;i<leng;i++){
                                    if (lower(obj.subjects[i]) == lower(opt)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        obj.academic_records.erase(obj.academic_records.begin()+i);
                                        cout<<"Subject successfully removed ..."<<endl;
                                        break;
                                    }
                                    if (i == leng-1){
                                        cout<<"Cannot find subject ..."<<endl;
                                    }
                                }
                            }
                        }
                    }else if (opt == "0"){
                        break;
                    }
                }

            }
            else if (edit == "7"){
                cout<<"Students Residence : "<<endl;cout<<obj.details.getResidence();
                cout<<"Enter new residence of student : "<<endl;
                cin.ignore();getline(cin, opt);cin.clear();
                cin.clear();obj.details.setResidence(opt);
            }
            else if (edit == "0"){
                //commit changes and push
                Student_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStudent(){
    //search student
    cout<<"you can only manage student if you add student"<<endl;
int cod = 1;
cout<<"Manage"<<endl;
cout<<"Enter students ID or 0 to leave: "<<endl;
int student_id;
cin >> student_id;
while (cin.fail()){
    cout<<" Invalid.......Try Again : "<<endl;
    cin.clear();cin.ignore();cin >> student_id;
}
if (student_id != 0){

    student_id -= student_base_id;
    //controls
    while (student_id < 0 || student_id >= student_count){
        cout<<" Invalid.....Enter Students ID or 0 to leave : "<<endl;
        cin >> student_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            cout<<"Invalid.......Enter valid student ID : ";
            cin >> student_id;
        }
        if(student_id != 0){
            student_id -= student_base_id;
        }
        else{
            cod = 0;
            break;
        }
    }

    if (cod == 1){
        //found student
        cout<<"Student Found"<<endl;
        student obj = Student_Container[student_id];
        //editing student
        while (true){
            cout<<"1. Enter students score"<<endl<<"2. show academic records "<<endl<<"3. remove student "<<endl<<"0. exit"<<endl;
            cout<<"What do you want to do : "<<endl;
            string manage;
            cin >> manage;
            if (manage == "1"){
                int leng = obj.subjects.size();
                cout<<"Enter the semester? (1,2) : "<<endl;
                cin >> num;
                while (num != 1 && num != 2){
                    cout<<"Enter the semester? (1,2) : "<<endl;
                    cin >> num;
                }
                for (int i=0;i<leng;i++){
                    if (obj.academic_records[i].Mark == -1){
                        cout<<"Subject :"<<endl;cout<<obj.academic_records[i].course_name;
                        cout<<"Do you want to record marks for this subject : "<<endl;
                        cin >> opt;opt = lower(opt);
                        while (opt != "y" && opt != "n"){
                            cout<<"please choose 'y' or 'n'"<<endl;
                            cin >> opt;
                            opt = lower(opt);
                        }
                        if (opt == "y"){
                            int credit_hours;
                            cout<<"Credit Hour(s)\t:\t";
                            cin >> credit_hours;
                            while (0 > credit_hours || credit_hours > 3){
                                cout<<"Invalid......Credit Hour(s)\t:\t";
                                cin >> credit_hours;
                            }
                            int score;
                            cout<<"Enter Mark\t:\t";
                            cin >> score;
                            while (0 > score || score >100){
                                cout<<"Invalid.......Enter Mark\t:\t";
                                cin >> score;
                            }
                            obj.academic_records[i].Mark = score;
                            obj.academic_records[i].credit_hour = score;
                            obj.academic_records[i].Semester = num;
                            obj.academic_records[i].Grade = calgrade(score);
                        }
                    }
                }
                Student_Container[obj.details.getIndex()] = obj;
            }
            else if (manage == "2"){
                int leng = obj.subjects.size();
                cout<<"############################################################################################"<<endl;
                cout<<"********************************************************************************************"<<endl;
                cout<<"Name : "<<endl;cout<<obj.details.getName();cout<<"Department\t";cout<<obj.department;
                cout<<"\tCourse : ";cout<<obj.course;cout<<"\tLevel : ";cout<<obj.level;"\tGPA :\t";calGpa(obj);
                cout<<"\n********************************************************************************************";
                cout<<"\n============================================================================================";
                for (int i=0;i<leng;i++){
                    if (obj.academic_records[i].Mark != -1){
                        cout<<"\n\nSubject :\t";cout<<obj.academic_records[i].course_name;
                        cout<<"\t\tMark :\t";cout<<obj.academic_records[i].Mark;
                        cout<<"\t\tGrade :\t";cout<<obj.academic_records[i].Grade;
                    }
                    else{
                        print("\n\nSubject :\t");print(obj.academic_records[i].course_name);
                        print("\t\tMark :\t");print("**N/A**");
                        print("\t\tGrade :\t");print("**N/A**");
                    }
                }
                print("\n\n============================================================================================");
                print("\n############################################################################################");
            }
            else if (manage == "3"){
                print("\nAre you sure you want to remove student? (y/n) : ");
                cin >> opt;opt = lower(opt);
                while (opt != "y" && opt != "n"){
                    print("\nplease choose 'y' or 'n'");
                    cin >> opt;
                    opt= lower(opt);
                }
                if (opt == "y"){
                    obj.details.setStatus("removed");
                    Student_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Student_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};

void addStaff(){
    //add student detail....read class and struct
    cin.clear();
    print("\n**************adding new staff*****************");
    staff newp;
    print("\nAssigned Staff ID : ");print(staff_base_id+staff_count);
    newp.details.setID(staff_base_id+staff_count);newp.details.setIndex(staff_count);staff_count++;
    string str;int num;
    print("\nEnter Staff Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    newp.details.setName(str);
    print("\nEnter Staff Age : ");
    cin >> num;
    while (cin.fail()){
        print("\n( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    newp.details.setAge(num);
    //list department for student to choose from
    print("\nEnter Department Name : ");
    cin >> str;
    newp.department = str;
    //list course using department

    print("\nEnter Staffs Job : ");
    cin >> str;
    newp.job = str;
    //list course using department

    //pushing to array
    Staff_Container[newp.details.getIndex()] = newp;

    print("\nDo you want to add another staff? (y/n) : ");
    cin >> str;
    if (str == "y"){
        addStaff();
    }
    else{
        //pass
    }

};

void editStaff(){
//search student
int pass = 1;
print("\n( edit ) Enter Staffs ID or 0 to leave : ");
int staff_id;
cin >> staff_id;
while (cin.fail()){
    print("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> staff_id;
}
if (staff_id != 0){
    staff_id -= staff_base_id;
    //controls
    while (staff_id < 0 || staff_id >= student_count){
        print("\n( invalid ) Enter Staffs ID or 0 to leave : ");
        cin >> staff_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n( invalid ) Enter valid Staff ID : ");
            cin >> staff_id;
        }
        if(staff_id != 0){
            staff_id -= staff_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\nStaff Found\n");
        staff obj = Staff_Container[staff_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true){
            print("\n\n1. name \n2. age \n3. department \n4. staff subjects \n5. residence \n0. exit\n");
            print("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                print("\nStaffs name : ");print(obj.details.getName());
                print("\n\nChange to : ");
                cin.ignore();getline(cin, opt);cin.clear();
            }
            else if (edit == "2"){
                print("\n\nChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                print("\nStaff's Department : ");print(obj.department);
                print("\n\nEnter New Staff's Department : ");
                cin.ignore();getline(cin, opt);cin.clear();
                obj.department = opt;
            }
            else if (edit == "4"){
                print("\n\n\nStaffs subject : \n");//list obj.subjects;
                while (true){
                    print("1. add subject \n2. remove subject \n0. exit\n");
                    print("select an option : ");
                    cin >> opt;
                    if (opt== "1"){
                        cin.ignore();
                        while (true){
                            print("\nenter subject to add or use 0 to leave : ");
                            getline(cin, opt);
                            if (opt == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(opt);
                            }
                        }

                    }
                    else if (opt == "2"){
                        cin.ignore();
                        while (true){
                            print("\nenter subject to remove or use 0 to leave : ");
                            getline(cin, opt);
                            if (opt == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(opt)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        print("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        print("\ncannot find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (opt == "0"){
                        break;
                    }
                }
            }
            else if (edit == "5"){
                print("\nStaffs Residence : ");print(obj.details.getResidence());
                print("\n\nChange to : ");
                cin.ignore();getline(cin, opt);cin.clear();
                cin.clear();obj.details.setResidence(opt);
            }
            else if (edit == "0"){
                //commit changes and push
                Staff_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStaff(){
    //search student
int pass = 1;
print("\n( manage )Enter Staffs ID or 0 to leave : ");
int staff_id;
cin >> staff_id;
while (cin.fail()){
    print("\n( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> staff_id;
}
if (staff_id != 0){
    staff_id -= staff_base_id;
    //controls
    while (staff_id < 0 || staff_id >= staff_count){
        print("\n( invalid ) Enter Staff ID or 0 to leave : ");
        cin >> staff_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n( invalid ) Enter valid staff ID : ");
            cin >> staff_id;
        }
        if(staff_id != 0){
            staff_id -= staff_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\nStaff Found\n");
        staff obj = Staff_Container[staff_id];
        //editing student
        while (true){
            print("\n\n1. remove staff \n0. exit\n");
            print("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                print("\nAre you sure you want to remove staff? (y/n) : ");
                cin >> opt;opt = lower(opt);
                while (opt != "y" && opt != "n"){
                    print("\nplease choose 'y' or 'n'");
                    cin >> opt;
                    opt = lower(opt);
                }
                if (opt == "y"){
                    obj.details.setStatus("removed");
                    Staff_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Staff_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};


string lower(string line){
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++){//boy
        for (int j=0;j<26;j++){
            if (line[i] == UPPER[j]){
                ret_lower += LOWER[j];
                break;
            }
            else if (j == 25){
                ret_lower += line[i];
            }
        }

    }
    return ret_lower;
}


string calgrade(double score){
    if (79 < score && score <= 100){
        return "A";
    }
    else if(74 < score && score <= 79){
        return "B+";
    }
    else if(69 < score && score <= 74){
        return "B";
    }
    else if(64 < score && score <= 69){
        return "C+";
    }
    else if(59 < score && score <= 64){
        return "C";
    }
    else if(54 < score && score <= 59){
        return "D+";
    }
    else if(49 < score && score <= 54){
        return "D";
    }
    else if(44 < score && score <= 49){

        return "E";
    }
    else if(-1 < score && score <= 44){
        return "F";
    }
    else{
        return "invalid mark";
    }
}


float getGpaScore(string grade){
    if (grade == "A"){
        return 4.0;
    }
    else if (grade == "B+"){
        return 3.5;
    }
    else if (grade == "B"){
        return 3.0;
    }
    else if (grade == "C+"){
        return 2.5;
    }
    else if (grade == "C"){
        return 2.0;
    }
    else if (grade == "D+"){
        return 1.5;
    }
    else if (grade == "D"){
        return 1.0;
    }
    else if (grade == "E"){
        return 0.5;
    }
    else if (grade == "F"){
        return 0.0;
    }
    return -1;
}

void calGpa(student obj){
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> newp_record = obj.academic_records;
    for (int i=0;i<len;i++){
        if (newp_record[i].Mark == -1){
            empty_score = true;
            cout << "**N/A**";
            break;
        }
        else{
            tch += newp_record[i].credit_hour;
            gpa += getGpaScore(newp_record[i].Grade)*newp_record[i].credit_hour;
        }
    }
    if (empty_score == false){
        if (len != 0){
            cout << gpa/tch;
        }
        else{
            cout << "**N/A**";
        }
    }
}
