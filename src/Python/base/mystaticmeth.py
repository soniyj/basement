# Example of class and static method

class A:
   def foo(self, msg):
      self.message = msg
      print(self.message)

   def __str__(self):
      return self.message

class S:
   nInstances = 0
   def __init__(self):
      S.nInstances = S.nInstances + 1

   @staticmethod
   def howManyInstances():
      print('Number of instances created: ', S.nInstances)

def test_A():
  x =  A()
  x.foo('instance')

  try:
    A.foo('instance 2')
  except:
    print "error: need an instance"

  # Call method thru Class and Instance
  A.foo(x, 'instance 2')
  return

def test_S():
  a = S()
  b = S()
  c = S()

  S.howManyInstances()
  a.howManyInstances()
  return

def main():
  test_A()
  test_S()
  return

if __name__ == "__main__":
  main()