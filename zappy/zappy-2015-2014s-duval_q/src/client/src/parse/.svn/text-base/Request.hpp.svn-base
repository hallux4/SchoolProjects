//
// Request.hpp for zappy in /home/duval_q//Documents/projects/zappy-2015-2014s-duval_q/src/client/src/parse
// 
// Made by quentin duval
// Login   <duval_q@epitech.net>
// 
// Started on  Thu Jul  5 13:32:25 2012 quentin duval
// Last update Sun Jul  8 00:53:50 2012 quentin duval
//

#ifndef		REQUEST_HPP_
# define	REQUEST_HPP_

#include	<map>
#include	<list>
#include	<string>

enum e_request_type
  {
    REQ_ASSERT_OK,
    REQ_ASSERT_KO,
    REQ_DEATH,
    REQ_NUMERIC_LIST,
    REQ_HELLO,
    REQ_INVENTORY,
    REQ_VIEW,
    REQ_NONE
  };

class Request
{
  private:
  e_request_type		type;
  std::list<std::string>	numericList;
  std::map<std::string, int>	inventory;
public:
  Request();
  ~Request();
  e_request_type		getType() const;
  void				setType(e_request_type req);
  std::list<std::string> const	&getNumericList() const;
  void				setNumericList(std::list<std::string> &list);
  void				addNumeric(std::string &numeric);
  void				flushNumericList();
  int				getNumberInInventory(std::string const &) const;
  void				setInventoryEntry(std::string, int);
};

#endif	/*	REQUEST_HPP_	*/
