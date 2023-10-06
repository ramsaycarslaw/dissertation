#include <iostream>
#include "cpp-effects/include/cpp-effects/cpp-effects.h"

namespace eff = cpp_effects;

/*
** Example
**
*/
struct Choose : eff::command<int> { };

int choose()
{
  return eff::invoke_command(Choose {});
}

int toss()
{
  if (choose())
  {
    std::cout << "Heads" << std::endl;
  }
  else
  {
    std::cout << "Tails" << std::endl;
  }
}

template <typename Answer, typename S>
class Stateful : public eff::handler<int, Choose>
{
  int handle_command(Choose<int>, eff::resumption<int(int)> r) override
  {
    return std::move(r).tail_resume(1 + rand() % 2);
  }

  int handle_return(int a)
  {
    return a;
  }
};

/*
 *
 *  Exit 
 * 
 *  with wrapper function exit(status) where status is an int.
 *
 *  Halts the execution with the given status
 */
struct Exit : eff::command<int> { int status; };

int exit_(int status) { return eff::invoke_command(Exit{{}, status}); };

template <typename T>
class EffectfulExit : public eff::handler<T, Exit> 
{
  private:
    T handle_command(Exit n, eff::resumption<T> r) override
    {
      exit(n.status);
      return std::move(r).tail_resume(n.status);
    }

    T handle_return(T v) override 
    {
      return v;
    }
};

/*
 *
 * Basic IO
 *
 *
 *
 */
struct Read : eff::command<std::string> { std::string content; };
struct Write : eff::command<std::string> { };

std::string read(std::string fname)
{
  return eff::invoke_command(Read{{}, fname});
}

void write(std::string fname)
{
  return eff::invoke_command(Write{{}, fname});
}

int main()
{
  std::cout << eff::handle<Stateful<int, int>>(toss);
  return 0;
}



