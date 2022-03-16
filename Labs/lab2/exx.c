#include <stdio.h>
int main()
{

    int h1, m1, s1, h2, m2, s2;
    int H, M, S, a;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    /*if(h1>h2 && m1>m2 && s1>s2){
    //a=h1; h1=h2; h2=a;

H=h1-h2;
M=m1-m2;
S=s1-s2;}*/
    if (h1 < h2)
    {
        H = h2 - h1;
    }
    else
    {
        H = 24 + h2 - h1;
    }
    if (m1 < m2)
    {
        M = m2 - m1;
    }
    else
    {
        M = 60 - m1 + m2;
    }
    if (s1 < s2)
    {
        S = s2 - s1;
    }
    else
    {
        S = 60 - s1 + s2;
    }

    printf("%d:%d:%d", H, M, S);
    return 0;
}