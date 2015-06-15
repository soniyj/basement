# Simple Example of Python Inheritance

# methods    : are inherited automatically
# attributes : need a call to the super class (as were private)

class Father(object):
  "Base class"

  def __init__(self, f):
    self.f = f

  def method_father(self):
    print "I'm the father"


class Son_1(Father):
  "Example of inheritance"
  def __init__(self, s):
    self.s = s


class Son_2(Father):
  "Example of inheritance using super()"

  def __init__(self, s):
    super(Son_2, self).__init__(s)
    self.s = s+self.f


class Son_3(Father):
  "Example of inheritance using class name"

  def __init__(self, s):
    Father.__init__(self, s)
    self.s = s*self.f

def test_son_1():
  print "* Son 1 *"
  s = Son_1(2)
  print s.s

  try:
   print s.f
  except:
    print "error: no attribute"

  try:
    s.method_father()
  except:
    print "error: no method"

def test_son_2():
  print "* Son 2 *"
  s = Son_2(3)
  print s.s

  try:
   print s.f
  except:
    print "error: no attribute"

  try:
    s.method_father()
  except:
    print "error: no method"

def test_son_3():
  print "* Son 3 *"
  s = Son_3(4)
  print s.s

  try:
   print s.f
  except:
    print "error: no attribute"

  try:
    s.method_father()
  except:
    print "error: no method"

def main():
  f = Father(1)
  print f.f

  test_son_1()
  test_son_2()
  test_son_3()
  return


if __name__ == "__main__":
  main()