#include <vector>
#include <map> // For std::map
#include <iostream> // For std::cout

int main() {
  std::vector<std::string> seqString{"a", "aa", "b", "bb", "aa", "ccc"};
  
  std::map<std::string, int> modaString;
  std::string maxCountString = "";
  std::string maxElement= "";
  std::string minElement= "";
  for (std::string strTmp : seqString) {
      if (maxCountString.empty()) {
	  maxCountString= strTmp;
      }
      if (maxElement.empty()) {
	  maxElement= strTmp;
      }
      if (minElement.empty()) {
	  minElement= strTmp;
      }
      
      if (maxElement < strTmp) {maxElement= strTmp;}
      if (minElement > strTmp) {minElement= strTmp;}
    if (modaString.contains(strTmp)) {
      modaString[strTmp] = modaString[strTmp] + 1;
      if (modaString[maxCountString] < modaString[strTmp]) {
	maxCountString = strTmp;
      }
    } else {
      modaString[strTmp] = 1;
    }
  }

  std::cout << "Moda string: " << maxCountString << std::endl;
  std::cout << "Max: " << maxElement << std::endl;
  std::cout << "Min: " << minElement << std::endl;
  return 0;
}
