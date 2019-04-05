#include <stdio.h>
#include <string.h>

void tabuleiro();
void cabecalho(); //FAVOR, LER COMENTÁRIOS DENTRO DESTA FUNÇÃO ANTES DE EXECUTA-LA

int main(void) {
  char casas[3][3] = {{'x', 'o', 'x'}, {'x', 'o', 'o'}, {'o', 'o','x'}};
  tabuleiro(casas);
  char retorno;
  int jogadas=0, linha, coluna, vez=0, i, j;
  do{
        jogadas = 1;
        for(i=0; i<=2; i++){
            for(j=0; j<=2; j++){
                casas[i][j] = ' ';
            }
        }
      do{
        tabuleiro(casas);
        if(vez%2==0){
            printf("Jogador X\n");
        }else{
            printf("Jogador O\n");
        }
        //tabuleiro(casas);
        printf("Digite a linha: ");
        scanf("%d", &linha);
        printf("Digite a coluna: ");
        scanf("%d", &coluna);
        if(linha < 1 || coluna < 1 || linha > 3 || coluna > 3){
            //printf("Jogada invalida!!\n");
            linha = 0;
            coluna = 0;
        }else if(casas[linha-1][coluna-1] != ' '){
            linha = 0;
            coluna = 0;
        }else{
            if(vez%2==0){
                casas[linha-1][coluna-1] = 'X';
            }else{
                casas[linha-1][coluna-1] = 'O';
            }
            vez++;
            jogadas++;
        }
        if(casas[0][0]=='X' && casas[0][1]=='X' && casas[0][2]=='X') jogadas=11; //VITÓRIAS POSSÍVEIS
        if(casas[1][0]=='X' && casas[1][1]=='X' && casas[1][2]=='X') jogadas=11;
        if(casas[2][0]=='X' && casas[2][1]=='X' && casas[2][2]=='X') jogadas=11;
        if(casas[0][0]=='X' && casas[1][0]=='X' && casas[2][0]=='X') jogadas=11;
        if(casas[0][1]=='X' && casas[1][1]=='X' && casas[2][1]=='X') jogadas=11;
        if(casas[0][2]=='X' && casas[1][2]=='X' && casas[2][2]=='X') jogadas=11;
        if(casas[0][0]=='X' && casas[1][1]=='X' && casas[2][2]=='X') jogadas=11;
        if(casas[0][2]=='X' && casas[1][1]=='X' && casas[2][0]=='X') jogadas=11;

        if(casas[0][0]=='O' && casas[0][1]=='O' && casas[0][2]=='O') jogadas=12;
        if(casas[1][0]=='O' && casas[1][1]=='O' && casas[1][2]=='O') jogadas=12;
        if(casas[2][0]=='O' && casas[2][1]=='O' && casas[2][2]=='O') jogadas=12;
        if(casas[0][0]=='O' && casas[1][0]=='O' && casas[2][0]=='O') jogadas=12;
        if(casas[0][1]=='O' && casas[1][1]=='O' && casas[2][1]=='O') jogadas=12;
        if(casas[0][2]=='O' && casas[1][2]=='O' && casas[2][2]=='O') jogadas=12;
        if(casas[0][0]=='O' && casas[1][1]=='O' && casas[2][2]=='O') jogadas=12;
        if(casas[0][2]=='O' && casas[1][1]=='O' && casas[2][0]=='O') jogadas=12;
      }while(jogadas<=9);

      tabuleiro(casas);
      if(jogadas == 10){
            printf("\tEMPATEE!!\n");
      }else if(jogadas == 11){
            printf("\tPlayer X Wins!!\n");
      }else if(jogadas == 12){
            printf("\tPlayer O Wins!!\n");
      }else{
        printf("Deseja continuar[s\n]?\n");
        scanf("%c", &retorno);
    }
  }while(retorno == 's');
  return 0;
}

void tabuleiro(char casas2[3][3]){
    cabecalho();
    printf("\t %c | %c | %c\n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t-------------\n");
    printf("\t %c | %c | %c\n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t-------------\n");
    printf("\t %c | %c | %c\n", casas2[2][0], casas2[2][1], casas2[2][2]);
}

void cabecalho(){
  /*
  USE DE ACORDO COM O SEU SISTEMA:
    system("cls");//Comando LimpaTela para Windows
    system("clear");//Comando LimpaTela para Linux/Unix/Mac
  */
    system("clear");//Comando LimpaTela para Linux/Unix/Mac
    printf("\t#################\n");
    printf("\t  Jogo da Velha\n");
    printf("\t#################\n");
}
