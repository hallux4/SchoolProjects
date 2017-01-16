#include <boost/regex.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <map>
#include "parser.hpp"
#include "color.hpp"
#include "game.hpp"
#include "gui.hpp"

#define	atom(num) std::atoi(std::string(match[num].first, match[num].second).c_str())
#define atos(num) std::string(match[num].first, match[num].second)

namespace pfunc
{
  static boost::smatch                         match;
  static boost::regex                          expre;

  static inline void PrintError(const std::string &cmd)
  { std::cerr << color::red << "Commande invalide : " << color::white << cmd << std::endl; }

  void	fpmsz(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	x;
    int	y;

    expre = "^msz ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	x = atom(1);
	y = atom(2);
	data.map.setDim(x, y);
      }
    else
      PrintError(cmd);
  }

  void	fpbct(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int x;
    int	y;

    expre = "^bct ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	x = atom(1);
	y = atom(2);
	data.map.setRess(x, y, game::FOOD, atom(3));
	data.map.setRess(x, y, game::LINEMATE, atom(4));
	data.map.setRess(x, y, game::DERAUMATRE, atom(5));
	data.map.setRess(x, y, game::SIBUR, atom(6));
	data.map.setRess(x, y, game::MENDIANE, atom(7));
	data.map.setRess(x, y, game::PHIRAS, atom(8));
	data.map.setRess(x, y, game::THYSTAME, atom(9));
      }
    else
      PrintError(cmd);
  }

  void	fptna(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^tna (.*)$";

    if (boost::regex_search(cmd, match, expre))
      {
 	std::string teamname = atos(1);

	data.map.addTeam(teamname);
	std::cout << color::blue << "New team : " << teamname << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppnw(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^pnw ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) (.*)$";

    if (boost::regex_search(cmd, match, expre))
      {
	int					player = atom(1);
	std::map<int, game::player>::iterator	it;

	data.map.addPlayer(atom(2), atom(3), player, (game::orientation)(atom(4)), atos(6));
	it = data.map.FindPlayer(player);
	if (it == data.map._players.end())
	  {
	    std::cerr << color::red << "pfunc::fppnw : Le joueur #" << player << " n'existe pas (il aurait du être créé à l'instant !)" << color::white << std::endl;
	    return ;
	  }
	it->second.setLevel(atom(5));
      }
    else
      PrintError(cmd);
  }

  void	fpppo(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^ppo ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	game::player::set(data.map, atom(1), atom(2), atom(3), (game::orientation)(atom(4)));
      }
    else
      PrintError(cmd);
  }

  void	fpplv(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^plv ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	game::player::setLevel(data.map, atom(1), atom(2));
    #warning "Niveau d'un joueur"
      }
    else
      PrintError(cmd);
  }

  void	fppin(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^pin ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	int	ress[7] = { atom(4), atom(5), atom(6), atom(7), atom(8), atom(9), atom(10) };

	game::player::setInv(data.map, atom(1), ress);
      }
    else
      PrintError(cmd);
  }

  void	fppex(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	joueur;

    expre = "^pex ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
      }
    else
      PrintError(cmd);
  }

  void	fppbc(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    std::string	msg;

    expre = "^pbc ([0-9]+) (.*)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	msg = std::string(match[2].first, match[2].second);
      }
    else
      PrintError(cmd);
  }

  void	fppic(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	joueur;
    int	x;
    int	y;
    int	level;

    expre = "^pic ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	x = atom(1);
	y = atom(2);
	level = atom(3);
	joueur = atom(4);
	data.map.getTile(x, y).setIncant(true);
      }
    else
      PrintError(cmd);
  }

  void	fppie(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^pie ([0-9]+) ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	data.map.getTile(atom(1), atom(2)).setIncant(0);
	//bool result = (std::string(match[3].first, match[3].second).at(0) == '0' ? false : true);
      }
    else
      PrintError(cmd);
  }

  void	fppfk(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;

    expre = "^pfk ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	std::cout << color::blue << "Le joueur #" << joueur << " pond un oeuf." << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppdr(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  // Le joueur jette une ressource
    expre = "^pdr ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
      }
    else
      PrintError(cmd);
  }

  void	fppgt(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  // Le joueur prend une ressource
    expre = "^pgt ([0-9]+) (-?[0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	if (atom(2) == -1)
	  std::cout << "\t" << color::orange << "Un client a envoyé une commande invalide (de type `prend ...`)!" << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppdi(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;

    expre = "^pdi ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	data.map.rmPlayer(joueur);
      }
    else
      PrintError(cmd);
  }

  void	fpenw(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	x;
    int	y;
    int num;

    expre = "^enw ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	num = atom(1);
	x = atom(3);
	y = atom(4);
	data.map.addEgg(x, y, num);
      }
    else
      PrintError(cmd);
  }

  void	fpeht(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^eht ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	game::player::setStatus(data.map, atom(1), game::player::PLAYER);
      }
    else
      PrintError(cmd);
  }

  void	fpebo(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^ebo ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << color::blue << "Un joueur s'est connecté pour l'oeuf #" << atom(1) << color::white << std::endl;
	// A ce stade la (au moins pour le server officiel), le joueur n'est plus rien (mais il existe)
      }
    else
      PrintError(cmd);
  }

  void	fpedi(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^edi ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	data.map.rmPlayer(atom(1));
      }
    else
      PrintError(cmd);
  }

  void	fpsgt(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		value;

    expre = "^sgt ([0-9.]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	value = atom(1);
	std::cout << color::blue << "Unité de temps : " << value << color::white << std::endl;
	data.TimeUnit = value;
      }
    else
      PrintError(cmd);
  }

#warning "Todo : Faire une vraie fin"
  void	fpseg(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^seg (.*)$";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << color::blue << "Fin du jeu. Victoire de l'équipe : " << std::string(match[1].first, match[1].second) << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsmg(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^smg (.*)$";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << color::blue << "Message du server : " << std::string(match[1].first, match[1].second) << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsuc(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^suc$";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cerr << color::orange << "Le server à reçu une commande inconnue" << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsbp(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^sbp$";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cerr << color::orange << "Le server à reçu une commande invalide (Mauvais paramètres)" << color::white << std::endl;
      }
    else
      PrintError(cmd);
  }
};


