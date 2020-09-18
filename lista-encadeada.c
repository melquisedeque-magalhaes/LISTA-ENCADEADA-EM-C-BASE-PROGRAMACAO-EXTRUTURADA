#include <stdio.h>
#include <stdlib.h>

/***  STRUCTS ***/

struct typeProduct {
    int cod;
    char descrition[30];
};

struct tNo {
    struct typeProduct data;
    struct tNo *next;
};

/***  PROTOTIPOS DE FUNÇÕES   ***/

int menu(void);
void incluir(struct tNo **, struct tNo *);
void listagem(struct tNo *);

/***  PRINCIPAL   ***/

void main(void){
    struct tNo *list = NULL, *p;

    int opcao, codigo;

    do{
        opcao = menu();

        switch (opcao)
        {
            case 1: 
                printf("\n\n*** INCLUSÃO ***\n\n");

                p = malloc(sizeof(struct tNo));

                printf("Digite o codigo: ");
                scanf("%d", &(p->data.cod));

                printf("Digite a descrição: ");
                fflush(stdin);
                gets(p->data.descrition);

                incluir(&list, p); // Incluir Produto na Lista

                break;

            case 2:

                printf("\n\n *** CONSULTAR *** \n\n");

                printf("Digite o Codigo: ");
                scanf("%d", &codigo);
                break;

            case 3:

                printf("\n\n ***    LISTAGEM ***    \n\n");

                listagem(list); //  LISTA TODOS OS PRODUTOS NA LISTA

                break;
            default:
                break;
        }
    }while(opcao != 0);
    
}


/***    MENU PRINCIPAL  ***/

int menu(void){

    int opc;

    printf("\n\n *** MENU ***\n\n");
    printf("1 -> INCLUSÃO\n");
    printf("2 -> CONSULTA\n");
    printf("3 -> LISTAGEM\n");
    printf("4 -> ALTERAÇÃO\n");
    printf("5 -> EXCLUIR\n");
    printf("0 -> SAIR\n");

    printf("Escolha sua opção: ");
    scanf("%d", &opc);

    return opc;
}

void incluir(struct tNo **lst, struct tNo *novo)  {

    struct tNo *p = (*lst), *q;

    if((*lst) == NULL){ // LISTA VAZIA

        novo->next = NULL;
        (*lst) = novo;

    }else{  //INICIO, FIM, MEIO
        if(novo ->data.cod < (*lst)->data.cod){     //  INICIO

            novo->next = (*lst);
            (*lst) = novo;

        }else{  //FIM, MEIO
            
            while(p->next != NULL)  // PECORRE A LISTA TODA ATE O FINAL
                p = p -> next;
                
            if(novo->data.cod > p->data.cod){   // FIM
            
                p->next = novo;
                novo->next = NULL;

            }else { // MEIO

                p = (*lst);

                while(p->data.cod < novo->data.cod){ 
                    q = p; // PECORRE A LISTA TODA ATE O FINAL
                    p = p -> next;
                }
                q -> next = novo;
                novo -> next = p;
            }
        }

    }
}

void listagem(struct tNo *lst){

    struct tNo *p = lst;

    while(p != NULL){   // PECORRE A LISTA TODA ATE O FINAL

        printf("%d -> %s \n", p -> data.cod, p -> data.descrition);
        p = p -> next;
        
    }

}