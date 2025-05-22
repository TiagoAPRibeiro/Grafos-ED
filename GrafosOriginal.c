#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "grafos.h"




 /**
 * @brief Criação de uma nova antena.
 * 
 * Esta função cria uma nova antena que recebe como parametro o nome da sua frequencia assim como as suas cordenadas, de modo sequencial é lhe atribuido um numero de ID.
 * @param idAntena ID atribuido.
 * @param nome é a sua frequencia.
 * @param linha linha onde se encontra na cordenada.
 * @param coluna coluna onde se encontra na cordenada.
 * 
 * @return Toda a estrutura de uma Antena(Vertice) nova criada.
 */
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

/**
 * @brief Criação de uma adjacencia.
 * 
 * Esta função atribui através do nome igual a sua adjacencia , criando um grafo completo entre todos os vertices de Antenas.
 * 
 * @param nome Faz a verificação de frequencias iguais atravez do nome.
 * 
 * 
 * @return Cria uma adjacencia entre vertices com o mesmo nome.
 */
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

/**
 * @brief Leitura de um ficheiro em formato TXT.
 * 
 * Esta função faz a leitura de um ficheiro no formato txt, onde recebe informaçoes do ficheiro com frequencias , linhas e colunas, é lhe atriubuido um numero ID aquando a leitura 
 * e guarda a nossa lista ligada todas as suas informaçoes.
 * 
 * @param nome Recebe as frequencias de todas as antenas presentes no ficheiro.
 * @param cordenadas Recebe todas as cordenadas do ficheiro txt.
 * @param ID Atribui um numero id a cada vertice.
 * 
 * 
 * @return Apos a sua leitura , em conjunto com as funcoes destinadas as suas criaçoes , guarda na lista ligada as novas frequencias com 
 * as respetivas cordenadas.
 */     
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
/**
 * @brief Fáz um print da informação em forma de lista das nossas frequencias e respetivas cordenadas.
 * 
 * Esta função ajuda na consulta de informação das Antenas , conseguimos ir verificando em forma de lista as suas frequençias , cordenadas e ID
 * para ser de melhor acesso visual a sua mudança na sua manipulação.
 * @param ID - id dos vertices.
 * @param nome Frequançia da Antena.
 * @param cordenadas Cordenadas da Antena.
 * 
 * 
 * @return Cria uma lista da informaçao atualizada da nossa Lista Ligada.
 */
void listagem(Vertices listaAntena){
    if(listaAntena == NULL){
        printf("Não há Grafos registados na sua lista de Antenas!\n");
        return;
    }
    Vertices actual = listaAntena;
    while(actual != NULL){
        printf("ID %d Vertice %c [%d, %d]\n", actual->idAntena, actual->nome, actual->linha, actual->coluna);
        actual = actual->seguinte;
    }
}

 /**
 * @brief Fáz um print da informação em forma de lista das nossas frequencias, IDs , e adjacencias.
 * 
 * Esta função lista todas as antenas de vertices , mas com a listagem já das suas adjacencias.
 * @param ID Id dos vertices.
 * @param nome Frequançia da Antena.
 *@param adjacentes Adjacencias
 * 
 * 
 * @return Cria uma lista da informaçao atualizada da nossa Lista Ligada, agora com os adjacentes
 */
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

  /**
 * @brief Fáz um print da informação em forma de lista das nossas frequencias filtrando pelo nome da frequencia que queremos.
 * 
 * Esta função pesquisa e lista as antenas vertices atravez do filtro do nome da antena que queremos ler.
 * 
 * @param nome Frequançia da Antena.
 * @param ID id dos vertices.
 * @param Adjacentes Adjacencias.
 * 
 * 
 * @return Cria uma lista da informaçao atraves da pesquisa por nome da antena.
 */
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
  /**
 * @brief Função para inserir um novo valor no topo da pilha
 * 
 * Esta função cria um no com o valor que le no topo da pilha.
 * @param ID Guarda o valor do Id na pilha.
 
 * 
 * 
 * @return Um valor no topo da pilha.
 */  
Pilha push(Pilha pilhaAntena, int idAntena){   
    Pilha novo;
    novo = (Pilha) malloc(sizeof(struct registo));
    if(novo != NULL){
        novo->idAntena = idAntena;
        novo->seguinte = pilhaAntena;
        return novo;
    }
    return pilhaAntena;
}
/**
 * @brief Função para remover um valor do topo da pilha.
 * 
 * Esta função remove o elemento ID do topo da pilha.
 * @param ID Remove o valor do Id na pilha e retorna um novo topo da pilha.
 
 * 
 * 
 * @return Remove um valor no topo da pilha.
 */
Pilha pop(Pilha pilhaAntena){   // remover o valor presente no topo da pilha- acrescentr return
    Pilha auxiliar;
    if(pilhaAntena != NULL){
        auxiliar = pilhaAntena->seguinte;
        free(pilhaAntena);
        return auxiliar;
    }
    return pilhaAntena;
}
/**
 * @brief Função para inserir um novo valor id no fim da fila.
 * 
 * Esta função adiciona um novo elemento no fim da fila.
 * @param ID Adiciona o ID no fim da fila.
 
 * 
 * 
 * @return Adiciona o valor Id lido no fim da fila.
 */
