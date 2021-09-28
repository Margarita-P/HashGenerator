#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string alphabet [26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                        "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                        "u", "v", "w", "x", "y", "z" };
int values [26] = {11111, 22222, 33333, 44444, 55555, 66666, 77777, 88888, 99999, 11122,
                   22233, 33344, 44455, 55566, 66677, 77788, 88899, 99110, 11333, 22444, 
                   33555, 44666, 55777, 66888, 77999, 88811};
//int values[26] = 
//string values [] = {}
void input2 (string &input)
{
    ifstream fr ("duom.txt");
    fr >> input;
    fr.close();
}
void input1 (string &input)
{
    cin >> input;
}
void HASH(string x, string y)
{
    y.clear();
    vector <string> array;
    vector <string> array1;
    string temp;
    string t;
    long int k;
    int index;
    int SizeOfInput = x.size();
    int ii= 0;
    
    for (string::size_type i = 0; i < x.size(); i++) 
    {
        temp = x[i];
        array.push_back(temp);
    }
    for(int i = 0; i<array.size(); i++)
    {
        for(int j=0; j<26; j++)
        {
            if(array[i] == alphabet[j])
            {
                k = 0;
                k = values[j] * SizeOfInput;
                k = k + (k * (SizeOfInput * (j + j + 1)));
                cout << "k: " << k << endl;
                t = ' ';
                t = alphabet[j+1];
                cout << t << endl;
                y += to_string(k);
                y += t;
            }
        }
    }
    cout << "y: " << hex << y << endl;   
}
int main()
{
    string input;
    string answer;
    string output;
    cout << "DO you want to enter input manually? (y/n)" << endl;
    cin >> answer;
    if(answer == "y") input1 (input);
    else if(answer == "n") input2 (input);
    else 
    {
        cout << "Entered wrong answer, restart program" ;
        exit;
    }

    HASH(input, output);

    return 0;
}
