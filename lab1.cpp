#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <iomanip>

int main()
{
  double x_next;
  double x_last;
  std::ofstream file;
  file.open("file.txt");
  for (double r = 2.4; r < 4; ) {

    for (double x = 0; x < 1; ) {
      x_next = x;
      x_last = x;
      for (int i = 0; i < 1000; i++)
      {
        x_last = x_next;
        x_next = r * x_last  * (1-x_last);
      }
      file << r<<" "<<x_next<< std::endl;
      x += 0.001;
    }
    r+=0.001;
    std::cout<<"r = "<< r <<std::endl;
  }

  file.close();

  std::cout<<"Waiting.."<<std::endl;
  std::cin.get();
}
