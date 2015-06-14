# Example how to use *, **, *args, **kwargs

__author__ = "soniyj"

def func_1(a,b,c):
  " Prints given values "
  print a,b,c

def func_2(*args):
  """
  It receives a tuple containing the positional arguments beyond the formal parameter list
  *args is a list of variable arguments
  Function can get also a normal static parameter
  """
  print args

  for arg in args:
    print arg

def func_3(**kwargs):
  """
  It receives a dictionary containing all the keyword arguments beyond the formal parameter list
  **kwargs contains the variable name and the value
  Function can get also a normal static parameter
  """

  print kwargs

  for kwarg in kwargs:
    print kwarg, kwargs[kwarg]

def test_func_1():
  " Testing '*' "
  func_1(1,2,3)
  l = [1,2,3]
  "It unpacked the values in list 'l' as positional arguments"
  "List should have as many arguments as thu function has"
  func_1(*l)

  try:
    func_1(l) # error
  except:
    print "error: l is a list"

  try:
    l2 = [1,2,3,4,5]
    func_1(l2)
  except:
    print "error: to many arguments"

  # Mixture of parameters
  l3 = [5,6]
  func_1(4, *l3)
  return

def test_func_2():
  " Testing '*args' "
  func_2(1)
  func_2(1,2,3)
  l = [1,2,3]
  func_2(l)  # list as 1 argument
  func_2(*l) # list element as arguments

def test_func_3():
  " Testing '**' "
  func_1(1,2,3)
  func_1(4,b=5,c=6)
  "It unpacked the dictionary used with it, and passed the items in the dictionary as keyword arguments to the function."
  "Dict should have as many arguments as thu function has"
  d1 = {'a':1,'b':2,'c':3}
  func_1(**d1)
  d2 = {'b':5,'c':6}
  func_1(4,**d2)

  try:
    func_1(d1)
  except:
    print "error: is a dictionary"

  try:
    d3 = {'a':1,'b':2,'c':3,'d':4}
    func_1(**d3)
  except:
    print "error: to many arguments"

  try:
    d3 = {'a':1,'b':2}
    func_1(**d3)
  except:
   print "error: number of arguments not correct"

def test_func_4():
  " Testing '**kwargs' "
  func_3(a=1)
  func_3(a=1,b=2,c=3)
  d = {'a':4,'b':5,'c':6}
  func_3(d=d) # needs to be a dictionary parameter
  func_3(**d) # dict element as parameters

def main():
  test_func_1()
  test_func_2()
  test_func_3()
  test_func_4()
  return

if __name__ == "__main__":
  main()