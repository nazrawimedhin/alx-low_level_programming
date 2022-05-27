#include "hash_tables.h"
#include <stdlib.h>
/**
 * hash_table_delete - deletes hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp, *next;
	unsigned long int i;

	if (ht != NULL)
	{
		if (ht->array != NULL)
		{
			for (i = 0; i < ht->size; i++)
			{
				temp = ht->array[i];
				while (temp != NULL)
				{
					next = temp->next;
					free(temp->value);
					free(temp);
					temp = next;
				}
			}
			free(ht->array);
		}
		free(ht);
	}
}