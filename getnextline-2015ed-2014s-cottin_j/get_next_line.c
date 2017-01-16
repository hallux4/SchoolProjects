/*
** get_next_line.c for  in /home/cottin_j/Bureau/ssh/getnextline-2015ed-2014s-cottin_j
**
** Made by joffrey cottin
**
** Started on  Sat Dec  3 06:55:02 2011 joffrey cottin
** Last update Wed Dec  7 12:53:28 2011 cottin_j
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int     end_of_readbuff(t_out *output, t_in *input)
{
  if (input->src[input->j] == 0)
    {
      output->dest[output->i] = 0;
      input->j = 0;
      return (1);
    }
  return (0);
}

static int end_of_line(t_out *output, t_in *input)
{
  if (input->src[input->j] == '\n')
    {
      output->dest[output->i] = 0;
      if (input->j + 1 >= input->nb_char)
        input->j = 0;
      else
        input->j++;
      return (1);
    }
  return (0);
}

static int      fill_dest(t_out *output, t_in *input)
{
  while (output->i < PASS_BUFF)
    {
      if (end_of_readbuff(output, input))
        return (0);
      if (end_of_line(output, input))
        return (1);
      output->dest[(output->i)++] = input->src[(input->j)++];
    }
  output->dest[output->i] = 0;
  return (1);
}

char            *get_next_line(const int fd)
{
  static t_in       input;
  t_out             output;

  if (!(output.dest = malloc(PASS_BUFF + 1)))
    return (0);
  output.i = 0;
  while (output.i < PASS_BUFF)
    {
      if (input.j == 0)
        if ((input.nb_char = read(fd, input.src, READ_BUFF)) <= 0)
          return (0);
      if (fill_dest(&output, &input))
        return (output.dest);
    }
  return (output.dest);
}
