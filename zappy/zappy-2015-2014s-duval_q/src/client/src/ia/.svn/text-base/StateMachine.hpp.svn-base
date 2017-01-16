#ifndef		STATEMACHINE_HPP_
# define	STATEMACHINE_HPP_

#include	<iostream>
#include	<algorithm>
#include	<fstream>
#include	<map>

#include	"State.hpp"

enum e_unknowComportment
  {
    FSM_QUIT,
    FSM_IGNORE,
    FSM_RESET
  };

template <typename T>
class StateMachine
{
private:
  e_unknowComportment	comportment;
  T			&owner;
  State<T>		*currentState;
  State<T>		*initialState;
  State<T>		*lastState;
  std::map<std::string, State<T> *>	states;
public:
  StateMachine(T &owner, e_unknowComportment cpt)
    :comportment(cpt)
    ,owner(owner)
    ,currentState(NULL)
    ,initialState(NULL)
{
}

  ~StateMachine(){}

  void	restart()
  {
    this->currentState = this->initialState;
  }

  std::map<std::string, State<T> *> const &getStates() const
  {
    return (this->states);
  }

  bool	addLink(std::string origin, Edge<T> *relation, std::string target)
  {
    State<T>	*sOrigin = this->states[origin];
    State<T>	*sTarget = this->states[target];

    if (!sOrigin || !sTarget || !relation)
      return (false);
    this->states[origin]->addLink(relation, this->states[target]);
    return (true);
  }

  void	addState(State<T> *state)
  {
    this->states[state->getName()] = state;
  }

  void setInitialState(State<T> *state)
  {
    this->initialState = state;
  }

  State<T>	*getState()
  {
    return (this->currentState);
  }
  
  bool	next()
  {
    if (!this->currentState)
      this->currentState = this->initialState;
    this->currentState->end(&this->owner);
    this->lastState = this->currentState;
    this->currentState = this->currentState->getNextState(&this->owner);
    if (!this->currentState)
      {
	std::cout << "next state unreachable" << std::endl;
	switch(this->comportment)
	  {
	  case (FSM_QUIT):
	    return (false);
	    break;
	  case (FSM_IGNORE):
	    this->currentState = this->lastState;
	    break;
	  case (FSM_RESET):
	    this->currentState = this->initialState;
	    break;
	  default:
	    return (false);
	    break;
	  }
      }
    this->currentState->begin(&this->owner);
    return (true);
  }
};

template <typename T>
std::fstream    &operator<<(std::fstream &stream, StateMachine<T> const &fsa)
{
  typename std::map<std::string, State<T> *> const &list = fsa.getStates();

  std::cout << "dumping FSA graph" << std::endl << std::endl;
  stream << "digraph FSADump {" << std::endl
         << "bgcolor=white" << std::endl
         << "node [style=filled];" << std::endl;
  for (typename std::map<std::string, State<T> *>::const_iterator it = list.begin(); it != list.end(); it++)
    {
      std::cout << "" << (*it).first
		<< std::endl
		<< "{"
		<< std::endl;
      stream << (*it).second;
      if ((*it).second->isFinal())
	stream << "" << (*it).first <<" [color=red];" << std::endl;
      std::cout << "}" << std::endl << std::endl;
    }
  stream << "}" << std::endl;
  return (stream);
}

#endif	/*	STATEMACHINE_HPP_	*/
