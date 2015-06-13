angular.module('gae_app', ['mm.foundation','ui.router'])

.config(function($stateProvider, $urlRouterProvider) {
  $urlRouterProvider.otherwise("/index");
  
  $stateProvider
  .state('index', {
    url:"/index",
    templateUrl: "index.html"
  })
  ; // End $stateProvider
});