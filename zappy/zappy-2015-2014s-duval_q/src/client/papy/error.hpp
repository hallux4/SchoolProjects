#include <exception>
#include <string>

class error : public std::exception {
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
