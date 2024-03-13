// Nestor Garcia
// 12/09/2022
// File I/O


#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Person {
private:
    string name;
    int age;
    string gender;
    
public:
    Person(string argN, int argAge, string argGender);

    void setName(string argN);
    void setAge(int argAge);
    void setGender(string argGender);

    string getName(void);
    int getAge(void);
    string getGender(void);
    
    
     
    };

bool compare(Person age1, Person age2);




int main() {
    list<Person> myPeople;
    list<Person>::iterator itr;

    char userResp;
    string userName, userGender;
    int userAge;



    do {
        cout << "\nName: ";
        getline(cin, userName);

        cout << "Age: ";
        cin >> userAge;
        cin.ignore();
      
        cout << "Gender: ";
        getline(cin, userGender);
        

        myPeople.push_back( Person(userName, userAge, userGender) );

        cout << "\nEnter another person? [Y/N]: ";
        cin >> userResp;
        cin.ignore();

    } while (userResp == 'y' || userResp == 'Y');

    myPeople.sort(compare);


    ofstream myFile;
    myFile.open("myPeople.csv");

    myFile << "Name,Age,Gender\n";

    for (itr = myPeople.begin(); itr != myPeople.end(); itr++) {
        myFile << itr->getName() << "," << itr->getAge() << "," << itr->getGender() << endl;
        
    }

    myFile.close();


    const int size = 30;
    string peopleArray[size];
    string temp;
    int counter = 0;


    ifstream myData;
    myData.open("myPeople.csv");

    while (!myData.eof()) {
        getline(myData, temp);
         
        peopleArray[counter] = temp;

       
        counter++;
    }

    myData.close();


    //cout << peopleArray[1] << endl;
    cout << "\n";
    for (int j = 0; j < myPeople.size() + 1; j++) {
       
        cout << peopleArray[j] << endl;
    }




    return(0);
}

Person::Person(string argN, int argAge, string argGender) {
    setName(argN);
    setAge(argAge);
    setGender(argGender);
}

void Person::setName(string argN) {
    name = argN;
}

void Person::setAge(int argAge) {
    age = argAge;
}

void Person::setGender(string argGender) {
    gender = argGender;
}

string Person::getName(void) {
    return (name);
}

int Person::getAge(void) {
    return (age);
}

string Person::getGender(void) {
    return (gender);
}

bool compare(Person age1, Person age2) { // youngest gets listed first

    return (age1.getAge() < age2.getAge());
}