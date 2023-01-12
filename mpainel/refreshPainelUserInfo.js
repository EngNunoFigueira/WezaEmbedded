let i=1;
setInterval(mult,150000);
function mult(){
  i= i* 2;
  postMessage(i);
}
