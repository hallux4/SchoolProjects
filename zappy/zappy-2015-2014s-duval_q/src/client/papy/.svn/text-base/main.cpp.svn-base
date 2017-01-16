//
// main.cpp for  in /home/hallux/Bureau/Dropbox/zappy/zappy-2015-2014s-duval_q/src/client/papy
//
// Made by joffrey
// Login   <hallux@epitech.net>
//
// Started on  Mon Jun 25 00:24:59 2012 joffrey
// Last update Wed Jun 27 14:52:04 2012 joffrey
//

#include "client.hh"
#include "connect.hh"

int main(int argc, char **argv)
{
  Client Tryout;
  try
    {
      Tryout.fill_args(argc, argv);
      Tryout.test_args();
      Tryout.display_params();
    }
  catch (const error & err)
    {
      std::cerr << "ERROR : " << err.getMessage() << std::endl;
      // Tryout.delete_option();
      return(1);
    }
  return 0;
}
