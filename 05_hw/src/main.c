#include "stack.h"

#include <stdio.h>

int main()
{
    Stack stack;
    initStack(&stack);

    const int first = 10;
    const int second = 20;
    const int third = 30;
    push(&stack, first);
    push(&stack, second);
    push(&stack, third);

    printf("After pushing elements:\n");
    traverseStack(&stack);

    pop(&stack);

    printf("After popping an element:\n");
    traverseStack(&stack);

    Node *searchResult = searchByValue(&stack, second);
    if (searchResult != NULL)
    {
        printf("Element with value 20 found.\n");
    }
    else
    {
        printf("Element with value 20 not found.\n");
    }

    Node *topElement = getTop(&stack);
    if (topElement != NULL)
    {
        printf("Top element: %d\n", topElement->data);
    }

    return 0;
}
