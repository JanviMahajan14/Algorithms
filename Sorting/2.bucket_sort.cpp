// given an array of students and their marks. Create a leaderboard as per their marks
#include<iostream>
#include<vector>
using namespace std;

class Student{
    public:
    string name;
    int marks;
};

void bucket_sort(Student s[], int n){
    //given the marks lies between 1-100

    // Every bucket is represented by a each vector
    vector<Student>marks[100];

    for(int i=0; i<n; i++){
        int m = s[i].marks;
        marks[m].push_back(s[i]);
    }

    // Iterating over the elements of each vector
    for(int i=100; i>=1; i--){
       for(vector<Student>::iterator it=marks[i].begin(); it!=marks[i].end(); it++){
           cout << (*it).name << " " << (*it).marks << endl;
       }
    }

}

int main(){
    int n;
    cin >> n;
    Student s[n];
    for(int i=0; i<n; i++){
        cin >> s[i].name;
        cin >> s[i].marks;
    }
    bucket_sort(s,n);
}