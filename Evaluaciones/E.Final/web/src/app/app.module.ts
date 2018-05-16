import { BrowserModule } from '@angular/platform-browser';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';

import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HttpClientModule } from '@angular/common/http';

import { AppComponent } from './app.component';

import { AdminService } from './services/admin.service';
import { RecetasService } from './services/recetas.service';
import { MateriasPrimasService } from './services/materias-primas.service';

export const routes: Routes = [
  {
    path: 'admin',
    loadChildren: 'app/modules/admin/admin.module#AdminModule'
  },
  {
    path: '',
    loadChildren:
      'app/modules/authentication/authentication.module#AuthenticationModule'
  },
  {
    path: '**',
    redirectTo: '/admin/materias-primas/list'
  }
];

@NgModule({
  declarations: [AppComponent],
  imports: [
    BrowserModule,
    BrowserAnimationsModule,
    RouterModule.forRoot(routes),
    HttpClientModule
  ],
  providers: [AdminService, RecetasService, MateriasPrimasService],
  bootstrap: [AppComponent]
})
export class AppModule {}
