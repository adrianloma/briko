var router = require('express').Router();

var routes = [
	'auth_routes',
	'user_routes',
	'project_routes',
	'reports_routes',
	'cuadrillas_routes',
	'error_routes'
];

var mountRoute = function (route) {
	require('./' + route)(router);
};

routes.forEach(mountRoute);

module.exports = router;