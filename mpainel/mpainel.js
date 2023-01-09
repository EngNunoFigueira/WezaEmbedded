<script>
  function getNames(item)
  {
      let newli   = document.createElement('li');
      let newSpan = document.createElement('span');
      let element = document.getElementById('utentes-list');
      newSpan.innerHTML = `${item.code}`;
      newli.appendChild(newSpan);
      element.appendChild(newli);
  }
</script>

<script>
  var listOfCalledTickets = [];
  var dateTime = new Date();

function clearListOfNames()
{
     var list = document.getElementById("utentes-list");
           while (list.hasChildNodes()) {
             list.removeChild(list.firstChild);
         }
}

function processTicketsCalled(element) {
// after GET the Tickets from MONGO DB save each unit
// and update the field status for closed.
  element.status = "closed";
  element.closeTime = dateTime.toLocaleDateString();
  listOfCalledTickets.push(element);
}
function putTicketStatusClose() {
  if(listOfCalledTickets.length >=1) {

      let urlApi = "";
      var json={};
      var calledTicket = {};
      var xhr  = new XMLHttpRequest();

      console.log("ENTROU NO PUT");
      listOfCalledTickets.forEach( function(ticket){
         urlApi = 'http://10.10.10.90:5000/registers/'+ ticket._id;
         calledTicket = {
            _id: ticket._id,
            counter: ticket.counter,
            code: ticket.code,
            status: ticket.status,
            serviceType: ticket.serviceType,
            openTime: ticket.openTime,
            closeTime: ticket.closeTime
           };

       console.log("URL:"+ urlApi);
       console.log("new status:"+ calledTicket.status);
       console.log("close time:"+ calledTicket.closeTime);

      json = JSON.stringify(calledTicket);
      xhr.open("PUT", urlApi, true);
      xhr.setRequestHeader('Content-type','application/json; charset=utf-8');
      xhr.onload = function () {
      var users = JSON.parse(xhr.responseText);
      if (xhr.readyState == 4 && xhr.status == "200") {
          console.table(users);
          listOfCalledTicket=[];
          }
     else {
              console.error(users);
    }
   }
   xhr.send(json);

});
}}
</script>

<script>
  /*THIS IS THE WORKER THAT WILL UPDATE THE USER DATA IN BACKGROUND*/
  function updateInfo() {
    const worker = new Worker('refreshPainelUserInfo.js')
    worker.onmessage = function(event) {
       putTicketStatusClose();
       clearListOfNames();
       const url='http://10.10.10.90:5000/registers/terminal';
          fetch(url)
           .then(response => response.json())
           .then(data => {
             data.message.forEach(getNames);
             data.message.forEach(processTicketsCalled);
          })
       .catch(error => alert(error));
   };
 }
</script>

