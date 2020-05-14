/* Data de submissao: 14/05/2020
 * Nome: André Luis Haime Coutinho
 * RA: 166329
 */

#include <stdio.h>


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
  
  // limpa o vetor pilha, por seguranca 
  for (int i=0; i< 100; i++) pilha[i] = '\n';
  
  
  for (int i =0; i<100; i++){
    // Percorre o buffer
    if (buffer[i] != ' ' && buffer[i] != '\n'){
      // se encontrar um caracter que não seja letra ou 
      // quebra de linha, adiciona no buffer
      push( buffer[i]);
      
      // variavel para indicar que o ultimo caracter encontrado
      // era letra
      era_letra = 1;
    }
    else if ((buffer[i] == ' ' || buffer[i] == '\n') && era_letra){
      // se encontrar um espaco ou quebra de linha e o ultimo caracter lido
      // tiver sido uma letra, tira todos os itens do buffer;
      tamanho_palavra = n_pilha;
      for (int j=0; j<tamanho_palavra; j++) printf("%c", pop());
      era_letra =0;
    }
    // se encontrar um espaco e o ultimo caracter não for uma letra,
    // imprime um espaco
    if (buffer[i] == ' ' && ! era_letra) printf(" ");
    // se encontrar uma quebra de linha e o ultimo caracter não for uma letra,
    // imprime uma quebra de linha
    else if (buffer[i] == '\n' && ! era_letra) printf("\n");
    // para o for quando encontrar uma quebra de linha
    if (buffer[i] == '\n') break;
  }

  return 0;
}
