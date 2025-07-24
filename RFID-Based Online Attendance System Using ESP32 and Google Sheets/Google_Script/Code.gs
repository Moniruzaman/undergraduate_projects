
function doPost(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  var uid = e.parameter.uid;
  var timestamp = new Date();
  sheet.appendRow([timestamp, uid]);
  return ContentService.createTextOutput("Success");
}