#include <iostream>

using namespace std; 


bool is_prime(long long int n)  
{
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
            break;
        }
    }
    return true; 
}


long long int biggest_prime(long long int x) {
    for (long long int i = x; i >= 0; i--) 
    {
      if (is_prime(i)) 
      {
        x = i; 
        break; 
      }
    }
    return x; 
}

int main() {
  std::cout << biggest_prime(100000) << endl ;
}