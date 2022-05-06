#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convertBinary1(int n);z//essa função recebe um inteiro n que contem o valor ASCII de um caractere e o transforma em binario utf-8(retorna esses valores no terminal);
int convertBinary2(FILE *file,int n);//essa função recebe um ponteiro de file e um inteiro n que contem o valor ASCII de um caractere e o transforma em binario utf-8(escreve esses valores no arquivo.txt);

int main(void){
    FILE *file;//é criado um ponteiro file para apontar para o arquivo.txt;
    file = fopen("file.txt","r");//o arquivo.txt é aberto para leitura usando o prefixo "r";

    if(file == NULL){//caso o arquivo não exista retorna uma mensagem;
        printf("Could not open file.\n");
        exit(0);
    }
    char text[1000000];//é definido o tamanho maximo do texto contido no arquivo.txt;
    while(fgets(text,1000000,file)!= NULL){//printa todo o conteudo do arquivo.txt;
        printf("%s\n",text);
    }

    printf("%d%d\n",text[0],text[1]);//apenas para parametro de testes é impresso os dois primeiros numeros decimais equivalentes aos dois primeiros caracteres contidos no arquivo.txt;
    printf("%d\n",strlen(text));//é contado e impresso o tamanho do texto contido no arquivo.txt;

    int cont = strlen(text);//o tamanho do texto é atribuido a variavel inteira cont;

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
        if(n == -61|| n == -62)//aqui é conferido se o caractere é igual a -61 ou -62 (esses numeros só retornam caso seja um caractere especial e equivalem a primeira parte dele);
        n = 128+n+128;//caso n seja um caractere especial menor que zero e igual a -61 ou -62 sera feito o seguinte calculo (128+(-n)+128), e então ele é transformado em utf-8 decimal;
        else if(n<0 && n!=-61 && n!= -62)//esse trecho é usado para a segunda parte de um caractere especial, se confere se ele é menor que zero e diferente de -61 e -62;
            n = 256+n;//e então se adiciona +256 a ele, o fazendo ficar equivalente a uft-8 em decimal;
        convertBinary1(n/2);
        return printf("%d", n % 2);//e aqui se printa no terminal e chama a função recursiva novamente para transformar os numeros subsequentes em binario;
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
        return fprintf(file,"%d",n % 2);//e aqui se escreve no arquivo.txt e chama a função recursiva novamente para transformar os numeros subsequentes em binario;
    }
}
