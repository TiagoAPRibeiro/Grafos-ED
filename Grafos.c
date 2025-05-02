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
novoVertice->idAntena = idAntena;
novoVertice->nome = nome;
novoVertice->linha = linha;
novoVertice->coluna = coluna;
novoVertice->adjacentes = NULL;
novoVertice->seguinte = listaAntena;
return(listaAntena);
}

//os vertices ja estao criados , aqui so fazemos conexoes, por isso é que nao precisamos de linha e coluna.
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
    char vt1, vt2;
    int linha = 1, coluna = 1;

    while(fscanf(ler, "%c", &nome) != EOF){
        if(nome != '.' && nome != '\n' && nome != ' '){
        listaAntena = novo_vertice(listaAntena, id, nome, linha, coluna);
        listaAntena = novo_adjacente(listaAntena, vt1, vt2);
        printf("Vertices lidos com sucesso !\n");
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
return listaAntena;
}

void listagem(Vertices listaAntena){
    while(listaAntena != NULL){
        printf("%d %c %d %d [", listaAntena->idAntena, listaAntena->nome, listaAntena->linha, listaAntena->coluna);
        Adjacentes auxiliar = listaAntena->adjacentes;
        while(auxiliar != NULL){
            printf("%d ", auxiliar->idAntena);
            auxiliar = auxiliar->seguinte;
        }
        printf("]\n");
        listaAntena = listaAntena->seguinte;
    }
}




int main(){
Vertices Grafo = NULL;    
int opcao;
do{
    printf("1 - ler ficheiro:\n 2 - listar dados:\n 3 - Sair do programa\n");
    scanf("%d", &opcao);
    switch (opcao){
        
        case 1:
        Grafo = leitura(Grafo);
        break;

        case 2:
        listagem(Grafo);
        break;
        
        case 3:
        printf("A sair do programa...\n");
        break;

        default:
        printf("Opcao invalida, tente novamente.\n");
        break;
        

    }
}while(opcao != 3);





    return 0;
}