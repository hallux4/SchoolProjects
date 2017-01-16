/* 
 * File:   main.cpp
 * Author: cottin_j
 *
 * Created on February 8, 2012, 5:42 PM
 */

#include "Control.hpp"
#include <float.h>
#include <stdexcept>

int main(int argc, char** argv)
{
  std::string data;
  std::string str;
  Control * lexed = new Control(data);

  if (argc == 1)
  {
    data.clear();
    while (std::cin)
    {
      getline(std::cin, str);
      data += "\n";
      if (str.find(";;") == std::string::npos)
        data += str;
      if (str.find(";;") != std::string::npos)
      {
        try
        {
          lexed->new_data(data);
          lexed->parsing();
        }
        catch (const error & err)
        {
          std::cerr << "ERROR : " << err.getMessage() << std::endl;
          delete lexed;
          return(1);
        }
        catch (const good_exit & err)
        {
          delete lexed;
	  return(0);
        }
        catch (const bad_argument & err)
        {
          std::cerr << "ERROR : " << err.getMessage() << std::endl;
          delete lexed;
          return(1);
        }
      }
    }
  }
  while (--argc && argv++)
  {
    std::ifstream fichier(*argv, std::ifstream::in);
    if (fichier)
    {
      std::stringstream buffer;
      buffer << fichier.rdbuf();
      fichier.close();
      data = buffer.str();
      try
      {
        lexed->new_data(data);
        lexed->parsing();
      }
      catch (const error & err)
      {
        std::cerr << "ERROR : " << err.getMessage() << std::endl;
        delete lexed;
        return(1);
      }
      catch (const good_exit & err)
      {
        std::cerr << "Exit : " << err.getMessage() << std::endl;
        delete lexed;
      }
      catch (const bad_argument & err)
      {
        std::cerr << "ERROR : " << err.getMessage() << std::endl;
        delete lexed;
        return(1);
      }
    }
    else
      std::cerr << "can't open " << *argv << std::endl;
  }
  return 0;
}