Fila enqueue(Fila filaAntena, int idAntena){ // colcoa no fim da lista
    Fila novo = (Fila)malloc(sizeof(struct registoFila));
    if(novo != NULL){
        novo->idAntena = idAntena;
        novo->seguinte = NULL;
        if(filaAntena == NULL){
            return novo;
        }else{
            Fila temporario = filaAntena;
            while(temporario->seguinte != NULL){
                temporario = temporario->seguinte;
            }
            temporario->seguinte = novo;
            return filaAntena;
        }
    }
    return filaAntena;
}
/**
 * @brief Função para remover o primeiro Id da fila.
 * 
 * Esta função remove o primiero Id da fila , e devolve o seu valor.
 * @param ID Remove o primiero ID da fila.
 
 * 
 * 
 * @return Remove o primiero ID da fila.
 */
Fila dequeue(Fila filaAntena, int* idAntena){
    if(filaAntena == NULL)
    return NULL;
    *idAntena = filaAntena->idAntena;
    Fila temporario = filaAntena;
    filaAntena = filaAntena->seguinte;
    free(temporario);
    return filaAntena;
}


/**
 * @brief Função para Encontrar todos os caminhos possiveis entre dois vertices.
 * 
 * Esta função recebe um ID inicial , e um ID destino , faz a sua travessia em profundidade , com recurso a pilha num sistema LIFO ,e encontra todos os caminhos possiveis entre os dois vertices escolhidos.
 * @param IDs Recebe os IDs da procura.
 * @param caminho Traça um caminho com recurso a pilha.
 * @param nome Antenas do mesmo grafo , nome.

 * 
 * 
 * @return Um caminho em profundidade entre dois Vertices de Antenas da mesmo frequencia.
 */
void profundidade_todos_caminhos(Vertices listaAntena, int idInicial, int idDestino, int visitados[], Pilha caminho){
    visitados[idInicial] = 1;
    caminho = push(caminho, idInicial);
    
    
    if(idInicial == idDestino){
       Pilha inverter = NULL;
       Pilha temporaria = caminho;
       while(temporaria != NULL){
           inverter = push(inverter, temporaria->idAntena);
           temporaria = temporaria->seguinte;
       }   
   
       printf("Caminho encontrado: ");
       while(inverter != NULL){
           printf("%d", inverter->idAntena);
           inverter = pop(inverter);
           if(inverter != NULL){
               printf(" -> ");
           }
       }
       printf("\n");
    
    }else{
       Vertices actual2 = listaAntena;
       while(actual2 != NULL && actual2->idAntena != idInicial){
           actual2 = actual2->seguinte;
       }
       if(actual2 != NULL){
           Adjacentes adjacente = actual2->adjacentes;
           while(adjacente != NULL){
               if(!visitados[adjacente->idAntena]){
                   profundidade_todos_caminhos(listaAntena, adjacente->idAntena, idDestino, visitados, caminho);
               }
               adjacente = adjacente->seguinte;
           }
          
       }
    }
    //bactracking / remove o vertice atual do caminho e marca o visitados como nao visitado = 0
    caminho = pop(caminho);
    visitados[idInicial] = 0;
   }
/**
 * @brief Função para imprimir todos os caminhos possiveis entre dois vertices.
 * 
 * Esta função é complementar a funcção anterior , serve para dar print de todos os caminhos.
 * 
 
 * 
 * 
 * @return Complementar a funcao anterior recursiva , que visa dar print a todos os caminhos entre dois vertices.
 */
void todos_os_caminhos(Vertices listaAntena, int idInicial, int IdDestino){
    int visitados[FICHEIRO] = {0};
    Pilha caminho = NULL;
    printf("Caminhos encontrados entre o ID %d e o ID %d:\n", idInicial, IdDestino);
    profundidade_todos_caminhos(listaAntena, idInicial, IdDestino, visitados, caminho);
}

/**
 * @brief Função que marca os visitados e o caminho possivel de um vertice e seus adjacentes.
 * 
 * Esta função recebe um id inicial de um grafo com o mesmo nome , e traça os seus caminhos visitados , assim como o caminho encontrado , usando a pesquisa em profundidade.
 * @param ID Recebe o id inicial
 * @param visitados Visita em profundidade os vertives e traca os seus caminhos visitados.
 * @param caminho Traça o caminho encontrado.
 * @param cordenadas Marca as suas cordenadas no grafo.
 * @param pilha Usa recurso de uma pilha.
 
 * 
 * 
 * @return Devolve os caminhos visitados e o caminho encontrado de uma pesquisa em profundidade atraves de um vertice inicial.
 */
