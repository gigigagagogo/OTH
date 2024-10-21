#ifndef _GRAMMAR_H
#define _GRAMMAR_H

typedef struct grammar {
        char *lhs;
        char *rhs;
} rules;

typedef struct nodeg {
        node_g *prev;
        rules rule;
        node_g *next; 
} node_g;



int generate_rules(node_g **head, node_g **tail);
int enqueue_grammar(node_g **head, node_g **tail, rules rule);

#endif /* _GRAMMAR_H */
