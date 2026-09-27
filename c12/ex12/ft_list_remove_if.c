void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		if (free_fct)
			(*free_fct)(tmp->data);
		free(tmp);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if ((*cmp)(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			if (free_fct)
				(*free_fct)(tmp->data);
			free(tmp);
		}
		else
			curr = curr->next;
	}
}
