# Math Tests
#
# - prime
# - fibonacci
# - factorial

__author__ = 'soniyj'

import math

# Prime #
def is_prime(n):
  if n % 2 == 0 and n > 2:
    return False
  return all(n % i for i in range(3, int(math.sqrt(n)) + 1, 2))

def fib_iter(n):
  a,b = 0,1
  for i in range(n):
    a,b = b, a+b
  return a

# Fibonacci #
def fib_gen():
  a,b = 0,1
  yield a
  yield b
  while True:
    a, b = b, a+b
    yield b

def fib_crazy(m):
  f = lambda n: ((1+math.sqrt(5))**n-(1-math.sqrt(5))**n)/(2**n*math.sqrt(5))
  print f(m)

def test_fib():
  f = fib_gen()
  f.next()
  for i in range(10):
    a = f.next()
  print(a)
  print
  print(fib_iter(10))
  print
  fib_crazy(10)

# Factorial #
def fact(n):
  f = 1
  for i in range(1,n+1):
    f = f*i
  return f

def fact_lambda(m):
  n = range(1,m+1)
  sum = reduce(lambda x,y: x*y, n)
  return sum

def test_fact():
  print(fact(6))
  print
  print(fact_lambda(6))

def main():
  print "# prime #"
  print is_prime(123), is_prime(5)
  print
  print "# fibonacci #"
  test_fib()
  print
  print "# factorial #"
  test_fact()

if __name__ == "__main__":    
  main()