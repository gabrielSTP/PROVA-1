#include<stdio.h>
#include<stdlib.h>

typedef int dado;

struct Node {

    dado valor;
    Node* prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct List {

    Node* cabeca, * cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista está vazia ou não
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node* novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node* novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        }
        else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n) //função inutil! uso de size++--
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node* tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else {
                Node* tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else {
                Node* penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x) { //O(n)
        Node* tmp = cabeca;
        while (tmp != NULL) {
            if (tmp->valor == x) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }

    void removeN(int n) {
        for (int i = 0; i < n && size > 0; i++) {
            popBack();
        }
    }

    void removeSegundo() {
        if (size == 2) {
            popBack();
        }
        else if (size > 2) {
            Node* segundo = cabeca->prox;
            Node* terceiro = segundo->prox;
            cabeca->prox = terceiro;
            delete(segundo);
            size--;
        }
    }

    void inserirTamanho() {
        pushBack(size);
    }

    void inserirN(int n) {
        for (int i = 1; i <= n; i++) {
            pushBack(i);
        }
    }

    void inserirPenultimo(dado valor) {
        if (size >= 2) {
            Node* penultimo = cabeca;
            while (penultimo->prox != cauda) {
                penultimo = penultimo->prox;
            }
            Node* novo = new Node(valor);
            penultimo->prox = novo;
            novo->prox = cauda;
            size++;
        }
    }

    void removePosicaoN(int n) {
        if (n <= size) {
            if (n == 1) {
                popFront();
            }
            else if (n == size) {
                popBack();
            }
            else {
                Node* anterior = NULL;
                Node* excluir = cabeca;
                for (int i = 0; i < n - 1; i++) {
                    anterior = excluir;
                    excluir = excluir->prox;
                }
                Node* posterior = excluir->prox;
                anterior->prox = posterior;
                delete(excluir);
                size--;
            }
        }
    }

    void sizeN(dado valor) { //QUESTÃO NUMERO 1
        if (size > valor) {
            while (size != valor) {
                popBack();
            }
        }
        else if (size < valor) {
            while (size != valor) {
                pushFront(0);
            }
        }

    }

    void removeMenor(dado valor) { //QUESTÃO NUMERO 2 (NÃO FUNCIONA!)
        //Node* valor = new Node(valor);
        Node* tmp = cabeca;
        while (tmp->prox != NULL) {
            Node* anterior = tmp;
            if (tmp->valor < valor) {
                
            }
        }
    }

    void insertDist(dado x) { //QUESTÃO NUMERO 4
        int cont = 1;
        while (cont != x+1) {
            Node* retorno = find(cont);
            if(retorno == NULL){
                pushBack(cont);
                
            }
            cont++;
        }
        
    }

    Node* repeatList() { //QUESTÃO NUMERO 3
        Node* tmp = cabeca;
        int a = size;
        
        for (int i = 1; i <= a; i++) {
            pushBack(tmp->valor);
            tmp = tmp->prox; 
        }
            return cauda;
    }
};

int main() {
    List l;
    l.pushFront(5);
    l.pushFront(4);
    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);
    //l.removeN(2);
    //l.sizeN(6);
    l.insertDist(20);
    //l.removeMenor(13);
    //l.repeatList();
    l.print();
    printf("Tamanho da lista: %d\n", l.size);
    return 0;
}