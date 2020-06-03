#include "functions.h"
int btree:: depthcurrent(node* current)
{
if (current->parent == NULL)
    {
        return 0;
    }
    else {
        return (1+depthcurrent(current->parent));
    }
}