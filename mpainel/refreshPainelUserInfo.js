/****************************************************************************************************** 
 * Author   : Nuno Figueira                                                                           *
 * Dev Year : 2019/2020                                                                               *
 * Release  : 1.1.0 beta                                                                              *
 * Project  : Agenda Medic - Mpainel                                                                  *
 *                                                                                                    *
 * Javascript worker functionality:                                                                   *
 * The worker is not full developed in this release. For now its basically used as a timer for now.   *
 * to manager the fetch interval used to refresh the list o Tickets ID to display.                    *
 *                                                                                                    *
 * But the point is:                                                                                  *
 * In future release, we pretend use a JS worker to execute the Fecth API data actions. Avoid doing   *
 * this operation on fronted side.                                                                    *
 * ****************************************************************************************************/

let expireTimer = 1;
setInterval(mult, 150000);
function mult() {
  expireTimer = expireTimer * 2;
  postMessage(expireTimer);
}
