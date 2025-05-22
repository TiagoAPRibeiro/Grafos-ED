#include <stdio.h>
#include "grafos.h"

int main(){
    Vertices grafo = NULL;
    char nomeVertice;
    int opcao, subopcao, idInicio, idDestino;
    do{
    printf("1-leitura\n2-listagem\n3-Pesquisa\n4-Sair\n");
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
            scanf(" %c", &nomeVertice); 
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
        do{
            
            printf("1-Pesquisa com Id Origem e Destino\n2-Pesquisa de Caminho em Profundidade\n3-Pesquisa de caminho em Largura\n4-Voltar atras\n");
            scanf("%d", &subopcao);
    
        switch(subopcao){
            case 1:
            printf("Qual o ID do vertice de origem ?\n");
            scanf("%d", &idInicio);
            printf("Qual o ID do vertice destino ?\n");
            scanf("%d", &idDestino);
            if(verificao(grafo, idInicio, idDestino)){
            todos_os_caminhos(grafo, idInicio, idDestino);
            }
            else{
                printf("As antenas não estão ligadas entre si, verifique melhor os seus adjacentes!\n");
            }
            break;
    
            case 2:
            printf("Qual o ID do vertice que pretende iniciar o caminho em Profundidade?\n");
            scanf("%d", &idInicio);
            if(verificarID(grafo, idInicio)){
            pesquisa_caminho_profundidade(grafo, idInicio);
            }
            else{
                printf("O ID não existe, tente um ID que faça parte do Grafo!\n");
            }
            break;
    
            case 3:
            printf("Qual o ID do vertice que pretende iniciar o caminho em Largura ?\n");
            scanf("%d", &idInicio);
            if(verificarID(grafo, idInicio)){
                pesquisa_largura(grafo, idInicio);
                }
                else{
                    printf("O ID não existe, tente um ID que faça parte do Grafo!\n");
                }
            
            break;
    
            case 4:
            printf("Voltar atras\n");
            break;
    
            default:
            printf("Opção invalida!\n");
            break;
        }
        }while(subopcao != 4);
        break;
    
        case 4:
        printf("Sair\n");
        break;
    
        default:
        printf("Opcao invalida\n");
        break;
        }
        }while(opcao != 4);
    
    
    
    
    
        return 0;
    }
    
    
    