//Двоичная запись числа
#include <iostream>
#include <fstream>
#include <math.h>
#include <stack>



using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);
	int a;
	cin >> a  ;

    stack<int> s;
    do{
        s.push(a%2);
        a = a/2;
    }while (a>0);
    while(!s.empty()){
        //cout << s.top();
        cout << s.top();
        s.pop();
    }
        //for(;;);




    return 0;
}
