/**
 * Client ID of the application (from the APIs Console).
 * @type {string}
 */
CLIENT_ID = '134279604576-07ic4jjruokr8t8idr5bblciedvre4sm.apps.googleusercontent.com';

/**
 * Scopes used by the application.
 * @type {string}
 */
SCOPES = 'https://www.googleapis.com/auth/userinfo.email';

/**
 * Angular Module
 */
angular.module('gae_app')

.controller('gae_main', ['$scope','$http',
function($scope,$http) {
  $scope.new_article = {};
  $scope.get_name = "";
  $scope.article_model = {};
  $scope.you_email = "";
  
  $scope.login = function() {
    signin(false, userAuthed, $scope);
  }
  
  $scope.get = function(tmp) {
    if(tmp.length > 0)
      getArticle($scope);
    else
      getAllArticles($scope);
  }
  
  $scope.set = function() {
    //alert(angular.toJson($scope.new_article));
    setArticle($scope);
  }
}]) /* End kiosk_main */

; /* End module */

function getAllArticles($scope) {
  gapi.client.helloworld.articles.listArticle().execute(
    function(resp) {
      if (!resp.code) {
        $scope.article_model = resp.items;
        //alert(angular.toJson($scope.article_model));
        $scope.$apply();
      }
      else
        alert("Please sign in");
    });
} /* getAllArticles() */

function getArticle($scope) {
  gapi.client.helloworld.articles.getArticle({'name': $scope.get_name}).execute(
    function(resp) {
      if (!resp.code) {
        //alert(angular.toJson(resp.result));
        $scope.article_model = [resp.result];
        $scope.$apply();
      }
      else {
        if(resp.code=="401")
          alert("Please sign in");
        else
          alert(resp.message);
      }
    });
} /* getArticle() */

function setArticle($scope) {
  if(angular.isDefined($scope.new_article.name) && angular.isDefined($scope.new_article.kind)) {
    gapi.client.helloworld.article.set({
      'name': $scope.new_article.name,
      'kind': $scope.new_article.kind
    }).execute(function(resp) {
      if (!resp.code) {
        //alert(angular.toJson(resp.result));
        $scope.new_article = {};
        $scope.$apply();
      }
      else
        alert("Please sign in");
    });
  }
  else
    alert("Please insert name and article");
} /* setArticle() */

function init() {
  var apisToLoad;
  var loadCallback = function() {
    if (--apisToLoad == 0) {
      //signin(true, userAuthed);
    }
  };

  apisToLoad = 2; // must match number of calls to gapi.client.load()
  apiRoot = '//' + window.location.host + '/_ah/api';
  gapi.client.load('helloworld', 'v1', loadCallback, apiRoot);
  gapi.client.load('oauth2', 'v2', loadCallback);
}

function signin(mode, authorizeCallback, $scope) {
  gapi.auth.authorize({client_id: CLIENT_ID,
    scope: SCOPES, immediate: mode},
    authorizeCallback($scope));
}

/* Bug: Timeout problem */
function userAuthed($scope) {
  var request =
      gapi.client.oauth2.userinfo.get().execute(function(resp) {
    if (!resp.code) {
      $scope.you_email = resp.email;
      $scope.$apply();
      //alert("1 "+$scope.you_email);
    }
    //alert(angular.toJson(resp));
    $scope.you_email = resp.email;
      $scope.$apply();
      //alert("2 "+$scope.you_email);
  });
}