# Database Implementation

from google.appengine.ext import ndb

class KidGame(ndb.Model):
  name = ndb.StringProperty()
  age = ndb.IntegerProperty()
