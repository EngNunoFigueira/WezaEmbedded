import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { FrotaComponent } from './frota/frota.component';
import { HomeComponent } from './home/home.component';
import { LoginComponent } from './login/login.component';
import { MapaComponent } from './mapa/mapa.component';
import { MotoristasComponent } from './motoristas/motoristas.component';
import { ProfilesComponent } from './profiles/profiles.component';

const routes: Routes = [
{path: 'home', component:HomeComponent},
{path: 'trafico', component:MapaComponent},
{path: 'profiles', component:ProfilesComponent},
{path: 'documents', component:MotoristasComponent},
{path: '', component:LoginComponent},
{path: 'login', component:LoginComponent},
{path: 'frota', component:FrotaComponent},

];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
