#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int content;
    struct Node *left;
    struct Node *right;
} node;

typedef struct {
    node *source;
} ref;

void start(ref *tree){
    tree->source = NULL;
}

node* insert(node *source, int value){
    if(source == NULL){
        node *New = (node *)malloc(sizeof(node));

        New->content = value;
        New->left = NULL;
        New->right = NULL;
        return New;
    } else {
        if(value < source->content){
            source->left = insert(source->left, value);
        } 
        if(value > source->content){
            source->right = insert(source->right, value);
        }
        return source;
    }
}

int length(node *source){
    if(source == NULL){
        return 0;
    } else {
        return 1 + length(source->left) + length(source->right);
    }
}

int search(node *source, int searched){
    if(source == NULL){
        return 0;
    } else {
        if(searched == source->content){
            return 1;
        } else {
            if(searched < source->content){
                return search(source->left, searched);
            }
            if(searched > source->content){
                return search(source->right, searched);
            }
        }
    }
}

void print(node *source){
    if(source != NULL){
        print(source->left);
        printf("%d ", source->content);
        print(source->right);
    }
}

node* remove(node *source, int toremove){
    if(source == NULL){
        printf("Invalid element!\n");
        return NULL;
    } else {
        if(source->content == toremove){
            if(source->left == NULL && source->right == NULL){
                free(source);
                return NULL;
            }
        } else {
            if(toremove < source->content){
                source->left = remove(source->left, toremove);
            } else {
                source->right = remove(source->right, toremove);
            }
            return source;
        }
    }
}

void menu(){
    printf("\n");
    printf("+----------MENU----------+\n");
    printf("| 1 - Insert Value       |\n");
    printf("| 2 - Print Tree         |\n");
    printf("| 3 - Search             |\n");
    printf("| 4 - Remove             |\n");
    printf("| 0 - Exit               |\n");
    printf("+------------------------+\n");
    printf("Select an option: ");
}

int main(){
    int op, num, value, rem;
    ref tree;
    node *source = NULL;

    start(&tree);

    do{
        menu();
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Number to add: ");
                scanf("%d", &num);
                source = insert(source, num);
                printf("\n");
                break;
            case 2:
                print(source);
                printf("\n");
                printf("Length: %d", length(source));
                break;
            case 3: 
                printf("Value you want to search: ");
                scanf("%d", &value);

                printf("Result: %d\n", search(source, value));
                break;
            case 4:
                printf("Element to remove: ");
                scanf("%d", &rem);

                source = remove(source, rem);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option!\n");
                break;
        }
    } while(op != 0);

    return 0;
}