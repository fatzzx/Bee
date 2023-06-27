#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.hpp"


typedef deck tp_item;

typedef struct tp_no {
    struct tp_no* esq;
    tp_item info;
    struct tp_no* dir;
} tp_no;

typedef tp_no* tp_arvore;

tp_arvore inicializa_arvore() {
    return NULL;
}

int arvore_vazia(tp_arvore raiz) {
    return raiz == NULL;
}

tp_no* aloca_no() {
    tp_no* no = (tp_no*)malloc(sizeof(tp_no));
    return no;
}

int insere_no(tp_arvore* raiz, tp_item e) {
    tp_no* pai = NULL;
    tp_no* novo;
    tp_no* p = *raiz;

    novo = aloca_no();
    if (!novo) {
        return 0;
    }

    novo->info = e;
    novo->esq = NULL;
    novo->dir = NULL;

    while (p != NULL) {
        pai = p;
        if (e.number < p->info.number) {
            p = p->esq;
        }
        else {
            p = p->dir;
        }
    }

    if (pai != NULL) {
        if (e.number < pai->info.number) {
            pai->esq = novo;
        }
        else {
            pai->dir = novo;
        }
    }
    else {
        *raiz = novo;
    }

    return 1;
}

void pre_ordem(tp_no* p) {
    if (p != NULL) {
        printf("%d ", p->info.number);
        pre_ordem(p->esq);
        pre_ordem(p->dir);
    }
}

void em_ordem(tp_no* p) {
    if (p != NULL) {
        em_ordem(p->esq);
        printf("%d ", p->info.number);
        em_ordem(p->dir);
    }
}

void pos_ordem(tp_no* p) {
    if (p != NULL) {
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        printf("%d ", p->info.number);
    }
}

tp_no* busca_no(tp_no* p, tp_item e) {
    while (p != NULL) {
        if (e.number < p->info.number) {
            p = p->esq;
        }
        else if (e.number > p->info.number) {
            p = p->dir;
        }
        else {
            return p;
        }
    }

    return NULL;
}

tp_arvore busca_no_rec(tp_arvore p, tp_item e) {
    if (p != NULL) {
        if (e.number < p->info.number) {
            return busca_no_rec(p->esq, e);
        }
        else if (e.number > p->info.number) {
            return busca_no_rec(p->dir, e);
        }
        else if (e.color < p->info.color) {
            return busca_no_rec(p->esq, e);
        }
        else if (e.color > p->info.color) {
            return busca_no_rec(p->dir, e);
        }
        else {
            return p;
        }
    }
    else {
        return NULL;
    }
}

int altura_arvore(tp_arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alt_esq = altura_arvore(raiz->esq);
    int alt_dir = altura_arvore(raiz->dir);

    return (alt_esq > alt_dir) ? alt_esq + 1 : alt_dir + 1;
}

int qtde_nos(tp_arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int tot_esq = qtde_nos(raiz->esq);
    int tot_dir = qtde_nos(raiz->dir);

    return (tot_esq + tot_dir + 1);
}

int remove_no(tp_arvore* raiz, tp_item e) {
    tp_no* p = *raiz;
    tp_no* ant = NULL;
    tp_no* sub;
    tp_no* pai;
    tp_no* filho;

    while (p != NULL && p->info.number != e.number) {
        ant = p;
        if (e.number < p->info.number) {
            p = p->esq;
        }
        else {
            p = p->dir;
        }
    }

    if (p == NULL) {
        return 0;
    }

    if (p->esq == NULL) {
        sub = p->dir;
    }
    else if (p->dir == NULL) {
        sub = p->esq;
    }
    else {
        pai = p;
        sub = p->dir;
        filho = sub->esq;

        while (filho != NULL) {
            pai = sub;
            sub = filho;
            filho = sub->esq;
        }

        if (pai != p) {
            pai->esq = sub->dir;
            sub->dir = p->dir;
        }

        sub->esq = p->esq;
    }

    if (ant == NULL) {
        *raiz = sub;
    }
    else if (p == ant->esq) {
        ant->esq = sub;
    }
    else {
        ant->dir = sub;
    }

    free(p);
    return 1;
}

void destroi_no(tp_no* no) {
    if (no == NULL) {
        return;
    }

    destroi_no(no->esq);
    destroi_no(no->dir);
    free(no);
    no = NULL;
}

void destroi_arvore(tp_arvore* raiz) {
    if (*raiz == NULL) {
        return;
    }

    destroi_no(*raiz);
    free(*raiz);
    *raiz = NULL;
}

#endif