
#include	<exception>

class	error : public std::exception {
private:
  std::string const message;

public:
  error(std::string const & mess)
    :message(mess)
  {
  }

  virtual ~error() throw() {}

  const std::string & getMessage() const
  {
    return message;
  }
};

class	bad_argument : public std::exception {
private:
  std::string const message;
  std::string const word;

public:
  bad_argument(std::string const & mess, std::string const & _word)
    :message(mess), word(_word)
  {
  }

  virtual ~bad_argument() throw() {}
          
  const std::string & getMessage() const
  {
    return message;
  }
  
  const std::string & getWord() const
  {
    return word;
  }
};

class	good_exit : public std::exception {
private:
  std::string const message;
  std::string const word;

public:
  good_exit(std::string const & mess)
    :message(mess)
  {
  }

  virtual ~good_exit() throw() {}
          
  const std::string & getMessage() const
  {
    return message;
  }
  
  const std::string & getWord() const
  {
    return word;
  }
};