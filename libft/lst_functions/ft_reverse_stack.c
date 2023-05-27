/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:41:28 by lcompieg          #+#    #+#             */
/*   Updated: 2022/12/06 16:41:36 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*reverse_stack(t_stack *current)
{
	t_stack	*previous;
	t_stack	*next;

	if (!current)
		return (NULL);
	previous = NULL;
	next = (current)->next;
	while ((current)->next != NULL)
	{
		(current)->next = previous;
		previous = current;
		(current) = next;
		next = next->next;
	}
	current->next = previous;
	return (current);
}
