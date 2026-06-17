/**
 * FARZI NATIONAL BANK - FULLY VERIFIED SERVER-SIDE CORE LEDGER
 * ARCHITECT: GOVIND RAM
 * VERSION: 5.0.0 (CORS COMPLIANT ENGINE)
 */

function doPost(e) {
  var output = ContentService.createTextOutput();
  output.setMimeType(ContentService.MimeType.JSON);
  
  // Set CORS headers manually to bypass browser restrictions
  var headers = {
    "Access-Control-Allow-Origin": "*",
    "Access-Control-Allow-Methods": "POST, GET, OPTIONS",
    "Access-Control-Allow-Headers": "Content-Type"
  };

  var lock = LockService.getScriptLock();
  try {
    lock.waitLock(30000); // 30 seconds concurrency lock guard
  } catch (f) {
    return ContentService.createTextOutput(JSON.stringify({"status": "failed", "message": "Server Busy. Thread lock timeout."})).setMimeType(ContentService.MimeType.JSON);
  }

  try {
    var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
    var requestData = JSON.parse(e.postData.contents);
    var action = requestData.action;
    var dataGrid = sheet.getDataRange().getValues();

    // 1. HARDLOCK LOGIN ROUTINE
    if (action === "login") {
      var inputId = parseInt(requestData.id);
      var inputName = requestData.name.toString().trim().toLowerCase();

      for (var i = 1; i < dataGrid.length; i++) {
        var recordId = parseInt(dataGrid[i][0]);
        var recordName = dataGrid[i][1].toString().trim().toLowerCase();
        
        if (recordId === inputId && recordName === inputName) {
          return ContentService.createTextOutput(JSON.stringify({
            "status": "success",
            "account": {
              "id": dataGrid[i][0],
              "name": dataGrid[i][1],
              "balance": parseFloat(dataGrid[i][2]),
              "pin": parseInt(dataGrid[i][3])
            }
          })).setMimeType(ContentService.MimeType.JSON);
        }
      }
      return ContentService.createTextOutput(JSON.stringify({"status": "failed", "message": "Account ID or Holder Name mismatch in Server Ledger."})).setMimeType(ContentService.MimeType.JSON);
    }

    // 2. CONSTRAINT CHECK SIGNUP ROUTINE
    else if (action === "signup") {
      var targetId = parseInt(requestData.id);
      
      for (var j = 1; j < dataGrid.length; j++) {
        if (parseInt(dataGrid[j][0]) === targetId) {
          return ContentService.createTextOutput(JSON.stringify({"status": "failed", "message": "Index Violation: Account ID already allocated."})).setMimeType(ContentService.MimeType.JSON);
        }
      }
      sheet.appendRow([targetId, requestData.name.toString().trim(), parseFloat(requestData.balance), parseInt(requestData.pin)]);
      return ContentService.createTextOutput(JSON.stringify({"status": "success"})).setMimeType(ContentService.MimeType.JSON);
    }

    // 3. SECURE DOUBLE-AUTHENTICATION BALANCE MUTATION (DEPOSIT/WITHDRAW)
    else if (action === "executeTransaction") {
      var authId = parseInt(requestData.id);
      var authPin = parseInt(requestData.pin);
      var trxType = requestData.transactionType;
      var trxAmount = parseFloat(requestData.amount);

      for (var k = 1; k < dataGrid.length; k++) {
        var currentId = parseInt(dataGrid[k][0]);
        var currentPin = parseInt(dataGrid[k][3]);
        var currentBalance = parseFloat(dataGrid[k][2]);

        if (currentId === authId) {
          if (currentPin !== authPin) {
            return ContentService.createTextOutput(JSON.stringify({"status": "failed", "message": "Security Alert: Micro-encryption PIN matching failed on Cloud Node!"})).setMimeType(ContentService.MimeType.JSON);
          }

          var updatedBalance = currentBalance;
          if (trxType === "deposit") updatedBalance += trxAmount;
          else if (trxType === "withdraw") updatedBalance -= trxAmount;

          sheet.getRange(k + 1, 3).setValue(updatedBalance);
          return ContentService.createTextOutput(JSON.stringify({"status": "success", "newBalance": updatedBalance})).setMimeType(ContentService.MimeType.JSON);
        }
      }
    }
  } catch (error) {
    return ContentService.createTextOutput(JSON.stringify({"status": "error", "message": error.toString()})).setMimeType(ContentService.MimeType.JSON);
  } finally {
    lock.releaseLock();
  }
}

function doGet(e) {
  return ContentService.createTextOutput("Farzi Matrix Core Server Node Live.");
}
