/*
** EPITECH PROJECT, 2020
** my_apply_on_matching_nodes
** File description:
** Applies a function to the data of the node on the list equal to data_ref
*/

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
    void const *data_ref, int (*cmp)())
{
    linked_list_t *block = *begin;

    while (block->next != NULL) {
        if ((*cmp)(block->data, data_ref) == 0)
            (*f)(block->data);
        block = block->next;
    }
    return (0);
}