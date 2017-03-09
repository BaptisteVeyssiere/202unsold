//
// calc.cpp for 202 in /home/veyssi_b/rendu/tek2/Math/202unsold
//
// Made by Baptiste Veyssiere
// Login   <veyssi_b@epitech.net>
//
// Started on  Mon Feb 27 17:25:55 2017 Baptiste Veyssiere
// Last update Thu Mar  9 12:56:38 2017 Baptiste Veyssiere
//

#include <vector>
#include <iostream>
#include <iomanip>

double	getEsp(double tab[5], int lim)
{
  double	sum;
  int		start;
  int		x;

  sum = 0;
  if (lim == 50)
    start = 10;
  else
    start = 20;
  x = -1;
  for (int i = start; i <= lim; i += 10)
    sum += (tab[++x] * (double)i);
  return (sum);
}

double	getVar(double tab[5], int lim)
{
  double	sum;
  int		start;
  int		x;
  double	e;

  sum = 0;
  if (lim == 50)
    start = 10;
  else
    start = 20;
  x = -1;
  for (int i = start; i <= lim; i += 10)
    sum += (tab[++x] * (double)((double)i * (double)i));
  e = getEsp(tab, lim);
  sum -= (e * e);
  return (sum);
}

double	get_sum(double tab[5][5], int j, int c)
{
  double	sum;

  sum = 0.0;
  if (c == 'x')
    for (int i = 0; i < 5; i++)
      sum += tab[i][j];
  else if (c == 'y')
    for (int i = 0; i < 5; i++)
      sum += tab[j][i];
  return (sum);
}

void	calc(const int a, const int b)
{
  double				tab[5][5];
  double				Xlaw[5];
  double				Ylaw[5];
  double				p[9];
  int					y;

  std::cout << "----------------------------------------" << std::endl;
  for (int i = 0; i <= 60; i += 10)
    {
      for (int j = 0; j <= 60; j += 10)
	{
	  if (i == 0 && j == 0)
	    std::cout << "      ";
	  else if (i == 0 && j != 60)
	    std::cout << "X=" << j << "  ";
	  else if (i == 0)
	    std::cout << "Y law" << std::endl;
	  else if (j == 0 && i != 60)
	    std::cout << "Y=" << i << "  ";
	  else if (j == 0)
	    std::cout << "X law ";
	  else if (j != 60 && i != 60)
	    {
	      tab[i / 10 - 1][j / 10 - 1] = ((a - (double)j) * (b - (double)i)) / ((5 * a - 150) * (5 * b - 150));
	      std::cout << std::fixed << std::setprecision(3) << tab[i / 10 - 1][j / 10 - 1] << " ";
	    }
	  else if (j == 60 && i != 60)
	    {
	      Ylaw[i / 10 - 1] = get_sum(tab, i / 10 - 1, 'y');
	      std::cout << std::fixed << std::setprecision(3) << Ylaw[i / 10 - 1] << std::endl;
	    }
	  else if (i == 60 && j != 60)
	    {
	      Xlaw[j / 10 - 1] = get_sum(tab, j / 10 - 1, 'x');
	      std::cout << std::fixed << std::setprecision(3) << Xlaw[j / 10 - 1] << " ";
	    }
	  else if (i == 60 && j == 60)
	    std::cout << "1" << std::endl;
	}
    }
  std::cout << "----------------------------------------" << std::endl;
  for (int i = 10; i <= 110; i += 10)
    {
      if (i == 10)
	std::cout << "z      ";
      else if (i == 110)
	std::cout << "total" << std::endl;
      else if (i == 100)
	std::cout << i << "   ";
      else
	std::cout << i << "    ";
    }
  std::cout << "p(Z=z) ";
  for (int i = 20; i <= 100; i += 10)
    {
      p[i / 10 - 2] = 0;
      for (int j = 10; j < i && j <= 50; j += 10)
	{
	  y = i - j;
	  p[i / 10 - 2] += tab[y / 10 - 1][j / 10 - 1];
	}
      std::cout << p[i / 10 - 2] << " ";
    }
  std::cout << "1" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "expected value of X:\t" << std::fixed << std::setprecision(1) << getEsp(Xlaw, 50) << std::endl;
  std::cout << "variance of X:\t\t" << std::fixed << std::setprecision(1) << getVar(Xlaw, 50) << std::endl;
  std::cout << "expected value of Y:\t" << std::fixed << std::setprecision(1) << getEsp(Ylaw, 50) << std::endl;
    std::cout << "variance of Y:\t\t" << std::fixed << std::setprecision(1) << getVar(Ylaw, 50) << std::endl;
  std::cout << "expected value of Z:\t" << std::fixed << std::setprecision(1) << getEsp(p, 100) << std::endl;
    std::cout << "variance of Z:\t\t" << std::fixed << std::setprecision(1) << getVar(p, 100) << std::endl;
  std::cout << "----------------------------------------" << std::endl;
}
