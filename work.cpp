#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
/*
 * It will iterate through all the lines in file and
 * put them in given vector
 */
bool getFileContent(string fileName, vector<string> & vecOfStrs)
{
    // Open the File
    ifstream in(fileName.c_str());
    // Check if object is valid
    if(!in)
    {
        cerr << "Cannot open the File : "<<fileName<<endl;
        return false;
    }
    // Read the next line from File untill it reaches the end.
    string str;
    string user_input;
    cout << "Write the word you're searching for:\n";
    cin >> user_input;

    while (getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if (str.size() > 2 and str == user_input){
            vecOfStrs.push_back(str);
        }
    }
    //Close The File
    in.close();
    return true;
}
int main()
{
    
    vector<string> vecOfStr;
    // Get the contents of file in a vector
    bool result = getFileContent("words_alpha.txt", vecOfStr);
    if(result)
    {
        cout << result;
        // Print the vector contents
        for(string & line : vecOfStr){
                cout<<line<<endl;
            
        }
        cout << result;
    }
}