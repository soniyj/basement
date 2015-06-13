#!/usr/bin/env python

"""Hello World API implemented using Google Cloud Endpoints.

Defined here are the ProtoRPC messages needed to define Schemas for methods
as well as those methods defined in an API.
"""

import endpoints
from protorpc import messages
from protorpc import message_types
from protorpc import remote
from google.appengine.ext import ndb

WEB_CLIENT_ID = '134279604576-07ic4jjruokr8t8idr5bblciedvre4sm.apps.googleusercontent.com'
ANDROID_CLIENT_ID = 'replace this with your Android client ID'
IOS_CLIENT_ID = 'replace this with your iOS client ID'
ANDROID_AUDIENCE = WEB_CLIENT_ID

package = 'Hello'

# Due to time reasons this class will be stored here
class KidGame(ndb.Model):
  name = ndb.StringProperty()
  kind = ndb.StringProperty()

class KidArticle(messages.Message):
  name = messages.StringField(1, required=True)
  kind = messages.StringField(2)
  
class ListArticle(messages.Message):
  items = messages.MessageField(KidArticle, 1, repeated=True)


@endpoints.api(name='helloworld', version='v1',
               allowed_client_ids=[WEB_CLIENT_ID, ANDROID_CLIENT_ID,
                                   IOS_CLIENT_ID, endpoints.API_EXPLORER_CLIENT_ID],
               audiences=[ANDROID_AUDIENCE],
               scopes=[endpoints.EMAIL_SCOPE])
class HelloWorldApi(remote.Service):
  """Helloworld API v1."""
  
  @endpoints.method(message_types.VoidMessage, ListArticle,
                    path='hellokids', http_method='GET',
                    name='articles.listArticle')
  def article_list(self, unused_request):
    current_user = endpoints.get_current_user()
    if current_user is None:
      raise endpoints.UnauthorizedException('User not Authorized')
    
    kidlist = KidGame.query()
    listItems = []
    for x in kidlist:
      listItems.append(KidArticle(name=x.name,kind=x.kind))
    
    if len(listItems)==0:
      raise endpoints.NotFoundException('No Articles found')
    
    return ListArticle(items=listItems)
    
  MULTIPLY_METHOD_RESOURCE_3 = endpoints.ResourceContainer(
    KidArticle
  )

  @endpoints.method(MULTIPLY_METHOD_RESOURCE_3, KidArticle,
                    path='hellokids', http_method='POST',
                    name='article.set')
  def article_set(self, request):
    current_user = endpoints.get_current_user()
    if current_user is None:
      raise endpoints.UnauthorizedException('User not Authorized')
    
    db = KidGame(name=request.name, kind=request.kind)
    db.put()
    return KidArticle(name=request.name, kind=request.kind)
  
  ID_RESOURCE_3 = endpoints.ResourceContainer(
    message_types.VoidMessage,
    name=messages.StringField(1)
  )
  
  @endpoints.method(ID_RESOURCE_3, KidArticle,
                    path='hellokids/{name}', http_method='GET',
                    name='articles.getArticle')
  def article_get(self, request):
    current_user = endpoints.get_current_user()
    if current_user is None:
      raise endpoints.UnauthorizedException('User not Authorized')
    
    kidlist = KidGame.query(KidGame.name==request.name)
    l_item = None
    for x in kidlist:
      l_item = KidArticle(name=x.name,kind=x.kind)
    
    if l_item is None:
      raise endpoints.NotFoundException('Article %s not found.' % (request.name))
      
    return KidArticle(name=x.name,kind=x.kind)


APPLICATION = endpoints.api_server([HelloWorldApi])
