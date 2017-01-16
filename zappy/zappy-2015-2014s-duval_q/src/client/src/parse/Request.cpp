#include	<iostream>

#include	"Request.hpp"

Request::Request()
  :type(REQ_NONE)
{

}

Request::~Request()
{

}

e_request_type Request::getType() const
{
  return (this->type);
}

void  Request::setType(e_request_type req)
{
  this->type = req;
}

std::list<std::string> const  &Request::getNumericList() const
{
  return this->numericList;
}

void	Request::setNumericList(std::list<std::string> &list)
{
  this->numericList = list;
}

void                          Request::addNumeric(std::string &numeric)
{
  this->numericList.push_back(numeric);
}
void                          Request::flushNumericList()
{
  this->numericList.clear();
}

int                           Request::getNumberInInventory(std::string const &id) const
{
  return (this->inventory.find(id))->second;
}

void                          Request::setInventoryEntry(std::string id, int val)
{
  this->inventory[id] = val;
}
