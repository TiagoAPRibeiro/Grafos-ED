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

typedef struct registo{
    int idAntena;
    struct registo* seguinte;
}* Pilha;

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
return novoVertice;
}
printf("Vertices criados com sucesso !\n");
return listaAntena;
}


Vertices novo_adjacente(Vertices listaAntena){
Vertices idA = listaAntena;
    while(idA != NULL){ // vai percorrer a lista ligada
Vertices idB = idA->seguinte;
    while(idB != NULL){
        if(idA->nome == idB->nome && idA->idAntena != idB->idAntena){
            Adjacentes novoAdjacenteA = (Adjacentes)malloc(sizeof(struct antena2));
            novoAdjacenteA->idAntena = idB->idAntena;
            novoAdjacenteA->seguinte = idA->adjacentes;
            idA->adjacentes = novoAdjacenteA;
        
        Adjacentes novoAdjacenteB = (Adjacentes)malloc(sizeof(struct antena2));
        novoAdjacenteB->idAntena = idA->idAntena;
        novoAdjacenteB->seguinte = idB->adjacentes;
        idB->adjacentes = novoAdjacenteB;
    }
    idB = idB->seguinte;   
}
idA = idA->seguinte; 
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
    printf("Não existem antenas para criar adjacentes!\n");
    return;
}
Vertices actual = listaAntena;
while(actual != NULL){
    printf("Adjacentes de %c com o ID: (%d): " , actual->nome, actual->idAntena);
    Adjacentes auxAdj = actual->adjacentes;
    if(auxAdj == NULL){
        printf("Os vertices não tem qualquer adjacente!\n");
    }
        while(auxAdj != NULL){
            printf("%d ", auxAdj->idAntena);
            auxAdj = auxAdj->seguinte;
        }
        printf("\n");
        actual = actual->seguinte;
}
}


void listagem_adjacente_filtro(Vertices listaAntena, char nomeVertice){
    if(listaAntena == NULL){
        printf("Não existem antenas para criar adjacentes!\n");
        return;
    }
    int encontrar = 0;
    Vertices actual = listaAntena;
    while(actual != NULL){
        if(actual->nome == nomeVertice){
            encontrar = 1;
            printf("Adjacentes do vertice %c com o id (%d) :", actual->nome, actual->idAntena);
        
            Adjacentes auxiliar = actual->adjacentes;
            if(auxiliar == NULL){
            printf("Nenhum");
             }else{
                while(auxiliar != NULL){
                    printf("[%d]", auxiliar->idAntena);
                    auxiliar = auxiliar->seguinte;
                }
             }
             printf("\n");
        }
        actual = actual->seguinte;

        }
        if(!encontrar){
            printf("Não foi encontrado nenhum vertice com o nome %c.", nomeVertice);
        }
    }
    
Pilha push(Pilha pilhaAntena, int idAntena){   // inserir o valor no inicio da pilha
    Pilha novo;
    novo = (Pilha) malloc(sizeof(struct registo));
    if(novo != NULL){
        novo->idAntena = idAntena;
        novo->seguinte = pilhaAntena;
        return novo;
    }
    return pilhaAntena;
}

Pilha pop(Pilha pilhaAntena){   // remover o valor presente no topo da pilha
    Pilha auxiliar;
    if(pilhaAntena != NULL){
        auxiliar = pilhaAntena->seguinte;
        free(pilhaAntena);
        return auxiliar;
    }
    return pilhaAntena;
}

int pesquisa_profundidade(Vertices listaAntena, int idInicial, int idDestino){                          // perceber melhor e estudar melhor a funcao 
int visitados[FICHEIRO];
Pilha pilha = NULL;
Pilha caminho = NULL;
int verificacao = 0;
for(int i = 0; i < FICHEIRO; i++){
    visitados[i] = 0;               // inicializar sempre o visitados a ´0´
}
pilha = push(pilha, idInicial);     // adiciona o id inicial no topo da lista
caminho = push(caminho, idInicial);
visitados[idInicial] = 1;
printf("Caminho percorrido!\n");
while(pilha != NULL){
    int idActual = pilha->idAntena;
    pilha = pop(pilha);
    if(idActual == idDestino){            // é so uma verificaçao 
       verificacao = 1;
       break;
    }

    Vertices actual = listaAntena;
    while(actual != NULL && actual->idAntena != idActual){
        actual = actual->seguinte;
    }
        if(actual != NULL){
            Adjacentes adj = actual->adjacentes;
            while(adj != NULL){
                if (!visitados[adj->idAntena]){
                    pilha = push(pilha, adj->idAntena);
                    caminho = push(caminho, adj->idAntena);
                    visitados[adj->idAntena] = 1;
                    printf("Aresta Visitada: %d -> %d\n", idActual, adj->idAntena);
                }
                adj = adj->seguinte;
            }
        }
    }
    
if(verificacao){
    printf("\nID Destino %d encontrado!\n", idDestino);
    printf("Caminho percorrido: ");
    while(caminho != NULL){
       Vertices actual = listaAntena;
       while(actual != NULL && actual->idAntena != caminho->idAntena){
        actual = actual->seguinte;
       }   
       if(actual != NULL){
        printf("[%d:(%d, %d)] <- ", actual->idAntena, actual->linha, actual->coluna);
       }  
       caminho = pop(caminho);
    }
    printf("\n");
    return 1;
}else{
    printf("ID destino %d não encontrado.\n", idDestino);
    return 0;
}            
}

