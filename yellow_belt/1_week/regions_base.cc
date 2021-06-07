#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

//enum class Lang {
                 // DE, FR, IT
                 //};

//struct Region {
//  string std_name;
//  string parent_std_name;
//  map<Lang, string> names;
//  int64_t population;
//};

bool operator<(const Region& lhs, const Region& rhs) {
  return make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < make_tuple(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
  map<Region, int> count_map;

  int res = 0;
  for(const Region& r : regions) {
    res = max(res, ++count_map[r]);
  }

  return res;

  //auto max_count = std::max_element(begin(count_map), end(count_map),
  //                                 [](const auto& p1, const auto& p2) {
  //                                   return p1.second < p2.second;
  //                                                                   });
  //return max_count->second;
}


int main() {
  cout << FindMaxRepetitionCount({
      {
       "Moscow",
       "Russia",
       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89
             
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                    89
                
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    89
                
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    89
                
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                    89
                
      },
        
    }) << endl;

  cout << FindMaxRepetitionCount({
      {
       "Moscow",
       "Russia",
       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                 89
             
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                    89
                
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                    89
                
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    89
                
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                    31
                
      },
        
    }) << endl;

  return 0;

}
