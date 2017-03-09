//
// main.cpp for 202unsold in /home/scutar_n/rendu/maths
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 17:24:40 2017 Nathan Scutari
// Last update Thu Mar  9 13:54:11 2017 Nathan Scutari
//

#include <iostream>

void	calc(const int, const int);

int	write_help(void)
{
  std::cout << "USAGE" << std::endl << "\t\t./202unsold a b" << std::endl;
  std::cout << "DESCRIPION" << std::endl;
  std::cout << "\t\ta\tconstant computed from the past results" << std::endl;
  std::cout << "\t\tb\tconstant computed from the past results" << std::endl;
  return (0);
}

int	write_err(std::string error)
{
  std::cerr << error << std::endl;
  return (84);
}

int	getnbr(std::string arg, int arg_nbr)
{
  int	i;
  int	nbr;

  i = -1;
  while (arg[++i])
    if (arg[i] < '0' || arg[i] > '9')
      {
	std::cerr << "Error in arg: " << arg_nbr << " positive integer greater than 50 expected" << std::endl;
	return (-1);
      }
  nbr = std::stoi(arg);
  if (nbr <= 50)
    {
      std::cerr << "Error in arg: " << arg_nbr << " expected integer greater than 50" << std::endl;
      return (-1);
    }
  return (nbr);
}

int	main(int ac, char **av)
{
  std::string	arg;
  int		nbr1;
  int		nbr2;

  if (ac == 2)
    {
      arg = av[1];
      if (arg == "-h")
	return (write_help());
      return (write_err("Invalid number of arguments, use \'./202unsold -h\' for help"));
    }
  else if (ac == 3)
    {
      if ((nbr1 = getnbr(av[1], 1)) == -1 ||
	  (nbr2 = getnbr(av[2], 2)) == -1)
	return (84);
      calc(nbr1, nbr2);
      return (0);
    }
  return (write_err("Invalid number of arguments, use \'./202unsold -h\' for help"));
}
