/*
interacting with users:
1 interacting menu
2 add/delete/search/modify staffs
3 write/read file
*/
#include "staffManger.h"
using namespace std;

StaffManger::StaffManger()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    //file doesn't exist.
    if (!ifs.is_open())
    {
        cout << "file doesn't exist!" << endl;
        this->m_empNum = 0;
        this->m_empArr = NULL;
        this->isEmpty = true;
    }
    // file exists.
    else
    {
        char ch;
        ifs >> ch;
        // file is empty.
        if (ifs.eof())
        {
            cout << "file is empty!" << endl;
            this->m_empNum = 0;
            this->m_empArr = NULL;
            this->isEmpty = true;
        }
        // file is not empty, read the information
        else
        {
            int num = this->getEmpNum();
            cout << "the number of staff is: " << num << endl;
            this->m_empNum = num;
            //explore space and save the information.
            this->m_empArr = new Staff*[this->m_empNum];
            this->init_Emp();

            for (int i=0; i<this->m_empNum; i++)
            {
                cout << setw(3) << left << this->m_empArr[i]->m_id << "\t" 
                << setw(10) << left << this->m_empArr[i]->m_name << "\t" 
                << setw(3) << right << this->m_empArr[i]->m_depId << endl;
            }
        }
        ifs.close();
    }
}

int StaffManger::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id; 
    string name;
    int depId;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> depId)
    {
        num++;
    }
    return num;
}

void StaffManger::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
 
    string line;
    int i = 0;
    
    while (getline(ifs, line))
    {
        istringstream ss(line);
        int id;
        string name;
        int depId;
        ss >> id >> name >> depId;

        Staff * staff = NULL;
        if (depId == 1)
        {
            staff = new Employee(id, name, depId);
        }
        else if (depId == 2)
        {
            staff = new Manager(id, name, depId);
        }
        else
        {
            staff = new Boss(id, name, depId);
        }
        this->m_empArr[i] = staff;
        i++;
    }
    ifs.close();
}

void StaffManger::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i=0; i<this->m_empNum; i++)
    {
        ofs << setw(3) << left << this->m_empArr[i]->m_id << "\t" 
        << setw(10) << left << this->m_empArr[i]->m_name << "\t" 
        << setw(3) << right << this->m_empArr[i]->m_depId << endl;

    }
    ofs.close();
}

void StaffManger::showMenu(){
    cout << "Welcome to the staff administration system!" << endl;
    cout << "0. exit current system" << endl;
    cout << "1. add staff information" << endl;
    cout << "2. show staff information" << endl;
    cout << "3. delete staff who has left" << endl;
    cout << "4. modify staff information" << endl;
    cout << "5. search staff information" << endl;
    cout << "6. sort staff based on their ids" << endl;
    cout << "7. clear the file" << endl;
}

void StaffManger::exitSystem(){
    cout << "welcome to use this system again!" << endl;
    return;
}

void StaffManger::addEmp()
{
    cout << "please input the number of staffs you wanna add: " << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0)
    {
        int newSize = this->m_empNum + addNum;
        // explore new array
        Staff ** newSpace = new Staff * [newSize];
        // copy original to new
        if (this->m_empArr != NULL)
        {
            for (int i=0; i<this->m_empNum; i++)
            {
                newSpace[i] = this->m_empArr[i];
            }
        }
        // add new data
        for (int i=0; i<addNum; i++)
        {
            int id;
            string name;
            int dep;

            cout << "please input the " << i+1 << "th staff's ID: " << endl;
            cin >> id;
            cout << "please input the " << i+1 << "th staff's name: " << endl;
            cin >> name;
            cout << "please input the " << i+1 << "th staff's departmment: " << endl;
            cout << "1. employee" << endl;
            cout << "2. manager" << endl;
            cout << "3. boss" << endl;
            cin >> dep;

            Staff * staff = NULL;
            switch (dep)
            {
            case 1:
                staff = new Employee(id, name, dep);
                break;
            case 2:
                staff = new Manager(id, name, dep);
                break;
            case 3:
                staff = new Boss(id, name, dep);
                break;
            default:
                break;
            }

            newSpace[this->m_empNum+i] = staff;
        }
        // release the original space
        delete[] this->m_empArr;
        // modify the pointer
        this->m_empArr = newSpace;
        this->m_empNum = newSize;
        this->isEmpty = false;

        this->save();
    }
    else
    {
        cout << "input must larger than zero!" << endl;
    } 
}

void StaffManger::showStaff()
{
    if (this->m_empNum == 0)
    {
        cout << "You haven't add any staff!" << endl;
    }
    for (int i=0; i<this->m_empNum; i++)
    {
        cout << "staff's ID: " << this->m_empArr[i]->m_id
        << "\tstaff's name: " << this->m_empArr[i]->m_name
        << "\tstaff's depID: " << this->m_empArr[i]->m_depId << endl; 
    }
}

