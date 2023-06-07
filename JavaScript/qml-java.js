    function updateListViewModelF(request) {

      var dataObj;
      var appendToList;
      console.log("Starting update the data from RestAPI");
      try {
          dataObj = JSON.parse(request.responseText);
          if((dataObjLength >= dataObj.message.length))
          {
              console.log("not found a new service");
          }
          else if( dataObj.message.length === 0)
          {
              console.log("the queue is empty");
          }
          else
          {
             for(var i = 0; i < dataObj.message.length; i++)
             {
               if(dataObj.message[i].serviceType==="Exame Medico")
                {
                  appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType: dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime
                 }
                 modelExames.append(appendToList);
                 console.log("the elements get was:" + appendToList.code);
               }
               if(dataObj.message[i].serviceType==="ATT Geral")
               {
                    appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType: dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime }

                 modelAttGeral.append(appendToList);
                 console.log("the elements get was:" + appendToList.code);
               }
               if(dataObj.message[i].serviceType==="Consultas")
               {
                    appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType: dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime }

                 modelConsulta.append(appendToList);
                 console.log("the elements get was:" + appendToList.code);
              }
             if(dataObj.message[i].serviceType==="Resultados")
             {
                    appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType: dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime }

                 modelResultados.append(appendToList);
                 console.log("the elements get was:" + appendToList.code);
             }
           }
           //refresh the size of object Message
           dataObjLength = dataObj.message.length;
          }
         }
     catch(e)
      {
         console.log("ERROR... " + e);
      }
    }

