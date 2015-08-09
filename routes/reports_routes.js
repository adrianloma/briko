module.exports = function (router) {
	var reportsController = require('../controllers/reports_controller');
	var auth = require('../controllers/auth_controller');

	router.get('/reports/amountPerPhase', auth.hasPermission('Ver Reportes'),
		reportsController.getAmountPerPhase);
	
	router.get('/reports/usersProductivity', auth.hasPermission('Ver Reportes'),
		reportsController.getUsersProductivity);

	router.get('/reports/calendar', reportsController.getCalendar);

	router.get('/reports/monthlyAmount', auth.hasPermission('Ver Reportes'),
		reportsController.getMonthlyClosedProjects);
	
	router.get('/reports/exportProjects', auth.isAdmin,
		reportsController.getAllProjectsData);
};