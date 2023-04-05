import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { LoginComponent } from './login/login.component';
import { MotoristasComponent } from './motoristas/motoristas.component';
import { MapaComponent } from './mapa/mapa.component';
import { GoogleMapsModule } from '@angular/google-maps';
import { HomeComponent } from './home/home.component';
import { ProfilesComponent } from './profiles/profiles.component';
import { FrotaComponent } from './frota/frota.component';

@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    MotoristasComponent,
    MapaComponent,
    HomeComponent,
    ProfilesComponent,
    FrotaComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
   GoogleMapsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
