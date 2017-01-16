//
// Function.hpp for  in /home/pincho_m//projet/rush/hell/etape2
// 
// Made by mathieu pinchon
// Login   <pincho_m@epitech.net>
// 
// Started on  Fri Dec 14 20:36:53 2012 mathieu pinchon
// Last update Sat Dec 15 19:45:59 2012 mathieu pinchon
//

#ifndef	FUNCTION_HPP
#define FUNCTION_HPP

#include        <boost/shared_ptr.hpp>

template <typename T>
class Function;

/*pour 0 argument*/

template<typename T>
struct Function<T()>
{
  typedef	T (*ptr)();

  class IIntern
  {
  public:
    virtual ~IIntern(){};
    virtual T operator()() = 0;
  };

  template <typename A>
  class Intern : public IIntern
  {
  public:
    A	*var;

    Intern(const A& enter)
    {
      var = new A(enter);
    }
    ~Intern(){}

    T operator()()
    {
      return (var->operator()());
    }
  };


  template <typename ret>
  class Intern<ret ()> : public IIntern
  {
  public:
    ptr	recup;

    Intern(const ptr enter)
    {
      recup = enter;
    }

    virtual ~Intern(){}

    T	operator()()
    {
      return recup();
    }
  };

  IIntern	*intern;

  template<typename big>
  Function(const big&  enter)
  {
    intern = new Intern<big>(enter);
  }

  Function(const ptr data)
  {
    intern = new Intern<T()>(data);
  }

  T	operator()() const
  {
    return (intern->operator()());
  }

  template<typename big>
  void	operator=(const big& enter)
  {
    intern = new Intern<big>();
  }

  void	operator=(const ptr enter)
  {
    intern = new Intern<T()>();
  }
};

/*pour 1 argument*/

template<typename T, typename arg>
struct Function<T(arg)>
{
  typedef	T (*ptr)(arg);

  class IIntern
  {
  public:
    virtual ~IIntern(){};
    virtual T operator()(const arg&) = 0;
  };

  template <typename A>
  class Intern : public IIntern
  {
  public:
    A	*var;

    Intern(const A& enter)
    {
      var = new A(enter);
    }
    ~Intern(){}

    T operator()(const arg& enter)
    {
      return (var->operator()(enter));
    }
  };


  template <typename ret, typename arg1>
  class Intern<ret (arg1)> : public IIntern
  {
  public:
    ptr	recup;

    Intern(const ptr enter)
    {
      recup = enter;
    }

    virtual ~Intern(){}

    T	operator()(const arg1& enter)
    {
      return (recup(enter));
    }
  };

  IIntern	*intern;

  template<typename big>
  Function(const big&  enter)
  {
    intern = new Intern<big>(enter);
  }

  Function(const ptr data)
  {
    intern = new Intern<T(arg)>(data);
  }

  T	operator()(const arg& enter) const
  {
    return (intern->operator()(enter));
  }

  template<typename big>
  void	operator=(const big& enter)
  {
    intern = new Intern<big>(enter);
  }

  void	operator=(const ptr enter)
  {
    intern = new Intern<T(arg)>(enter);
  }
};


/*Pour 2 argument*/

template<typename T, typename arg, typename arg2>
struct Function<T(arg, arg2)>
{
  typedef	T (*ptr)(arg, arg2);

  class IIntern
  {
  public:
    virtual ~IIntern(){};
    virtual T operator()(const arg&, const arg2&) = 0;
  };

  template <typename A>
  class Intern : public IIntern
  {
  public:
    A	*var;

    Intern(const A& enter)
    {
      var = new A(enter);
    }
    ~Intern(){}

    T operator()(const arg& enter, const arg2& second)
    {
      return (var->operator()(enter, second));
    }
  };


  template <typename ret, typename arg1>
  class Intern<ret(arg1)> : public IIntern
  {
  public:
    ptr	recup;

    Intern(const ptr enter)
    {
      recup = enter;
    }

    virtual ~Intern(){}

    T	operator()(const arg1& enter, const arg2 & second)
    {
      return (recup(enter, second));
    }
  };

  IIntern	*intern;

  template<typename big>
  Function(const big&  enter)
  {
    intern = new Intern<big>(enter);
  }

  Function(const ptr data)
  {
    intern = new Intern<T(arg)>(data);
  }

  T	operator()(const arg& enter, const arg& second) const
  {
    return (intern->operator()(enter, second));
  }

  template<typename big>
  void	operator=(const big& enter)
  {
    intern = new Intern<big>(enter);
  }

  void	operator=(const ptr enter)
  {
    intern = new Intern<T(arg)>(enter);
  }
};


#endif
