#include <iostream>
#include "cpp-effects/include/cpp-effects/cpp-effects.h"

namespace eff = cpp_effects;

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

int main()
{
  std::cout << "Normal" << std::endl;
  exit_(1);
  std::cout << "Unreachable" << std::endl;
  return 0;
}



