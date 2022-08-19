#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
      friend ostream &operator<<( ostream &output, const Distance &D ) { 
         output << "F : " << D.feet << " I : " << D.inches;
         return output;            
      }

      friend istream &operator>>( istream  &input, Distance &D ) { 
         input >> D.feet >> D.inches;
         return input;            
      }
};

int main() {
   Distance D1(15, 11), D2;

   cout << "Enter the value of object : " << endl;
   cin >> D2;'
   44'
   cout << "Second Distance :" << D1 << endl;
   cout << "Third Distance :" << D2 << endl;

   return 0;
}