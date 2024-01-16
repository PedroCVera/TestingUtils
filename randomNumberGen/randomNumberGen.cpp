/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomNumberGen.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoimbra <pcoimbra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:08:24 by pcoimbra          #+#    #+#             */
/*   Updated: 2024/01/16 13:44:49 by pcoimbra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <random>

#define MAXNUMBER INT32_MAX

long	CheckRepeat(std::vector<long> &vec)
{
	std::vector<long>::iterator ite = vec.begin();
	std::vector<long>::iterator it;

	srand (time(NULL));
	for (; ite != vec.end(); ite++)
	{
		it = vec.begin();
		while (it != ite)
			it++;
		it++;
		for (; it != vec.end(); it++)
			if (*it == *ite)
			{
				*it += 1;
				return 0;
			}
	}
	return 1;
}

std::vector<long>	N_gen(long N)
{
	long	n = N;
	std::vector<long>	vec;

	srand (time(NULL));
	for(; n > 0; n--)
		vec.push_back((rand() % (INT32_MAX - 1)));
	while (CheckRepeat(vec) == 0)
		CheckRepeat(vec);
	return vec;
}

long	ft_stoi(char *str)
{
	long ret = 0;
	long j = 0;

	for (long i = 0; str[i] != '\0'; i++)
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

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	N = ft_stoi (av[1]);
		if (N > MAXNUMBER)
			std::cout << "Number too high, change it manually in macro if you want the max to be bigger" << std::endl;
		std::vector<long> vec;
		vec = N_gen(N);
		std::vector<long>::iterator ite = vec.begin();
	
		for (; ite != vec.end(); ite++)
			std::cout << *ite << " ";
		std::cout << std::endl;
	}
	else
		std::cout << "Only input is number of numbers to generate." << std::endl;	
}