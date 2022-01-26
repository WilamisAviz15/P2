#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void function(int i, int t, char v[])
{
    if(i < t)
    {
        return function(i+1, t, v);
    }
    else
    {
        if(v[i] % 2 == 0)
        {
            char uDig = v[i];
            uDig -= 4;
            v[i] = uDig;
            printf("%s", v);
        }
        else
        {
            char uDig = v[i];
            uDig -= 3;
            v[i] = uDig;
            printf("%s", v);
        }
        return;
    }
}

int main() 
{
    char n[10];
    scanf("%s", n);
    int tam = strlen(n);
    //printf("%d", tam);
    function(0, tam, n);
    return 0;
}