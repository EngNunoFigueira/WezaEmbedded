/***************************************************************************************************** 
 * Author   : Nuno Figueira                                                                          *
 * Dev Year : 2019/2020                                                                              *
 * Release  : 1.1.0 beta                                                                             *
 * Project  : Agd-Medic, Monitor Mpainel                                                             *
 *                                                                                                   *
 * Javascript functionality:                                                                         *
 * The main purpose of this javascript code is to manager the info of tickets printed by the         *
 * terminal machine:                                                                                 *  
 * The Restfull API is called to GET all tickets, with status called, and the ticket will be print   *
 * on Monitor screen.                                                                                *
 * But, after the ticket timeout expire, the Resfull API, PUT method, is fetch to updated the fields *
 * status and datetime. To closed and with current time, respectively.                               * 
 * Using a JS Worker we don't need refresh the full Single Page. Just refresh the HTML element list  *
 * of ticket, when the Worker event is trigger.                                                      *    
 * **************************************************************************************************/

// Function description:
// Create a dynamic HTML compoment, of type list, to display the ticket printed on the terminal machine.
// Everytime we print or request a new ticket, on the terminal, this function will added an element in the HTML list.
function getNames(item) {
  let newli = document.createElement('li');
  let newSpan = document.createElement('span');
  let element = document.getElementById('ticket-list');
  newSpan.innerHTML = `${item.code}`;
  newli.appendChild(newSpan);
  element.appendChild(newli);
}

// Helpers: Declaration of global variables:
var listOfCalledTickets = [];
var dateTime = new Date();

// Function description:
// This function remove all the ticket "closed" from the display screen.
function clearListOfTicketsId() {
  var list = document.getElementById("ticket-list");
  while (list.hasChildNodes()) {
    list.removeChild(list.firstChild);
  }
}

// Function description:
// Execute the Restfull API <POST> to update the Ticket status to close.
// And the ticket field datetime , will be updated too with the current close time.
function processTicketsCalled(element) {
  element.status = "close";
  element.closeTime = dateTime.toLocaleDateString();
  listOfCalledTickets.push(element);
}

// Function description:
// THIS FUNCTIONS IS CALLED EACH 2.5 MINUTES TO UPDATE THE STATUS OF OPENS TICKETS...
// After the timer used to display the ticket on the monitors expired, this ticket is hide 
// or removed from the list. To complete the process, the field status and the close time, are updated with the 
// values: closed and the current time respectively. To finish the procedure the PUT is executed.
function putTicketStatusClose() {
  if (listOfCalledTickets.length >= 1) {

    let urlApi = "";
    var json = {};
    var calledTicket = {};
    var xhr = new XMLHttpRequest();

    console.log("PROCESSING TICKET ON PUT");
    listOfCalledTickets.forEach(function (ticket) {
      urlApi = 'http://10.10.10.90:5000/registers/' + ticket._id;
      calledTicket = {
        _id: ticket._id,
        counter: ticket.counter,
        code: ticket.code,
        status: ticket.status,
        serviceType: ticket.serviceType,
        openTime: ticket.openTime,
        closeTime: ticket.closeTime
      };

      console.log("URL:" + urlApi);
      console.log("new status:" + calledTicket.status);
      console.log("close time:" + calledTicket.closeTime);

      json = JSON.stringify(calledTicket);
      xhr.open("PUT", urlApi, true);
      xhr.setRequestHeader('Content-type', 'application/json; charset=utf-8');
      xhr.onload = function () {
        var users = JSON.parse(xhr.responseText);
        if (xhr.readyState == 4 && xhr.status == "200") {
          console.table(users);
          listOfCalledTickets = [];
        }
        else {
          console.error(users);
        }
      }
      xhr.send(json);

    });
  }
}

// Function description:
// The main algorithm will be executed under a Javascript WORKER procedure.
// In each event of the Worker, the followings methods will be executed:
// putTicketStatusClose () -> update the ticket fields, status and close time.
// clearListOfTicketsId () -> stop display the expiered ticket on the monitor. 
// getNames ()             -> Get the ID of the ticket to display on the monitor.
// processTicketsCalled () -> save the "PUT" the ticket with the fields updated. 
function updateInfo() {
  const worker = new Worker('refreshPainelUserInfo.js')
  worker.onmessage = function (event) {
    putTicketStatusClose();
    clearListOfTicketsId();
    const url = 'http://10.10.10.90:5000/registers/terminal';
    fetch(url)
      .then(response => response.json())
      .then(data => {
        data.message.forEach(getNames);
        data.message.forEach(processTicketsCalled);
      })
      .catch(error => alert(error));
  };
}