------------------------------------------ JAVA CODE THAT WORKING version 1.1-----------------------------------------------
 /*..............................JAVASCRIPT METHODS TO MANAGER THE DATA..................................*/
    property var locale: Qt.locale()
    property date currentDate: new Date()
    property int indexToRemove:1000
    property var modelItemToUpdate : {
    id_:""
    counter:""
    code: ""
    status: ""
    serviceType: ""
    openTime: ""
    closeTime:""
   };
    property int dataObjLength:0;
    // FILL THE LIST MODELs WITH DATA GET FROM SERVER REST API
    function updateListViewModelF(request) {

      var dataObj;
      var appendToList;
      var registerDuplicated=0;
      console.log("Starting update the data from RestAPI");
      try {
          dataObj = JSON.parse(request.responseText);
          if((dataObjLength === dataObj.message.length))
          {
              console.log("not found a new service");
              console.log("dataObjLength is equal = " + dataObjLength);
          }
          else if( dataObj.message.length === 0)
          {
              console.log("the queue is empty");
          }
          else
          {
             for(var i = 0; i < dataObj.message.length; i++)
             {
               if(dataObj.message[i].serviceType==="Exame Medico")
                {
                  registerDuplicated=0;
                  for(var j = 0; j < modelExames.count; j++){
                      if( modelExames.get(j).code===dataObj.message[i].code ) {
                         registerDuplicated=100;
                      }
                  }
                  if(registerDuplicated===0){
                  appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType: dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime
                 }
                 modelExames.append(appendToList);
                }
               }
              if(dataObj.message[i].serviceType==="ATT Geral")
               {
                 registerDuplicated=0;
                 for(var jj = 0; jj < modelAttGeral.count; jj++){
                      if( modelAttGeral.get(jj).code===dataObj.message[i].code ) {
                         registerDuplicated=100;
                      }
                  }
                  if(registerDuplicated===0){
                    appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType:dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime }

                 modelAttGeral.append(appendToList);
                 }
               }
               if(dataObj.message[i].serviceType==="Consultas")
               {
                 registerDuplicated=0;
                 for(var jjj = 0; jjj < modelConsulta.count; jjj++){
                    if(modelConsulta.get(jjj).code===dataObj.message[i].code) {
                        //console.log("the elements get was :" + modelConsulta.get(jjj).code);
                        registerDuplicated=100;
                    }
                  }
                  if(registerDuplicated===0){
                    appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType:dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime }

                 modelConsulta.append(appendToList);
                }
              }
            if(dataObj.message[i].serviceType==="Resultados")
             {
                registerDuplicated=0;
                for(var jjjj = 0; jjjj < modelResultados.count; jjjj++){
                      if(modelResultados.get(jjjj).code===dataObj.message[i].code) {
                         registerDuplicated=100;
                      }
                }
                  if(registerDuplicated===0){
                    appendToList = {
                     _id:dataObj.message[i]._id,
                      counter: dataObj.message[i].counter,
                      code: dataObj.message[i].code,
                      status: dataObj.message[i].status,
                      serviceType: dataObj.message[i].serviceType,
                      openTime: dataObj.message[i].openTime,
                      closeTime: dataObj.message[i].closeTime }

                 modelResultados.append(appendToList);
                }
             }
           }
           //refresh the size of object Message
           dataObjLength = dataObj.message.length + 1;
          }
         }
     catch(e)
      {
         console.log("ERROR... " + e);
      }
    }
    //

    function postData(item)
    {
        const url="https://pokeapi.co/api/v2/pokemon/1";
    }
    function apiGetData() {
        var request = new XMLHttpRequest();
        request.open('GET', "http://192.168.13.160:3000/admins/", /* async = */ false);
        request.responseType ="json";
        request.send();
        if(request.status===200){
             // myFunction(request);
              updateListViewModel(request, modelAttGeral);
        }
        else {
            console.log("error " + request.status);
        }
    }

    function apiGetExamesData() {
            ActionsManager.welcome()
        console.log("INSIDE THE NEW JS " );
        var request = new XMLHttpRequest();
        request.open('GET', "http://192.168.13.160:3000/register/", /* async = */ false);
        request.responseType ="json";
        request.send();
        if(request.status===200){
             //console.log("MESSAGE " + request.responseText);
              updateListViewModelF(request, modelExames);
        }
        else {
            console.log("error " + request.status);
        }
    }

    function myFunction(request) {
       var myObj;
       var toAppend;
       try {
           myObj = JSON.parse(request.responseText);
           for(var i = 0; i < myObj.message.length; i++)
           {
             toAppend = {
                     CodigoUtente:myObj.message[i].email
                   //Hora:
                   //Sala:"2"
                   //Andar:"RC"
                   //Medico:"Walter Wango"
               }
              modelAttGeral.append(toAppend);

              console.log("the elements get are:" + toAppend.CodigoUtente);
           }
         }
    catch(e)
         {
           console.log("ERROR... " + e);
       }
   }

   function getNames(item)
    {
      //console.log("These are the names "+ item.email);
    }

   //.................................... UPDATE DATA JAVASCRIPT CODE.........................................
   function getTimeStamp()
   {
      var date= new Date(year, month, day, hours, minutes, seconds, milliseconds);
      date.currentDate.getDate();
      date.currentDate.getHours();
      date.currentDate.getMinutes();
      date.currentDate.getSeconds();

      return date.currentDate.getHours() + " " + date.currentDate.getHours()+":"+ date.currentDate.getMinutes()+ date.currentDate.getSeconds();
   }

   function refreshListViewModel(modelName, index)
   {
      console.log('This item will be remove from the LISTVIEW MODEL:')
      console.log('Model name: modelName and '  + " index: " + index)
      modelName.remove(index);
   }

   function getModelItem()
   {
      console.log('This is the current Item:')
      console.log(modelConsulta.get(listConsultas.currentIndex).code + ' selected')
   }

   function getModelCurrentItem(item, modelName)
   {
      indexToRemove = item.currentIndex;
      modelItemToUpdate = {
                _id:     modelName.get(item.currentIndex)._id,
                code:    modelName.get(item.currentIndex).code,
                counter: modelName.get(item.currentIndex).counter,
                status: "closed",
                serviceType: modelName.get(item.currentIndex).serviceType,
                openTime: modelName.get(item.currentIndex).openTime,
                closeTime:currentDate.toLocaleDateString("hh:mm:ss.zzz")
             };
   }

   function apiPostData()
   {
       console.log("Theses are the data to update on server")
       console.log("_id: " + modelItemToUpdate._id)
       console.log("counter: "+ modelItemToUpdate.counter)
       console.log("code: "+ modelItemToUpdate.code)
       console.log("status: "+ modelItemToUpdate.status)
       console.log("serviceType: "+ modelItemToUpdate.serviceType)
       console.log("openTime: "+ modelItemToUpdate.openTime)
       console.log("closeTime: "+ modelItemToUpdate.closeTime)

     var json = JSON.stringify(modelItemToUpdate);
     const url="http://192.168.13.160:3000/register/"+modelItemToUpdate._id;
     console.log("this is the URI "+ url)

     var request = new XMLHttpRequest();
     request.open("PUT", url, true);
     request.setRequestHeader('Content-type', 'application/json; charset=UTF-8');
     request.onload = function () {
                     var users = JSON.parse(request.responseText);
                     if (request.readyState === 4 && request.status === "200")
                      { console.table(users); }
                     else
                      { console.error(users); }
                  }
     request.send(json);

   }
   // END DATA UPDATE AND POST

 //.....................................................END.....................................................