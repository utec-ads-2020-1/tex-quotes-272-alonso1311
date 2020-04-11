#include<iostream>
#include<string>
#include<vector>

using namespace std;
string to_search = "\"", first_change = "``", second_change = "''";
bool first = true;

void Replace(const int&, string&);

int main() {
    string line;        
    vector<string> result;

    while(getline(cin, line, '\n') and !line.empty()){
        while(true){
            int found = line.find(to_search);
            if(found != string::npos)
                Replace(found, line);
            else 
                break;
            
        }
        result.push_back(line); 
    }

    for(auto const& i : result)
        cout << i << endl;

    return 0;
}

void Replace(const int& found, string& line){
    if(first == true){
        line.replace(found, to_search.size(), first_change);
        first = false;
    } else if(first == false){
        line.replace(found, to_search.size(), second_change);
        first = true;
    } 
}
