#ifndef __GUI_EXCEPT_HPP_
#define __GUI_EXCEPT_HPP_

#include <string>
#include <exception>

namespace gui
{
  class except : public std::exception
  {
  public:
    except(const std::string &str) throw();
    ~except() throw();
    const char *what() const throw();

  private:
    const std::string msg;

  private:
    except();
  };
};

#endif /* __GUI_EXCEPT_HPP_ */
