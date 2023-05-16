#include <iostream>
#include <vector>
#include <random>
#include <sstream>
#include <numeric>
#include <iomanip>
#include <type_traits>

using namespace std;

template<typename T>
class Point {
public:
   Point(T x, T y)
      : x_(x)
      , y_(y)
   {
   }
   
   Point() = default;

   T GetX() const {
      return x_;
   }

   T GetY() const {
      return y_;
   }

   Point operator+(const Point<T>& p) {
      return Point{x_ + p.x_, y_ + p.y_};
   }

   Point operator/(int num) {
      return {x_ / num, y_ / num};
   }

private:
   T x_ = 0;
   T y_ = 0;
};

template<typename T>
ostream& operator<<(ostream& out, const Point<T>& p) {
      out.precision(2);
      int n;
      if (is_same<int, T>::value) {
         n = 2;
      } else if (is_same<double, T>::value) {
         n = 5;
      }
      out << "(" << setw(n) << p.GetX() << ", " << setw(n) << p.GetY() << ")";
      return out;
   }

template<typename T>
T average(const vector<T>& v) {
   T sum{};
   for (auto e : v) {
      sum = sum + e;
   }
   return sum / static_cast<int>(v.size());
}

int main() {
   vector<Point<double>> v_point{{5.6, 4.6}, {4.6, 8.3}, {8.3, 5.6}};
   vector<int> v_int{1, 2, 3, 6, 9}; 
   vector<double> v_double{5.6, 4.6, 8.3};  

   uniform_int_distribution<int> unif_int(-10, 10);
   uniform_real_distribution<double> unif_double(-10.0, 10.0);  
   default_random_engine re;

   int count_point = 10;
   for (int i = 0; i < count_point; ++i) {
      
      auto p_double = Point<double>{unif_double(re), unif_double(re)};
      auto num_int = unif_int(re);
      auto num_double = unif_double(re);

      v_point.push_back(p_double);
      v_int.push_back(num_int); 
      v_double.push_back(num_double);  

      cout << setw(24) << p_double << setw(25) << num_int << setw(28) << num_double << endl;
   }

   cout << "average point integer: " << average(v_point) << " ";
   cout << "average vector of int: " << average(v_int) << " ";
   cout << "average vector of dub: " << average(v_double);
}