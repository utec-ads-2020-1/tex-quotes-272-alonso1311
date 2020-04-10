#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string line;        
    bool first = true;
    char to_search = '"';
    vector<string> result;

    while(getline(cin, line, '\n') and !line.empty()){
        while(true){
            int found = line.find(to_search);
            if(found != string::npos && first == true){
                line.replace(found, 1, "``");
                first = false;
            } else if(found != string::npos && first == false){
                line.replace(found, 1, "''");
                first = true;
            } else {
                break;
            }
        }
        result.push_back(line); 
    }

    for(auto const& i : result)
        cout << i << endl;

    return 0;
}
