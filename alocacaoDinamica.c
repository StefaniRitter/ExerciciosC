#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto { 
        char nome[30]; 
        int codigo;
        double preco;
    };
    
typedef struct node { 
struct Produto produto; 
struct node* next; 
} Node; 
    
Node* criaProduto(char *nome, int codigo, double preco){
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL){
        strcpy(novo->produto.nome, nome);
        novo->produto.codigo = codigo;
        novo->produto.preco = preco;
        novo->next = NULL;
    }
    
    return novo;
}

void adicionaProduto(Node **lista, char *nome, int codigo, double preco){
    Node *novo = criaProduto(nome, codigo, preco);
    if(*lista == NULL) {
        *lista = novo;
    } else{
        Node *atual = *lista;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novo;
    }
}

void imprimeProduto(const struct Produto *produto){
    printf("\nCódigo: %d\n", produto->codigo);
    printf("Produto: %s\n", produto->nome);
    printf("Preço: %.2f\n", produto->preco);
    printf("\n--------------------------------\n");
}

void buscarPorNome(Node *lista, char *nome){
    int encontrado = 0;
    while (lista != NULL) {
        if (strcmp(lista->produto.nome, nome) == 0){
            imprimeProduto(&lista->produto);
            encontrado = 1;
        }
        lista = lista->next;
    }
    if (!encontrado) {
        printf("\nProduto não encontrado!\n");
    }
}

void exibirLista(Node *lista) {
    if (lista == NULL) {
        printf("\nLista de produtos vazia!\n");
        return;
    }
    
    printf("\n------Produtos Cadastrados------\n");
    while (lista != NULL) {
        imprimeProduto(&lista->produto);
        lista = lista->next;
    }
}

int main()
{
    Node *lista = NULL;
    int opcao;
    
        printf("\n---------- Compras++ -----------\n");
    
    do {
        printf("\n------------- MENU -------------\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Buscar por nome\n");
        printf("3 - Exibir lista de produtos\n");
        printf("4 - Sair\n");
        printf("Informe o número referente à opção escolhida: ");
        scanf("%d", &opcao);
        getchar(); // usado para limpar o buffer do teclado
        printf("\n--------------------------------\n");
        
        if (opcao == 1) {
            char nome[30];
            int codigo;
            double preco;

            printf("\nInforme o nome do produto: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0; // remover o '\n' do final
            printf("Informe o código: ");
            scanf("%d", &codigo);
            printf("Informe o preço: ");
            scanf("%lf", &preco);
            getchar();
            adicionaProduto(&lista, nome, codigo, preco);
            printf("\nProduto cadastrado com sucesso!\n");
            
        } else if (opcao == 2){
            char nome[30];
            printf("\nInforme o nome do produto que deseja buscar: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;
            buscarPorNome(lista, nome);
            
        } else if (opcao == 3){
            exibirLista(lista);
        
        } else if (opcao == 4) {
            printf("\nPrograma encerrado!\n");
        } else {
            printf("\nOpção inválida!\n");
        }
        
        
    } while (opcao != 4);
    
    Node *atual = lista;
    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->next;
        free(temp);
    }

    return 0;
}