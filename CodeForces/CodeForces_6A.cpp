#include <iostream>
#include <vector>
using namespace std;

int Check_Tri(int a, int b, int c)
{
    if(a+b>c and a+c>b and b+c>a)  return 1;  //TRIANGLE
    if(a+b==c or a+c==b or b+c==a) return -1; //SEGMENT
    return 0;                                 //IMPOSSIBLE
}

void Check(vector<int> A)
{
    int res1 = Check_Tri(A[0],A[1],A[2]);
    int res2 = Check_Tri(A[1],A[2],A[3]);

    if(res1 == 1) { cout << "TRIANGLE";return;}
    if(res2 == 1) { cout << "TRIANGLE";return;}
    if(res1 == -1) { cout << "SEGMENT";return;}
    if(res2 == -1) { cout << "SEGMENT";return;}

    cout << "IMPOSSIBLE";
}

int main()
{
    vector<int> A(4);
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    sort(A.begin(),A.end(),greater<int>());
    Check(A);
    return 0;
}