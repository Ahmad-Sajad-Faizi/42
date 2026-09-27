t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*new_elem;
	int		i;

	list = NULL;
	i = 0;
	while (i < size)
	{
		new_elem = ft_create_elem(strs[i]);
		if (!new_elem)
			return (list);
		new_elem->next = list;
		list = new_elem;
		i++;
	}
	return (list);
}
