# Python Documentation Tests
#
# Few concept regarding comments (#) and string, double quote ("") or single quote('')
# (#)     : it's a simple comment, won't be used into doc
# ("",'') : can be comments and can be used for making the document
#
# Doc convention: double quote string class and function, single quote method and other
#
# How to use python code documentation
# help(class | function) -> returns all information available
# CLASS.__doc__          -> information about the Class
# FUNC.__doc__           -> information about the Function
# CLASS.__init__.__doc__ -> info for an built-in method
# CLASS.method.__doc__   -> info for a user-defined method

# Simple Class (this is just a comment)
class MyInt():
  """
  Documentation and Comment on multi-lines
  This is a simple Class for showing the awesome python stuff
  """

  def __init__(self, integer):
    'Constructor (single quote doc)'
    self.integer = long(integer)

  def __add__(self, integer):
    'List extension (comment and doc)'
    return long(str(self.integer) + str(integer))

class Summy(object):
  " Class for testing the Sum(n) "
  _num = 0

  def __init__(self, n):
    " Constructor "
    self._num = n

  def simple_sum(self, n=0):
    ' Simple Sum using a for statement '
    s = 0
    if n== 0:
      m = self._num
    else:
      m = n

    for x in range(m):
      s += x

    return s

  def range_sum(self, n=0):
    ' Sum using sum() plus range() and one line if statement '
    return sum(range(n if n>0 else self._num))

  def crazy_gauss_1(self, n=0):
    ' Sum with Arithmetic Progression {(n-1)*[(n-1)+1]}/2 '
    m = n if n>0 else self._num
    return ((m-1)*((m-1)+1))/2

  def crazy_gauss_2(self, n=0):
    ' Sum with Arithmetic Progression (n*(n-1))/2 '
    m = n if n>0 else self._num
    return (m*(m-1))/2

class Dicsy(object):
  " Dict examples "

  def gen_simple_dict(self, n=10):
    'Generate a dictionary {x : x*2} of n-elements'
    return {x: x*2 for x in range(n)}

  def gen_pow_dict(self, n=10):
    'Generate a dictionary {x : x**2} of n-elements, x**2 := pow(2)'
    return {x: x**2 for x in range(n)}

def main():
  s = Summy(10)
  print s.simple_sum()
  print s.range_sum(15)
  print s.crazy_gauss_1()
  print s.crazy_gauss_2(15)

  print

  d = Dicsy()
  print d.gen_simple_dict()
  print d.gen_pow_dict()
  return

if __name__ == '__main__':
  main()