int StaffManger::isExist(int id)
{
    int index = -1;
    for (int i=0; i<this->m_empNum; i++)
    {
        if (this->m_empArr[i]->m_id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void StaffManger::delStaff()
{
    if (this->isEmpty)
    {
        cout << "File doesn't exist or is empty!" << endl;
        return;
    }
    int id;
    cout << "please enter the staff's ID you wanna delete: " << endl;
    cin >> id;
    int index = this->isExist(id);

    if (index == -1)
    {
        cout << "Staff doesn't exist!" << endl;
    }
    else
    {
        for (int i=index; i<this->m_empNum-1; i++)
        {
            this->m_empArr[i] = this->m_empArr[i+1];
        }
        this->m_empNum--;
        this->save();
    }
}

void StaffManger::modify()
{
    if (this->isEmpty)
    {
        cout << "File doesn't exist or is empty!" << endl;
        return;
    }
    int id;
    cout << "please enter the staff's ID you wanna modify: " << endl;
    cin >> id;
    int index = this->isExist(id);

    if (index == -1)
    {
        cout << "Staff doesn't exist!" << endl;
    }
    else
    {
        int id;
        string name;
        int depId;

        cout << "The ID you searched is exist: " << endl;
        this->m_empArr[index]->showInfo();

        cout << "please enter the new ID: " << endl;
        cin >> id;
        cout << "please enter the new name: " << endl;
        cin >> name;
        cout << "please enter the new depID: " << endl;
        cin >> depId;

        Staff * staff = NULL;
        switch (depId)
        {
        case 1:
            staff = new Employee(id, name, depId);
            break;
        case 2:
            staff = new Manager(id, name, depId);
            break;
        case 3:
            staff = new Boss(id, name, depId);
            break;
        default:
            break;
        }
        this->m_empArr[index] = staff;
        this->save();
    }
}

void StaffManger::search()
{
    if (this->isEmpty)
    {
        cout << "File doesn't exist or is empty!" << endl;
        return;
    }
    cout << "please enter the searching method: " << endl;
    cout << "1. based on name" << endl;
    cout << "2. based on ID" << endl;
    int select;
    cin >> select;
    if (select == 2)
    {
        int id;
        cout << "please enter the staff's ID you wanna modify: " << endl;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            cout << "search Successfully!" << endl;
            this->m_empArr[index]->showInfo();
        }
        else
        {
            cout << "search failed, the staff doesn't exist!" << endl;
        }
    }
    else
    {
        bool flag = false;
        string name;
        cout << "please enter the staff's ID you wanna modify: " << endl;
        cin >> name;
        for (int i=0; i<this->m_empNum; i++)
        {
            if (this->m_empArr[i]->m_name == name)
            {
                cout << "search Successfully!" << endl;
                this->m_empArr[i]->showInfo();
                flag = true;
            }
        }
        if (flag == false)
        {
            cout << "search failed, the staff doesn't exist!" << endl;
        }
    }
}

void StaffManger::sort()
{
    cout << "please enter the sorting method: " << endl;
    cout << "1. inverse=false" << endl;
    cout << "2. inverse=true" << endl;
    int select;
    cin >> select;
    if (select == 1)
    {
        for (int i=0; i<this->m_empNum-1; i++)
        {
            for (int j=0; j<this->m_empNum-i-1; j++)
            {
                if (this->m_empArr[j]->m_id > this->m_empArr[j+1]->m_id)
                {
                    Staff * temp = this->m_empArr[j];
                    this->m_empArr[j] = this->m_empArr[j+1];
                    this->m_empArr[j+1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i=0; i<this->m_empNum-1; i++)
        {
            for (int j=0; j<this->m_empNum-i-1; j++)
            {
                if (this->m_empArr[j]->m_id < this->m_empArr[j+1]->m_id)
                {
                    Staff * temp = this->m_empArr[j];
                    this->m_empArr[j] = this->m_empArr[j+1];
                    this->m_empArr[j+1] = temp;
                }
            }
        }
    }
}

void StaffManger::clear()
{
    cout << "Are you sure to clear?" << endl;
    cout << "1. yes   2. no" << endl;
    int select;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_empArr != NULL)
        {
            for (int i=0; i<this->m_empNum; i++)
            {
                if (this->m_empArr[i] != NULL)
                {
                    delete this->m_empArr[i];
                    this->m_empArr[i] = NULL;
                }
            }
            delete[] this->m_empArr;
            this->m_empArr = NULL;
            this->m_empNum = 0;
            this->isEmpty = true;
        }
        cout << "Clear successfully!" << endl;
    }
}

StaffManger::~StaffManger()
{
    if (this->m_empArr != NULL)
    {
        for (int i=0; i<this->m_empNum; i++)
        {
            if (this->m_empArr[i] != NULL)
            {
                delete this->m_empArr[i];
                this->m_empArr[i] = NULL;
            }
        }
        delete[] this->m_empArr;
        this->m_empArr = NULL;
    }
}

