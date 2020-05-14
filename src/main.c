/* Data de submissao:
 * Nome:
 * RA:
 */

#include <stdio.h>
#include <string.h>

const int tam_buffer=100;
char pilha[100];
int n_pilha=0;

void push(char c) {
/* Insere caractere c na pilha */
  if (n_pilha < 100) {
    pilha[n_pilha]=c;
    n_pilha++;
  }
}

char pop() {
/* Remove caractere do topo da pilha */
  char c;
  if (n_pilha>0) {
    n_pilha--;
    c = pilha[n_pilha];
  }
  return c;
}


int main() {
  char buffer[tam_buffer];
  int flag = 0;
  int era_letra =0;
  int tamanho_palavra =0;
  
  fgets(buffer, tam_buffer, stdin);
  //printf("%s", buffer);
  
  for (int i=0; i< 100; i++) pilha[i] = '\n';
  //printf("%d", n_pilha);
  for (int i =0; i<100; i++){
    if (buffer[i] != ' ' && buffer[i] != '\n'){
      push( buffer[i]);
      era_letra = 1;
    }
    else if ((buffer[i] == ' ' || buffer[i] == '\n') && era_letra){
     
      tamanho_palavra = n_pilha;
      for (int j=0; j<tamanho_palavra; j++) printf("%c", pop());
      era_letra =0;
    }
    if (buffer[i] == ' ' && ! era_letra) printf(" ");
    else if (buffer[i] == '\n' && ! era_letra) printf("\n");
    if (buffer[i] == '\n') break;
  }

  return 0;
}