int pesquisa_caminho_profundidade(Vertices listaAntena, int idInicial){
    int visitados[FICHEIRO];
    Pilha pilha = NULL;
    Pilha caminho = NULL;

    for(int i = 0; i < FICHEIRO; i++){
        visitados[i] = 0; // Corrigido: iniciar todos como não visitados
    }

    pilha = push(pilha, idInicial);
    caminho = push(caminho, idInicial);
    visitados[idInicial] = 1;

    printf("Caminho Percorrido!\n");

    while(pilha != NULL){
        int idActual = pilha->idAntena;
        pilha = pop(pilha);

        Vertices actual = listaAntena;
        while(actual != NULL && actual->idAntena != idActual){
            actual = actual->seguinte;
        }

        if(actual != NULL){
            Adjacentes adjacente = actual->adjacentes;
            while(adjacente != NULL){
                if(!visitados[adjacente->idAntena]){
                    pilha = push(pilha, adjacente->idAntena);
                    caminho = push(caminho , adjacente->idAntena);
                    visitados[adjacente->idAntena] = 1;
                    printf("Aresta Visitada: %d -> %d\n", idActual, adjacente->idAntena);
                }
                adjacente = adjacente->seguinte;
            }
        }
    }

    // Imprimir caminho
    printf("Caminho Encontrado: ");
    while(caminho != NULL){
        Vertices actual = listaAntena;
        while(actual != NULL && actual->idAntena != caminho->idAntena){
            actual = actual->seguinte;
        }
        if(actual != NULL){
            printf("%d <-", actual->idAntena);
        }
        caminho = pop(caminho);
    }
    printf("\n");
    return 1;
}




int main(){
Vertices grafo = NULL;
char nomeVertice;
int opcao, subopcao, idInicio, idDestino;
do{
printf("1-leitura\n2-listagem\n3-Pesquisa\n4-Pesquisa caminho profundidade\n5-Sair");
scanf("%d", &opcao);

switch(opcao){
case 1:    
grafo = leitura(grafo);
novo_adjacente(grafo);
break;

case 2:
    do{
        
        printf("1-Lista de Antenas Lidas\n2-Listar Adjacentes Totais\n3-Listar Adjacentes por Nome\n4-Voltar atras\n");
        scanf("%d", &subopcao);

    switch(subopcao){
        case 1:
        listagem(grafo);
        break;

        case 2:
        listagem_adjacente(grafo);
        break;

        case 3:
        printf("Pretende explorar a adjacencia de que vertice?\n");
        scanf(" %c", &nomeVertice); // espaço no %c para ignorar o \n consumido pelo buffer nas opcoes do menu.
        listagem_adjacente_filtro(grafo, nomeVertice);
        break;

        case 4:
        printf("Sair\n");
        break;

        default:
        printf("Opção invalida!\n");
        break;
    }
    }while(subopcao != 4);
    break;



case 3:
printf("Qual o ID do vertice de origem ?\n");
scanf("%d", &idInicio);
printf("Qual o ID do vertice destino ?\n");
scanf("%d", &idDestino);
pesquisa_profundidade(grafo, idInicio, idDestino);
break;

case 4:
printf("Qual o ID do vertice que pretende iniciar o caminho?\n");
scanf("%d", &idInicio);
pesquisa_caminho_profundidade(grafo, idInicio);
break;

case 5:
printf(" Sair\n");
break;

default:
printf("opcao invalida\n");
break;
}
}while(opcao != 5);





    return 0;
}






