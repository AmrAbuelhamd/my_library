//Двоичная запись числа
#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>



using namespace std;

int main()
{
    // to extract the answer from the file
    ifstream inFile;
	inFile.open("input.txt");
	int a;
	inFile >> a  ;
        inFile.close();

    // for outputting the results in a file and the program logic
    ofstream outFile;
    outFile.open("output.txt");

    stack<int> s;
    do{
        s.push(a%2);
        a = a/2;
    }while (a>0);
    while(!s.empty()){
        //cout << s.top();
        outFile << s.top();
        s.pop();
    }
        //for(;;);

    outFile.close();



    return 0;
}
