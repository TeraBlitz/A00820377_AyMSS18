import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Routes, RouterModule } from '@angular/router';
import { FormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';
import {
  MatListModule,
  MatCardModule,
  MatButtonModule,
  MatInputModule,
  MatDatepickerModule,
  MatSelectModule,
  MatSlideToggleModule,
  MatNativeDateModule,
  MatExpansionModule,
  MatSnackBarModule,
  MatButtonToggleModule
} from '@angular/material';

import { NavigationModule } from '../../components/navigation/navigation.module';

import { AdminComponent } from './admin.component';
import { AdminListComponent } from './admin-list/admin-list.component';
import { AdminEditComponent } from './admin-edit/admin-edit.component';
import { AdminItemComponent } from './admin-item/admin-item.component';
import { RecetasEditComponent } from './recetas-edit/recetas-edit.component';
import { RecetasItemComponent } from './recetas-item/recetas-item.component';
import { RecetasListComponent } from './recetas-list/recetas-list.component';
import { MateriasPrimasEditComponent } from './materias-primas-edit/materias-primas-edit.component';
import { MateriasPrimasListComponent } from './materias-primas-list/materias-primas-list.component';
import { MateriasPrimasItemComponent } from './materias-primas-item/materias-primas-item.component';

const routes: Routes = [
  {
    path: '',
    component: AdminComponent,
    children: [
      {
        path: 'materias-primas',
        children: [
          {
            path: 'list',
            component: MateriasPrimasListComponent
          },
          {
            path: 'new',
            component: MateriasPrimasEditComponent
          },
          {
            path: ':id',
            component: MateriasPrimasItemComponent
          },
          {
            path: ':id/edit',
            component: MateriasPrimasEditComponent
          }
        ]
      },
      {
        path: 'recetas',
        children: [
          {
            path: 'list',
            component: RecetasListComponent
          },
          {
            path: 'new',
            component: RecetasEditComponent
          },
          {
            path: ':id',
            component: RecetasItemComponent
          },
          {
            path: ':id/edit',
            component: RecetasEditComponent
          }
        ]
      },
      {
        path: 'admin',
        children: [
          {
            path: 'list',
            component: AdminListComponent
          },
          {
            path: 'new',
            component: AdminEditComponent
          },
          {
            path: ':id',
            component: AdminItemComponent
          },
          {
            path: ':id/edit',
            component: AdminEditComponent
          }
        ]
      }
    ]
  }
];

@NgModule({
  imports: [
    CommonModule,
    RouterModule.forChild(routes),
    HttpClientModule,
    FormsModule,
    MatListModule,
    MatCardModule,
    MatButtonModule,
    MatInputModule,
    MatDatepickerModule,
    MatNativeDateModule,
    MatSlideToggleModule,
    MatSelectModule,
    MatExpansionModule,
    MatSnackBarModule,
    MatButtonToggleModule,
    NavigationModule
  ],
  declarations: [
    AdminComponent,
    AdminListComponent,
    AdminEditComponent,
    AdminItemComponent,
    RecetasEditComponent,
    RecetasItemComponent,
    RecetasListComponent,
    MateriasPrimasEditComponent,
    MateriasPrimasListComponent,
    MateriasPrimasItemComponent
  ]
})
export class AdminModule {}
