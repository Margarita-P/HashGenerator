#include <iostream>
#include <fstream>

using namespace std;

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
int main()
{
    string input;
    input1 (input);
    input2 (input);
    cout << input << endl;

    return 0;
}
