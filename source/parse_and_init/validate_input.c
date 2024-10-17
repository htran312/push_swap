/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htran-th <htran-th@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:19:47 by htran-th          #+#    #+#             */
/*   Updated: 2024/10/17 21:53:35 by htran-th         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_range(char *str)
{
    long nbr;
    
    nbr = ft_atoi(str);
    if (nbr > MAX_INT || nbr < MIN_INT)
        return (0);
    return (1);
}

static int check_character_and_sign(char *str)
{
    int i;

    i = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        if (str[1] == '+' || str[1] == '-' || str[1] == '\0')
            return (0);
        i++;
    }
    while (str[i] != '\0')
    {
        if (!ft_strchr("0123456789", str[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_valid_integer(char *str)
{
    if (!str || str[0] == '\0')
        return (0);
    if (!check_character_and_sign(str))
        return (0);
    if (!check_range(str))
        return (0);
    return (1);
}