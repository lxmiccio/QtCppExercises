#include <iostream>

int main()
{
  if(true)          std::cout << "true" << std::endl;
  if(false)         std::cout << "false" << std::endl;
  if(42)            std::cout << "42" << std::endl;
  if(0)             std::cout << "0" << std::endl;
  if(42.4242)       std::cout << "42.4242" << std::endl;
  if(0.0)           std::cout << "0.0" << std::endl;
  if(-0.0)          std::cout << "-0.0" << std::endl;
  if(-1)            std::cout << "-1" << std::endl;
  if('\0')          std::cout << "\\0" << std::endl;
  if('\1')          std::cout << "\\1" << std::endl;
  if("1")           std::cout << "\"1\"" << std::endl;
  if("false")       std::cout << "\"false\"" << std::endl;
  if(std::cout)     std::cout << "std::cout" << std::endl;
  if(std::cin)      std::cout << "std::cin" << std::endl;
}
