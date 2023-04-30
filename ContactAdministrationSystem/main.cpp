#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

# define MAX 1000

struct contact{
    string name;
    string address;
    int gender;  //1男2女
    int age;
    string phone;
};

struct addressBooks{
    struct contact cArr[MAX];
    int size;
};

void showMenu(){
    cout << "1、Add Contact" << endl;
    cout << "2、Show Contact" << endl;
    cout << "3、Delete Contact" << endl;
    cout << "4、Search Contact" << endl;
    cout << "5、Edit Contact" << endl;
    cout << "6、Clear Contact" << endl;
    cout << "0、Exit System" << endl;
}

void addContact(addressBooks *abs){
    if (abs->size == MAX){
        cout << "the address book is full!" << endl;
        return;
    }
    else{
        string name;
        cout << "please input the name" << endl;
        cin >> name;
        abs->cArr[abs->size].name = name;

        string address;
        cout << "please input the address" << endl;
        cin >> address;
        abs->cArr[abs->size].address = address;

        int gender;
        cout << "please input the gender" << endl;
        cout << "1-male; 2-female" << endl;
        cin >> gender;
        while (true){
            if (gender == 1 || gender == 2){
                abs->cArr[abs->size].gender = gender;
                break;
            }
            cout << "the input is incorrect, please input again!" << endl;
        }

        int age;
        cout << "please input the age" << endl;
        cin >> age;
        abs->cArr[abs->size].age = age;

        string phone;
        cout << "please input the phone" << endl;
        cin >> phone;
        abs->cArr[abs->size].phone = phone;

        abs->size++;
        cout << "Add successfully!" << endl;
    }
    system("clear");
}

void showContact(addressBooks *abs){
    if (abs->size == 0){
        cout << "Current record is empty!" << endl;
    }
    else{
        for (int i = 0; i < abs->size; i++){
            cout << "name: " << abs->cArr[i].name << "\t";
            cout << "gender: " << (abs->cArr[i].gender == 1?"男":"女")  << "\t";
            cout << "age: " << abs->cArr[i].age << "\t";
            cout << "address: " << abs->cArr[i].address << "\t";
            cout << "phone: " << abs->cArr[i].phone << "\t";
            cout << endl;
        }
    }
}

int find(addressBooks *abs, string name){
    for (int i = 0; i < abs->size; i++){
        if (abs->cArr[i].name == name){
            return i;
        }
    }
    return -1;
}

void deleteContact(addressBooks *abs, string name){
    int pos = find(abs, name);
    if (pos == -1){
        cout << "This person isn't exist!" << endl;
        return;
    }
    else{
        for (int i = pos+1; i < abs->size; i++){
            abs->cArr[i-1] = abs->cArr[i];
        }
        abs->size--;
        cout << "Delete successfully!" << endl;
    }
    system("clear");
}

void searchContact(addressBooks *abs, string name){
    int pos = find(abs, name);
    if (pos == -1){
        cout << "This person isn't exist!" << endl;
    }
    else{
        cout << "name: " << abs->cArr[pos].name << "\t";
        cout << "gender: " << (abs->cArr[pos].gender == 1?"男":"女")  << "\t";
        cout << "age: " << abs->cArr[pos].age << "\t";
        cout << "address: " << abs->cArr[pos].address << "\t";
        cout << "phone: " << abs->cArr[pos].phone << "\t";
        cout << endl;
    }
    system("clear");
}

void editContact(addressBooks *abs, string name){
    int pos = find(abs, name);
    if (pos == -1){
        cout << "This person isn't exist!" << endl;
    }
    else{
        string nname;
        int ngender;
        int nage;
        string nphone;
        string naddress;
        cout << "please input the new name: " << endl;
        cin >> nname;
        cout << "please input the new gender(1-male;2-female): " << endl;
        cin >> ngender;
        cout << "please input the new age: " << endl;
        cin >> nage;
        cout << "please input the new phone: " << endl;
        cin >> nphone;
        cout << "please input the new address: " << endl;
        cin >> naddress;
        abs->cArr[pos].name = nname;
        abs->cArr[pos].gender = ngender;
        abs->cArr[pos].age = nage;
        abs->cArr[pos].address = naddress;
        abs->cArr[pos].phone = nphone;
        cout << "Edit successfully!" << endl; 
    }
    system("clear");
}

void clearContact(addressBooks *abs){
    abs->size = 0;
    cout << "Clear successfully!" << endl;
    system("clear");
}

int main(){
    addressBooks abs;
    abs.size = 0;

    while (true){
        showMenu();

        int select;
        cin >> select;

        switch (select)
        {
        case 1:  // 1、Add Contact
            addContact(&abs);
            break;
        case 2:  // 2、Show Contact
            showContact(&abs);
            break;
        case 3:  // 3、Delete Contact
            {
                cout << "please input the person you want to delete: " << endl;
                string name;
                cin >> name;
                deleteContact(&abs, name);
                break;
            }
        case 4:  // 4、Search Contact
            {
                cout << "please input the person you want to find: " << endl;
                string name;
                cin >> name;
                searchContact(&abs, name);
                break;
            }
        case 5:  // 5、Edit Contact
            {
                cout << "please input the person you want to edit: " << endl;
                string name;
                cin >> name;
                editContact(&abs, name);
                break;
            }
        case 6:  // 6、Clear Contact
            break;
        case 0:  // 0、Exit System
            cout << "Look forward to see you next time!" << endl;
            return 0;
        default:
            break;
        }
    }

    return 0;
}