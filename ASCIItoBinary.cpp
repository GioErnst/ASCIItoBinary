#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertBinary1(int n);
int convertBinary2(FILE *file,int n);

int main(void){
    FILE *file;
    file = fopen("file.txt","r");

    if(file == NULL){
        printf("Could not open file.\n");
        exit(0);
    }
    char text[1000000];
    while(fgets(text,1000000,file)!= NULL){
        printf("%s\n",text);
    }

    printf("%d%d\n",text[0],text[1]);
    printf("%d\n",strlen(text));

    int cont = strlen(text);

    for(int i =0; i < cont ;i++){
        if(text[i]!=' ')
            convertBinary1(text[i]);
            printf(" ");
    }

    fclose(file);
    file = fopen("file.txt","a");
        fprintf(file,"\n");
        for(int i =0; i < cont ;i++){
            if(text[i]!=' ')
                convertBinary2(file,text[i]);
        fprintf(file," ");
        }
    fclose(file);
}

int convertBinary1(int n){
   if(n == 0)
        return 0;
    else{
        if(n == -61|| n == -62)
        n = 128+n+128;
        else if(n<0 && n!=-61 && n!= -62)
            n = 256+n;
        convertBinary1(n/2);
        return printf("%d", n % 2);
    }
}

int convertBinary2(FILE *file,int n){
if(n == 0)
    return 0;
    else{
        if(n == -61|| n == -62)
        n = 128+n+128;
        else if(n<0 && n!=-61 && n!= -62)
            n = 256+n;
        convertBinary2(file,n/2);
        return fprintf(file,"%d",n % 2);
    }
}
