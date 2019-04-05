// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de An�lise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laborat�rio de Programa��o
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orienta��es gerais -----
//  Descri��o: esse arquivo deve conter as quest�es do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as quest�es do trabalho

//  ----- Dados do Aluno -----
//  Nome: Matheus Alves Rodrigues
//  email: mr634580@gmail.com
//  Matr�cula: 2017216027
//  Semestre: 2

//  Copyright � 2016 Renato Novais. All rights reserved.
// �ltima atualiza��o: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno1.h"

struct DATA{
	int dia;
	int mes;
	int ano;
};
typedef struct DATA dma;
/*
## fun��o utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
*/
int somar(int x, int y){
  int soma;
  soma = x+y;
  return soma;
}

/*
## fun��o utilizada para testes  ##
 fatorial = fatorial de um n�mero
@objetivo
    calcular o fatorial de um n�mero
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //fun��o utilizada para testes
  if(x==0)
	return 1;
  else
	return x*fatorial(x-1);
}
void DataConverter(char *data, int *dia, int *mes, int *ano){

    int i = 0, j, cont, parada = 0, condicao = 0;
    char string[5];

     for(j = 0; j < 3; j++){
        cont = 0;
        while(i < strlen(data)){

            if(data[i] - 47 == 0)
                break;
            if(((data[i] - 48 < 0) && (data[i] - 48 > 9)) || (data[i] - 48 < 0) || (data[i] - 48 > 9)){
                  parada = 1;
                  break;
            } else if(data[i] - 48 >= 0 && data[i] - 48 <= 9){
                string[cont++] = data[i];
            }
            i++;
        }

        if(parada){
          condicao = 1;
          break;
        }

        string[cont] = '\0'; //?para n�o pegar lixo

        if(j == 0 && cont <= 2) //?cont <= 2 para limitar a quantidade de casas
            *dia = atoi(string);
        else if(j == 1 && cont <= 2)
            *mes = atoi(string);
        else if(j == 2 && (cont == 2 || cont == 4))
            *ano = atoi(string);
        else
          condicao = 1;

        i++;
    }

    if(condicao)
      *dia = *mes = *ano = 0;
}
/*Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = m�s, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inv�lida
    1 -> se data v�lida
 */
