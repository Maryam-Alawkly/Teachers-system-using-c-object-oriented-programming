#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//The Basic Class
class Teacher
{
//Private Section
private:
    int Teacher_ID = 0;
    string Teacher_Name;
    string Teacher_Age;
    double Teacher_Salary;
    string Teacher_PersonalCard;
    string Teacher_BloodType;
    string Teacher_Address;
    string Teacher_PhoneNumber;
    string Teacher_Qualification;
    string Teacher_Degree;

//public Section
public:

    //Data Entry Function
    void CreatedRecord();

    //Data Modification Function
    void ModCreRecord();

    //Data Show Function
    void showInfo();

    //Setter Functions
    void setName(string);

    void setAge(string);

    void setSalary(double);

    void setPersonalCard(string);

    void setBloodType(string);

    void setAddress(string);

    void setPhoneNumber(string);

    void setQualification(string);

    void setDegree(string);

    //Getter Functions
    int getId();

    string getName();

    string getAge();

    double getSalary();

    string getPersonalCard();

    string getBloodType();

    string getAddress();

    string getPhoneNumber();

    string getQualification();

    string getDegreet();

    void writeRecord();

    void displayRecord();

    void search_ID();

    void search_Name();

    void deleteRecord();

    void modifyAll();

    void modifyName();

    void modifyAge();

    void modifySalary();

    void modifyPersonalCard();

    void modifyBloodType();

    void modifyAddress();

    void modifyPhoneNumber();

    void modifyQualification();

    void modifyDegree();

    void SalaryBonus();
};

Teacher tea;//Object from Class Teacher
fstream for_tea;//Object from fstream

//Data Entry Function
void Teacher::CreatedRecord()
{
    Teacher_ID = Teacher_ID + 1;
    cout << "\nTeacher's ID is : " << Teacher_ID << endl;

    cout << "\nEnter the Teacher's Name : ";
    cin >> Teacher_Name;

    cout << "\nEnter the Teacher's Age : ";
    cin >> Teacher_Age;

    cout << "\nEnter the Teacher's Salary : ";
    cin >> Teacher_Salary;

    cout << "\nEnter the Teacher's Personal Card : ";
    cin >> Teacher_PersonalCard;

    cout << "\nEnter the Teacher's Blood Type : ";
    cin >> Teacher_BloodType;

    cout << "\nEnter the Teacher's Address : ";
    cin >> Teacher_Address;

    cout << "\nEnter the Teacher's PhoneNumber : ";
    cin >> Teacher_PhoneNumber;

    cout << "\nEnter the Teacher's Qualification : ";
    cin >> Teacher_Qualification;

    cout << "\nEnter the Teacher's Degree : ";
    cin >> Teacher_Degree;
}

//Data Modification Function
void Teacher::ModCreRecord()
{
    cout << "\nTeacher's ID is : " << Teacher_ID << endl;

    cout << "\nEnter the Teacher's Name : ";
    cin >> Teacher_Name;

    cout << "\nEnter the Teacher's Age : ";
    cin >> Teacher_Age;

    cout << "\nEnter the Teacher's Salary : ";
    cin >> Teacher_Salary;

    cout << "\nEnter the Teacher's Personal Card : ";
    cin >> Teacher_PersonalCard;

    cout << "\nEnter the Teacher's Blood Type : ";
    cin >> Teacher_BloodType;

    cout << "\nEnter the Teacher's Address : ";
    cin >> Teacher_Address;

    cout << "\nEnter the Teacher's PhoneNumber : ";
    cin >> Teacher_PhoneNumber;

    cout << "\nEnter the Teacher's Qualification : ";
    cin >> Teacher_Qualification;

    cout << "\nEnter the Teacher's Degree : ";
    cin >> Teacher_Degree;
}

//Data Show Function
void Teacher::showInfo()
{
    cout << "\n\n\t" << Teacher_ID << "\t" << Teacher_Name << "\t"
         << Teacher_Age << "\t" << Teacher_Salary << "\t"
         << Teacher_PersonalCard << "\t" << Teacher_BloodType << "\t"
         << Teacher_Address << "\t" << Teacher_PhoneNumber << "\t"
         << Teacher_Qualification << "\t" << Teacher_Degree << "\n";
}

