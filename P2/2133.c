#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void monta_array(char frases[])
{
    if(scanf("%[^\n]s", frases) == EOF)
    {
        printf("%s", frases);
        return;
        
    }
    else
    {
        return monta_array(frases);
    }
}

int main() {
    char frases[100];
    int i = 0;

    //frases = (char*)malloc(100*sizeof(char));

    //scanf("%[^\n]s", frases);
    //printf("%s", frases);

    monta_array(frases);
    return 0;
}