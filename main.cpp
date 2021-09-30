#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string alphabet [52] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
                        "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", 
                        "u", "v", "w", "x", "y", "z", "A", "B", "C", "D",
                        "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                        "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
                        "Y", "Z"};
int values [62] = {11111, 22222, 33333, 44444, 55555, 66666, 77777, 88888, 99999, 11122,
                   22233, 33344, 44455, 55566, 66677, 77788, 88899, 99110, 11333, 22444, 
                   33555, 44666, 55777, 66888, 77999, 88811,
                   11123, 22234, 33345, 44456, 55567, 66678, 77789, 88812, 99923, 11134,
                   22245, 33367, 44478, 55589, 66691, 77712, 88823, 99134, 11345, 22456, 
                   33567, 44678, 55789, 66891, 77912, 88821 };
void input2 (string &input)
{
    ifstream fr ("v.txt");
    fr >> input;
    fr.close();
}
void input1 (string &input)
{
    cin >> input;
}
void HASH(string x, string &y)
{
    y.clear();
    vector <string> array;
    string temp;
    string t;
    long int k;
    int SizeOfInput = x.size();
    if(SizeOfInput > 6)
    {
        string::size_type i = 0;
        while( i < x.size() && array.size() < 6) 
        {
            temp = x[i];
            array.push_back(temp);
            i=i+3;
        }
    }
    else
    {
        for (string::size_type i = 0; i < x.size(); i++) 
        {
            temp = x[i];
            array.push_back(temp);
        }
    }
    for(int i = 0; i<array.size(); i++)
    {
        for(int j=0; j<52; j++)
        {
            if(array[i] == alphabet[j])
            {
                if(array[i] == array[i-1])
                {
                    k = 0;
                    k = values[j+i+i] * SizeOfInput;
                    k = k + (k * (SizeOfInput * (j + j + 1)));
                    if(k<0)
                    {
                        k=-k;
                    }
                    t = ' ';
                    t = alphabet[j+1+i];
                    y += to_string(k);
                    y += t; 
                }
                else
                {
                    k = 0;
                    k = values[j] * SizeOfInput;
                    k = k + (k * (SizeOfInput * (j + j + 1)));
                    if(k<0)
                    {
                        k=-k;
                    }
                    t = ' ';
                    t = alphabet[j+1];
                    y += to_string(k);
                    y += t; 
                }
            }
        }
    }
    int i = 0;
    while(y.size() < 64)
    {
        int k1 = values[SizeOfInput+i]*(SizeOfInput+i);
        k1 = k1 % 10;
        y += to_string(k1);
        if(i >= 52)
        {
            i=0;
        }
        /*if(y.size() < 64)
        {
            y += alphabet[SizeOfInput+i+1];
        }*/
        i++;
    }
    
    while(y.size() >= 65)
    {
        y.erase(y.end()-1);
    }    
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
    cout << "size: " << output.size() << endl;
    cout << "y: " << hex << output << endl;   

    return 0;
}
