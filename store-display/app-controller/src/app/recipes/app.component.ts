import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './index.html',
  styleUrls: ['./index.css']
})
export class AppComponent {
  id = 0;
  title = 'MOS';
  fish  = 'assets/images/gelo-rodaballo.jpg';
  receita = 'assets/images/rodaballo-sat.jpg';
    ngOnInit() {

    this.callMethod();

    this.id = setInterval(() => {

      this.callMethod(); 

    }, 5000);

  }

  

  /*------------------------------------------

  --------------------------------------------

  ngOnDestroy

  --------------------------------------------

  --------------------------------------------*/

  ngOnDestroy() {

    if (this.id) {

      clearInterval(this.id);

    }

  }

  

  /*------------------------------------------

  --------------------------------------------

  callMethod

  --------------------------------------------

  --------------------------------------------*/

  callMethod(){

    console.log('Call Function Every Five Seconds.', new Date());

  }
}
