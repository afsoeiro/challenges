#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person {
    protected:
    std::string name;
    int age;
    int cur_id;
    public:
    virtual void getdata() {
        cin >> this->name >> this->age;
    }
    virtual void putdata() {
        cout << this->name << " " << this->age << " ";
    }
    Person() {
    }
};

class Professor : public Person {
    protected:
    int publications;
    private:
    static int counter;
    public:
    void getdata() override {
        Person::getdata();
        cin >> this->publications;
    }
    void putdata() override {
        Person::putdata();
        cout << this->publications << " " << this->cur_id << endl;
    }
    Professor() {
        this->cur_id = (++ Professor::counter);
    }
};

int Professor::counter = 0;
class Student : public Person {
    protected:
    int marks[6];
    private:
    static int counter;
    public:
    void getdata() override {
        //string name, int age, int publications
        Person::getdata();
        //cout << "Will input student data... " << endl;
        int mark;
        for(int i = 0; i < 6; i ++) {
            cin >> mark;
            this->marks[i] = mark;
        }
    }
    void putdata() override {
        Person::putdata();
        int sum = 0;
        for(auto item : this->marks) {
            sum += item;
        }
        cout << sum << " " << this->cur_id << endl;
    }
    Student() {
        this->cur_id = (++ Student::counter);
    }
};
int Student::counter = 0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
