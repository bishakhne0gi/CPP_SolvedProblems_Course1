#include <bits/stdc++.h>
using namespace std;
int calMarks(vector <int> marks){
    return marks[0]+marks[1];
}
bool compare(pair<string,vector<int>> s1, pair<string,vector<int>> s2){
    vector<int> m1= s1.second;
    vector<int> m2= s2.second;
    return calMarks(m1)> calMarks(m2);
}
int main(){
    vector<pair<string,vector<int>>> student_marks={
        {"Rohan",{10,20}},
        {"Atul",{15,67}},
        {"Binoy",{70,89}}
    };
    sort(student_marks.begin(), student_marks.end(), compare);
    for(auto x: student_marks){
        cout<<x.first<<endl;
    }
    return 0;
}