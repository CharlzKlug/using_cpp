#include <string>
#include <iostream>

int area(int x, int y) {
  return x * y;
}

int framed_area(int x, int y) {
  constexpr int frame_width= 2;
  return area(x-frame_width, y-frame_width);
}

void error(std::string inputMessage) {
  std::cerr << inputMessage << std::endl;
  exit(-1);
}

double f(int x, int y, int z) {
  int area1= area(x,y);
  if (area1<=0) error("No positive area");
  int area2= framed_area(1,z);
  if (area2 <= 0) error("No positive area");
  int area3= framed_area(y,z);
  if (area3 <= 0) error("No positive area");
  double ratio= double(area1) / area3;
  std::cout << "area1 = " << area1 << std::endl;
  std::cout << "area2 = " << area2 << std::endl;
  std::cout << "area3 = " << area3 << std::endl;
  std::cout << "ratio = " << ratio << std::endl;
  return ratio;
}

int main() {
  f(10, 11, 12);
}
