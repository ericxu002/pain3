#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void take_input(int& num_of_test_cases, int& num_of_friendships, vector<string>& set1, vector<string>& set2, unordered_map<string,vector<string> >& container){
    cin >> num_of_test_cases;
    cin >> num_of_friendships;
    string person1, person2;
    for(int i = 0; i < num_of_friendships; i++){
        cin >> person1 >> person2;
        container[person1].push_back(person2);
        container[person2].push_back(person1);
        for(auto x : c)
        //cout << container[person1].size() << endl;
        
        if(container[person1].size() > container[person2].size()){
            cout << container[person1].size() << endl;
        }
        else{
            cout << container[person2].size() << endl;
        }
    }
}


int main(){
    int num_of_test_cases, num_of_friendships;
    unordered_map<string,vector<string> > container;
    vector<string> set1, set2;
    take_input(num_of_test_cases, num_of_friendships, set1, set2, container);
    return 0;
}