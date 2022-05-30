#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

void solve(unsigned long &num_of_test_cases, unsigned long &num_of_friendships, unordered_map<string, vector<string> > &container, unordered_map<string, string>& A)
{
    cin >> num_of_test_cases;
    //cin >> num_of_friendships;
    

    for (unsigned long z = 0; z < num_of_test_cases; z++)
    {
        
        cin >> num_of_friendships;
        for (unsigned long i = 0; i < num_of_friendships; i++)
        {
            string person1(""), person2("");
            //PROBLEM RN IS THAT IT IS READING EMPTY CHARS

            while(person1 == ""){
                cin >> person1;
            }
            while(person2 == ""){
                cin >> person2;
            }
            //cin >> person1 >> person2;
            //cout << "PERSON 1: " << person1 << " PERSON 2: " << person2 << endl;
            if(A[person1] == ""){
                container[person1].push_back(person1);
                A[person1] = person1;
                //cout<< " PERSON1 NOT HERE !!! " << endl;
                
            }
            if(A[person2] == ""){
                container[person2].push_back(person2);
                A[person2] = person2;
                //cout<< " PERSON2 NOT HERE !!! " << endl;
            }

            //now union part

            //these two parts if we do a,c and a,b it equals union c,b
            //so basically it deals with the parent directly aka the keys of the hashmap instead of the children
            person1 = A[person1];
            person2 = A[person2];

            if(person1 == person2){ // this is for the case in which unioning two things within the same group don't want to count twice so skip entire procedure
                cout << container[person1].size() <<endl;
                continue;
            } 

            // cout << "\nContainer[person1] contents: ";
            // for(auto p : container[person1]){
            //     cout<< p << " ";
            // }
            // cout << "\nContainer[person2] contents: ";
            // for(auto z : container[person2]){
            //     cout<< z << " ";
            // }
            // cout << "\nAFTER SWAP" << endl;

            if(container[person1].size() < container[person2].size()){
                swap(person1, person2);
            }

            // cout << "\nContainer[person1] contents: ";
            // for(auto p : container[person1]){
            //     cout<< p << " ";
            // }
            // cout << "\nContainer[person2] contents: ";
            // for(auto z : container[person2]){
            //     cout<< z << " ";
            // }
            
            for(auto x : container[person2]){
                A[x] = (person1);
                container[person1].push_back(x);

            }
            // for(unsigned long i = 0; i < container[person2].size(); i++){
            //     A[i] = (person1);
            //     container[person1].push_back(container[person1][i]);
                
            // }
        
            cout << container[person1].size() << endl;
            //container[person2].clear();
            
        }
        container.clear();
        A.clear();
    }
}

unsigned long main(){
    ios_base::sync_with_stdio(false); 
    unsigned long num_of_test_cases, num_of_friendships;
    unordered_map<string,vector<string> > container;
    unordered_map<string, string> A; 
    //unordered_map<string, string> a;
    //unordered_map<string, string> b;
    //vector<string> set1, set2;

    solve(num_of_test_cases, num_of_friendships, container, A);
    return 0;
}