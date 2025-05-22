/**
 * @file grafos.h
 * 
 * Este arquivo contém as declarações das funções e os seus respetivos comentarios.
 */


/**Tamanho de array criado para suportar todas as variaveis do tipo ao longo do codigo. */
#define FICHEIRO 50


/**
 * @struct Adjacentes
 * @brief Estrutura da função.
 * 
 * 
 */
typedef struct antena2{
    int idAntena; 
    struct antena2* seguinte;
    } * Adjacentes;
    
    /**
 * @struct Vertices
 * @brief Estrutura da função.
 * 
 * 
 */
    typedef struct antena1{
     int idAntena; 
     char nome;
     int linha;
     int coluna; 
     Adjacentes adjacentes; 
     struct antena1 * seguinte;  
    } * Vertices;
    
    /**
 * @struct Pilha
 * @brief Estrutura da função para pesquisas de Profundidade.
 * 
 * 
 */
    typedef struct registo{
        int idAntena;
        struct registo* seguinte;
    }* Pilha;
    
    /**
 * @struct Fila
 * @brief Estrutura da função para pesquisas em largura.
 * 
 * 
 */
    typedef struct registoFila{
        int idAntena;
        struct registoFila* seguinte;
    }* Fila;


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
    Vertices novo_vertice(Vertices listaAntena, int idAntena, char nome, int linha, int coluna);


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
    Vertices novo_adjacente(Vertices listaAntena);

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
    Vertices leitura(Vertices listaAntena);

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
    void listagem(Vertices listaAntena);

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
    void listagem_adjacente(Vertices listaAntena);

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
    void listagem_adjacente_filtro(Vertices listaAntena, char nomeVertice);
/**
 * @brief Função para inserir um novo valor no topo da pilha
 * 
 * Esta função cria um no com o valor que le no topo da pilha.
 * @param ID Guarda o valor do Id na pilha.
 
 * 
 * 
 * @return Um valor no topo da pilha.
 */
    Pilha push(Pilha pilhaAntena, int idAntena);
/**
 * @brief Função para remover um valor do topo da pilha.
 * 
 * Esta função remove o elemento ID do topo da pilha.
 * @param ID Remove o valor do Id na pilha e retorna um novo topo da pilha.
 
 * 
 * 
 * @return Remove um valor no topo da pilha.
 */
    Pilha pop(Pilha pilhaAntena);
 /**
 * @brief Função para inserir um novo valor id no fim da fila.
 * 
 * Esta função adiciona um novo elemento no fim da fila.
 * @param ID Adiciona o ID no fim da fila.
 
 * 
 * 
 * @return Adiciona o valor Id lido no fim da fila.
 */
    Fila enqueue(Fila filaAntena, int idAntena);
/**
 * @brief Função para remover o primeiro Id da fila.
 * 
 * Esta função remove o primiero Id da fila , e devolve o seu valor.
 * @param ID Remove o primiero ID da fila.
 
 * 
 * 
 * @return Remove o primiero ID da fila.
 */
    Fila dequeue(Fila filaAntena, int* idAntena);
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
    void profundidade_todos_caminhos(Vertices listaAntena, int idInicial, int idDestino, int visitados[], Pilha caminho);
/**
 * @brief Função para imprimir todos os caminhos possiveis entre dois vertices.
 * 
 * Esta função é complementar a funcção anterior , serve para dar print de todos os caminhos.
 * 
 
 * 
 * 
 * @return Complementar a funcao anterior recursiva , que visa dar print a todos os caminhos entre dois vertices.
 */
    void todos_os_caminhos(Vertices listaAntena, int idInicial, int IdDestino);
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
    void pesquisa_caminho_profundidade(Vertices listaAntena, int idInicial);
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
    void pesquisa_largura(Vertices listaAntena, int idInicial);
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
    int verificao(Vertices listaAntena, int idInicial, int idDestino);
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
    int verificarID(Vertices listaAntena, int idInicial);

    