int q1(char *data){
    int i, j, cont, k;
    int dia=0, mes=0, ano=0, datavalida=0;
    char strDia[3], strMes[3], strAno[5];


    for(i=0; data[i] != '/'; i++){
        strDia[i] = data[i];
    }
    strDia[i] = '\0';

    for(i=i+1, j=0; data[i] != '/'; j++, i++){
      strMes[j] = data[i];
    }

    cont = i + 5;

    for(i=i+1, k=0; data[i] != '\0'; k++, i++) {
		strAno[k] = data[i];
	}


    dia = atoi(strDia);
    mes = atoi(strMes);
    ano = atoi(strAno);

    if(dia > 31)
        return datavalida = 0;

	if(ano >= 0000 && ano <= 9999){
        	if (mes >= 1 && mes <= 12){
            		if (dia >= 1 && dia <= 31 && mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
                        datavalida = 1;
            		else if (dia >= 1 && dia <= 30 && mes == 4 || mes == 6 || mes == 9 || mes == 11)
                		datavalida = 1;
            		else if (dia >= 1 && dia <= 28 && mes == 2)
                		datavalida = 1;
            		else if (dia == 29 && mes == 2 && ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
                        datavalida = 1;
               		else
                		datavalida = 0;
       		}else{
                    datavalida = 0;
        	}
	}else{
		datavalida = 0;
	}
    return datavalida;

}
/*
 Q2 = diferen�a entre duas datas
 @objetivo
    Calcular a diferen�a em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Al�m disso, a fun��o tem tr�s par�metros qtdDias, qtdMeses e qtdAnos. Esses tr�s par�metros devem ser utilizados para guardar os resultados dos c�lculos. Na chamada da fun��o deve passar o valor -1 para os tr�s
 @saida
    1 -> c�lculo de diferen�a realizado com sucesso
    2 -> datainicial inv�lida
    3 -> datafinal inv�lida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int dias, meses, anos, nDias;
    int validador = 0;
    int inicioDia, inicioMes, inicioAno, finalDia, finalMes, finalAno;
    dma entraDATA;
    dma finalDATA;


 //data valida == 1, data invalida == 2;
    if(q1(datainicial) == 1){
        DataConverter(datainicial, &entraDATA.dia, &entraDATA.mes, &entraDATA.ano);
        inicioDia = entraDATA.dia;
        inicioMes = entraDATA.mes;
        inicioAno = entraDATA.ano;
    } else
        return 2;

 //data valida == 1, data invalida = 3
    if(q1(datafinal) == 1){
        DataConverter(datafinal, &finalDATA.dia, &finalDATA.mes, &finalDATA.ano);
        finalDia = finalDATA.dia;
        finalMes = finalDATA.mes;
        finalAno = finalDATA.ano;
    } else
        return 3;

 //data inicial > datafinal retorna '4'
    if((inicioAno > finalAno) || (inicioAno == finalAno && ((inicioMes > finalMes) ||  ((inicioMes == finalMes) && (inicioDia > finalDia))))){
        return 4;
    }

 //calculo diferenca valido == 1
    else{
        anos = finalAno - inicioAno;

    if(finalMes >= inicioMes){
        meses = finalMes - inicioMes;
        if(finalDia >= inicioDia){
            dias = finalDia - inicioDia;
        } else
            if(finalDia < inicioDia){
                dias = inicioDia - finalDia;
                meses = meses -1;
                if(((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) && (finalAno % 400 == 0 || (inicioAno % 4 == 0 && inicioAno % 100 != 0))) || ((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) && (finalAno % 400 != 0 || (finalAno % 4 != 0 && finalAno % 100 == 0)))){
                    if((finalMes == 2) || (inicioMes == 2)){
                        dias = 29 - dias;
                    } else
                        if(((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || (finalMes == 11)) || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                            dias = 30 - dias;
                        } else
                            if((finalMes == 1 || finalMes == 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 || finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 || inicioMes == 5 || inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){
                                dias = 31 - dias;
                            }
                } else{
                    if((finalMes == 2) || (inicioMes == 2)){
                        dias = 28 - dias;
                    } else
                        if(((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || (finalMes == 11)) || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                            dias = 30 - dias;
                        } else
                            if((finalMes == 1 || finalMes == 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 || finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 || inicioMes == 5 || inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){                            nDias = 31 - nDias;
                            }
                }
            }

        else if(finalMes < inicioMes){
                meses = inicioMes - finalMes;
                anos = anos - 1;
                meses = 12 - meses;

            if(finalDia >= inicioDia){
                dias = finalDia - inicioDia;
            } else
                if(finalDia < inicioDia){
                    dias = inicioDia - finalDia;
                    meses = meses -1;
                    if(((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) && (inicioAno % 400 == 0 || (inicioAno % 4 == 0 && inicioAno % 100 != 0))) || ((finalAno % 400 == 0 || (finalAno % 4 == 0 && finalAno % 100 != 0)) && (inicioAno % 400 != 0 || (inicioAno % 4 != 0 && inicioAno % 100 == 0)))){
                        if((finalMes == 2) || (inicioMes == 2)){
                            dias = 29 - dias;
                        } else

                        if((((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || finalMes == 11)) || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                            dias = 30 - dias;
                        } else

                        if((finalMes == 1 || finalMes== 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 || finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 || inicioMes == 5 || inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){
                            dias = 31 - dias;
                        }
                    }
                else{
                    if((finalMes == 2) || (inicioMes == 2)){
                        dias = 28 - dias;
                    } else

                    if(((finalMes == 4) || (finalMes == 6) || (finalMes == 9) || (finalMes == 11)) || ((inicioMes == 4) || (inicioMes == 6) || (inicioMes == 9) || (inicioMes == 11))){
                        dias = 30 - dias;
                    } else

                    if((finalMes == 1 || finalMes == 3 || finalMes == 5 || finalMes == 7 || finalMes == 8 || finalMes == 10 || finalMes == 12) || (inicioMes == 1 || inicioMes == 3 || inicioMes == 5 || inicioMes == 7 || inicioMes == 8 || inicioMes == 10 || inicioMes == 12)){
                        dias = 31 - dias;
                    }
                }
            }
        }
    }
    validador = 1;
  }
 //validador == 1, return diferenca das datas
    if(validador == 1){
        *qtdDias = dias;
        *qtdMeses = meses;
        *qtdAnos = anos;
        return 1;
  }
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se � uma pesquisa Case Sensitive ou n�o. Se isCaseSensitive = 1, a pesquisa deve considerar difer�ncias entre mai�sculos e min�sculos.
        Se isCaseSensitive != 1, a pesquisa n�o deve  considerar difer�ncias entre mai�sculos e min�sculos.
 @saida
    Um n�mero n >= 0.
*/
int q3(char *texto, char c, int isCaseSensitive){
    int i, qtdOcorrencias = 0;

    if(isCaseSensitive == 0){
        for(i=0; texto[i] != '\0'; i++){
            if(texto[i]==c-32 || texto[i]==c+32 || texto[i]==c)
                qtdOcorrencias++;
        }
    }
    else if(isCaseSensitive==1){
        for(i=0; texto[i] != '\0'; i++){
            if(texto[i]==c)
                qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;

}
/*Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorr�ncias de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que ir� guardar as posi��es de in�cio e fim de cada ocorr�ncia da palavra (strBusca) no texto base (texto).
 @saida
    Um n�mero n >= 0 correspondente a quantidade de ocorr�ncias encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e sa�da correspondente. Por exemplo, se tiver uma �nica ocorr�ncia, a posi��o 0 do vetor deve ser preenchido com o �ndice de in�cio do texto, e na posi��o 1, deve ser preenchido com o �ndice de fim da ocorrencias. Se tiver duas ocorr�ncias, a segunda ocorr�ncia ser� amazenado nas posi��es 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como h� uma ocorr�ncia da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o �ndice da posi��o no texto deve come�ar ser contado a partir de 1.
        O retorno da fun��o, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){

    int i,j,k,x,a,contador1,ocorrencias,contador3;

    x=a=j=k=contador1=ocorrencias=contador3=0;

    if(strlen(strBusca)==1){
        for(i=0;strTexto[i]!='\0';i++){
            if(strTexto[i]==strBusca[0])
                contador1++;
        }
        return contador1;
    }

    for(i = 0; strTexto[i]!='\0'; i++){
        contador1=0;
        if(strTexto[i]==-61){
            contador3++;
        }
        if(strTexto[i] == strBusca[j]){
            for(x=i+1,k=j+1;strBusca[k]==strTexto[x];x++,k++)
                contador1++;
        }
        if(contador1==strlen(strBusca)-1){
            posicoes[a++]=(i+1)-contador3;
            posicoes[a++]=x-contador3;
            ocorrencias++;
        }
    }
    return ocorrencias;
}

/*
 Q5 = inverte n�mero
 @objetivo
    Inverter n�mero inteiro
 @entrada
    uma int num.
 @saida
    N�mero invertido
*/


int q5(int num){
    int valorInvertido, aux;
    valorInvertido=aux=0;

    while(num > 0){
        aux = num % 10;
        valorInvertido = valorInvertido * 10 + aux;
        num = num/10;
    }

    return valorInvertido;
}

/*Q6 = ocorr�ncia de um n�mero em outro
 @objetivo
    Verificar quantidade de vezes da ocorr�ncia de um n�mero em outro
 @entrada
    Um n�mero base (numerobase) e um n�mero de busca (numerobusca).
 @saida
    Quantidade de vezes que n�mero de busca ocorre em n�mero base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0;
    int vetorBase[100];
    int vetorBusca[100];
    int contadorBase=0, i=0, j=0, controle=0;
    int contadorBusca=0;


    while(numerobase>=0){
		if(numerobase < 10 && numerobase >= 0 ){
			vetorBase[contadorBase]=numerobase;
			break;
		}
		else{
			vetorBase[contadorBase]=numerobase%10;
			numerobase=numerobase/10;
			contadorBase++;
		}
	}
	while(numerobusca>=0){
		if(numerobusca < 10 && numerobase >= 0){
			vetorBusca[contadorBusca]=numerobusca;
			break;
		}
		else{
			vetorBusca[contadorBusca]=numerobusca%10;
			numerobusca=numerobusca/10;
			contadorBusca++;
		}
	}
	for ( i = 0; i <= contadorBase; ++i){
		if(contadorBusca == 0){
			if (vetorBusca[0] == vetorBase[i]){
				qtdOcorrencias++;
			}
		}
		else{
			if(vetorBusca[j] == vetorBase[i]){
				controle=1;
				j++;
			}
			else if (vetorBusca[j] != vetorBase[i]){
				controle=0;
				j=0;
			}
			if(controle == 1 && j == contadorBusca){
				controle=0;
				j=0;
				qtdOcorrencias++;
			}
		}
	}
    return qtdOcorrencias;
}

