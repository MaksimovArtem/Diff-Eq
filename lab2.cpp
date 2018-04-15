#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <iomanip>

int main()
{
  double x_next, x_last;
  double y_next, y_last;
  std::ofstream per1;
  per1.open("period1.txt");
  std::ofstream per2;
  per2.open("period2.txt");
  for (double b = -0.6; b < 0.6; ) {

    for (double lambda = 0; lambda < 2; ) {
      //x_next = b;
      //y_last = lambda;
      x_last = b;
      y_next = lambda;
      for (int i = 0; i < 1000; i++)
      {
        //y_next = x_next;
        //x_next = 1 - lambda * x_next * x_next - b * y_last;
        //y_last = y_next;
        x_next = y_next;
        y_next = lambda - b*x_last - y_next*y_next;
        x_last = x_next;
      }
      int turn = 0;
      double x_period = INT_MAX, y_period = INT_MAX;
      while(x_next != x_period && y_next != y_period && turn <= 20)
      {
        ++turn;
        x_period = x_next;
        y_period = y_next;
        //y_next = x_next;
        //x_next = 1 - lambda * x_next * x_next - b * y_last;
        //y_last = y_next;
        x_next = y_next;
        y_next = lambda - b*x_last - y_next*y_next;
        x_last = x_next;
      }
      if(turn == 1)
      {
        per1 << b << " "<< lambda <<std::endl;
      }
      else if(turn ==2)
      {
        per2 << b << " " <<lambda <<std::endl;
      }

      lambda+= 0.001;
    }
    b+=0.001;
  }

  per1.close();

  std::cout<<"Waiting.."<<std::endl;
  std::cin.get();
}
