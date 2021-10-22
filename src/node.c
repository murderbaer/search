#include "node.h"

void append(node * list, node * node) {
    if (list == 0) {
        list = node;
    } else {
        node->children = list->children;
        list->children = node;
    }
}