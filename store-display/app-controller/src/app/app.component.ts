import { Component, OnInit } from '@angular/core';
import * as readjson from './recipes.json';

@Component({
  selector: 'app-root',
  templateUrl: './index.html',
  styleUrls: ['./index.css']
})

export class AppComponent {
  id = 0;
  title = 'MOS';
  flagId:number=0;
  typeOfFish:string = "rodaballo";
  fish  = 'assets/images/gelo-rodaballo.jpg';
  receita = 'assets/images/rodaballo-sat.jpg';
  products: any = (readjson as any).default;
  
  ngOnInit() {
    console.log("NUNO MIGUEL FIGUEIRA");
    //console.log("NOME DO PRODUTO", this.products[0].name);
    //this.products[0].name;
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

    //console.log('Call Function Every Five Seconds.', new Date());
    if(this.flagId < 8 && this.typeOfFish =="rodaballo")
    {
      //this.fish  = 'assets/images/gelo-rodaballo.jpg';
      this.receita = this.products[this.flagId].rodaballo;
      this.flagId ++;
    }
    if(this.flagId < 8 && this.typeOfFish =="lubina" )
    {
      this.receita = this.products[this.flagId].lubina;
      this.flagId ++;
    }
    if(this.flagId < 8 && this.typeOfFish =="bacalao" )
    {
      this.receita = this.products[this.flagId].bacalao;
      this.flagId ++;
    }
    if(this.flagId < 8 && this.typeOfFish =="gambas" )
    {
      this.receita = this.products[this.flagId].gambas;
      this.flagId ++;
    }
    if(this.flagId == 8 && this.typeOfFish =="rodaballo")
    {
      this.flagId = 0;
      this.fish = 'assets/images/lubina-gelo-03.jpg';
      this.typeOfFish ="lubina";
    }
    if(this.flagId == 8 && this.typeOfFish =="lubina")
    {
      this.flagId = 0;
      this.fish  = 'assets/images/bacalao-01.jpg';
      this.typeOfFish ="bacalao";
    }
    if(this.flagId == 8 && this.typeOfFish =="bacalao")
    {
      this.flagId = 0;
      this.fish  = 'assets/images/gambas-gelo-02.jpg';
      this.typeOfFish ="gambas";
    }
    if(this.flagId == 8 && this.typeOfFish =="gambas")
    {
      this.flagId = 0;
      this.fish  = 'assets/images/gelo-rodaballo.jpg';
      this.typeOfFish ="rodaballo";
    }
    
  }
}
