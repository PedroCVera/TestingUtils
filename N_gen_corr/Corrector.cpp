/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Corrector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:46:02 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/16 13:02:39 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

int	CheckRepeat(std::vector<int> &vec)
{
	std::vector<int>::iterator ite = vec.begin();
	std::vector<int>::iterator it;

	for (; ite != vec.end(); ite++)
	{
		it = vec.begin();
		while (it != ite)
			it++;
		it++;
		for (; it != vec.end(); it++)
			if (*it == *ite)
			{
				std::cout << "issue with: " << *it << std::endl;
				*it *= 2;
				std::cout << "fixed: " << *it << std::endl;
				return 0;
			}
	}
	return 1;
}

int	ft_stoi(char *str)
{
	int ret = 0;
	int j = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '+' && i == 0)
			j++;
		else if (str[i] > '9' || str[i] < '0')
			return -1;
	}
	while (str[j] != '\0')
	{
		ret = ret * 10 + (str[j] - '0');
		j++;
	}
	return ret;
}

std::vector<int> Parser(char **av, int ac)
{
	std::vector<int> ret;

	for (int i = 1; i < ac; i++)
		ret.push_back(ft_stoi(av[i]));
	return ret;
}

int main(int ac, char **av)
{
	std::vector<int> corrector;

	corrector = Parser(av, ac);
	while (CheckRepeat(corrector) == 0)
		CheckRepeat(corrector);
	if (CheckRepeat(corrector) == 1)
		std::cout << "nice" << std::endl;
	std::cout << "corrigiu" << std::endl;
	std::cout << "\n\n" << std::endl;
	
	std::vector<int>::iterator ite = corrector.begin();
	
	for (; ite != corrector.end(); ite++)
		std::cout << *ite << " ";
	
	std::cout << std::endl;
	
	return 1;
}
