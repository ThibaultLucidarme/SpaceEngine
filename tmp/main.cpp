#include "InputManager.hpp"

void foo(){};

int main()
{
  try
  {
    InputManager im("testc","testp");

    std::cout << im.ReadClassData("test2")<<std::endl;
    std::cout << im.ReadClassData("test1")<<std::endl;
    std::cout << im.ReadPersonalData("test2")<<std::endl;
    std::cout << im.ReadPersonalData("test1")<<std::endl;
    std::cout << im.ReadClassData("test3")<<std::endl;
  }
  catch(const std::exception& error)
  { std::cerr << error.what(); }

return 0;
}

