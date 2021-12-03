#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
/*
 * It will iterate through all the lines in file and
 * call the given callback on each line.
 */
using namespace std;



bool iterateFile(string fileName, function<void (const string & )> callback)
{
    // Open the File
    ifstream in(fileName.c_str());
    // Check if object is valid
    if(!in)
    {
        cerr << "Cannot open the File : " << fileName << endl;
        return false;
    }
    string str;
    // Read the next line from File untill it reaches the end.
    
    vector<string> vecOfStr;
    while (getline(in, str)){
        // Call the given callback
            callback(str);
    }
    //Close The File
    in.close();
    return true;
}
int main()
{
    cout << "Write the word you're searching for\n";
    string user_input;
    cin >> user_input;
    vector<string> vecOfStr;
    //Call given lambda function for each line in file
    bool res = iterateFile("words_alpha.txt", [&](const string & str){
        // Add to vector
        vecOfStr.push_back(str);
    });
if(res){
    for(string & line : vecOfStr){
        //if (line == user_input){
        cout<<user_input<<endl;
            
        }
    }
}

