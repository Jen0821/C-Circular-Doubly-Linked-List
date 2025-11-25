#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

list *newList (payload e) {
    list *xs = malloc(sizeof(list));
    if (xs == NULL) {
        exit(1);
    }

    node *sentinel = malloc(sizeof(node));
    if (sentinel == NULL) {
        free(xs);
        exit(1);
    }

    sentinel->x = e;
    sentinel->back = sentinel;
    sentinel->next = sentinel;

    xs->none = sentinel;
    xs->current = sentinel;

    return xs;
}

void freeList(list *xs) {
    if (xs == NULL) return;

    node *current = xs->none->next;

    while (current != xs->none) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    free(xs->none);
    free(xs);
}

void first (list *xs) {
    xs->current = xs->none->next;
}

void last (list *xs) {
    xs->current = xs->none->back;
}

bool none (list *xs) {
    return xs->current == xs->none;
}

bool after(list *xs) {
    if (xs->current == xs->none) return false;
    xs->current = xs->current->next;
    return xs->current != xs->none;
}

bool before(list *xs) {
    if (xs->current == xs->none) return false;
    xs->current = xs->current->back;
    return xs->current != xs->none;
}

void insertAfter(list *xs, payload x) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) exit(1);
    new_node->x = x;

    new_node->next = xs->current->next;
    new_node->back = xs->current;

    xs->current->next->back = new_node;
    xs->current->next = new_node;

    xs->current = new_node;
}

void insertBefore(list *xs, payload x) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) exit(1);
    new_node->x = x;

    new_node->back = xs->current->back;
    new_node->next = xs->current;

    xs->current->back->next = new_node;
    xs->current->back = new_node;

    xs->current = new_node;
}

bool deleteToAfter(list *xs) {
    if (xs->current == xs->none) return false;

    node *to_delete = xs->current;

    xs->current->back->next = xs->current->next;
    xs->current->next->back = xs->current->back;

    xs->current = xs->current->next;

    free(to_delete);

    return true;
}

bool deleteToBefore(list *xs) {
    if (xs->current == xs->none) return false;

    node *to_delete = xs->current;

    xs->current->back->next = xs->current->next;
    xs->current->next->back = xs->current->back;

    xs->current = xs->current->back;

    free(to_delete);

    return true;
}