//Setter Functions

void Teacher::setName(string n)
{
    Teacher_Name = n;
}

void Teacher::setAge(string a)
{
    Teacher_Age= a;
}

void Teacher::setSalary(double s)
{
    Teacher_Salary = s;
}

void Teacher::setPersonalCard(string p)
{
    Teacher_PersonalCard = p;
}

void Teacher::setBloodType(string b)
{
    Teacher_BloodType = b;
}

void Teacher::setAddress(string ad)
{
    Teacher_Address = ad;
}

void Teacher::setPhoneNumber(string ph)
{
    Teacher_PhoneNumber = ph;
}

void Teacher::setQualification(string q)
{
    Teacher_Qualification = q;
}

void Teacher::setDegree(string d)
{
    Teacher_Degree = d;
}

//Getter Functions
int Teacher::getId()
{
    return Teacher_ID;
}

string Teacher::getName()
{
    return Teacher_Name;
}

string Teacher::getAge()
{
    return Teacher_Age;
}

double Teacher::getSalary()
{
    return Teacher_Salary;
}

string Teacher::getPersonalCard()
{
    return Teacher_PersonalCard;
}

string Teacher::getBloodType()
{
    return Teacher_BloodType;
}

string Teacher::getAddress()
{
    return Teacher_Address;
}

string Teacher::getPhoneNumber()
{
    return Teacher_PhoneNumber;
}

string Teacher::getQualification()
{
    return Teacher_Qualification;
}

string Teacher::getDegreet()
{
    return Teacher_Degree;
}

void Teacher::writeRecord()//Record Write Function
{
    for_tea.open("Teacher.txt",ios::out|ios::app);
    tea.CreatedRecord();
    for_tea.write((char*)&tea,sizeof(Teacher));
    for_tea.close();
    cout << "\n\n Record Created \n";
    cout << "-------------- \n";
}

void Teacher::displayRecord()//Records Display Function
{

    cout << "\n\n\tID\tName\tAge\tSalary\tP_Card\tB_Ty\tAddress\tPhonNumber\tQualifica\tDegree\n\t----------------------------------------------------------------------------------------------";

    for_tea.open("Teacher.txt",ios::in);
    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        tea.showInfo();
        cout << "\n\t----------------------------------------------------------------------------------------------\n";
    }
    getchar();
    cout << "Press any key from keyboard to return to the list \n";
    for_tea.close();
    getchar();
}

void Teacher::search_ID()//Search Function in Records by ID
{
    int num;
    cout << "\nEnter the Teacher ID to search for the record : ";
    cin >> num;
    bool test = false;
    for_tea.open("Teacher.txt",ios::in);
    for_tea.seekg(0,ios::beg);
    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nTeacher found!\n\n\tID\tName\tAge\tSalary\tP_Card\tB_Ty\tAddress\tPhonNumber\tQualifica\tDegree\n\t----------------------------------------------------------------------------------------------";
            tea.showInfo();
            cout << "\n\t----------------------------------------------------------------------------------------------\n";
            test = true;
        }
    }
    for_tea.close();
    if(test == false)
    {
        cout <<"\nThis record is not registered!! \n";
        cout <<"------------------------------- \n";

    }
}

void Teacher::search_Name()//Search Function in Records by Name
{
    string name;
    cout << "\nEnter the Teacher Name to search for the record : ";
    cin >> name;
    bool test = false;
    for_tea.open("Teacher.txt",ios::in);
    for_tea.seekg(0,ios::beg);
    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getName() == name)
        {
            cout << "\nTeacher found!\n\n\tID\tName\tAge\tSalary\tP_Card\tB_Ty\tAddress\tPhonNumber\tQualifica\tDegree\n\t----------------------------------------------------------------------------------------------";
            tea.showInfo();
            cout << "\n\t----------------------------------------------------------------------------------------------\n";
            test = true;
        }
    }
    for_tea.close();
    if(test == false)
    {
        cout <<"\nThis record is not registered!! \n";
        cout <<"------------------------------- \n";
    }
}

