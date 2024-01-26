#include <cstdio>
#include <vector>

using namespace std;

vector<int> humanYearsCatYearsDogYears(int humanYears) {
  int catYears = 0;
  int dogYears = 0;
  int tmp = humanYears;
  vector<int> All_years;
  
  while (tmp >= 1) {
    if (tmp == 1) {
      catYears += 15;
      dogYears += 15;
    } else if (tmp == 2) {
      catYears += 9;
      dogYears += 9;
    } else {
      catYears += 4;
      dogYears += 5;
    }
    
    --tmp;
  }
    
  All_years.push_back(humanYears);
  All_years.push_back(catYears);
  All_years.push_back(dogYears);
  
  return All_years;
}
