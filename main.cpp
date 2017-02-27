//
// main.cpp for 202unsold in /home/scutar_n/rendu/maths
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Feb 27 17:24:40 2017 Nathan Scutari
// Last update Mon Feb 27 17:46:21 2017 Nathan Scutari
//

#include <iostream>

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

  i = -1;
  while (arg[++i])
    if (arg[i] < '0' || arg[i] > '9')
      {
	std::cerr << "Error in arg:" << arg_nbr << "positive integer expected" << std::endl;
	return (-1);
      }
  return (std::stoi(arg));
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
      if ((nbr1 = getnbr(av[1], 1) == -1) ||
	  (nbr2 = getnbr(av[2], 2)) == -1)
	return (84);
      calc(nbr1, nbr2);
      return (0);
    }
  return (write_err("Invalid number of arguments, use \'./202unsold -h\' for help"));
}