void Teacher::deleteRecord()//Deletion Function of Record Data
{
    int num;
    bool test = false;
    cout << "\nEnter the Teacher Id to search for the record : ";
    cin >> num;
    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);
    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            test = true;
            cout << "\n\nRecord has been deleted";
            cout << "\n-----------------------\n";
        }
        if(tea.getId()!= num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
    }
    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyAll()//Modification Function in Record Data
{
    int num;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            test = true;

        }
        if(tea.getId()!= num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.ModCreRecord();
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nRecord has been modify\n";
            cout << "-----------------------\n";
        }
    }

    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyName()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Name : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setName(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nName has been modify\n";
            cout << "--------------------\n";
        }
    }

    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyAge()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Age : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setAge(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nAge has been modify\n";
            cout << "-------------------\n";
        }
    }

    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifySalary()//Modification Function in Record Data
{
    int num;
    double modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Salary : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setSalary(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nSalary has been modify\n";
            cout << "-----------------------\n";
        }
    }

    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyPersonalCard()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Personal Card : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setPersonalCard(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nPersonal Card has been modify\n";
            cout << "-----------------------------\n";
        }
    }

    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyBloodType()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Blood Type : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setBloodType(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nBlood Type has been modify\n";
            cout << "--------------------------\n";
        }
    }

    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyAddress()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Address : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setAddress(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nAddress has been modify\n";
            cout << "-----------------------\n";
        }
    }
    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyPhoneNumber()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Phone Number : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setPhoneNumber(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nPhone Number has been modify\n";
            cout << "---------------------------------\n";
        }
    }
    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::modifyQualification()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Qualification : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setQualification(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nQualification has been modify\n";
            cout << "------------------------------\n";
        }
    }
    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}


void Teacher::modifyDegree()//Modification Function in Record Data
{
    int num;
    string modify;
    bool test = false;

    cout << "\nEnter the Teacher ID for which you want to modify the data from the record : ";
    cin >> num;

    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the Teacher's Degree : ";
            cin >> modify;
            test = true;
        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setDegree(modify);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nDegree has been modify\n";
            cout << "-----------------------\n";
        }
    }
    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

void Teacher::SalaryBonus()//The Increase in salaries Function
{
    int num;
    bool test = false;
    double SalaryAfterIncrease,SalaryBonusValue;
    cout << "\nEnter the Teacher ID to increase his salary : ";
    cin >> num;
    for_tea.open("Teacher.txt",ios::in|ios::out);
    fstream for_tea2;
    for_tea2.open("re.txt",ios::out);
    for_tea.seekg(0,ios::beg);

    while(for_tea.read((char*)&tea,sizeof(Teacher)))
    {
        if(tea.getId() == num)
        {
            cout << "\nEnter the value of the increase : ";
            cin >> SalaryBonusValue;

            SalaryAfterIncrease=SalaryBonusValue+tea.getSalary();
            test = true;

        }
        if(tea.getId() != num)
        {
            for_tea2.write((char*)&tea,sizeof(Teacher));
        }
        else
        {
            tea.setSalary(SalaryAfterIncrease);
            for_tea2.write((char*)&tea,sizeof(Teacher));
            cout << "\n\nSalary has been modify\n";
            cout << "-----------------------\n";
        }
    }
    if(test == false)
    {
        cout << "\nThis record is not registered!! \n";
        cout << "------------------------------- \n";
    }
    for_tea2.close();
    for_tea.close();
    remove("Teacher.txt");
    rename("re.txt","Teacher.txt");
}

//The Sub_Class
class Class2:public Teacher
{

};

