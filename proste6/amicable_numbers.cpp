#include <cstdio>
#include <cassert>

int sumOfDivisors(int n) {
  
  int sum = 0;
  for(int i = 2; i*i <= n; ++i) {
    if(n % i == 0) {
      
      if(i != n/i) {
        sum += i;
        sum += (n/i);
      }
      else sum += i;
      
    }
  }
  // +1 beacause for loop starts from 2 so as not to count pair {1 , n}
  return sum + 1; 
  
}

bool amicable_numbers(int a, int b) {
    
  return ((sumOfDivisors(a) == b) && (sumOfDivisors(b) == a));
  
}

int main() {
  
  assert(sumOfDivisors(220) == 284);
  
  int number1, number2;
  scanf("%d %d", &number1, &number2);
  
  if (amicable_numbers(number1, number2)) printf("YES\n");
  else printf("NO\n");
  
  return 0;
}