void pesquisa_caminho_profundidade(Vertices listaAntena, int idInicial){
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
                    
                    Vertices destino = listaAntena;
                    while(destino != NULL && destino->idAntena != adjacente->idAntena){
                        destino = destino->seguinte;
                    }
                    if(destino != NULL){
                        printf("Caminho Visitado: %d [%d, %d] -> %d [%d, %d]\n", idActual, actual->linha, actual->coluna, destino->idAntena, destino->linha, destino->coluna);
                    }
                    
                }
                adjacente = adjacente->seguinte;
            }
        }
    }
    //imprmir ao contrario , assumindo que é uma pilha.
    Pilha inverter = NULL;
    Pilha caminhoTemp = caminho;
    while(caminhoTemp != NULL){
        inverter = push(inverter, caminhoTemp->idAntena);
        caminhoTemp = caminhoTemp->seguinte;
    }

    // Imprimir caminho
    printf("Caminho Encontrado: ");
    while(inverter != NULL){
        Vertices actual = listaAntena;
        while(actual != NULL && actual->idAntena != inverter->idAntena){
            actual = actual->seguinte;
        }
        if(actual != NULL){
            printf(" -> %d ", actual->idAntena);
        }
        inverter = pop(inverter);
    }
    printf("\n");
    
}
/**
 * @brief Função que marca os visitados e o caminho possivel de um vertice e seus adjacentes.
 * 
 * Esta função recebe um id inicial de um grafo com o mesmo nome , e traça os seus caminhos visitados , assim como o caminho encontrado , usando a pesquisa em Largura com recurso a uma fila.
 * @param ID Recebe o id inicial
 * @param visitados Visita em fila os vertives e traca os seus caminhos visitados.
 * @param caminho Traça o caminho encontrado.
 * @param cordenadas Marca as suas cordenadas no grafo.
 * @param fila Usa recurso a uma fila.
 
 * 
 * 
 * @return Devolve os caminhos visitados e o caminho encontrado de uma pesquisa em Largura atraves de um vertice inicial.
 */
void pesquisa_largura(Vertices listaAntena, int idInicial){
    Fila fila = NULL;
    Fila caminho = NULL;
    int visitados[FICHEIRO] = {0};
    

    fila = enqueue(fila, idInicial);
    visitados[idInicial] = 1;

    printf("Caminho em Largura a partir do vertice %d:\n", idInicial);

    while(fila != NULL){
        int idActual = fila->idAntena;
        fila = dequeue(fila, &idActual);
        caminho = enqueue(caminho, idActual);

        
        Vertices actual = listaAntena;
        while(actual != NULL && actual->idAntena != idActual){
            actual = actual->seguinte;
        }
        if(actual != NULL){
            Adjacentes adjacente = actual->adjacentes;
            while(adjacente != NULL){
                if(!visitados[adjacente->idAntena]){
                    fila = enqueue(fila, adjacente->idAntena);
                    visitados[adjacente->idAntena] = 1;
                    Vertices caminho = listaAntena;
                    while(caminho!= NULL && caminho->idAntena != adjacente->idAntena){
                        caminho = caminho->seguinte;
                        
                    }
                    if(caminho !=  NULL){
                        printf("Caminho visitado: %d [%d, %d] -> %d [%d, %d]\n", idActual, actual->linha, actual->coluna, caminho->idAntena, caminho->linha, caminho->coluna);
                    }
                }
                adjacente = adjacente->seguinte;
            }
        }
    }
    printf("\n");
    printf("Caminho encontrado: ");
    while(caminho!= NULL){
        printf(" -> %d ", caminho->idAntena);
        caminho = dequeue(caminho, &idInicial);
    }
    printf("\n");
}
/**
 * @brief Função de verificação de dois vertices.
 * 
 * Esta função serve para complementar uma funcao de ID inicila e ID destino , e serve como verificação de que os dois vertices de procura , os seus IDs fazem parte do mesmo grafo e se sao adjacente.
 * @param ID Recebe o id inicial e o destino
 * @param Adjacentes Verifica se são adjacentes
 
 * 
 * 
 * @return Verifica se os dois IDs de vertices que queremos na pesquisa fazem parter do mesmo grafo de adjacencia.
 */
int verificao(Vertices listaAntena, int idInicial, int idDestino){
    Vertices actual = listaAntena;
    while(actual != NULL && actual->idAntena != idInicial){
        actual = actual->seguinte;
    }
    if(actual != NULL){
        Adjacentes adjacente = actual->adjacentes;
        while(adjacente != NULL){
            if(adjacente->idAntena == idDestino){
                return 1;
            }
            adjacente = adjacente->seguinte;
        }
    }
    return 0;
}
/**
 * @brief Função de verificação de existencia de um vertice
 * 
 * Esta função serve para fazer a verificação da existencia do vertice que queremos usar na lista ligada , em caso de nao existir , da um erro.
 * @param ID Recebe o id inicial de procura
 * 
 
 * 
 * 
 * @return Verifica a existencia do Id que procuramos na lista ligada.
 */
int verificarID(Vertices listaAntena, int idInicial){
Vertices actual = listaAntena;
while(actual != NULL && actual->idAntena != idInicial){
    actual = actual->seguinte;
}
if(actual != NULL){
    Adjacentes adjacente = actual->adjacentes;
    while(adjacente != NULL){
        if(adjacente->idAntena != idInicial){
            return 1;
        }
        adjacente = adjacente->seguinte;
    }
}
return 0;
}






