#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FICHEIRO 50

typedef struct antena2{
int idAntena; //idv2
struct antena2* seguinte;
} * Adjacentes;

typedef struct antena1{
 int idAntena; //idv1
 char nome;
 int linha;
 int coluna; 
 Adjacentes adjacentes; // antena2
 struct antena1 * seguinte;  
} * Vertices;

Vertices novo_vertice(Vertices listaAntena, int idAntena, char nome, int linha, int coluna){           
Vertices novoVertice;
novoVertice = (Vertices)malloc(sizeof(struct antena1));  
if(novoVertice != NULL){
novoVertice->idAntena = idAntena;
novoVertice->nome = nome;
novoVertice->linha = linha;
novoVertice->coluna = coluna;
novoVertice->adjacentes = NULL;
novoVertice->seguinte = listaAntena;
printf("%d %c %d %d\n", novoVertice->idAntena, novoVertice->nome, novoVertice->linha, novoVertice->coluna);
return novoVertice;
}
return listaAntena;
}


Vertices novo_adjacente(Vertices listaAntena, int idAntena1, int idAntena2){ // pergunta os numeros que queremos ligar , id1 e id2
Vertices auxiliar = listaAntena;
while(auxiliar != NULL){
    if(auxiliar->idAntena == idAntena1){ //verifica a condicao se a id antena qualquer existente na lista for == "id de antena que dizemos q queremos ligar" ? verdade,existe  entao:
    Adjacentes novo;
    novo = (Adjacentes)malloc(sizeof(struct antena2));//cria espaço para um novo adjacente 
    novo->idAntena = idAntena2;//guarda o id da "outra antena que queremos ligar" fica como id1 -> id2
    novo->seguinte = auxiliar->adjacentes;// insere no inicio da lista ligada
    auxiliar->adjacentes = novo;               //agora a lista de adjacentes comeca com o "novo" que acabei de criar.     
    }
    if(auxiliar->idAntena == idAntena2){  // aqui faz o inverso para termos algo como dois pontos ligados.
    Adjacentes novo;
    novo = (Adjacentes)malloc(sizeof(struct antena2));
    novo->idAntena = idAntena1;                                                             //fica como id2 -> id1
    novo->seguinte = auxiliar->adjacentes;
    auxiliar->adjacentes = novo;
    }
    auxiliar = auxiliar->seguinte;
    
} 
    return listaAntena;
}

Vertices leitura(Vertices listaAntena){
    char nome_ficheiro[FICHEIRO];
    printf("Qual o nome do ficheiro que pretende ler ?\n");
    scanf("%s", nome_ficheiro);

    FILE *ler = fopen(nome_ficheiro, "r");
    if(ler == NULL){
        printf("Erro ao abrir o ficheiro !\n");
        return(listaAntena);
    }
    char nome;
    int id = 1;
    int linha = 1, coluna = 1;

    while(fscanf(ler, "%c", &nome) != EOF){
        if(nome != '.' && nome != '\n' && nome != ' '){
        listaAntena = novo_vertice(listaAntena, id, nome, linha, coluna);
        
        id++;
    }
   
    if (nome == '\n'){
        linha++;
        coluna = 1;
    }
        else{
            coluna++;
        }
    }
fclose(ler);
printf("Vertices lidos com sucesso !\n");

return listaAntena;
}

void listagem(Vertices listaAntena){
    if(listaAntena == NULL){
        printf("Não há Grafos registados na sua lista de Antenas!\n");
        return;
    }
    Vertices actual = listaAntena;
    while(actual != NULL){
        printf("%d %c %d %d\n", actual->idAntena, actual->nome, actual->linha, actual->coluna);
        actual = actual->seguinte;
    }
}


void listagem_adjacente(Vertices listaAntena){
    if(listaAntena == NULL){
        printf("Não existem Antenas para criar as suas adjacencias!\n");
        return;
    }
    Vertices temp = listaAntena;
    while(temp!= NULL){
        printf("%d %c %d %d tem como adjacencia o vertice [", listaAntena->idAntena, listaAntena->nome, listaAntena->linha, listaAntena->coluna);
        Adjacentes aux = listaAntena->adjacentes;
        while(aux!= NULL){
            printf("%d ", aux->idAntena);
            aux = aux->seguinte;

        }
        printf("\n");
        temp = temp->seguinte;
    }
    
}



int main(){
Vertices grafo = NULL;

int opcao;
do{
printf("\n1- leitura\n 2- listagem\n 3 - listar Adjacente 4\n - sair\n");
scanf("%d", &opcao);

switch(opcao){
case 1:    
grafo = leitura(grafo);
break;

case 2:
listagem(grafo);
break;

case 3:
listagem_adjacente(grafo);
break;

case 4:
printf("Sair\n");
break;

default:
printf("opcao invalida\n");
break;
}
}while(opcao != 4);





    return 0;
}