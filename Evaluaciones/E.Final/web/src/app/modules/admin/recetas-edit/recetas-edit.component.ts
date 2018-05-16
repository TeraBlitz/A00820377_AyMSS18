import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { RecetasService } from '../../../services/recetas.service';
import { MatSnackBar } from '@angular/material';

@Component({
  selector: 'app-recetas-edit',
  templateUrl: './recetas-edit.component.html',
  styleUrls: ['./recetas-edit.component.scss']
})
export class RecetasEditComponent implements OnInit {
  public id: any;
  public r: any;

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private rService: RecetasService,
    private snackBar: MatSnackBar
  ) {
    this.r = {};
  }

  ngOnInit() {
    this.id = this.route.snapshot.params['id'];
    if (this.id) {
      this.rService.getR(this.id).subscribe((response: any) => {
        this.r = response.item;
      });
    }
  }

  createR() {
    this.rService
      .createR(this.r)
      .catch((error, caught) => {
        this.snackBar.open(
          'La receta no pudo ser agregada. Verificar los datos.',
          null,
          {
            duration: 2000
          }
        );
        return caught;
      })
      .subscribe(() => {
        this.router.navigateByUrl('/admin/recetas/list');
      });
  }

  updateR() {
    this.rService
      .updateR(this.r)
      .catch((error, caught) => {
        this.snackBar.open(
          'La receta no pudo ser agregada. Verificar los datos.',
          null,
          {
            duration: 2000
          }
        );
        return caught;
      })
      .subscribe(() => {
        this.router.navigateByUrl('/admin/recetas/list');
      });
  }
}
