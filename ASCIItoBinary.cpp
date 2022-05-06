#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int convertBinario(int n){
   if(n == 0)
        return 0;
    else
    {
        if(n == -61|| n == -62)
        {
        n = 128+n+128;
        }
        else if(n<0 && n!=-61 && n!= -62)
        {
            n = 256+n;
        }
        convertBinario(n/2);
        return printf("%d", n % 2);
    }
}
int convertBinario2(FILE *file,int n);
int main(void)
{
    FILE *file;
    file = fopen("arquivo.txt","r");

    if(file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(0);
    }
    char texto[1000000];
    while(fgets(texto,1000000,file)!= NULL)
    {
        printf("%s\n",texto);
    }

    printf("%d%d\n",texto[0],texto[1]);
    printf("%d\n",strlen(texto));

    int cont = strlen(texto);

    for(int i =0; i < cont ;i++)
    {
        if(texto[i]!=' ')
            convertBinario(texto[i]);
            printf(" ");
    }

    fclose(file);
    file = fopen("arquivo.txt","a");
        fprintf(file,"\n");
        for(int i =0; i < cont ;i++){
            if(texto[i]!=' ')
                convertBinario2(file,texto[i]);
        fprintf(file," ");
        }
    fclose(file);

}
int convertBinario2(FILE *file,int n){
if(n == 0)
    return 0;
    else{
        if(n == -61|| n == -62)
        {
        n = 128+n+128;
        }
        else if(n<0 && n!=-61 && n!= -62)
        {
            n = 256+n;
        }
        convertBinario2(file,n/2);
        return fprintf(file,"%d",n % 2);
    }
}