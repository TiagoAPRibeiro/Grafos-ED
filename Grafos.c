#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct antena2{
int idAntena;
struct antena2* seguinte;
} * Adjacentes;

typedef struct antena1{
 int idAntena;
 char nome;
 int linha;
 int coluna; 
 Adjacentes adjacentes;
 struct antena1 * seguinte;  
} * Vertices;

Vertices novo_vertice(Vertices listaAntena, int idantena, char nome, int linha, int coluna){
Vertices novoVertice;
novoVertice = (Vertices)malloc(sizeof(struct antena1));  
novoVertice->idAntena = idantena;
novoVertice->nome = nome;
novoVertice->linha = linha;
novoVertice->coluna = coluna;
novoVertice->adjacentes = NULL;
novoVertice->seguinte = listaAntena;
return(listaAntena);
}












int main(){





    return 0;
}