int main()
{
    Class2 obj;
    int choice;
    string back_0;
    while(true)//The Menu
    {

loop://A Loop to Return The List

        cout << "\n\t\t******************************************";
        cout << "\n\t\t Welcome to The Teacher's Registry System ";
        cout << "\n\t\t******************************************";
        cout << "\n\n\t\tEnter the choice :\n\t\t----------------------";
        cout << "\n\n\t\t1-Add Teacher's Data";
        cout << "\n\n\t\t2-Display Teacher's Data";
        cout << "\n\n\t\t3-Search in Teacher's Data";
        cout << "\n\n\t\t4-Delete from Teacher's Data";
        cout << "\n\n\t\t5-Modify in Teacher's Data";
        cout << "\n\n\t\t6-Teacher's Bonus";
        cout << "\n\n\t\t7-Exit\n";

        cin >> choice;
        system("cls");//To clear the screen

        switch(choice)
        {
        case 1:
        {
            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;
            system("cls");//To clear the screen

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                obj.writeRecord();
            }

            break;
        }

        case 2:
        {
            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;
            system("cls");//To clear the screen

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                obj.displayRecord();
                system("cls");

            }
            break;
        }
        case 3:
        {
            int s_choice;

            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;
            system("cls");//To clear the screen

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                while(true)
                {
                    cout<<"\n\t1-search by Teacher's id ";
                    cout<<"\n\n\t2-search by Teacher's name ";
                    cout<<"\n\n\t3-exit";
                    cout<<"\n\n\n\tEnter your choice : ";

                    cin>>s_choice;
                    system("cls");

                    switch(s_choice)
                    {
                    case 1:
                    {
                        obj.search_ID();
                        break;
                    }
                    case 2:
                    {
                        obj.search_Name();
                        break;
                    }
                    case 3:
                    {
                        goto loop;
                        break;
                    }
                    default:
                    {
                        cout << "\nError in entering!!\n";
                        break;
                    }
                    }
                }
            }
            break;
        }

        case 4:
        {
            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;
            system("cls");//To clear the screen

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                obj.deleteRecord();
            }
            break;
        }

        case 5:
        {
            int d_choice;
            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;
            system("cls");//To clear the screen

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                while(true)
                {

                    cout<<"\n\n\t1-To modify all data";
                    cout<<"\n\n\t2-To modify Teacher_Name";
                    cout<<"\n\n\t3-To modify Teacher_Age";
                    cout<<"\n\n\t4-To modify Teacher_Salary";
                    cout<<"\n\n\t5-To modify Teacher_PersonalCard";
                    cout<<"\n\n\t6-To modify Teacher_BloodType";
                    cout<<"\n\n\t7-To modify Teacher_Address";
                    cout<<"\n\n\t8-To modify Teacher_PhoneNumber";
                    cout<<"\n\n\t9-To modify Teacher_Qualification";
                    cout<<"\n\n\t10-To modify Teacher_Degree";
                    cout<<"\n\n\t11-Exit";
                    cout<<"\n\n\tChoose the method of modification\n\n";

                    cin>>d_choice;
                    system("cls");

                    switch(d_choice)
                    {
                    case 1:
                    {
                        tea.modifyAll();
                        break;
                    }

                    case 2:
                    {
                        tea.modifyName();
                        break;

                    }
                    case 3:
                    {
                        tea.modifyAge();
                        break;

                    }

                    case 4:
                    {
                        tea.modifySalary();
                        break;
                    }

                    case 5:
                    {
                        tea.modifyPersonalCard();
                        break;
                    }

                    case 6:
                    {
                        tea.modifyBloodType();
                        break;
                    }

                    case 7:
                    {
                        tea.modifyAddress();
                        break;
                    }

                    case 8:
                    {
                        tea.modifyPhoneNumber();
                        break;
                    }

                    case 9:
                    {
                        tea.modifyQualification();
                        break;
                    }
                    case 10:
                    {
                        tea.modifyDegree();
                        break;
                    }

                    case 11:
                    {
                        goto loop;
                    }

                    default:
                    {
                        cout << "\nError in entering!!\n";
                        break;
                    }
                    }
                }

                break;
            }
        }
        case 6:
        {
            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                obj.SalaryBonus();
                goto loop;
            }
            break;
        }
        case 7:
        {
            cout << "Enter 'yes' to return to the main menu Or 'no' to continue\n\n";
            cin >> back_0;
            system("cls");//To clear the screen

            if(back_0 == "yes")
            {
                goto loop;
            }
            if(back_0 == "no")
            {
                cout << "\n\t\t***********************************";
                cout << "\n\t\t*** Thanks You for Your Use ^_^ ***\n";
                cout << "\t\t***********************************\n";
                exit(0);
            }
            break;
        }
        default :
        {
            cout << "\nError in entering!!\n";
            break;
        }
        }
    }
    return 0;
}
